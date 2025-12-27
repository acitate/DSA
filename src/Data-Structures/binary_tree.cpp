#include <iostream>
#include <binary_tree.hpp>

using namespace BT;

/*
 * Search the value by the binary search.
 *
 * @param value The value that must be searched for in the nodes of the tree.
 *
 * @return If the value is found, a pointer to the node containing this value is returned; 
 * otherwise, a `nullptr` is returned.
 */
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
    
    return curr_node;
}

/*
 * It inserts the desired value into the tree.
 *
 * @param value The desired value.
 * 
 * This function uses binary search to find a node that has no left or right child, 
 * with the property that if it has no left child, its value is greater than the desired value, 
 * and if it has no right child, its value is smaller than the desired value, 
 * and then places the desired value on the left or right side of the found node.
 * If the specified node already exists, it only increments its count.
 */
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

/* 
 * It places second node in the position of first node, and first node 
 * will no longer be in its previous location. 
 * 
 * @param x The node that will no longer be in its previous position.
 * @param y The node that will take the place of node **x**.
 * 
 * This function only swaps the parents and does not affect the left or right children.
 */
void BinaryTree::transplant(Node* x, Node* y) {
    if (!x->parent) {
        BinaryTree::root = y;
    } else {
        if (x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->parent = x->parent;
}

/*
 * It prints the values in order.
 *
 * @param curr_root For setting the root of the tree.
 */
void BinaryTree::print(Node* curr_root=nullptr) {
    if (!curr_root)
        curr_root = BinaryTree::root;
    print(curr_root->left);
    std::cout<<curr_root->value<<" "<<std::endl;
    print(curr_root->right);
}

/*
 * It returns the minimum value of the tree or the specified subtree.
 * 
 * @param curr_root For setting the root of the tree.
 * @return Pointer to the minimum node.
 * 
 * To find the minimum value, it goes as far left as possible.
 */
Node* BinaryTree::get_min(Node* curr_root=nullptr) {
    if (!curr_root)
        curr_root = BinaryTree::root;
    if (!curr_root || !curr_root->left)
        return curr_root;
    else
        return get_min(curr_root->left);
}

/*
 * It returns the maximum value of the tree or the specified subtree.
 * 
 * @param curr_root For setting the root of the tree.
 * @return Pointer to the maximum node
 * 
 * To find the maximum value, it goes as far right as possible.
 */
Node* BinaryTree::get_max(Node* curr_root=nullptr) {
    if (!curr_root)
        curr_root = BinaryTree::root;
    if (!curr_root || !curr_root->right)
        return curr_root;
    else
        return get_max(curr_root->right);
}


/*
 * It returns the height of the tree.
 *
 * @param curr_root For setting the root of the tree.
 * @return The height of the tree
 * 
 * Tree height = max(left subtree height, right subtree height) + 1;
 * In other words, the height of a tree is equal to the length of the longest path that leads to a leaf.
 */
int BinaryTree::get_height(Node* curr_root=nullptr) {
    int height = 0;
    if (!BinaryTree::root)
        return height;

    if (!curr_root)
        curr_root = BinaryTree::root;
    if (curr_root->right)
        height = get_height(curr_root->right);
    if (curr_root->left)
        height = std::max(height, get_height(curr_root->left));
    height++;

    return height;
}

/*
 * It returns the closest value greater than the specified node.
 * 
 * @param node The specified node.
 * @return Pointer to the successor node.
 * 
 * The successor is the smallest node in the right subtree of the given node, 
 * and if the node does not have a right subtree, the successor must be found among its parents.
 */
Node* BinaryTree::successor(Node* node=nullptr) {
    if (!node) {
        node = BinaryTree::root;
        if (!node)
            return nullptr;
    }
    Node* node_succ = nullptr;
    
    if (node->right)
        node_succ = get_min(node->right);
    else {
        node_succ = node->parent;
        while (node->parent && node->parent->left != node) {
            node = node->parent;
            node_succ = node_succ->parent;
        }
    }

    return node_succ;
}

/*
 * It returns the closest value smaller than the specified node.
 * 
 * @param node The specified node.
 * @return Pointer to the predecessor node.
 * 
 * The predecessor is the biggest node in the left subtree of the given node, 
 * and if the node does not have a left subtree, the predecessor must be found among its parents.
 */
Node* BinaryTree::predecessor(Node* node=nullptr) {
    if (!node) {
        node = BinaryTree::root;
        if (!node)
            return nullptr;
    }
    Node* node_predec = nullptr;
    
    if (node->left)
        node_predec = get_max(node->right);
    else {
        node_predec = node->parent;
        while (node->parent && node->parent->right != node) {
            node = node->parent;
            node_predec = node_predec->parent;
        }
    }

    return node_predec;
}

/*
 * It removes the specified value from the tree, and if the value is not found, it does nothing.
 *
 * @param The specified value
 * @return 1 If the binary is not empty, otherwise 0
 * 
 * The way this function works is that if the specified node is a leaf, it deletes it directly. 
 * If it has only a left or only a right child, it replaces itself with that child. 
 * If it has both children, it replaces itself with its successor, 
 * because the successor of the specified node is the smallest among all nodes in its right subtree, 
 * and therefore does not disrupt the binary tree structure.
 * If the count of the specified node is greater than one, it only decreases the count by one.
 */
int BinaryTree::remove(double value) {
    Node* node = search(value);

    if (node) {
        if (node->count > 1)
            node->count--;
        else {
            if (node->left && !node->right)
                transplant(node, node->left);
            else if (!node->left && node->right)
                transplant(node, node->right);
            else if (node->left && node->right) {
                Node* node_succ = get_min(node->right);

                if (node->right != node_succ) {
                    transplant(node_succ, node_succ->right);
                    node_succ->right = node->right;
                }
                transplant(node, node_succ);

                node_succ->left = node->left;
            } else {
                if (!node->parent)
                    BinaryTree::root = nullptr;
                else {
                    if (node->parent->left == node)
                        node->parent->left = nullptr;
                    else
                        node->parent->right = nullptr;
                }
            }
            delete node;
        }
        return 1;
    } else
        return 0;
}
