#include <iostream>
#include <vector>

int MathMod(int a, int b) {
    return (a % b + b) % b;
}

void rotate(std::vector<int> &data, int shift) {
    int length = data.size();
    if (!length) {
        return;
    }
    std::vector<int> afterShift(length);
    for (int i = 0; i < length; i++) {
        afterShift[MathMod(i + shift, length)] = data[i];
    }
    data = afterShift;
}

int main() {
    int amountOfNumbers = 0;
    std::cin >> amountOfNumbers;
    std::vector<int> numbers(amountOfNumbers);
    for (int &elem : numbers) {
        std::cin >> elem;
    }
    int shiftWidth = 0;
    std::cin >> shiftWidth;
    rotate(numbers, shiftWidth);
    for (int elem : numbers) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}
