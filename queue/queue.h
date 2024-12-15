
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef QUEUE_DATA_TYPE
typedef QUEUE_DATA_TYPE queue_type;
#else
typedef struct queue_type queue_type;
#endif /* QUEUE_DATA_TYPE */

typedef struct queue_node {
    queue_type *data;
    struct queue_node *next;
} queue_node;

extern queue_node *create_queue ();
extern int is_queue_empty (queue_node *sentinel);
extern int enqueue (queue_node *sentinel, queue_type *data);
extern queue_type *dequeue (queue_node *sentinel);
extern queue_type *front_element (queue_node *sentinel);
extern void print_queue_ptr (queue_node *sentinel);

#ifdef QUEUE_DATA_TYPE
#ifdef QUEUE_DATA_FORMAT
extern void print_queue (queue_node *sentinel) {
    if (is_queue_empty(sentinel)) {
        printf("(Queue Empty)\n");
        return;
    }

    queue_node *current_node;

    current_node = sentinel->next->next->next;
    printf(QUEUE_DATA_FORMAT, *current_node->data);

    current_node = current_node->next;
    while (current_node != sentinel->next->next) {
        printf(" -> ");
        printf(QUEUE_DATA_FORMAT, *current_node->data);

        current_node = current_node->next;
    }

    printf("\n");
    return;
}
#endif /* QUEUE_DATA_FORMAT */
#endif /* QUEUE_DATA_TYPE */

#endif /* _QUEUE_H_ */
