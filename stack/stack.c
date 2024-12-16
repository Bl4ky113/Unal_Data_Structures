
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_type stack_type;
typedef struct stack_node {
    stack_type *data;
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

stack_type *pop_stack (stack_node *sentinel) {
    if (is_stack_empty(sentinel)) {
        return NULL;
    }

    stack_node *current_node;
    stack_type *current_data;
    current_node = sentinel->next;

    sentinel->next = current_node->next;

    current_data = current_node->data;
    free(current_node);
    return current_data;
}

stack_node *destroy_stack (stack_node *sentinel) {
    stack_node *prev_node, *current_node;

    current_node = sentinel->next;
    while (current_node != NULL) {
        prev_node = current_node;
        current_node = current_node->next;

        prev_node->next = NULL;
        prev_node->data = NULL;

        free(prev_node);
    }

    prev_node->next = NULL;
    prev_node->data = NULL;
    free(prev_node);

    sentinel->next = NULL;
    sentinel->data = NULL;
    free(sentinel);
    return NULL;
}

/* Only pointers since using an incomplete type */
void print_stack_ptr (stack_node *sentinel) {
    if (is_stack_empty(sentinel)) {
        printf("(Empty Stack)\n");
        return;
    }

    stack_node *current_node;
    current_node = sentinel->next;
    
    printf("%p", current_node->data);
    current_node = current_node->next;
    while (current_node != NULL) {
        printf(" <- %p", current_node->data);
        current_node = current_node->next;
    }
    
    printf("\n");
    return;
}
