#include <iostream>
#include <vector>
#include <type_traits>

template<bool Condition, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if(true, T) {
    typedef type T;
}

template <typename T>
class Array {
  public:
    Array(size_t n, const T& val): data_(n, val) {
    }

    template <
             typename Iterator,
             typename = typename std::enable_if<!std::is_integral<Iterator>::value>::type
             >
    Array(Iterator first, Iterator last) {
        
    }
};
