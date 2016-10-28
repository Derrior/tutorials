#include "polygon.h"
#include <iostream>
using namespace std;

void check_output() {
    {
    Polynomial<int> x;
    cout << "1: " << x << " <-> " << 0 << "\n";
    }
    {
    Polynomial<int> x{-1};
    cout << "2: " << x <<  " <-> " << -1 << "\n";
    }
    {
    Polynomial<int> x{-2};
    cout << "3: " << x <<  " <-> " << -2 << "\n";
    }
    {
    Polynomial<int> x{{-2, -2, -2}};
    cout << "4: " << x <<  " <-> " << "-2*x^2-2*x-2" << "\n";
    }
    {
    Polynomial<int> x{{-1, -1, -1}};
    cout << "5: " << x << " <-> " << "-x^2-x-1" <<  "\n";
    }
    {
    Polynomial<int> x{{0, 0, -1}};
    cout << "6: " << x << " <-> " << "-x^2" << "\n";
    }
    {
    Polynomial<int> x{{-1, 0, 0}};
    cout << "7: " << x <<  " <-> " << -1 << "\n";
    }
    {
    Polynomial<int> x{{-1, 0, -1}};
    cout << "8: " << x << " <-> " << "-x^2-1" << "\n";
    }
    {
    Polynomial<int> x{{0, -1, 0}};
    cout << "9: " << x << " <-> " << "-x" << "\n";
    }
    {
    Polynomial<int> x{{0, 0, 0}};
    cout << "10: " << x << " <-> " << "0" <<"\n";
    }
    {
    Polynomial<int> x;
    cout << "11: " << x <<  " <-> " << "0" <<"\n";
    }
    {
    Polynomial<int> x{1};
    cout << "12: " << x <<  " <-> " << "1" <<"\n";
    }
    {
    Polynomial<int> x{2};
    cout << "13: " << x << "  <-> " << "2" <<"\n";
    }
    {
    Polynomial<int> x{{2, 2, 2}};
    cout << "14: " << x <<  " <-> " << "2*x^2+2*x+2" <<"\n";
    }
    {
    Polynomial<int> x{{1, 1, 1}};
    cout << "15: " << x <<  " <-> " << "x^2+x+1" <<"\n";
    }
    {
    Polynomial<int> x{{0, 0, 1}};
    cout << "16: " << x <<  " <-> " << "x^2" <<"\n";
    }
    {
    Polynomial<int> x{{1, 0, 0}};
    cout << "17: " << x <<  " <-> " << "1" <<"\n";
    }
    {
    Polynomial<int> x{{1, 0, 1}};
    cout << "18: " << x <<  " <-> " << "x^2+1" <<"\n";
    }
    {
    Polynomial<int> x{{0, 1, 0}};
    cout << "19: " << x <<  " <-> " << "x" <<"\n";
    }
    {
    Polynomial<int> x{{0, 0, 0}};
    cout << "20: " << x <<  " <-> " << "0" <<"\n";
    }

}

void check_arithm() {
    Polynomial<int> a(std::vector<int>{1, 2, 3}); //3 x^2 + 2x + 1
    cout << a <<  " <-> " << "3*x^2+2*x+1" <<endl;
    a *= 2;
    cout << a <<  " <-> " << "6*x^2+4*x+2" <<endl;
    a -= 2;
    cout << a << " <-> " << "6*x^2+4*x" << endl;
    a += 2;
    cout << "a: " << a <<  " <-> " << "a: 6*x^2+4*x+2" <<endl;

    Polynomial<int> b = 2;
    cout << "b: " << b <<  " <-> " << "b: 2" <<endl;

    b *= a;
    cout << "b*a: " << b <<  " <-> " << "b*a: 12*x^2+8*x+4" <<endl;

    b -= a;
    cout << b <<  " <-> " << "6*x^2+4*x+2" <<endl;

    b += a;
    cout << b <<  " <-> " << "12*x^2+8*x+4" <<endl;

    b += Polynomial<int>(1);
    cout << b <<  " <-> " << "12*x^2+8*x+5" <<endl;

    b -= Polynomial<int>(1);
    cout << b <<  " <-> " << "12*x^2+8*x+4" <<endl;

    b *= Polynomial<int>(1);
    cout << b <<  " <-> " << "12*x^2+8*x+4" <<endl;

    cout << (b == a) << ' ' << (b != a) << ' ' << (b != 1) << ' ' << (b == 1) << ' ' << (1 == b) << ' ' << (1 != b) <<  " <-> " << "0 1 1 0 0 1" <<endl;

    cout << Polynomial<int>({1, 2, 3}).Degree() <<  " <-> " << "2" <<endl;

    Polynomial<double> c({5, 1, 0}), d({5, 1, 0, 0});
    cout << c * d <<  " <-> " << "x^2+10*x+25" <<endl;
    (((a *= 1) += 1) -= 1) *= 1;
    cout << "---------\n";
    cout << c % d <<  " <-> " << "0" <<endl;

    cout << "---------\n";
    cout << c / d <<  " <-> " << "1" <<endl;

    cout << "---------\n";
    cout << (c , d) <<  " <-> " << "x+5" <<endl;

}


int main() {
    check_output();
    check_arithm();
}
