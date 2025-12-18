#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

typedef struct Node {
    double data;
    struct Node *prev, *next;
} Node;

Node* create(double data);

void print(Node *node);
void append(Node **node, double data);
void insert(Node **node, double data, int pos);

#endif 