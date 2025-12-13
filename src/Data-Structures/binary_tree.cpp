#include <iostream>
#include <binary_tree.hpp>

using namespace std;

Node* BinaryTree::get_min(Node* curr_root=nullptr) {
    if (!curr_root)
        curr_root = BinaryTree::root;
    if (!curr_root || !curr_root->left)
        return curr_root;
    else
        return get_min(curr_root->left);
}

Node* BinaryTree::get_max(Node* curr_root=nullptr) {
    if (!curr_root)
        curr_root = BinaryTree::root;
    if (!curr_root || !curr_root->right)
        return curr_root;
    else
        return get_min(curr_root->right);
}
