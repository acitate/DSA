#include <stack.h>
#include <stdlib.h>
#include <stdio.h>
#include <linked_list.h>


Stack *stack_create(void *data) {
    Stack *new_stack = (Stack*) malloc(sizeof(Stack));

    new_stack->list = ll_create(data);

    return new_stack;
}


int stack_push(Stack **stack, void *data) {
    if (stack == NULL || *stack == NULL) {
        fprintf(stderr ,"Stack is NULL!\n");
        return 1;
    }

    if (data == NULL) {
        fprintf(stderr, "Data is NULL!\n");
        return 1;
    }
 
    return ll_insert(&((*stack)->list), data, 0);; 
}


int stack_peek(Stack *stack, void **out) {
    if (stack == NULL) {
        fprintf(stderr, "Stack is NULL!\n");
        return 1;
    }

    if (out == NULL) {
        fprintf(stderr, "Out pointer is NULL!\n");
        return 1;
    }

    LLNode *node;
    if (ll_get(stack->list, 0, &node) != 0) {
        return 1;
    } 
    *out = node->data;
} 


int stack_pop(Stack **stack, void **out) {

    if (stack == NULL || *stack == NULL) {
        fprintf(stderr, "Stack is NULL!\n");
        return 1;
    }

    if (out != NULL) {
        LLNode *node;
        if (ll_get((*stack)->list, 0, &node) != 0) {
            return 1;
        }
        *out = node->data;
    }
    
    return ll_delete(&(*stack)->list, 0);  
}


int stack_size(Stack *stack) {
    return ll_length(stack->list);
}