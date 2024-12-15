
#include<stdio.h>
#include <stdlib.h>

typedef struct queue_type queue_type;
typedef struct queue_node {
    queue_type *data;
    struct queue_node *next;
} queue_node;

queue_node *create_queue () {
    static queue_node *new_queue, *placeholder;
    new_queue = (queue_node *) malloc(sizeof(queue_node));
    placeholder = (queue_node *) malloc(sizeof(queue_node));

    new_queue->next = placeholder;
    placeholder->next = placeholder;

    return new_queue;
}

int is_queue_empty (queue_node *sentinel) {
    if (sentinel->next->next == sentinel->next) {
        return 1;
    }

    return 0;
}

int enqueue (queue_node *sentinel, queue_type *data) {
    queue_node *new_node, *current_node;

    new_node = (queue_node *) malloc(sizeof(queue_node));
    new_node->data = data;

    current_node = sentinel->next;
    sentinel->next = new_node;

    new_node->next = current_node->next;
    current_node->next = new_node;
    return 0;
}

queue_type *dequeue (queue_node *sentinel) {
    queue_node *current_node;
    queue_type *current_data;

    current_node = sentinel->next->next->next;
    sentinel->next->next->next = current_node->next;

    if (current_node == sentinel->next) {
        sentinel->next = current_node->next;
    }
    
    current_data = current_node->data;
    free(current_node);
    return current_data;
}

queue_type *front_element (queue_node *sentinel) {
    return sentinel->next->next->next->data;
}

int remove_queue (queue_node *sentinel) {
    queue_node *current_node;
    current_node = sentinel->next->next;

    while ( current_node != sentinel->next ) {
        sentinel->next->next = current_node->next;

        free(current_node);
        current_node = sentinel->next->next;
    }

    free(sentinel->next); // Placeholder
    free(sentinel); // Sentinel
    return 0;
}

void print_queue_ptr (queue_node *sentinel) {
    if (is_queue_empty(sentinel)) {
        printf("(Queue Empty)\n");
        return;
    }

    queue_node *current_node;

    current_node = sentinel->next->next->next;
    printf("%p", current_node->data);

    current_node = current_node->next;
    while (current_node != sentinel->next->next) {
        printf(" -> %p", current_node->data);

        current_node = current_node->next;
    }

    printf("\n");
    return;
}
    
