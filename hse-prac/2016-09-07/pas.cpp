#include <iostream>

int main() {
    int lineNumber;
    std::cin >> lineNumber;
    for (int i = 0; i < lineNumber + 1; i++) {
        long long currentNumber = 1;
        for (int j = 1; j < i + 1; j++) {
            std::cout << currentNumber << ' ';
            currentNumber *= (i - j);
            currentNumber /= j;
        }
        std::cout << '\n';
    }

}
