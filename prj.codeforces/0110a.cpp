#include <iostream>

int main() {
    int n(0), k(0);
    std::cin >> n >> k;
    while (k > 0) {
        if (k > 0) {
            while ((k > 0) && (n % 10 != 0)) {
                n -= 1;
                k--;
            }
        }
        if (k > 0) {
            while ((k > 0) && (n % 10 == 0)) {
                n /= 10;
                k--;
            }
        }
    }
    std::cout << n;
}