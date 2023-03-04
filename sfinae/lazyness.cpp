#include "gtest/gtest.h"
#include <concepts>

template <int N> struct Danger { typedef char block[N]; };

template <typename T, int N> struct Tricky {
  int k = N;
  void test_lazyness() { Danger<N> no_boom_yet; }
};

TEST(sfinae, tricky) {
  Tricky<int, -2> ok;
  EXPECT_EQ(ok.k, -2);
}