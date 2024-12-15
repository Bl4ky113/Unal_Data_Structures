
#define STACK_DATA_TYPE double
#define STACK_DATA_FORMAT "%lf"

#include <stdio.h>
#include "stack.h"

int main (int args, char** vargs) {
    stack_node *my_stack;
    stack_type *my_data; 
    double foo = 123.123;

    my_stack = create_stack();
    push_stack(my_stack, &foo);
    my_data = pop_stack(my_stack);

    printf("%lf\n", *my_data);

    push_stack(my_stack, &foo);
    push_stack(my_stack, &foo);
    push_stack(my_stack, &foo);

    print_stack_ptr(my_stack);
    print_stack(my_stack);

    pop_stack(my_stack);
    print_stack_ptr(my_stack);
    print_stack(my_stack);
    pop_stack(my_stack);
    print_stack_ptr(my_stack);
    print_stack(my_stack);
    pop_stack(my_stack);

    print_stack_ptr(my_stack);
    print_stack(my_stack);
    return 0;
}
