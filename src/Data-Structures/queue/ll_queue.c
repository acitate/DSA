#include <stdio.h>
#include <stdlib.h>
#include <ll_queue.h>
#include <linked_list.h>


LLQueue *queue_ll_create(void *data) {
    LLQueue *new_queue= (LLQueue*) malloc(sizeof(LLQueue));

    new_queue->list = ll_create(data);

    return new_queue;
}


int queue_ll_enqueue(LLQueue **queue, void *data) {
    if (queue == NULL || *queue == NULL) {
        fprintf(stderr, "Queue is NULL!\n");
        return 1;
    }

    if (data == NULL) {
        fprintf(stderr, "Data is NULL!\n");
        return 1;
    }

    return ll_append(&((*queue)->list), data);
}


int queue_ll_dequeue(LLQueue **queue, void **out) {
    if (*queue == NULL || queue == NULL) {
        fprintf(stderr, "Queue is NULL!\n");
        return 1;
    }

    if (out != NULL) {
        LLNode *node;
        if (ll_get((*queue)->list, 0, &node) != 0) {
            return 1;
        }
        *out = node->data;
    }

    return ll_delete(&((*queue)->list), 0);
}
