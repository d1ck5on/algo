#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adjacent_vertices(n + 1);
    for (int i = 1; i <= n; ++i) {
        int is_edge;
        for (int j = 1; j <= n; ++j) {
            std::cin >> is_edge;
            if (is_edge) {
                adjacent_vertices[i].push_back(j);
                adjacent_vertices[j].push_back(i);
            }
        }
    }

    int start;
    int end;
    std::cin >> start >> end;

    std::vector<int> min_distance(n + 1);
    for (int i = 1; i <= n; ++i) {
        min_distance[i] = n + 100;
    }

    min_distance[start] = 0;

    std::vector<std::vector<int>> vertices_distance(n + 1);
    vertices_distance[0].push_back(start);
    for (int distance = 0; distance <= n; ++distance) {
        if (vertices_distance[distance].empty()) {
            break;
        }

        for (int vertex = 0; vertex < vertices_distance[distance].size(); ++vertex) {
            int curr_vertex = vertices_distance[distance][vertex];

            for (int adjacent_vertex : adjacent_vertices[curr_vertex]) {
                if (min_distance[adjacent_vertex] != n + 100) {
                    continue;
                }

                min_distance[adjacent_vertex] = min_distance[curr_vertex] + 1;
                vertices_distance[min_distance[adjacent_vertex]].push_back(adjacent_vertex);
            }
        }
    }

    if (min_distance[end] == n + 100) {
        std::cout << -1;
        return 0;
    }

    if (min_distance[end] == 0) {
        std::cout << 0;
        return 0;
    }

    std::cout << min_distance[end] << std::endl;

    std::vector<int> result;
    int curr = end;
    while (curr != start) {
        result.push_back(curr);

        for (int adjacent_vertex : adjacent_vertices[curr]) {
            if (min_distance[adjacent_vertex] == min_distance[curr] - 1) {
                curr = adjacent_vertex;
                break;
            }
        }
    }

    result.push_back(start);
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        std::cout << *it << ' ';
    }
}
