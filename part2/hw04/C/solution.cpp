#include <iostream>
#include <vector>
#include <set>

#define int long long

int32_t main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<std::pair<int, int>>> adjacent_vertices(n + 1);
    for (int i = 0; i < k; ++i) {
        int s, f, l;
        std::cin >> s >> f >> l;
        adjacent_vertices[s].emplace_back(f, l);
        adjacent_vertices[f].emplace_back(s, l);
    }

    int s, f;
    std::cin >> s >> f;

    std::vector<int> distance(n + 1);
    for (int i = 1; i <= n; ++i) {
        distance[i] = 1000000 * n + 5;
    }
    distance[s] = 0;

    std::vector<int> is_visited(n + 1);

    std::set<std::pair<int, int>> queue;
    queue.insert({0, s});

    while (!queue.empty()) {
        int curr_vertex = queue.begin()->second;
        queue.erase(queue.begin());

        if (is_visited[curr_vertex]) {
            continue;
        }

        is_visited[curr_vertex] = true;
        for (auto [adj_vertex, length] : adjacent_vertices[curr_vertex]) {
            if (is_visited[adj_vertex]) {
                continue;
            }

            if (distance[curr_vertex] + length >= distance[adj_vertex]) {
                continue;
            }

            queue.erase({distance[adj_vertex], adj_vertex});
            queue.insert({distance[curr_vertex] + length, adj_vertex});

            distance[adj_vertex] = distance[curr_vertex] + length;
        }
    }

    if (distance[f] == 1000000 * n + 5) {
        std::cout << -1;
        return 0;
    }
    std::cout << distance[f];
}
