#include <iostream>
#include <vector>

void bfs(int start, std::vector<std::vector<int>> &adjacent_vertices, std::vector<int> &min_distance) {
    std::vector<std::vector<int>> distance(adjacent_vertices.size());
    distance[0].push_back(start);

    for (int i = 0; i < distance.size(); ++i) {
        if (distance[i].empty()) {
            return;
        }

        for (int j = 0; j < distance[i].size(); ++j) {
            for (int vertex: adjacent_vertices[distance[i][j]]) {
                if (min_distance[vertex] != adjacent_vertices.size()) {
                    continue;
                }

                min_distance[vertex] = min_distance[distance[i][j]] + 1;
                distance[min_distance[vertex]].push_back(vertex);
            }
        }
    }
}

int main() {
    int n;
    int m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> edges;
    std::vector<std::vector<int>> adjacent_vertices(n + 1);
    for (int i = 0; i < m; ++i) {
        int s, f;
        std::cin >> s >> f;
        adjacent_vertices[s].push_back(f);
        adjacent_vertices[f].push_back(s);
        edges.emplace_back(f, s);
    }

    int s, t;
    std::cin >> s >> t;

    std::vector<int> s_min_distance(n + 1);
    std::vector<int> t_min_distance(n + 1);

    for (int i = 0; i < n + 1; ++i) {
        s_min_distance[i] = n + 1;
        t_min_distance[i] = n + 1;
    }

    s_min_distance[s] = 0;
    t_min_distance[t] = 0;

    bfs(s, adjacent_vertices, s_min_distance);
    bfs(t, adjacent_vertices, t_min_distance);

    int result = 0;
    for (auto edge: edges) {
        if (s_min_distance[edge.first] + 1 + t_min_distance[edge.second] != s_min_distance[t] &&
            s_min_distance[edge.second] + 1 + t_min_distance[edge.first] != s_min_distance[t]) {
            ++result;
        }
    }

    std::cout << result;
}