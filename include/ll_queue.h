#ifndef LL_QUEUE_H
#define LL_QUEUE_H
#include <linked_list.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LLQueue {
    
    LLNode *list;
} LLQueue;

int queue_ll_enqueue(LLQueue **queue, void *data);
int queue_ll_dequeue(LLQueue **queue, void **out);
LLQueue *queue_ll_create(void *data);

#ifdef __cplusplus
}
#endif

#endif