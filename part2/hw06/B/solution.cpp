#include <iostream>
#include <vector>
#include <cmath>
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

double distance(std::pair<double, double> a, std::pair<double, double> b) {
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<double, double>> points (n + 1);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        points[i] = {x, y};
    }

    dsu mst(n);

    std::vector<std::pair<double, std::pair<int, int>>> edges;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }

            std::pair<int, int> pts = {i, j};

            edges.push_back({distance(points[i], points[j]), pts});
        }
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::pair<int, int> pts = {a, b};

        edges.push_back({0, pts});
    }

    std::sort(edges.begin(), edges.end());

    double result = 0;

    for (auto edge : edges) {
        double w = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;

        if (mst.find(a) == mst.find(b)) {
            continue;
        }

        result += w;
        mst.union_sets(a, b);
    }

    printf("%.5f", result);

}