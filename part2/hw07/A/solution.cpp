#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int key;
    int height = 1;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BST {
public:

    BST(Node* root) : root_(root) {};

    void Add(int x) {
        AddInSubtree(x, root_);
        int height = 0;
        if (root_->right != nullptr && root_->right->height > height) {
            height = root_->right->height;
        }

        if (root_->left != nullptr && root_->left->height > height) {
            height = root_->left->height;
        }

        root_->height = height + 1;
    }

    int Height() {
        return root_->height;
    }

private:

    void AddInSubtree(int x, Node* root) {
        if (x == root->key) {
            return;
        }

        if (x < root->key) {
            if (root->left != nullptr) {
                AddInSubtree(x, root->left);
                
                int height = root->left->height + 1;

                if (root->height < height) {
                    root->height = height;
                }

                return;
            }

            root->left = new Node({.key = x, .parent = root});
            int height = root->left->height + 1;

            if (root->height < height) {
                root->height = height;
            }

            return;
        }

        if (x > root->key) {
            if (root->right != nullptr) {
                AddInSubtree(x, root->right);
                
                int height = root->right->height + 1;
                if (root->height < height) {
                    root->height = height;
                }
                return;
            }

            root->right = new Node({.key = x, .parent = root});
            int height = root->right->height + 1;
            if (root->height < height) {
                root->height = height;
            }
            return;
        }
    }

    Node* root_ = nullptr;
};

int main() {
    int a;
    std::cin >> a;

    if (a == 0) {
        return 0;
    }

    BST bst(new Node({.key = a}));

    std::cin >> a;
    while (a) {
        bst.Add(a);
        std::cin >> a;
    }

    std::cout << bst.Height();
}