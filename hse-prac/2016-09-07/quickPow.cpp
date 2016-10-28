#include <iostream>


const int BYTES_AMOUNT = 32;

int main() {
    long long number, power;
    std::cin >> number >> power;
    long long degree = 1;
    for (int i = BYTES_AMOUNT; i >= 0; i--) {
        bool bitValue = power & (1ll << i);
        if (bitValue) {
            degree *= degree * number;
        } else {
            degree *= degree;
        }
    }
    std::cout << degree << '\n';
}
