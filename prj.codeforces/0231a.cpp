#include <iostream>

int main() {
    int n(0), games(0), win(0);
    std::cin >> n;
    for (int i(0); i < n; i++) {
        int k(0);
        for (int j(0); j < 3; j++) {
            std::cin >> games;
            k = k + games;
        }
        if (k >= 2) {
            win++;
        }
        else k = 0;
    }
    std::cout << win << std::endl;
}