#include "gtest/gtest.h"
#include <concepts>
#include <type_traits>

template <typename, typename = void>
struct has_typedef_foobar : std::false_type {};

template <typename T>
struct has_typedef_foobar<T, std::void_t<typename T::foobar>> : std::true_type {
};

struct foo {
  using foobar = float;
};
struct bar {};

TEST(sfinae, hasfoobar) {
  EXPECT_EQ(has_typedef_foobar<foo>::value, true);
  EXPECT_EQ(has_typedef_foobar<bar>::value, false);
}