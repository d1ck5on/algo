#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

struct ArticulationPointFinder {
    std::vector<std::pair<int, int>> edges_;
    int vertex_cnt;
    int edges_cnt;
    std::vector<std::vector<int>> adjacent_vertices;
    std::vector<bool> is_visited;
    std::vector<int> parent;
    std::vector<int> tin;
    std::vector<int> up;
    std::vector<bool> is_articulation_point;

    ArticulationPointFinder(int vert_cnt, int edg_cnt, std::vector<std::pair<int, int>> edges)
            : edges_(std::move(edges)),
              vertex_cnt(vert_cnt),
              edges_cnt(edg_cnt),
              adjacent_vertices(vert_cnt + 1),
              is_visited(vert_cnt + 1),
              parent(vert_cnt + 1),
              tin(vert_cnt + 1),
              up(vert_cnt + 1),
              is_articulation_point(vert_cnt + 1) {
        for (const auto i: edges_) {
            adjacent_vertices[i.first].push_back(i.second);
            adjacent_vertices[i.second].push_back(i.first);
        }

        for (int i = 1; i <= vert_cnt; ++i) {
            up[i] = vertex_cnt + 1000;
        }
    }

    std::vector<int> find() {

        for (int i = 1; i <= vertex_cnt; ++i) {
            if (is_visited[i]) {
                continue;
            }

            dfs(i, 1, true);
        }
        std::vector<int> points;

        for (int i = 1; i <= vertex_cnt; ++i) {
            if (is_articulation_point[i]) {
                points.push_back(i);
            }
        }

        return  points;
    }

private:
    void dfs(int start, int time, bool is_root) {
        is_visited[start] = true;
        tin[start] = time++;

        int child_cnt = 0;
        int is_art_point = false;

        for (const auto vertex: adjacent_vertices[start]) {
            if (parent[start] == vertex) {
                continue;
            }

            if (is_visited[vertex]) {
                up[start] = std::min(up[start], tin[vertex]);
                continue;
            }

            ++child_cnt;
            parent[vertex] = start;
            dfs(vertex, time, false);
            up[start] = std::min(up[start], up[vertex]);

            if (tin[start] <= up[vertex]) {
                is_art_point = true;
            }
        }

        if (is_root && child_cnt >= 2 || !is_root && child_cnt >= 1 && is_art_point) {
            is_articulation_point[start] = true;
        }
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

    ArticulationPointFinder art_point_finder(n, m, edges);
    std::vector<int> points = art_point_finder.find();

    std::cout << points.size() << std::endl;
    for (const int i: points) {
        std::cout << i << std::endl;
    }
}