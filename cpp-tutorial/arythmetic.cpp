#include <iostream>

using namespace std;

int main() {
    int a = 4, b = 5;
    cout << a << ' ' << b << endl;
    int sum = a + b;  // 9
    int sub = a - b;  // -1
    int mul = a * b;  // 20
    int div = a / b;  // 0
    int rem = a % b;  // 4
    
    float c = a;
    float true_div = c / b;  // 0.8
}
