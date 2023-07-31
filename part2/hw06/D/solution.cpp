#include <vector>
#include <iostream>
#include <algorithm>

struct dsu {
    dsu(int size) : items_(size + 1), depth_(size + 1), size_(size) {
        for (int i = 1; i <= size; ++i) {
            items_[i] = i;
            depth_[i] = 1;
        }
    } 

    int find(int x) {
        int result = x;
        while (result != items_[result]) {
            result = items_[result];
        }

        items_[x] = result;
        return result;
    }

    void union_sets(int x, int y) {
        int a = find(x);
        items_[x] = a;
        int b = find(y);
        items_[y] = b;
        
        if (a == b) {
            return;
        }

        if (depth_[a] > depth_[b]) {
            std::swap(a, b);
        }
        items_[a] = b;

        if (depth_[a] == depth_[b]) {
            ++depth_[b];
        }

        size_ -= 1;
    }

    std::vector<int> items_;
    std::vector<int> depth_;
    int size_ = 0;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj_vert(n + 1);
    std::vector<std::pair<int, std::pair<int, int>>> edges;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w;
        adj_vert[a].push_back({b, w});
        adj_vert[b].push_back({a, w});
        
        std::pair<int, int> from_to = {a, b};
        edges.push_back({w, from_to});
    }

    int result1 = 0;
    std::vector<std::pair<int, std::pair<int, int>>> res_edges;

    std::sort(edges.begin(), edges.end());

    dsu mst(n);

    for (auto edge : edges) {
        int w = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;
        if (mst.find(from) == mst.find(to)) {
            continue;
        }

        mst.union_sets(from, to);
        std::pair<int, int> from_to = {from, to};
        res_edges.push_back({w, from_to});
        result1 += w;
    }

    int best_result2 = -1;

    for (auto del_edge : res_edges) {
        dsu mst(n);
        int result2 = 0;
        for (auto edge : edges) {
            if (edge == del_edge) {
                continue;
            }

            int w = edge.first;
            int from = edge.second.first;
            int to = edge.second.second;
            if (mst.find(from) == mst.find(to)) {
                continue;
            }

            mst.union_sets(from, to);
            result2 += w;
        }

        if (mst.size_ == 1 && (result2 < best_result2 || best_result2 == -1)) {
            best_result2 = result2;
        }
    }

    std::cout << result1 << ' ' << best_result2;
}