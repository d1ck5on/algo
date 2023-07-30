#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &adjacent_vertices,
         std::vector<int> &colors,
         int start,
         int color,
         bool &is_possible) {
    if (!is_possible) {
        return;
    }
    colors[start] = color;
    for (const auto vertex: adjacent_vertices[start]) {
        if (colors[vertex] == color) {
            is_possible = false;
        }

        if (colors[vertex] == 0) {
            dfs(adjacent_vertices, colors, vertex, 3 - color, is_possible);
        }
    }
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
        adjacent_vertices[f].push_back(t);
        adjacent_vertices[t].push_back(f);
    }

    std::vector<int> colors(n + 1);
    bool is_possible = true;

    for (int vertex = 1; vertex <= n; ++vertex) {
        if (colors[vertex] != 0) {
            continue;
        }

        dfs(adjacent_vertices, colors, vertex, 1, is_possible);
    }

    if (is_possible) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}