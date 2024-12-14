#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef STACK_DATA_TYPE

#define STACK_DATA_TYPE int

#endif /* STACK_DATA_TYPE */

typedef struct stack_type stack_type;
typedef struct stack_node {
    const stack_type *data;
    struct stack_node *next;
} stack_node;

stack_node *create_stack () {
    stack_node *new_sentinel = (stack_node *) malloc(sizeof(stack_node));
    new_sentinel->next = NULL;

    return new_sentinel;
}

int is_stack_empty (stack_node *sentinel) {
    if (sentinel->next == NULL) {
        return 1;
    }

    return 0;
}

int push_stack (stack_node *sentinel, stack_type *new_data) {
    stack_node *new_node, *current_node;

    current_node = sentinel->next; // Sentinel can be empty

    new_node = (stack_node *) malloc(sizeof(stack_node));
    new_node->data = new_data;

    new_node->next = current_node;
    sentinel->next = new_node;
    return 0;
}

stack_node *pop_stack (stack_node *sentinel) {
    if (is_stack_empty(sentinel)) {
        return NULL;
    }

    stack_node *current_node;
    current_node = sentinel->next;

    sentinel->next = current_node->next;

    return current_node;
}

void print_stack (stack_node *sentinel) {
    stack_node *current_node;
    current_node = sentinel->next;

    if (current_node == NULL) {
        printf("(Empty Stack)\n");
        return;
    }
    
    printf("%p", current_node->data);
    current_node = current_node->next;
    while (current_node != NULL) {
        printf(" <- %p", current_node->data);
        current_node = current_node->next;
    }
    
    printf("\n");
    return;
}
