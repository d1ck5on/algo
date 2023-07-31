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

    std::vector<std::pair<int, int>> vertices(n * m + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vertices[i*m + j + 1] = {i + 1, j + 1};
        }
    }

    std::vector<std::pair<double, std::pair<int, int>>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n) {
                std::pair<int, int> from_to = {i*m + j + 1, (i + 1)*m + j + 1};
                std::pair<int, std::pair<int, int>> edge = {1, from_to};
                edges.push_back(edge);
            }

            if (j + 1 < m) {
                std::pair<int, int> from_to = {i*m + j + 1, i*m + j + 1 + 1};
                std::pair<int, std::pair<int, int>> edge = {2, from_to};
                edges.push_back(edge);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            std::cin >> a;

            if ((a == 1 || a == 3) && i + 1 < n) {
                std::pair<int, int> from_to = {i*m + j + 1, (i + 1)*m + j + 1};
                edges.push_back({0, from_to});
            }

            if ((a == 2 || a == 3) && j + 1 < m) {
                std::pair<int, int> from_to = {i*m + j + 1, i*m + j + 1 + 1};
                edges.push_back({0, from_to});
            }
        }
    }

    std::sort(edges.begin(), edges.end());

    int result = 0;
    std::vector<std::pair<int, int>> res_edges;

    dsu items(n * m);

    for (auto edge : edges) {
        int w = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;

        if (items.find(from) == items.find(to)) {
            continue;
        }

        items.union_sets(from, to);
        result += w;

        if (w != 0) {
            res_edges.emplace_back(from, w);
        }
    }

    std::cout << res_edges.size() << ' ' << result << std::endl;
    for (auto i : res_edges) {
        std::cout << vertices[i.first].first << ' ' << vertices[i.first].second << ' ' << i.second << std::endl;
    }
}