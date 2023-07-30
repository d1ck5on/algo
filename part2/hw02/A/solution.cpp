#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &adjacent_vertices,
         std::vector<int> &color,
         std::vector<int> &top_sorted,
         int start,
         bool &is_sorted) {
    if (!is_sorted) {
        return;
    }

    color[start] = 1;

    for (const auto vertex: adjacent_vertices[start]) {
        if (color[vertex] == 2) {
            continue;
        } else if (color[vertex] == 1) {
            is_sorted = false;
            return;
        }

        dfs(adjacent_vertices, color, top_sorted, vertex, is_sorted);
    }

    color[start] = 2;
    top_sorted.push_back(start);
}

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adjacent_vertices(n + 1);
    for (int i = 0; i < m; ++i) {
        int f;
        int t;
        std::cin >> f >> t;
        adjacent_vertices[f].push_back(t);
    }
    std::vector<int> color(n + 1);
    std::vector<int> top_sorted;
    bool is_sorted = true;

    for (int i = 1; i <= n; ++i) {
        if (color[i] != 0) {
            continue;
        }
        dfs(adjacent_vertices, color, top_sorted, i, is_sorted);
    }

    if (is_sorted) {
        std::reverse(top_sorted.begin(), top_sorted.end());
        for (auto i : top_sorted) {
            std::cout << i << ' ';
        }
    } else {
        std::cout << -1;
    }
}
