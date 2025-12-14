#include <iostream>
#include <binary_tree.hpp>

using namespace std;

Node* BinaryTree::search(double value) {
    Node* curr_node = BinaryTree::root;

    while (curr_node->left || curr_node->right) {
        if (curr_node->value == value)
            return curr_node;
        else if (curr_node->value < value)
            curr_node = curr_node->right;
        else
            curr_node = curr_node->left;
    }
    // If value not found then return nullptr
    return curr_node;
}

void BinaryTree::insert(double value) {
    Node* parent = BinaryTree::root;
    Node* node = search(value);

    // First insert in the binary tree
    if (!parent) {
        node = new Node;
        node->value = value;
        BinaryTree::root = node;
        return;
    }

    // If node has exist then add to the number of nodes
    if (node)
        node->count++;
    else {
        while (parent->left || parent->right) {
            if (parent->value < value) {
                if (!parent->right) 
                    break;
                parent = parent->right;
            }
            else {
                if (!parent->left)
                    break;
                parent = parent->left;
            }
        }

        node = new Node;
        node->value = value;
        node->parent = parent;

        if (node->value > parent->value)
            parent->right = node;
        else
            parent->left = node;
    }
}

// Print values in order
void BinaryTree::print(Node* curr_root=nullptr) {
    if (!curr_root)
        curr_root = BinaryTree::root;
    print(curr_root->left);
    cout<<curr_root->value<<" "<<endl;
    print(curr_root->right);
}

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
        return get_max(curr_root->right);
}
