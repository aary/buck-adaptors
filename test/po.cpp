#include <boost/program_options.hpp>

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
namespace po = boost::program_options;


static void handle_kill_command(const po::variables_map& vm,
                                const po::options_description& options);
static void handle_build_command(const po::variables_map& vm,
                                 const po::options_description& options);

static string get_help_string(const po::options_description& options);

static std::tuple<std::string, po::variables_map, po::options_description>
parse_flags(
        int argc,
        char** argv,
        const po::options_description& general_options,
        std::vector<std::tuple<std::string, po::options_description,
                    po::positional_options_description>> options_description,
        std::string (*get_help_string)(const po::options_description& options));


int main(int argc, char** argv) {

    // the general commands that can be used with any subcommand
    auto general_options = po::options_description{};
    general_options.add_options()
        ("verbose,v", po::value<int>()->default_value(1), "The verbosity level")
        ("help,h", "Display general or subcommand help");

    auto build_options = po::options_description{};
    build_options.add_options()
        ("target", po::value<std::string>(), "The name of the target to build, "
            "the flag --target itself is optional")
        ("compression", po::value<int>()->default_value(10),
            "The compression of the build")
        ("flag", "Set to enable flagging of flagworthy things");
    auto build_positional_options = po::positional_options_description{};
    build_positional_options.add("target", 1);

    auto kill_options = po::options_description{};
    kill_options.add_options()
        ("target", po::value<std::string>(), "The name of the target to build, "
            "the flag --target itself is optional");
    auto kill_positional_options = po::positional_options_description{};
    kill_positional_options.add("target", 1);

    try {
        // this ugly problem will be solved in C++17 with structured bindings
        auto return_tuple = parse_flags(argc, argv, general_options,
                {{"build", build_options, build_positional_options},
                 {"kill", kill_options, kill_positional_options}},
                get_help_string);
        const auto& command = std::get<0>(return_tuple);
        const auto& vm = std::get<1>(return_tuple);
        const auto& relevant_options = std::get<2>(return_tuple);

        if (command == "build") {
            handle_build_command(vm, relevant_options);
        } else if (command == "kill") {
            handle_kill_command(vm, relevant_options);
        }

    } catch (std::exception& exc) {
        cerr << exc.what() << endl;
        return 1;
    }

    return 0;
}

std::tuple<std::string, po::variables_map, po::options_description> parse_flags(
        int argc,
        char** argv,
        const po::options_description& general_options,
        std::vector<std::tuple<std::string, po::options_description,
                    po::positional_options_description>> options_description,
        string (*get_help_string)(const po::options_description& options)) {
    // get the command string, if one does not exist then throw an exception
    // with the usage
    auto command = string{argv[1]};
    auto iter_to_options = std::find_if(options_description.begin(),
            options_description.end(), [&](const auto& tup) {
        return std::get<0>(tup) == command;
    });

    // throw a runtime error with the help
    if (iter_to_options == options_description.end()) {
        throw std::runtime_error{get_help_string(general_options)};
    }

    // make the options
    const auto& relevant_command = std::get<0>(*iter_to_options);
    auto& relevant_options = std::get<1>(*iter_to_options);
    const auto& relevant_positional_options = std::get<2>(*iter_to_options);
    relevant_options.add(general_options);

    // get the variable map
    auto vm = po::variables_map{};
    po::store(po::command_line_parser(vector<string>{argv + 2, argv + argc})
            .options(relevant_options).positional(relevant_positional_options)
            .run(), vm);

    return std::make_tuple(std::move(relevant_command), std::move(vm),
            std::move(relevant_options));
}


void handle_build_command(const po::variables_map& vm,
                          const po::options_description& options) {

    if (vm.count("help")) {
        cout << get_help_string(options);
        return;
    }

    if (vm.count("target")) {
        cout << "Building target for " << vm["target"].as<std::string>()
             << endl
             << "With verbosity " << vm["verbose"].as<int>() << endl;
    }
}

void handle_kill_command(const po::variables_map& vm,
                         const po::options_description& options) {

    if (vm.count("help")) {
        cout << get_help_string(options);
        return;
    }

    if (vm.count("target")) {
        cout << "Killing target " << vm["target"].as<std::string>()
             << endl
             << "With verbosity " << vm["verbose"].as<int>() << endl;
    }
}

string get_help_string(const po::options_description& options) {
    static const auto PROGRAM_NAME = "po";
    stringstream ss;
    ss << "Usage: " << endl;
    ss << "  " << PROGRAM_NAME << " build <target> [options]" << endl;
    ss << "  " << PROGRAM_NAME << " build --help" << endl;
    ss << "  " << PROGRAM_NAME << " kill <target> [options]" << endl;
    ss << "  " << PROGRAM_NAME << " kill --help";
    ss << endl << endl;
    ss << "Options:" << endl;
    ss << options << endl;
    return ss.str();
}
