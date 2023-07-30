#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dist(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        dist[i] = 1000000000;
    }
    dist[1] = 0;

    for (int step = 1; step <= n + 1; ++step) {
        bool is_stop = true;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                int edge = (179*i + 719*j) % 1000 - 500;

                if (dist[j] > dist[i] + edge) {
                    dist[j] = dist[i] + edge;
                    is_stop = false;
                }
            }
        }
        if (is_stop) {
            break;
        }
    }

    std::cout << dist[n] << std::endl;
}