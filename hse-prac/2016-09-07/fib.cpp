#include <iostream>

int main() {
    int numbersCount;
    std::cin >> numbersCount;
    long long previousNumber, currentNumber;
    previousNumber = currentNumber = 1;
    std::cout << previousNumber << ' ' << currentNumber << ' ';
    for (int i = 2; i < numbersCount; i++) {
        std::cout << previousNumber + currentNumber << ' ';
        std::swap(previousNumber, currentNumber);
        currentNumber += previousNumber;
    }
    std::cout << '\n';
    return 0;
}
