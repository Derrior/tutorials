#include <iostream>

int main() {
    double sum = 0.0;
    for (double i = 1; i < 100; ++i) {
        sum += 1.0 / static_cast <double> (i);
        std::cout << i << ": " << sum << std::endl;
    }
}
