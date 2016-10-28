#include <iostream>


int main() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            std::cout << static_cast <unsigned char>(i * 16 + j) << ' ';
        }
        std::cout << '\n';
    }
}
