#include "gtest/gtest.h"
#include <concepts>

template <typename T> struct has_typedef_foobar {
  using yes = char[1];
  using no = char[2];
  template <typename C> static yes &test(typename C::foobar *);
  template <typename> static no &test(...);
  enum { value = (sizeof(test<T>(0)) == sizeof(yes)) };
};

struct foo {
  using foobar = float;
};
struct bar {};

TEST(sfinae, hasfoobarnaive) {
  EXPECT_EQ(has_typedef_foobar<foo>::value, true);
  EXPECT_EQ(has_typedef_foobar<bar>::value, false);
}