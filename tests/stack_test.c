
#define STACK_DATA_TYPE double

#include <stdio.h>
#include "stack.h"

int main (int args, char** vargs) {
    stack_node *my_stack, *my_node; 
    double foo = 123.123;

    my_stack = create_stack();
    push_stack(my_stack, &foo);
    my_node = pop_stack(my_stack);

    printf("%p\t%lf\n", my_node, *my_node->data);

    push_stack(my_stack, &foo);
    push_stack(my_stack, &foo);
    push_stack(my_stack, &foo);

    print_stack_ptr(my_stack);
    print_stack("%lf", my_stack);

    pop_stack(my_stack);
    print_stack_ptr(my_stack);
    print_stack("%lf", my_stack);
    pop_stack(my_stack);
    print_stack_ptr(my_stack);
    print_stack("%lf", my_stack);
    pop_stack(my_stack);

    print_stack_ptr(my_stack);
    print_stack("%lf", my_stack);
    return 0;
}
