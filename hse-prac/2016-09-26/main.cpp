#include "myalgorithm.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> A(10);
    std::vector<int> part1 = {1, 3, 5, 7, 9};
    std::vector<int> part2 = {2, 4, 6};
    A.resize(distance(A.begin(), merge(part1.begin(), part1.end(), 
                                      part2.begin(), part2.end(),
                                      A.begin())));

    for (int elem : A) {
        std::cout << elem << ' ';
    }
    std::cout << '\n' << *lowerbound(A.begin(), A.end(), 
                                    [](const int &x) {
                                        return x > 4;
            
    });
}
