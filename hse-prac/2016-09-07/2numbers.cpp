#include <iostream>
#include <vector>


int main() {
    int numbersAmount;
    std::cin >> numbersAmount;
    std::vector<int> inputArray(numbersAmount);
    for (int i = 0; i < numbersAmount; i++) {
        cin >> inputArray[i];
    }
}
