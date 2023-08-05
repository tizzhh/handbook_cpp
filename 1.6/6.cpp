#include <iostream>
#include <vector>

int main(void) {
    int m, n, k;
    std::cin >> m >> n >> k;
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    int y, x;
    for (int i = 0; i < k; ++i) {
        std::cin >> y >> x;
        --y;
        --x;
        matrix[y][x] = -1;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int mines = 0;
            if (matrix[i][j] != -1) {
                for (int k = i - 1; k < i + 2; ++k) {
                    for (int l = j - 1; l < j + 2; ++l) {
                        if (k == i && l == j) continue;
                        if ((k >= 0 && k < m) && (l >= 0 && l < n) && matrix[k][l] == -1) {
                            ++mines;
                        }
                    }
                }
                matrix[i][j] = mines;
            }
            matrix[i][j] == -1 ? std::cout << '*' : std::cout << matrix[i][j];
            if (j != n - 1) std::cout << ' ';
        }
        std::cout << '\n';
    }
}