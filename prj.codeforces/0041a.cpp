#include <iostream>
#include <string>

int main() {
    int k(0);
    std::string s, t;
    std::string s1;
    std::cin >> s >> t;
    int len = s.length();
    for (int i(len - 1); i >= 0; i--) {
        s1.push_back(s[i]);
    }
    if (t == s1){
        std::cout << "YES";
    }
    else std::cout << "NO";
}