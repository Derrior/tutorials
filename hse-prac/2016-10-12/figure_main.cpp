#include "figure.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<Figure*> figures;

    std::string type;
    double val;

    while (std::cin >> type >> val) {
        if (type == "Circle")
            figures.push_back(new Circle(val));
        else if (type == "Square")
            figures.push_back(new Square(val));
    }

    for (Figure * f : figures)
        std::cout << f->Area() << "\n";

    for (Figure * f : figures)
         delete f;
}
