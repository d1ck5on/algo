#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct OneWayTraffic {
    std::vector<std::pair<int, int>> edges_;
    int vertex_cnt;
    int edges_cnt;
    std::vector<std::vector<int>> adjacent_vertices;

    std::vector<std::vector<int>> result_edges;
    std::vector<int> colors;
    std::vector<int> parent;
    std::vector<int> tin;
    std::vector<int> up;

    bool is_one_way = true;

    OneWayTraffic(int vert_cnt, int edg_cnt, std::vector<std::pair<int, int>> edges)
            : edges_(std::move(edges)),
              vertex_cnt(vert_cnt),
              edges_cnt(edg_cnt),
              adjacent_vertices(vert_cnt + 1),
              result_edges(vert_cnt + 1),
              colors(vert_cnt + 1),
              parent(vert_cnt + 1),
              tin(vert_cnt + 1),
              up(vert_cnt + 1) {
        for (const auto i: edges_) {
            adjacent_vertices[i.first].push_back(i.second);
            adjacent_vertices[i.second].push_back(i.first);
        }

        for (int i = 1; i <= vert_cnt; ++i) {
            up[i] = vert_cnt + 1000;
        }
    }

    void OneWaying() {
        for (int i = 1; i <= vertex_cnt; ++i) {
            if (colors[i] != 0) {
                continue;
            }

            dfs(1, 1);
        }
    }

private:
    void dfs(int start, int time) {
        if (!is_one_way) {
            return;
        }

        colors[start] = 1;
        tin[start] = time++;

        bool parent_edge_find = false;

        for (const auto i: adjacent_vertices[start]) {
            if (parent[start] == i && parent_edge_find) {
                result_edges[start].push_back(i);
                up[start] = std::min(up[start], tin[i]);
                continue;
            }

            if (parent[start] == i && !parent_edge_find) {
                parent_edge_find = true;
                continue;
            }

            if (colors[i] == 1) {
                result_edges[start].push_back(i);
                up[start] = std::min(up[start], tin[i]);
                continue;
            }

            if (colors[i] == 2) {
                continue;
            }

            parent[i] = start;
            dfs(i, time);
            up[start] = std::min(up[start], up[i]);
            if (up[i] <= tin[start]) {
                result_edges[start].push_back(i);
            } else {
                is_one_way = false;
            }
        }
        colors[start] = 2;

    }
};

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int f;
        int t;
        std::cin >> f >> t;
        edges.emplace_back(f, t);
    }
    OneWayTraffic one_way_traffic(n, m, edges);
    one_way_traffic.OneWaying();

    if (!one_way_traffic.is_one_way) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::unordered_map<int, int>> result_edges(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (const auto vertex: one_way_traffic.result_edges[i]) {
            ++result_edges[i][vertex];
        }
    }

    for (const auto i: edges) {
        if (result_edges[i.first].contains(i.second)) {
            std::cout << i.first << ' ' << i.second << std::endl;
            --result_edges[i.first][i.second];
            if (result_edges[i.first][i.second] == 0) {
                result_edges[i.first].erase(i.second);
            }
        } else {
            std::cout << i.second << ' ' << i.first << std::endl;
            --result_edges[i.second][i.first];
            if (result_edges[i.second][i.first] == 0) {
                result_edges[i.second].erase(i.first);
            }
        }
    }
}
