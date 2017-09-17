#include <gtest/gtest.h>

#include <boost/atomic.hpp>
#include <boost/coroutine2/all.hpp>

TEST(boost, atomic) {
    boost::atomic<int> a;
    a.store(1);
    EXPECT_EQ(a.load(), 1);
}

TEST(boost, Coroutine) {
    auto sum = 0;
	using Coroutine_t = boost::coroutines2::coroutine<int>::push_type;
    auto coro = Coroutine_t{[&](auto& yield) {
        for (;;) {
            sum += yield.get();
            yield(); // jump back to starting context
         }
	}};

	coro(1); // transfer {1} to coroutine-function
	coro(2); // transfer {2} to coroutine-function
	coro(3); // transfer {3} to coroutine-function
	coro(4); // transfer {4} to coroutine-function
	coro(5); // transfer {5} to coroutine-function

    EXPECT_EQ(sum, 15);
}
