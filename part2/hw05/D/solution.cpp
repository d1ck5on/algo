#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    int s, e;
    std::cin >> s >> e;

    std::vector<std::vector<double>> adj_matrix(n + 1, std::vector<double>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            adj_matrix[i][j] = 200;
        }
    }

    for (int i = 0; i < m; ++i) {
        int s, e, p;
        std::cin >> s >> e >> p;
        adj_matrix[s][e] = p;
        adj_matrix[e][s] = p;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (adj_matrix[k][i] == 200 || adj_matrix[i][j] == 200) {
                    continue;
                }

                double new_prob = 100 - ((100 - adj_matrix[k][i]) * (100 - adj_matrix[i][j]) / 100);

                if (adj_matrix[k][j] < new_prob) {
                    continue;
                }

                adj_matrix[k][j] = new_prob;
                adj_matrix[j][k] = new_prob;
            }
        }
    }

    std::cout << adj_matrix[s][e] / 100;

}
