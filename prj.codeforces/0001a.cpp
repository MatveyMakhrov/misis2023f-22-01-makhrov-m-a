#include<iostream>

int main() {
    long long int n(0), m(0), a(0), k1(0), k2(0);
    std::cin >> n >> m >> a;
    if (n % a == 0) {
        k1 = n / a;
    }
    else k1 = n / a + 1;
    if (m % a == 0) {
        k2 = m / a;
    }
    else k2 = m / a + 1;
    std::cout << k1 * k2;
}