#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &adjacent_vertices,
         std::vector<int> &colors,
         std::vector<int> &prev,
         int start,
         int &start_cycle,
         int &end_cycle) {

    if (start_cycle != -1) {
        return;
    }

    colors[start] = 1;
    for (const auto vertex: adjacent_vertices[start]) {
        if (colors[vertex] == 1 && vertex != prev[start]) {
            start_cycle = vertex;
            end_cycle = start;
            break;
        }

        if (colors[vertex] == 0) {
            prev[vertex] = start;
            dfs(adjacent_vertices, colors, prev, vertex, start_cycle, end_cycle);
        }
    }

    colors[start] = 2;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<std::vector<int>> adjacent_vertices(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int in;
            std::cin >> in;
            if (in == 1) {
                adjacent_vertices[i].push_back(j);
            }
        }
    }

    std::vector<int> colors(n + 1);
    int start_cycle = -1;
    int end_cycle = -1;
    std::vector<int> prev(n + 1);

    for (int vertex = 1; vertex <= n; ++vertex) {
        if (start_cycle != -1) {
            break;
        }

        if (colors[vertex] != 0) {
            continue;
        }

        dfs(adjacent_vertices, colors, prev, vertex, start_cycle, end_cycle);
    }

    if (start_cycle != -1) {
        std::cout << "YES" << std::endl;

        std::vector<int> cycle;
        cycle.push_back(start_cycle);
        int it_vertex = end_cycle;
        while (it_vertex != start_cycle) {
            cycle.push_back(it_vertex);
            it_vertex = prev[it_vertex];
        }

        std::cout << cycle.size() << std::endl;
        for (const auto vertex: cycle) {
            std::cout << vertex << ' ';
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}