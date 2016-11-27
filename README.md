# Buck Adaptors

This repository contains a adaptors to various libraries written in C++ for
portability.  Folders in this repository are submodule backed and therefore
the recommended way to install any of these modules is with git submodules

```shell
git submodule add <remote> <name of library>
git submodule update --init --recursive
```
And then add the relevant repository to the `.buckconfig` for your project

```shell
[repositories]
    <name of library> = <path of submodule>
```

See [this example project](https://github.com/aary/sharp-example) for an
example of how to use buck with buck-backed git submodules containing library
code.

### Motivation

Compilation in C++ with external libraries has been a massive pain in the past
because it invariably involves some sort of install process with a complicated
bootstrap shell script that dumps unwanted things into your file system, and
often require sudo access.

Buck in addition to being a cross language build platform, can also solve the
problem of installing external libraries by virtue of its modularized
structure of compile files.
