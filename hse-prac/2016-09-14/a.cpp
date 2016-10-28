#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string password;
    std::getline(std::cin, password);
    bool lengthCondition = false, symbolsCondition = true;
    lengthCondition = (password.length() >= 8) && (password.length() <= 14);
    bool hasUpperCase, hasLowerCase, hasNumeral, hasOther;
    hasUpperCase = hasLowerCase = hasNumeral = hasOther = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUpperCase = true;
        } else if (islower(c)) {
            hasLowerCase = true;
        } else if (isdigit(c)) {
            hasNumeral = true;
        } else if (isspace(c) || iscntrl(c)) {
            symbolsCondition = false;
        } else {
            hasOther = true;
        }
    }
    int conditionAmount = hasOther + hasUpperCase + hasLowerCase + hasNumeral;
    if (lengthCondition && symbolsCondition && (conditionAmount >= 3)) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
    return 0;
}
