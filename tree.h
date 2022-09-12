#include <memory>
#include <functional>
#include <algorithm>

class SearchTree {
private:
    struct Node {
        Node* parent;
        double val;
        Node* left;
        Node* right;

        Node(Node* parent, double val1) : parent(parent), val(val1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void deleteTree(Node* root) {
        if(root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }


public:
    SearchTree() {
        this->root = nullptr;
    }

    bool InTree(double v) {
        Node* node = root;
        while (node != nullptr) {

            if (node->val == v) return true;

            if (node->val > v) node = node->left;
            else node = node->right;
        }

        return false;
    }


    void Push(double v) {
        Node* prev = nullptr;
        Node* node = root;
        while (node != nullptr) {
            prev = node;
            if (node->val > v) node = node->left;
            else node = node->right;
        }

        node = new Node(prev, v);

        if (prev == nullptr) {
            root = node;
            return;
        }

        if (prev->val > v) prev->left = node;
        else prev->right = node;

        return;
    }

    void visit_r(Node* node, const std::function<void(double value)>& func) {
        if (node->left != nullptr) {
            visit_r(node->left, func);
        }

        func(node->val);
        
        if (node->right != nullptr) {
            visit_r(node->right, func);
        }
    }

    void visit(const std::function<void(double value)>& func) {
        if (root == nullptr) {
            return;
        }

        visit_r(root, func);
    }


    ~SearchTree() {
        deleteTree(root);
    }
};