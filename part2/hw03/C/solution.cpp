#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
    int z;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::vector<int>>> field;
    std::vector<std::vector<std::vector<int>>> min_distance;

    int sx, sy, sz;

    for (int i = 0; i < n; ++i) {
        std::vector<std::vector<int>> stage(n, std::vector<int>(n));
        min_distance.emplace_back(n, std::vector<int>(n));
        char inp;
        //std::cin >> inp;

        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                std::cin >> inp;

                min_distance[i][x][y] = n * n * n + 100;

                switch (inp) {
                    case '#':
                        stage[x][y] = 0;
                        break;
                    case '.':
                        stage[x][y] = 1;
                        break;
                    case 'S':
                        sx = x;
                        sy = y;
                        sz = i;
                        min_distance[i][x][y] = 0;
                        stage[x][y] = 1;
                        break;
                    default:
                        return 0;
                }
            }
        }

        field.push_back(stage);
    }

    std::vector<std::vector<Point>> distance_vec(n * n * n + 100);
    distance_vec[0].push_back(Point{sx, sy, sz});

    for (int distance = 0; distance < distance_vec.size(); ++distance) {
        if (distance_vec[distance].empty()) {
            break;
        }

        for (int i = 0; i < distance_vec[distance].size(); ++i) {
            Point vertex = distance_vec[distance][i];

            std::vector<Point> adjacent;
            if (vertex.x + 1 < n && field[vertex.z][vertex.x + 1][vertex.y] == 1) {
                adjacent.push_back(Point{vertex.x + 1, vertex.y, vertex.z});
            }
            if (vertex.x - 1 >= 0 && field[vertex.z][vertex.x - 1][vertex.y] == 1) {
                adjacent.push_back(Point{vertex.x - 1, vertex.y, vertex.z});
            }
            if (vertex.y + 1 < n && field[vertex.z][vertex.x][vertex.y + 1] == 1) {
                adjacent.push_back(Point{vertex.x, vertex.y + 1, vertex.z});
            }
            if (vertex.y - 1 >= 0 && field[vertex.z][vertex.x][vertex.y - 1] == 1) {
                adjacent.push_back(Point{vertex.x, vertex.y - 1, vertex.z});
            }
            if (vertex.z + 1 < n && field[vertex.z + 1][vertex.x][vertex.y] == 1) {
                adjacent.push_back(Point{vertex.x, vertex.y, vertex.z + 1});
            }
            if (vertex.z - 1 >= 0 && field[vertex.z - 1][vertex.x][vertex.y] == 1) {
                adjacent.push_back(Point{vertex.x, vertex.y, vertex.z - 1});
            }

            for (Point adj_vertex: adjacent) {
                if (min_distance[adj_vertex.z][adj_vertex.x][adj_vertex.y] != n * n * n + 100) {
                    continue;
                }

                min_distance[adj_vertex.z][adj_vertex.x][adj_vertex.y] = min_distance[vertex.z][vertex.x][vertex.y] + 1;
                distance_vec[min_distance[adj_vertex.z][adj_vertex.x][adj_vertex.y]].push_back(adj_vertex);
            }
        }
    }


    int result = n * n * n + 100;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (min_distance[0][i][j] < result) {
                result = min_distance[0][i][j];
            }
        }
    }

    std::cout << result;
}