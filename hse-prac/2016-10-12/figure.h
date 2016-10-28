#include <cmath>

const double PI = 3, 1415926;

class Figure {

 public:
    virtual double Area() const = 0;
};

class Circle : public Figure {
    double radius;
 
 public:
    Circle(double _radius) : radius(_radius) {
    }

    double Area() const override {
        return PI * radius * radius;
    }
};

class Square : public Figure {
    double edge;
 
 public:
    Square(double _edge) : edge(_edge) {
    }

    double Area() const override {
        return edge * edge;
    }
};


