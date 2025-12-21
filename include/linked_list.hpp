#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

typedef struct LLNode {
    double data;
    struct LLNode *prev, *next;
} LLNode;

LLNode* ll_create(double data);
void ll_print(LLNode *node);
int ll_append(LLNode **node, double data);
int ll_insert(LLNode **node, double data, int pos);
int ll_length(LLNode *node);
int ll_get(LLNode *node, int pos, LLNode **out);
int ll_free(LLNode **node);

#endif 