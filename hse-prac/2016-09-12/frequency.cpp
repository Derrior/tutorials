#include <iostream>
#include <vector>
#include <string>

const int LINES_AMOUNT = 8;

int main() {
    std::string inputText;
    char inputChar;
    std::vector<int> symbolFrequency(128, 0);
    while (std::cin >> inputChar) {
        symbolFrequency[static_cast <int> (inputChar)]++;
    }
    std::cout.width(3);
    for (int i = 2; i < LINES_AMOUNT; i++) {
        for (int j = 0; j < 128 / LINES_AMOUNT; j++) {
            std::cout.width(3);
            std::cout << static_cast <char> (i * 128 / LINES_AMOUNT + j) << ' ';
        }
        std::cout << '\n';
        for (int j = 0; j < 128 / LINES_AMOUNT; j++) {
            std::cout.width(3);
            std::cout << symbolFrequency[i * 128 / LINES_AMOUNT + j] << ' ';
        }
        std::cout << "\n\n";
    }


}
