#include <iostream>
#include <vector>

void transpose(std::vector<std::vector<int> > & matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < i; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void inputMatrix(std::vector<std::vector<int> > &matrix) {
    for (auto &v : matrix) {
        for (auto &element : v) {
            std::cin >> element;
        }
    }
}

void outputMatrix(std::vector<std::vector<int> > &matrix) {
    for (auto &v : matrix) {
        for (auto &element : v) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int matrixSize = 0;
    std::cin >> matrixSize;
    std::vector<std::vector<int> > matrix(matrixSize, std::vector<int>(matrixSize, 0));
    inputMatrix(matrix);
    transpose(matrix);
    outputMatrix(matrix);
}
