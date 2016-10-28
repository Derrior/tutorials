#include <cstring>
#include <iostream>
template <typename T> 

class ZeroInit {
public:
    ZeroInit() {
        memset(this, -1, sizeof(T));
    }
};


class Point : public ZeroInit<Point> {
public:
    int x, y;
    Point() {
    }
    
};

int main() {
    Point a;
    std::cout << a.x << std::endl;
}
