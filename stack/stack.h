
#ifndef _STACK_H_
#define _STACK_H_

#include<stdlib.h>

#ifdef STACK_DATA_TYPE

typedef STACK_DATA_TYPE stack_type;

#endif /* STACK_DATA_TYPE */

typedef struct stack_node {
    const stack_type *data;
    struct stack_node *next;
} stack_node;

extern stack_node *create_stack ();
extern int is_stack_empty (stack_node *sentinel);
extern int push_stack (stack_node *sentinel, stack_type *new_data);
extern stack_node *pop_stack (stack_node *sentinel);
extern void print_stack (stack_node *sentinel);

#endif /* _STACK_H_ */
