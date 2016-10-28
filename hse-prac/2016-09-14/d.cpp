#include <cctype>
#include <deque>
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

bool isDecimal(const std::string& testString) {
    for (char currentSymbol : testString) {
        if (!isdigit(currentSymbol)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string currentLine;
    std::getline(std::cin, currentLine);
    std::vector<std::string> arguments = Split(currentLine, ' ');
    int amountOfOutputLines = 10;
    for (size_t i = 0; i < arguments.size(); ++i) {
        if (arguments[i] == "-n") {
            if (i < arguments.size() - 1 && isDecimal(arguments[i + 1])) {
                amountOfOutputLines = stoi(arguments[i + 1]);
            }
        }
    }
    std::deque <std::string> ourTail;
    while (std::getline(std::cin, currentLine)) {
        ourTail.push_back(currentLine);
        if (static_cast<int> (ourTail.size()) > amountOfOutputLines) {
            ourTail.pop_front();
        }
    }
    while (!ourTail.empty()) {
        std::cout << ourTail.front() << '\n';
        ourTail.pop_front();
    }
    return 0;
}
