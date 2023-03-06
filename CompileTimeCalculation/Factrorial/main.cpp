#include <iostream>

constexpr int factorial(int n) {
    return n ? (n * factorial(n - 1)) : 1;
}

constexpr int f10 = factorial(10);

int main() {
    std::cout<< f10;
    return 0;
}
