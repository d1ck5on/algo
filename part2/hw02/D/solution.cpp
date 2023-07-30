#include <iostream>
#include <vector>
#include <algorithm>

struct BridgeFinder {
    std::vector<std::pair<int, int>> edges_;
    int vertex_cnt;
    int edges_cnt;
    std::vector<std::vector<int>> adjacent_vertices;
    std::vector<std::vector<int>> reversed_edges;
    std::vector<int> top_sorted;
    std::vector<bool> is_visited;
    std::vector<int> colors;
    int comp_cnt = 0;

    BridgeFinder(int vert_cnt, int edg_cnt, std::vector<std::pair<int, int>> edges)
            : edges_(std::move(edges)),
              vertex_cnt(vert_cnt),
              edges_cnt(edg_cnt),
              adjacent_vertices(vert_cnt + 1),
              reversed_edges(vert_cnt + 1),
              is_visited(vert_cnt + 1),
              colors(vert_cnt + 1) {
        for (const auto i: edges_) {
            adjacent_vertices[i.first].push_back(i.second);
            reversed_edges[i.second].push_back(i.first);
        }
    }

    void top_sort() {
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
        comp_cnt = color - 1;
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
            if (is_visited[i]) {
                continue;
            }

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
    bridge_finder.top_sort();
    bridge_finder.coloring();

    std::cout << bridge_finder.comp_cnt << std::endl;
    for (int i = 1; i <= n; ++i) {
        std::cout << bridge_finder.colors[i] << ' ';
    }
}
