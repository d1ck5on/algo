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

    int component_count = 0;
    std::vector<std::vector<int>> components;

    for (int vertex = 1; vertex <= n; ++vertex) {
        if (is_visited[vertex]) {
            continue;
        }

        ++component_count;
        int vertices_count = 0;
        components.emplace_back();
        dfs(adjacent_vertices, is_visited, vertex, vertices_count, components[component_count - 1]);

    }

    std::cout << component_count << std::endl;
    for (const auto &component : components) {
        std::cout << component.size() << std::endl;
        for (const auto vertex : component) {
            std::cout << vertex << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}