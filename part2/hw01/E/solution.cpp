#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &adjacent_vertices,
         std::vector<int> &colors,
         std::vector<bool> &is_possible,
         int start) {

    colors[start] = 1;
    is_possible[start] = true;

    for (const auto vertex: adjacent_vertices[start]) {
        if (colors[vertex] == 0) {
            dfs(adjacent_vertices, colors, is_possible, vertex);
        }
    }

    colors[start] = 2;

}

int main() {
    int n;
    int m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> adjacent_vertices(n + 1);
    for (size_t i = 0; i < m; ++i) {
        int f;
        int t;
        std::cin >> f >> t;
        adjacent_vertices[t].push_back(f);
    }

    std::vector<int> colors(n + 1);
    std::vector<bool> is_possible(n + 1);

    dfs(adjacent_vertices, colors, is_possible, 1);

    for (int i = 1; i < n + 1; ++i) {
        if (is_possible[i]) {
            std::cout << i << ' ';
        }
    }
}