#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string name;
    std::cin >> name;
    int len = name.length();
    std::sort(name.begin(), name.end());
    name.erase(std::unique(name.begin(), name.end()), name.end());
    if (name.size() % 2 == 0) std::cout << "CHAT WITH HER!" << std::endl;
    else std::cout << "IGNORE HIM!";
    std::cout << name;
}