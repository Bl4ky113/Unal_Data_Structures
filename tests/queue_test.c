
#define QUEUE_DATA_TYPE int
#define QUEUE_DATA_FORMAT "%d"

#include <stdio.h>
#include "queue.h"

#include <malloc.h>

int main (void) {
    queue_node *my_queue;
    queue_type *node_data; 
    int foo, bar, qux, foobar;

    my_queue = create_queue();
    foo = 123;
    bar = 345;
    qux = 567;
    foobar = 999;

    enqueue(my_queue, &foo);
    enqueue(my_queue, &bar);
    enqueue(my_queue, &qux);
    enqueue(my_queue, &foobar);
    enqueue(my_queue, &bar);
    enqueue(my_queue, &bar);
    enqueue(my_queue, &qux);
    enqueue(my_queue, &foo);

    print_queue_ptr(my_queue);
    print_queue(my_queue);
    malloc_stats();

    node_data = dequeue(my_queue);
    printf("\t%d\n", *node_data);
    node_data = dequeue(my_queue);
    printf("\t%d\n", *node_data);
    node_data = dequeue(my_queue);
    printf("\t%d\n", *node_data);

    print_queue_ptr(my_queue);
    print_queue(my_queue);
    malloc_stats();
    enqueue(my_queue, &qux);
    enqueue(my_queue, &foo);
    print_queue_ptr(my_queue);
    print_queue(my_queue);
    malloc_stats();
    return 0;
}
