#include <iostream>
#include <vector>


int main() {
    int matrixSize;
    std::cin >> matrixSize;
    std::vector<std::vector<int>> matrix(matrixSize, std::vector<int>(matrixSize));
    for (auto& matrixLine : matrix) {
        for (auto& element : matrixLine) {
            std::cin >> element;
        }
    }
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            for (int k = 0; k < matrixSize; ++k) {
                if (matrix[matrix[i][j]][k] != matrix[i][matrix[j][k]]) {
                    std::cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    std::cout << "YES\n";
    return 0;
}
