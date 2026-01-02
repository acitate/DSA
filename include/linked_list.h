#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#define LL_FOR_EACH(head) \
        for (LLNode *pos = head; pos != NULL; pos = pos->next)


typedef struct LLNode {
    void *data;
    struct LLNode *prev, *next;
} LLNode;

LLNode* ll_create(void *data);
int ll_append(LLNode **node, void *data);
int ll_insert(LLNode **node, void *data, int pos);
int ll_length(LLNode *node);
int ll_get(LLNode *node, int pos, LLNode **out);
int ll_free(LLNode **node);
int ll_delete(LLNode **node, int pos);

#ifdef __cplusplus
}
#endif

#endif 