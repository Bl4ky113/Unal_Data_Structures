
#define STACK_DATA_TYPE double

#include <stdio.h>
#include "stack.h"

int main (int args, char** vargs) {
    stack_node *my_stack, *my_node; 
    double foo = 123.123;

    my_stack = create_stack();
    push_stack(my_stack, foo);
    my_node = pop_stack(my_stack);

    printf("%p\t%lf", my_node, my_node->data);
    return 0;
}
