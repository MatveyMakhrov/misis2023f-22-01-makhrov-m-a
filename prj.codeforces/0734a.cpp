#include <iostream>
#include <string>

int main() {
    int n(0), kA(0), kD(0);
    std::string results;
    std::cin >> n >> results;
    int len = results.length();
    for (int i(0); i < len; i++) {
        if (results[i] == 65) {
            kA++;
        }
        else kD++;
    }
    if (kA > kD) {
        std::cout << "Anton";
    }
    if (kA < kD) {
        std::cout << "Danik";
    }
    if (kA == kD) {
        std::cout << "Friendship";
    }
}