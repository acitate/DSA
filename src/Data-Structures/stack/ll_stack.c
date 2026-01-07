#include <ll_stack.h>
#include <stdlib.h>
#include <stdio.h>
#include <linked_list.h>


/*
 * Create a linked list based stack with the given data.
 *
 * @param data Pointer to element to store in the stack
 * @return Pointer to the newly created stack
 */
LLStack *stack_ll_create(void *data) {
    LLStack *new_stack = (LLStack*) malloc(sizeof(LLStack));

    new_stack->list = ll_create(data);

    return new_stack;
}


/*
 * Push a new element to top of the stack.
 *
 * @param stack Pointer to pointer of the stack that is to be pushed to
 * @param data Pointer to data to push
 * @return 0 on success, 1 on fail.
 */
int stack_ll_push(LLStack **stack, void *data) {
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


/*
 * View the top element of the stack without removing it.
 *
 * @param stack Pointer to the stack to peek
 * @param out Pointer to pointer of the memory to store peek'd element
 * @return 0 on success, 1 on fail
 */
int stack_ll_peek(LLStack *stack, void **out) {
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
    return 0;
} 


/*
 * Pop (remove and return) the element at top of the stack.
 *
 * @param stack Pointer to pointer of the stack to pop
 * @param out Pointer to pointer of the variable to store the popped element
 * @return 0 on success, 1 on fail
 */
int stack_ll_pop(LLStack **stack, void **out) {

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


/*
 * Get the number of elements stored in a stack.
 *
 * @param stack Pointer to stack to get size of
 * @return Number of elements in the stack 
 */
int stack_ll_size(LLStack *stack) {
    return ll_length(stack->list);
}