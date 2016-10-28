#include "array.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Array<int> a(5), b(3, 4);
    Array<int> c({});
    a.out();
    cout << '\n';
    b.out();
    cout << '\n';
    (a + b).out();
    c.out();

}
