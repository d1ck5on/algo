#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x;
    int y;
    int z;

    double distance(Point &other) const {
        return std::sqrt(std::pow(std::abs(x - other.x), 2) + std::pow(std::abs(y - other.y), 2));
    }
};

struct Apple {
    Point center;
    int radius;

    bool is_cross(Apple &other) {
        if (center.distance(other.center) <= (radius + other.radius)) {
            return true;
        }

        return false;
    }
};

void dfs(std::vector<std::vector<int>> &edges,
         std::vector<bool> &is_visited,
         std::vector<int> &result,
         int start) {
    is_visited[start] = true;

    for (const auto i: edges[start]) {
        if (is_visited[i]) {
            continue;
        }
        dfs(edges, is_visited, result, i);
    }

    result.push_back(start);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Apple> apples;
    for (int i = 0; i < n; ++i) {
        int x, y, z, r;
        std::cin >> x >> y >> z >> r;
        apples.push_back({.center = Point{x, y, z}, .radius = r});
    }

    std::vector<std::vector<int>> edges(n + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!apples[i].is_cross(apples[j])) {
                continue;
            }

            if (apples[i].center.z > apples[j].center.z) {
                edges[i + 1].push_back(j + 1);
            } else {
                edges[j + 1].push_back(i + 1);
            }
        }
    }

    std::vector<bool> is_visited(n + 1);
    std::vector<int> result;

    dfs(edges, is_visited, result, 1);

    std::cout << result.size() << std::endl;
    for (const auto i: result) {
        std::cout << i << ' ';
    }


}