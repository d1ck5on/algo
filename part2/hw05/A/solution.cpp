#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj_matrix(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> adj_matrix[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adj_matrix[i][j] == 0) {
                continue;
            }

            for (int k = 1; k <= n; ++k) {
                if (adj_matrix[k][i] == 0) {
                    continue;
                }

                adj_matrix[k][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << adj_matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}