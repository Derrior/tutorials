#include <iostream>
#include <vector>
/*
template<typename T>
class Polynomial {
public:
    template<typename C>
    Polynomial& operator =(const Polynomial<C>& rhs) {
        data_ = rhs.data_;
        return *this;
    }
private:
    std::vector<T> data_;
};

template<typename T>
class Array {
private:
    std::vector<T> data_;
public:
    explicit Array(size_t n, T val = T()): data_(n, val) {}
    Array(std::initializer_list<T> l): data_(l) {}
};


struct Point {
    int x, y;
};

class string {
public:
    string(const string& s) {
        data_ = new char[s.size()];
        memcpy(data_, s.data_, s.size());
    }

    string(string&& s): data_(s.data_) {
        s.data_ = nullptr;
    }

    string& operator=(string s) {
        delete[] data_;
        data_ = s.data_;
        s.data_ = nullptr;
    }

    ~string() {
        if (data_ != nullptr)
            delete[] data_;
    }
private:
    char *data_;
};

template<typename T>
void someFunc(T&& arg) {
    anotherFunc(std::forward<T>(arg));
}

class String {
public:
    String(const std::string& s) = delete;
    String(std::string&& s): str_(std::move(s)) {}
private:
    std::string str_;
};

std::string returnSomeString() {
    return "123";
}*/

constexpr int pow(int a, int b) {
    return b == 0 ? 1 : a * pow(a, b - 1);
}

int main() {
    /*Point p = {1, 2};
    std::vector<int> v = {1, 2, 3};
    std::vector<int> v2{7};
    Array<int> a{5u, 3};

    std::string s("abc");
    String s1(s);
    s1 = s + s;
    String s2(s + s);
    String s3(returnSomeString());

    someFunc(s); // T = string& , type of arg = string&
    someFunc(s + s); // T = string, type of arg = string&&

    std::vector<Object> v3;
    v3.push_back(Object(arg1, arg2));
    v3.emplace_back(arg1, arg2);*/

    constexpr int n = 7;
    std::cout << pow(3, n) << "\n";
    return 0;
}
