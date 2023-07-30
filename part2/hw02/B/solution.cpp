#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

struct BridgeFinder {
    std::vector<std::pair<int, int>> edges_;
    int vertex_cnt;
    int edges_cnt;
    std::vector<std::vector<int>> adjacent_vertices;
    std::vector<std::vector<int>> reversed_edges;
    std::vector<int> top_sorted;
    std::vector<bool> is_visited;
    std::vector<int> colors;
    std::vector<int> parent;

    BridgeFinder(int vert_cnt, int edg_cnt, std::vector<std::pair<int, int>> edges)
            : edges_(std::move(edges)),
              vertex_cnt(vert_cnt),
              edges_cnt(edg_cnt),
              adjacent_vertices(vert_cnt + 1),
              reversed_edges(vert_cnt + 1),
              is_visited(vert_cnt + 1),
              parent(vert_cnt + 1),
              colors(vert_cnt + 1) {
        for (const auto i: edges_) {
            adjacent_vertices[i.first].push_back(i.second);
            adjacent_vertices[i.second].push_back(i.first);
        }
    }

    std::vector<int> find_bridges() {
        reverse_edges();
        coloring();
        std::vector<int> bridges;
        for (int i = 0; i < edges_cnt; ++i) {
            if (colors[edges_[i].first] != colors[edges_[i].second]) {
                bridges.push_back(i + 1);
            }
        }
        return bridges;
    }

    void reverse_edges() {
        reset_visited();
        for (int i = 1; i <= vertex_cnt; ++i) {
            if (is_visited[i]) {
                continue;
            }
            dfs1(i);
        }
        std::reverse(top_sorted.begin(), top_sorted.end());
    }

    void coloring() {
        reset_visited();
        int color = 1;
        for (const auto i: top_sorted) {
            if (is_visited[i]) {
                continue;
            }
            dfs2(i, color);
            ++color;
        }
    }

private:
    void dfs2(int start, int color) {
        is_visited[start] = true;
        colors[start] = color;

        for (const auto i: reversed_edges[start]) {
            if (is_visited[i]) {
                continue;
            }

            dfs2(i, color);
        }
    }

    void reset_visited() {
        for (int i = 0; i <= vertex_cnt; ++i) {
            is_visited[i] = false;
        }
    }

    void dfs1(int start) {
        is_visited[start] = true;

        for (const auto i: adjacent_vertices[start]) {
            if (i == parent[start]) {
                continue;
            }

            if (is_visited[i]) {
                reversed_edges[i].push_back(start);
                reversed_edges[start].push_back(i);
                continue;
            }

            parent[i] = start;
            reversed_edges[i].push_back(start);
            dfs1(i);
        }

        top_sorted.push_back(start);
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
    BridgeFinder bridge_finder(n, m, edges);
    std::vector<int> bridges = bridge_finder.find_bridges();

    std::cout << bridges.size() << std::endl;
    for (const int i: bridges) {
        std::cout << i << ' ';
    }
}