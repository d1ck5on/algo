#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

struct F {
    int vertex_cnt_;
    std::vector<std::vector<int>> edges_;
    std::vector<std::vector<int>> reversed_edges_;
    std::vector<int> amount_;
    long long time = 0;

    std::vector<int> result_details;

    std::unordered_set<int> one_tree;
    std::vector<int> top_sorted;
    std::vector<int> is_visited;

    F(int vert_cnt, std::vector<std::vector<int>> edges, std::vector<int> amount,
      std::vector<std::vector<int>> reversed_edges)
            : vertex_cnt_(vert_cnt),
              edges_(std::move(edges)),
              reversed_edges_(std::move(reversed_edges)),
              amount_(std::move(amount)),
              is_visited(vert_cnt + 1) {
    }

    void get_result() {
        top_sort();
        tree_find();

        for (const auto i: top_sorted) {
            if (one_tree.contains(i)) {
                result_details.push_back(i);
                time += amount_[i];
            }
        }
    }

private:
    void tree_find() {
        for (int i = 1; i <= vertex_cnt_; ++i) {
            is_visited[i] = false;
        }

        dfs2(1);
    }

    void top_sort() {
        for (int i = 1; i <= vertex_cnt_; ++i) {
            is_visited[i] = false;
        }

        for (int i = 1; i <= vertex_cnt_; ++i) {
            if (is_visited[i]) {
                continue;
            }

            dfs1(i);
        }

        std::reverse(top_sorted.begin(), top_sorted.end());
    }

    void dfs1(int start) {
        is_visited[start] = true;

        for (const auto i: edges_[start]) {
            if (is_visited[i]) {
                continue;
            }
            dfs1(i);
        }

        top_sorted.push_back(start);
    }

    void dfs2(int start) {
        is_visited[start] = true;

        for (const auto i: reversed_edges_[start]) {
            if (is_visited[i]) {
                continue;
            }

            dfs2(i);
        }

        one_tree.insert(start);
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> amount(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> amount[i];
    }

    std::vector<std::vector<int>> edges(n + 1);
    std::vector<std::vector<int>> reversed_edges(n + 1);
    for (int i = 1; i <= n; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int t;
            std::cin >> t;
            edges[t].push_back(i);
            reversed_edges[i].push_back(t);
        }
    }

    F f(n, edges, amount, reversed_edges);
    f.get_result();

    std::cout << f.time << ' ' << f.result_details.size() << std::endl;
    for (const auto i: f.result_details) {
        std::cout << i << ' ';
    }

}

