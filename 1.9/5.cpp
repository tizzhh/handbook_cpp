#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

int main(void) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::vector<std::vector<int>> result = Transpose(matrix);
    for (int i = 0; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            std::cout << result[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size(), columns = matrix[0].size();
    std::vector<std::vector<int>> result(columns, std::vector<int>(rows));
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}