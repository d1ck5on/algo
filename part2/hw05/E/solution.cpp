#include <iostream>
#include <vector>

#define int long long

int32_t main() {
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
            for (int k = 1; k <= n; ++k) {
                if (adj_matrix[k][j] < adj_matrix[k][i] + adj_matrix[i][j]) {
                    continue;
                }

                adj_matrix[k][j] = adj_matrix[k][i] + adj_matrix[i][j];
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            result = std::max(adj_matrix[i][j], result);
        }
    }

    std::cout << result;
}
