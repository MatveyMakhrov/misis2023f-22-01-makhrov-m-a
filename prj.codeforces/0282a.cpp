#include <iostream>
#include <string>

int main() {
    int n(0), x(0);
    std::string operation;
    std::cin >> n;
    for (int i(0); i < n; i++) {
        std::cin >> operation;
        char c(0);
        c = operation[1];
        if (c == '+') {
            x++;
        }
        if (c == '-') {
            x--;
        }
    }
    std::cout << x;
}