#include <iostream>
#include <string>

int main() {
    int n(0);
    std::string word;
    std::cin >> n;
    for (int i(0); i < n; i++) {
        std::cin >> word;
        int len;
        len = word.length();
        if (len > 10) {
            word.erase(1, len - 2);
            std::string in = std::to_string(len - 2);
            word.insert(1, in);
            std::cout << word << std::endl;
        }
        else {
            std::cout << word << std::endl;
        }
    }
}