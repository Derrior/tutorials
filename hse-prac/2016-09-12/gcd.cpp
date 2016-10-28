#include <iostream>

int GCD(int a, int b) {
    while (b != 0) {
        std::swap(a, b);
        b = b % a;
    }
    return a;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << GCD(a, b) << '\n';
}
