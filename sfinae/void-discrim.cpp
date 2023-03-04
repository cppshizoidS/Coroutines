#include "gtest/gtest.h"
#include <type_traits>

struct One {
  using fst = int;
};

struct Two {
  using snd = int;
};

template <typename T, std::void_t<typename T::fst> * = nullptr> int foo() {
  return 1;
}

template <typename T, std::void_t<typename T::snd> * = nullptr> int foo() {
  return 2;
}

TEST(sfinae, discrimbroken) {
  auto x = foo<One>();
  auto y = foo<Two>();
  EXPECT_EQ(x, 1);
  EXPECT_EQ(y, 2);
}
