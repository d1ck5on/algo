#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define int long long

int32_t main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    int s;
    std::cin >> s;

    std::vector<int> cities(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> cities[i];
    }

    std::vector<std::vector<std::pair<int, int>>> adjacent_vertices(n + 1);
    for (int i = 0; i < m; ++i) {
        int s, f, l;
        std::cin >> s >> f >> l;
        adjacent_vertices[s].emplace_back(f, l);
        adjacent_vertices[f].emplace_back(s, l);
    }

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

    std::vector<std::pair<int, int>> result;
    for (int city : cities) {
        result.emplace_back(distance[city], city);
    }

    std::sort(result.begin(), result.end());

    for (auto & it : result) {
        std::cout << it.second << ' ' << it.first << std::endl;
    }
}

