#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
                data_[base_size_ - 1 + i].insert(10000000000);
                continue;
            }

            data_[base_size_ - 1 + i].insert(items[i]);
        }

        for (int i = base_size_ - 2; i >= 0; --i) {
            data_[i] = data_[2 * i + 1];
            data_[i].merge(data_[2 * i + 2]);
        }
    } 

    int FindMin(int x, int l, int r) {
        std::multiset<int> result;
        FindMinOnSegment(l, r, 0, base_size_ - 1, 0, &result);

        if (result.empty()) {
            return 10000000000;
        }

        if (result.find(x) != result.end()) {
            result.erase(x);
        }

        auto it = result.lower_bound(x);
        if (it == result.end()) {
            return 10000000000;
        }

        return *it;
    }

    void Set(int index, int item) {
        int old_item = *data_[base_size_ - 1 + index].begin();
        data_[base_size_ - 1 + index].clear();
        data_[base_size_ - 1 + index].insert(item);
        Remax((base_size_ + index - 2) / 2, item, old_item);
    }

private:
    void Remax(int curr_leaf, int new_item, int old_item) {
        data_[curr_leaf].erase(data_[curr_leaf].find(old_item));
        data_[curr_leaf].insert(new_item);

        if (curr_leaf == 0) {
            return;
        }

        Remax((curr_leaf - 1) / 2, new_item, old_item);
    }

    void FindMinOnSegment(int l, int r, int curr_l, int curr_r, int curr_leaf, std::multiset<int>* result) {
        if (curr_l >= l && curr_r <= r) {
            result->merge(data_[curr_leaf]);
            return;
        }

        if (!(l <= curr_r && r >= curr_l)) {
            return;
        }

        FindMinOnSegment(l, r, curr_l, (curr_l + curr_r) / 2, 2*curr_leaf + 1, result);
        FindMinOnSegment(l, r, (curr_l + curr_r) / 2 + 1, curr_r, 2*curr_leaf + 2, result);
    }

    int base_size_ = 0;
    std::vector<std::multiset<int>> data_;
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
        case 1: {
            int x, l, r;
            std::cin >> l >> r >> x;
            std::cout << seg_tree.FindMin(x, l, r) << std::endl;
            break;
        }
        
        case 2:
        {
            int i, x;
            std::cin >> i >> x;
            seg_tree.Set(i, x);
            break;
        }

        default:
            break;
        }
    }
}