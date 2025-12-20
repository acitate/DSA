#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

typedef struct LLNode {
    double data;
    struct LLNode *prev, *next;
} LLNode;

LLNode* ll_create(double data);
void ll_print(LLNode *node);
void ll_append(LLNode **node, double data);
void ll_insert(LLNode **node, double data, int pos);

#endif 