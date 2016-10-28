#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& whatToSplit, char separator) {
    std::string currentToken;
    std::vector<std::string> result;
    for (char currentSymbol : whatToSplit) {
        if (currentSymbol == separator) {
            result.push_back(currentToken);
            currentToken.clear();
        } else {
            currentToken.push_back(currentSymbol);
        }
    }
    result.push_back(currentToken);
    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    char separator = 0;
    std::cin >> separator;
    std::vector<std::string> splitResult = Split(input, separator);
    for (std::string currentToken : splitResult) {
        std::cout << currentToken << '\n';
    }
    return 0;
}


