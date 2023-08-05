#include <iostream>
#include <utility>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    std::pair<size_t, size_t> p = MatrixArgMax(matrix);
    std::cout << p.first << ' ' << p.second << '\n';
}

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    std::pair<size_t, size_t> p = {0, 0};
    size_t rows = matrix.size(), columns = matrix[0].size();
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            if (matrix[i][j] > matrix[p.first][p.second]) {
                p = {i, j};
            }
        }
    }
    
    return p;
}