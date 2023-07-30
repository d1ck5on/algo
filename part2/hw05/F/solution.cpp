#include <iostream>
#include <vector>
#include <cmath>
#define int long long

int32_t main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> next(n + 1, std::vector<int>(n + 1));

    std::vector<std::vector<int>> adj_matrix(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            adj_matrix[i][j] = -(2ll << 60);
        }
    }

    for (int i = 0; i <= n; ++i) {
        adj_matrix[i][i] = 0;
    }

    std::vector<std::pair<int, int>> route(m + 1);
    for (int i = 1; i <= m; ++i) {
        int b, e, w;
        std::cin >> b >> e >> w;
        if (w > adj_matrix[b][e]) {
            adj_matrix[b][e] = w;
            next[b][e] = i;
            route[i] = {b, e};
        }
    }


    std::vector<int> concerts(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> concerts[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adj_matrix[i][j] == -(2ll << 60)) {
                continue;
            }

            for (int k = 1; k <= n; ++k) {
                if (adj_matrix[k][i] == -(2ll << 60)) {
                    continue;
                }

                if (adj_matrix[k][j] >= adj_matrix[k][i] + adj_matrix[i][j]) {
                    continue;
                }

                adj_matrix[k][j] = adj_matrix[k][i] + adj_matrix[i][j];
                next[k][j] = next[k][i];
            }
        }
    }


    std::vector<int> inf_cycles;
    for (int i = 1; i <= n; ++i) {
        if (adj_matrix[i][i] > 0) {
            inf_cycles.push_back(i);
        }
    }

    std::vector<int> result;
    int curr_city = concerts[0];
    for (int i = 1; i < k; ++i) {
        int next_city = concerts[i];

        for (int cycle : inf_cycles) {
            if (adj_matrix[curr_city][cycle] != -(2ll << 60) && adj_matrix[cycle][next_city] != -(2ll << 60)) {
                std::cout << "infinitely kind";
                return 0;
            }
        }

        while (curr_city != next_city) {
            int race = next[curr_city][next_city];
            curr_city = route[race].second;
            result.push_back(race);
        }
    }

    std::cout << result.size() << std::endl;
    for (auto i : result) {
        std::cout << i << ' ';
    }
}
