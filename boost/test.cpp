#include <boost/accumulators/accumulators.hpp>
#include <boost/algorithm/algorithm.hpp>
#include <boost/align/align.hpp>
#include <boost/align.hpp>
#include <boost/any.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/assert.hpp>
#include <boost/current_function.hpp>
#include <boost/assign.hpp>
#include <boost/atomic.hpp>
#include <boost/memory_order.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap.hpp>
#include <boost/bind.hpp>
#include <boost/is_placeholder.hpp>
#include <boost/mem_fn.hpp>
#include <boost/chrono.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/compute.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/requires.hpp>
#include <boost/concept/usage.hpp>
#include <boost/concept_archetype.hpp>
#include <boost/concept_check.hpp>
#include <boost/config.hpp>
#include <boost/cstdint.hpp>
#include <boost/cxx11_char_types.hpp>
#include <boost/detail/workaround.hpp>
#include <boost/limits.hpp>
#include <boost/version.hpp>
#include <boost/container/adaptive_pool.hpp>
#include <boost/container/allocator.hpp>
#include <boost/container/allocator_traits.hpp>
#include <boost/container/container_fwd.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/detail/adaptive_node_pool.hpp>
#include <boost/container/detail/adaptive_node_pool_impl.hpp>
#include <boost/container/detail/addressof.hpp>
#include <boost/container/detail/advanced_insert_int.hpp>
#include <boost/container/detail/algorithm.hpp>
#include <boost/container/detail/alloc_helpers.hpp>
#include <boost/container/detail/allocation_type.hpp>
#include <boost/container/detail/allocator_version_traits.hpp>
#include <boost/container/detail/auto_link.hpp>
#include <boost/container/detail/block_list.hpp>
#include <boost/container/detail/block_slist.hpp>
#include <boost/container/detail/compare_functors.hpp>
#include <boost/container/detail/config_begin.hpp>
#include <boost/container/detail/config_end.hpp>
#include <boost/container/detail/construct_in_place.hpp>
#include <boost/container/detail/copy_move_algo.hpp>
#include <boost/container/detail/destroyers.hpp>
#include <boost/container/detail/dispatch_uses_allocator.hpp>
#include <boost/container/detail/dlmalloc.hpp>
#include <boost/container/detail/flat_tree.hpp>
#include <boost/container/detail/function_detector.hpp>
#include <boost/container/detail/is_sorted.hpp>
#include <boost/container/detail/iterator.hpp>
#include <boost/container/detail/iterator_to_raw_pointer.hpp>
#include <boost/container/detail/iterators.hpp>
#include <boost/container/detail/math_functions.hpp>
#include <boost/container/detail/min_max.hpp>
#include <boost/container/detail/minimal_char_traits_header.hpp>
#include <boost/container/detail/mpl.hpp>
#include <boost/container/detail/multiallocation_chain.hpp>
#include <boost/container/detail/mutex.hpp>
#include <boost/container/detail/next_capacity.hpp>
#include <boost/container/detail/node_alloc_holder.hpp>
#include <boost/container/detail/node_pool.hpp>
#include <boost/container/detail/node_pool_impl.hpp>
#include <boost/container/detail/pair.hpp>
#include <boost/container/detail/placement_new.hpp>
#include <boost/container/detail/pool_common.hpp>
#include <boost/container/detail/pool_common_alloc.hpp>
#include <boost/container/detail/pool_resource.hpp>
#include <boost/container/detail/singleton.hpp>
#include <boost/container/detail/std_fwd.hpp>
#include <boost/container/detail/to_raw_pointer.hpp>
#include <boost/container/detail/transform_iterator.hpp>
#include <boost/container/detail/tree.hpp>
#include <boost/container/detail/type_traits.hpp>
#include <boost/container/detail/value_init.hpp>
#include <boost/container/detail/variadic_templates_tools.hpp>
#include <boost/container/detail/version_type.hpp>
#include <boost/container/detail/workaround.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/list.hpp>
#include <boost/container/map.hpp>
#include <boost/container/new_allocator.hpp>
#include <boost/container/node_allocator.hpp>
#include <boost/container/node_handle.hpp>
#include <boost/container/options.hpp>
#include <boost/container/pmr/deque.hpp>
#include <boost/container/pmr/flat_map.hpp>
#include <boost/container/pmr/flat_set.hpp>
#include <boost/container/pmr/global_resource.hpp>
#include <boost/container/pmr/list.hpp>
#include <boost/container/pmr/map.hpp>
#include <boost/container/pmr/memory_resource.hpp>
#include <boost/container/pmr/monotonic_buffer_resource.hpp>
#include <boost/container/pmr/polymorphic_allocator.hpp>
#include <boost/container/pmr/pool_options.hpp>
#include <boost/container/pmr/resource_adaptor.hpp>
#include <boost/container/pmr/set.hpp>
#include <boost/container/pmr/slist.hpp>
#include <boost/container/pmr/small_vector.hpp>
#include <boost/container/pmr/stable_vector.hpp>
#include <boost/container/pmr/string.hpp>
#include <boost/container/pmr/synchronized_pool_resource.hpp>
#include <boost/container/pmr/unsynchronized_pool_resource.hpp>
#include <boost/container/pmr/vector.hpp>
#include <boost/container/scoped_allocator.hpp>
#include <boost/container/scoped_allocator_fwd.hpp>
#include <boost/container/set.hpp>
#include <boost/container/slist.hpp>
#include <boost/container/small_vector.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/container/string.hpp>
#include <boost/container/throw_exception.hpp>
#include <boost/container/uses_allocator.hpp>
#include <boost/container/uses_allocator_fwd.hpp>
#include <boost/container/vector.hpp>
#include <boost/context/all.hpp>
#include <boost/implicit_cast.hpp>
#include <boost/polymorphic_cast.hpp>
#include <boost/polymorphic_pointer_cast.hpp>
#include <boost/convert.hpp>
#include <boost/make_default.hpp>
#include <boost/checked_delete.hpp>
#include <boost/core/addressof.hpp>
#include <boost/core/checked_delete.hpp>
#include <boost/core/demangle.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/core/explicit_operator_bool.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/core/is_same.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <boost/core/no_exceptions_support.hpp>
#include <boost/core/noncopyable.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/core/ref.hpp>
#include <boost/core/scoped_enum.hpp>
#include <boost/core/swap.hpp>
#include <boost/core/typeinfo.hpp>
#include <boost/core/underlying_type.hpp>
#include <boost/detail/iterator.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/detail/no_exceptions_support.hpp>
#include <boost/detail/scoped_enum_emulation.hpp>
#include <boost/detail/sp_typeinfo.hpp>
#include <boost/get_pointer.hpp>
#include <boost/iterator.hpp>
#include <boost/non_type.hpp>
#include <boost/noncopyable.hpp>
#include <boost/ref.hpp>
#include <boost/swap.hpp>
#include <boost/type.hpp>
#include <boost/utility/addressof.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/utility/explicit_operator_bool.hpp>
#include <boost/utility/swap.hpp>
#include <boost/visit_each.hpp>
#include <boost/coroutine2/all.hpp>
#include <boost/crc.hpp>
#include <boost/date_time.hpp>
#include <boost/blank.hpp>
#include <boost/blank_fwd.hpp>
#include <boost/cstdlib.hpp>
#include <boost/pending/detail/disjoint_sets.hpp>
#include <boost/pending/disjoint_sets.hpp>
#include <boost/dll/alias.hpp>
#include <boost/dll.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/pending/lowest_bit.hpp>
#include <boost/exception/all.hpp>
#include <boost/fiber/all.hpp>
#include <boost/filesystem.hpp>
#include <boost/flyweight.hpp>
#include <boost/foreach.hpp>
#include <boost/foreach_fwd.hpp>
#include <boost/format.hpp>
#include <boost/function.hpp>
#include <boost/function_equal.hpp>
#include <boost/functional.hpp>
#include <boost/fusion/view.hpp>
#include <boost/geometry.hpp>
#include <boost/pending/property_serialize.hpp>
#include <boost/hana/all.hpp>
#include <boost/heap/policies.hpp>
#include <boost/heap/priority_queue.hpp>
#include <boost/heap/skew_heap.hpp>
#include <gtest/gtest.h>

TEST(boost, boost) {
    auto int_ptr = boost::make_shared<int>(1);
    EXPECT_EQ(*int_ptr, 1);
}
