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

    bool is_balance() {
        return bypass_balance(root_);
    }

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

    Node* Max() {
        return MaxInSubtree(root_);
    }

    Node* SecondMax() {
        Node* max = Max();
        if (max->left == nullptr) {
            return max->parent;
        }

        return MaxInSubtree(max->left);
    }

    std::vector<int> sorted() {
        std::vector<int> result;

        bypass(root_, &result);
        return result;
    }

    std::vector<int> forks() {
        std::vector<int> result;

        bypass_forks(root_, &result);
        return result;
    }

private:

    bool bypass_balance(Node* root) {
        if (root->left != nullptr && root->right != nullptr) {
            if (root->right->height - root->left->height < -1 || root->right->height - root->left->height > 1) {
                return false;
            }
        } else if (root->left == nullptr && root->right != nullptr) {
            if (root->right->height > 1) {
                return false;
            }
        } else if (root->left != nullptr && root->right == nullptr) {
            if (root->left->height > 1) {
                return false;
            }
        }

        if (root->left != nullptr) {
            bool res = bypass_balance(root->left);
            if (!res) {
                return false;
            }
        }

        if (root -> right != nullptr) {
            bool res = bypass_balance(root->right);
            if (!res) {
                return false;
            }
        }

        return true;
    }

    void bypass_forks(Node* root, std::vector<int>* result) {
        if (root->left != nullptr) {
            bypass_forks(root->left, result);
        }

        if (root->left == nullptr && root->right != nullptr || root->left != nullptr && root->right == nullptr) {
            result->push_back(root->key);
        }

        if (root->right != nullptr) {
            bypass_forks(root->right, result);
        }
    }


    void bypass(Node* root, std::vector<int>* result) {
        if (root->left != nullptr) {
            bypass(root->left, result);
        }

        result->push_back(root->key);

        if (root->right != nullptr) {
            bypass(root->right, result);
        }
    }

    Node* MaxInSubtree(Node* root) {
        if (root->right == nullptr) {
            return root;
        }

        return MaxInSubtree(root->right);
    }

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

    if (bst.is_balance()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}