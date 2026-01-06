#ifndef LL_STACK_H
#define LL_STACK_H
#include <linked_list.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LLStack
{
    LLNode *list;
} LLStack;

LLStack *stack_ll_create(void *data);
int stack_ll_push(LLStack **stack, void *data);
int stack_ll_peek(LLStack *stack, void **out);
int stack_ll_pop(LLStack **stack, void **out);
int stack_ll_size(LLStack *stack);

#ifdef __cplusplus
}
#endif

#endif