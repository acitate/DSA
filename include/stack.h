#ifndef STACK_H
#define STACK_H
#include <linked_list.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Stack
{
    int top;
    LLNode *list;
} Stack;

Stack *stack_create(void *data);
int stack_push(Stack **stack, void *data);
void *stack_peek(Stack *stack);

#ifdef __cplusplus
}
#endif

#endif