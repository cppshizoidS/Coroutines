#include "gtest/gtest.h"
#include <concepts>

template <typename T, typename = std::enable_if_t<(sizeof(T) > 4)>>
int foo(T x) {
  return 14;
}

template <typename T, typename = std::enable_if_t<(sizeof(T) <= 4)>>
int foo(T x) {
  return 42;
}

TEST(sfinae, naiveovr) {
  EXPECT_EQ(foo('c'), 14);
  EXPECT_EQ(foo(1.0), 42);
}