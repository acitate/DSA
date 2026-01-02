#ifndef STACK_H
#define STACK_H
#include <linked_list.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Stack
{
    LLNode *list;
} Stack;

Stack *stack_create(void *data);
int stack_push(Stack **stack, void *data);
int stack_peek(Stack *stack, void **out);
int stack_pop(Stack **stack, void **out);
int stack_size(Stack *stack);

#ifdef __cplusplus
}
#endif

#endif