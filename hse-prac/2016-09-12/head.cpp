#include <iostream>
#include <string>
#include <cstdio>


int main() {
    int amountOfLines = 0;
    std::cin >> amountOfLines;
    std::string result, currentLine;
    std::getline(std::cin, currentLine); 
    for (int i = 0; i < amountOfLines; i++) {
        if (!std::getline(std::cin, currentLine)) {
            break;
        }
        result.append(currentLine);
        result.push_back('\n');
    }
    std::cout << result;
}
