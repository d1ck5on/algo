#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, s, f;
    std::cin >> n >> s >> f;

    std::vector<std::vector<int>> adjacency_matrix(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> adjacency_matrix[i][j];
        }
    }

    std::vector<int> distance(n + 1);
    for (int i = 1; i <= n; ++i) {
        distance[i] = 100 * n + 5;
    }
    distance[s] = 0;

    std::vector<int> is_visited(n + 1);

    std::set<std::pair<int, int>> queue;
    queue.insert({0, s});

    std::vector<int> from(n + 1);


    while (!queue.empty()) {
        int curr_vertex = queue.begin()->second;
        queue.erase(queue.begin());

        if (is_visited[curr_vertex]) {
            continue;
        }

        is_visited[curr_vertex] = true;
        for (int adj_vertex = 1; adj_vertex <= n; ++adj_vertex) {
            if (is_visited[adj_vertex]) {
                continue;
            }

            int length = adjacency_matrix[curr_vertex][adj_vertex];
            if (length == -1) {
                continue;
            }

            if (distance[curr_vertex] + length >= distance[adj_vertex]) {
                continue;
            }

            queue.erase({distance[adj_vertex], adj_vertex});
            queue.insert({distance[curr_vertex] + length, adj_vertex});

            from[adj_vertex] = curr_vertex;
            distance[adj_vertex] = distance[curr_vertex] + length;
        }
    }

    if (distance[f] == 100 * n + 5) {
        std::cout << -1;
        return 0;
    }

    int vertex = f;
    std::vector<int> result;
    while (vertex != s) {
        result.push_back(vertex);
        vertex = from[vertex];
    }
    result.push_back(s);

    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        std::cout << *it << ' ';
    }
}

