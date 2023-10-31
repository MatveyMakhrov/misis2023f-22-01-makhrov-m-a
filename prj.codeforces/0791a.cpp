#include <iostream>

int main() {
    int a(0), b(0), years(0);
    std::cin >> a >> b;
    while (a <= b) {
        a *= 3;
        b *= 2;
        years++;
    }
    std::cout << years;
}