#include <iostream>

int main() {
    int k(0), n(0), w(0), sum(0);
    std::cin >> k >> n >> w;
    for (int i(1); i <= w; i++) {
        sum += i * k;
    }
    if (sum >= n) {
        std::cout << sum - n;
    }
    else std::cout << 0;
}