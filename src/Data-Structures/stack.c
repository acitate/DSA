#include <stack.h>
#include <stdlib.h>
#include <linked_list.h>


Stack *stack_create(void *data) {
    Stack *new_stack = (Stack*) malloc(sizeof(Stack));

    new_stack->list = ll_create(data);
    new_stack->top = 0;

    return new_stack;
}


int stack_push(Stack **stack, void *data) {
    int code = ll_append((&(*stack)->list), data);
    if (code == 0) {
        (*stack)->top++;
        return code;
    }
    return 1; 
}


void *stack_peek(Stack *stack) {
    LLNode *node;
    ll_get(stack->list, stack->top, &node);
    return node->data;
}