#include <iostream>
#include <string>

int main() {
    int len(0);
    std::string amount;
    std::cin >> amount;
    len = amount.length();
    for (int i(0); i < len - 1; i++) {
        for (int j(0); j < len - i - 1; j += 2) {
            char j1 = amount[j];
            char j2 = amount[j + 2];
            if (j1 > j2) {
                std::swap(amount[j], amount[j + 2]);
            }
        }
    }
    std::cout << amount;
}