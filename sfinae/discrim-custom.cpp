#include "gtest/gtest.h"
#include <concepts>

template <typename T> struct TypeIdentity { using type = T; };

template <typename...> struct Void : TypeIdentity<void> {};
template <typename... Args> using Void_t = typename Void<Args...>::type;

// ensure that new Void_t is still alias to void
TEST(mysfinae, newvoid) {
  auto res = std::is_same_v<std::void_t<int>, Void_t<int>>;
  EXPECT_EQ(res, true);
}

// ----------------------------------------------------------------------------

struct One {
  using fst = int;
};

struct Two {
  using snd = int;
};

template <typename T, Void_t<typename T::fst> * = nullptr> int foo() {
  return 1;
}

template <typename T, Void_t<typename T::snd> * = nullptr> int foo() {
  return 2;
}

TEST(sfinae, discrimfixed) {
  auto x = foo<One>();
  auto y = foo<Two>();
  EXPECT_EQ(x, 1);
  EXPECT_EQ(y, 2);
}
