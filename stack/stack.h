/*
 * MUST Define STACK_DATA_TYPE before using this lib :)
 */

#ifndef _STACK_H_
#define _STACK_H_

#include<stdlib.h>

#ifdef STACK_DATA_TYPE
typedef STACK_DATA_TYPE stack_type;
#else 
typedef struct stack_type stack_type;
#endif /* STACK_DATA_TYPE */

typedef struct stack_node {
    stack_type *data;
    struct stack_node *next;
} stack_node;

extern stack_node *create_stack ();
extern int is_stack_empty (stack_node *sentinel);
extern int push_stack (stack_node *sentinel, stack_type *new_data);
extern stack_node *pop_stack (stack_node *sentinel);
extern void print_stack_ptr (stack_node *sentinel);

#ifdef STACK_DATA_TYPE
extern void print_stack (char *data_format, stack_node *sentinel) {
    stack_node *current_node;
    current_node = sentinel->next;

    if (current_node == NULL) {
        printf("(Empty Stack)\n");
        return;
    }
    
    printf(data_format, *current_node->data);
    current_node = current_node->next;
    while (current_node != NULL) {
        printf(" <- ");
        printf(data_format, *current_node->data);
        current_node = current_node->next;
    }
    
    printf("\n");
    return;
}
#endif 

#endif /* _STACK_H_ */
