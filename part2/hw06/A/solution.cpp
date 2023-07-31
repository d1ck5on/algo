#include <vector>
#include <iostream>
#include <algorithm>

struct dsu {
    dsu(int size) : items_(size + 1), depth_(size + 1) {
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

        if (depth_[a] > depth_[b]) {
            std::swap(a, b);
        }
        items_[a] = b;

        if (depth_[a] == depth_[b]) {
            ++depth_[b];
        }
    }

    std::vector<int> items_;
    std::vector<int> depth_;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    std::sort(edges.begin(), edges.end(), [](std::vector<int> a, std::vector<int> b) {return a[2] < b[2];});

    dsu mst(n);

    int result = 0;

    for (auto edge : edges) {
        if (mst.find(edge[0]) != mst.find(edge[1])) {
            mst.union_sets(edge[0], edge[1]);
            result += edge[2];
        }
    }

    std::cout << result;

}