#include "gtest/gtest.h"
#include <concepts>
#include <experimental/type_traits>

template <typename T> using has_typedef_foobar_t = typename T::foobar;
template <typename T>
using has_typedef_foobar =
    std::experimental::is_detected<has_typedef_foobar_t, T>;

struct foo {
  using foobar = float;
};
struct bar {};

TEST(sfinae, detect) {
  EXPECT_EQ(has_typedef_foobar<foo>::value, true);
  EXPECT_EQ(has_typedef_foobar<bar>::value, false);
}