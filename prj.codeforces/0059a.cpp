#include <iostream>
#include <string>

int main() {
    int letters(0), LETTERS(0);
    std::string word;
    std::cin >> word;
    int len = word.length();
    for (int i(0); i < len; i++) {
        if (isupper(word[i])) {
            LETTERS++;
        }
        else letters++;
    }
    if (letters >= LETTERS) {
        for (int i(0); i < len; i++)
            if (isupper(word[i])) {
                word[i] += 32;
            }
    }
    else {
        for (int i(0); i < len; i++) {
            if (islower(word[i])) {
                word[i] -= 32;
            }
        }
    }
    std::cout << word;
}