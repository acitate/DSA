#include <stdio.h>
#include <stdlib.h>
#include <linked_list.hpp>


/*
 * Create new node with given data.
 *
 * @param data The double value to store in the node
 * @return Pointer to newly created node
 */
LLNode *ll_create(double data) {
    LLNode *new_node = (LLNode*) malloc(sizeof(LLNode));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


/*
 * Print all data in list from given head to tail
 *
 * @param node Pointer to first node in the list
 * 
 * Output format: "data1 data2 data3 ..."
 * Prints "List empty." if node is null.
 */
void ll_print(LLNode *node) {
    if (node == NULL) {
        printf("List empty.\n");
    } else if (node->next != NULL) {
        printf("%f ", node->data);
        ll_print(node->next);
    } else {
        printf("%f \n", node->data);
    }
}


/*
 * Append new node to the end of linked list.
 *
 * @param node Pointer to pointer of first node in the list
 * @param data Double value to append to the end of the list
 */
void ll_append(LLNode **node, double data) {
    
    if (*node != NULL) {
        // Case 1: List not empty

        LLNode *new_node = ll_create(data);
        LLNode *temp = *node;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        return;
    } else {
        // Case 2: List empty

        *node = ll_create(data);
    }

}


/*
 * Insert new node at specified position in list.
 *
 * @param node Pointer to pointer of first node in the list
 * @param data Double value to insert in list
 * @param pos Index where the new node should be inserted. Zero-based numbering.
 * 
 * If node is NULL, creates a new node with data.
 * length: number of elements in list (One-based)
 * If pos > length of list, prints "Index out of bounds!"
 * If pos == length, 'appends' a new node to the end of list.
 */
void ll_insert(LLNode **node, double data, int pos) {
    /*
        Insert 'data' at index 'pos' of linked list 'node'. 
    */
    if (*node == NULL) {
        *node = ll_create(data);
        return;
    }

    int length = 0;
    LLNode *new_node = ll_create(data);
    LLNode *temp = *node, *target = NULL;

    while (temp != NULL) {
        // Find the length of list(Zero-based numbering) and target node.

        if (length == pos ) {
            target = temp;
        }
        temp = temp->next;
        length++;
    }

    if (pos > length || pos < 0) {
        printf("Index (%i) is out of bounds!\n", pos);
        return;
    }

    if (pos == 0) {
        /*  Case 1: Insert at start of list. 
            Example:
            list = [12, 23, 56, 19]
            insert(list, 99, 0)
            print(list) -> [99, 12, 23, 56, 19]
        */
        target->prev = new_node;
        new_node->next = target;
        *node = new_node;
        return;
    } else if (pos > 0 && pos < length) {
        /*  Case 2: Insert anywhere in range (0, length). 
            Example:
            list = [12, 23, 56, 19]
            insert(list, 99, 3)
            print(list) -> [12, 23, 56, 99, 19]
        */
        LLNode *prev = target->prev;
        new_node->prev = prev;
        prev->next = new_node;
        target->prev = new_node;    
        new_node->next = target;
        return;
    } else {
        // Case 3: Insert exactly at the end.
        ll_append(node, data);
    }
} 