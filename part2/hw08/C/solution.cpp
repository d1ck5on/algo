#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

class SegmentTree {
public:
    explicit SegmentTree(const std::vector<int>& items) {
        int size = items.size();
        int bitmask = 9223372036854775808; // 2^63
        base_size_ = 64;

        while ((bitmask & size) == 0) {
            --base_size_;
            bitmask = bitmask >> 1;
        }

        base_size_ = 1 << base_size_;
        
        data_.resize(2 * base_size_ - 1);

        for (int i = 0; i < base_size_; ++i) {
            if (i >= items.size()) {
                data_[base_size_ - 1 + i] = {-10000000000, i};
                continue;
            }

            data_[base_size_ - 1 + i] = {items[i], i};
        }

        for (int i = base_size_ - 2; i >= 0; --i) {
            data_[i] = std::max(data_[2*i + 1], data_[2*i + 2]);
        }
    } 

    std::pair<int, int> FindMax(int l, int r) {
        return FindMaxOnSegment(l, r, 0, base_size_ - 1, 0);
    }

    void Set(int index, int item) {
        data_[base_size_ - 1 + index] = {item, index};
        Remax((base_size_ + index - 2) / 2);
    }

private:
    void Remax(int curr_leaf) {
        data_[curr_leaf] = std::max(data_[2*curr_leaf + 1], data_[2*curr_leaf + 2]);

        if (curr_leaf == 0) {
            return;
        }

        Remax((curr_leaf - 1) / 2);
    }

    std::pair<int, int> FindMaxOnSegment(int l, int r, int curr_l, int curr_r, int curr_leaf) {
        if (curr_l >= l && curr_r <= r) {
            return data_[curr_leaf];
        }

        if (!(l <= curr_r && r >= curr_l)) {
            return {-10000000000, -1};
        }

        return std::max(FindMaxOnSegment(l, r, curr_l, (curr_l + curr_r) / 2, 2*curr_leaf + 1),
        FindMaxOnSegment(l, r, (curr_l + curr_r) / 2 + 1, curr_r, 2*curr_leaf + 2));
    }

    int base_size_ = 0;
    std::vector<std::pair<int, int>> data_;
};

int32_t main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    SegmentTree seg_tree(a);

    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;

        switch (type)
        {
        case 1:
            int l, r;
            std::cin >> l >> r;
            std::cout << seg_tree.FindMax(l, r).second << std::endl;
            break;
        
        case 2:
            int i, x;
            std::cin >> i >> x;
            seg_tree.Set(i, x);
            break;

        default:
            break;
        }
    }
}