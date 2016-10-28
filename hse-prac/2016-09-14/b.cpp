#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::string onlyLetters;
    for (char c : inputLine) {
        if (isalpha(c)) {
            onlyLetters.push_back(tolower(c));
        }
    }
    std::string reversedLetters(onlyLetters);
    std::reverse(reversedLetters.begin(), reversedLetters.end());
    if (reversedLetters == onlyLetters) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
