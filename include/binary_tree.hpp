#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

namespace BT {
    struct Node {
        double value;
        int count = 1;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;
    };

    class BinaryTree {
        private:
            Node* root = nullptr;

            void transplant(Node* x, Node* y);
        public:
            void insert(double value);
            int remove(double value);
            void print(Node* curr_root=nullptr);

            Node* get_min(Node* curr_root=nullptr);
            Node* get_max(Node* curr_root=nullptr);
            int get_height(Node* curr_root=nullptr);

            Node* search(double value);
            Node* successor(Node* node=nullptr);
            Node* predecessor(Node* node=nullptr);
    };
};

#endif