#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &adjacent_vertices,
         std::vector<bool> &is_visited,
         int start,
         int &vertices_count,
         std::vector<int> &vertices) {
    is_visited[start] = true;
    ++vertices_count;
    vertices.push_back(start);

    for (const auto &vertex : adjacent_vertices[start]) {
        if (!is_visited[vertex]) {
            dfs(adjacent_vertices, is_visited, vertex, vertices_count, vertices);
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

    std::vector<bool> is_visited(n + 1);

    int vertices_count = 0;

    std::vector<int> vertices;

    dfs(adjacent_vertices, is_visited, 1, vertices_count, vertices);

    std::sort(vertices.begin(), vertices.end());

    std::cout << vertices_count << std::endl;
    for (const auto vertex : vertices) {
        std::cout << vertex << ' ';
    }

    return 0;
}