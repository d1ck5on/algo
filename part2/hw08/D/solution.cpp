#include <iostream>
#include <vector>

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
                data_[base_size_ - 1 + i] = 0;
                continue;
            }

            if (items[i] % 2 == 1 || items[i] % 2 == -1) {
                data_[base_size_ - 1 + i] = 0;
                continue;
            }

            data_[base_size_ - 1 + i] = 1;
        }

        for (int i = base_size_ - 2; i >= 0; --i) {
            data_[i] = data_[2*i + 1] + data_[2*i + 2];
        }
    } 

    int FindSum(int l, int r) {
        return FindSumOnSegment(l, r, 0, base_size_ - 1, 0);
    }

    void Set(int index, int item) {
        if (item % 2 == 0) {
            data_[base_size_ - 1 + index] = 1;
        } else {
            data_[base_size_ - 1 + index] = 0;
        }
        Resum((base_size_ + index - 2) / 2);
    }

private:
    void Resum(int curr_leaf) {
        data_[curr_leaf] = data_[2*curr_leaf + 1] + data_[2*curr_leaf + 2];

        if (curr_leaf == 0) {
            return;
        }

        Resum((curr_leaf - 1) / 2);
    }

    int FindSumOnSegment(int l, int r, int curr_l, int curr_r, int curr_leaf) {
        if (curr_l >= l && curr_r <= r) {
            return data_[curr_leaf];
        }

        if (!(l <= curr_r && r >= curr_l)) {
            return 0;
        }

        return FindSumOnSegment(l, r, curr_l, (curr_l + curr_r) / 2, 2*curr_leaf + 1) +
        FindSumOnSegment(l, r, (curr_l + curr_r) / 2 + 1, curr_r, 2*curr_leaf + 2);
    }

    int base_size_ = 0;
    std::vector<int> data_;
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
            std::cout << seg_tree.FindSum(l, r) << std::endl;
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