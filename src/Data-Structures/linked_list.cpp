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
 * @return 0 on success, 1 on fail.
 */
int ll_append(LLNode **node, double data) {
    
    if (*node != NULL) {
        // Case 1: List not empty

        LLNode *new_node = ll_create(data);
        LLNode *temp = *node;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        return 0;
    } else {
        // Case 2: List empty

        *node = ll_create(data);
        return 0;
    }
    return 1;
}


/*
 * Insert new node at specified position in list.
 *
 * @param node Pointer to pointer of first node in the list
 * @param data Double value to insert in list
 * @param pos Index where the new node should be inserted. Zero-based numbering
 * @return 0 on success, 1 if index out of bounds
 * 
 * If node is NULL, creates a new node with data.
 * length: number of elements in list (One-based)
 * If pos > length of list, prints "Index out of bounds!"
 * If pos == length, 'appends' a new node to the end of list.
 */
int ll_insert(LLNode **node, double data, int pos) {
    /*
        Insert 'data' at index 'pos' of linked list 'node'. 
    */
    if (*node == NULL) {
        *node = ll_create(data);
        return 0;
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
        return 1;
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
        return 0;
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
        return 0;
    } else if (pos == length) {
        // Case 3: Insert exactly at the end.
        return ll_append(node, data);
    }
} 


/*
 * Get number of elements in the linked list.
 *
 * @param node Pointer to first node in the linked list
 * @return Integer number of elements in list
 */
int ll_length(LLNode *node) {
    int length = 0;

    while (node != NULL) {
        node = node->next;
        length++;
    }

    return length;
}


/*
 * Get node at specified index of list.
 *
 * @param node Pointer to first node in linked list
 * @param pos Zero-based index of node to retrieve 
 * @param out Pointer to pointer of node where the retrieved node is to be stored
 */
int ll_get(LLNode *node, int pos, LLNode **out) {
    int length = ll_length(node);

    if (pos >= length || pos < 0) {
        return 1;
    }
    
    for (int counter = 0; counter < pos; counter++) {
        node = node->next;
    }

    *out = node;
    return 0;
}


/*
 * Free all nodes in linked list.
 *
 * @param node Pointer to pointer of first node in linked list
 * @return 1 If node is null or points to null, 0 if success
 * 
 * After calling list is empty and node is set to NULL.
 */
int ll_free(LLNode **node) {
    if (node == NULL || *node == NULL) {
        return 1;
    }

    LLNode *next;

    while (*node != NULL) {
        next = (*node)->next;
        free(*node);
        *node = next;
    }

    *node = NULL;
    return 0;
}