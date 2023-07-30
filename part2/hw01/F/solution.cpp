#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &adjacent_vertices,
         std::vector<int> &dp,
         std::vector<bool> &is_visited,
         int start) {

    int result = 1;
    is_visited[start] = true;

    for (const auto vertex: adjacent_vertices[start]) {
        if (is_visited[vertex]) {
            continue;
        }

        dfs(adjacent_vertices, dp, is_visited, vertex);
        result += dp[vertex];
    }

    dp[start] = result;
}

int main() {

    int n;

    std::cin >> n;

    std::vector<std::vector<int>> adjacent_vertices(n + 1);
    for (size_t i = 0; i < n - 1; ++i) {
        int f;
        int t;
        std::cin >> f >> t;
        adjacent_vertices[t].push_back(f);
        adjacent_vertices[f].push_back(t);
    }

    std::vector<int> dp(n + 1);
    std::vector<bool> is_visited(n + 1);

    for (int i = 1; i < n + 1; ++i) {
        if (is_visited[i]) {
            continue;
        }

        dfs(adjacent_vertices, dp, is_visited, i);
    }

    for (int i = 1; i < n + 1; ++i) {
        std::cout << dp[i] << ' ';
    }

}
