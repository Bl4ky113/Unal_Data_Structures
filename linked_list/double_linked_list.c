#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct listnode {
    int value;
    int index;
    struct listnode *next;
    struct listnode *prev;
} listnode;

listnode *new_list () {
    listnode *list_ptr = malloc(sizeof(listnode));
    list_ptr->index = 0;
    list_ptr->next = NULL;
    list_ptr->prev = NULL;
    return list_ptr;
}

int get_node_by_index (listnode *sentinel, int index) {
    int value, i;
    listnode *current_node;

    current_node = sentinel;
    while (current_node->index != index || current_node->next != NULL) {
        current_node = current_node->next;
    }

    if (current_node->index != index) {
        return INT_MAX;
    }

    value = current_node->value;
    return value;
}

int insert_node (listnode *sentinel, int value, int index) {
    int i;
    listnode *new_node, *current_node;

    if (sentinel->next == NULL) {
        new_node = malloc(sizeof(listnode));
        new_node->index = 0;
        new_node->value = value;
        new_node->next = NULL;
        new_node->prev = NULL;

        sentinel->next = new_node;
        sentinel->prev = new_node;
        sentinel->index = 0;
        return 0; // Empty List
    }

    i = 0;
    current_node = sentinel;

    while (current_node->next != NULL && i < index) {
        i++;
        current_node = current_node->next;
    }

    
    new_node = malloc(sizeof(listnode));
    if (current_node == sentinel) {
        new_node->index = 0;
    } else {
        new_node->index = current_node->index + 1;
    }

    new_node->value = value;
    new_node->next = current_node->next;
    new_node->prev = current_node;

    current_node->next = new_node;

    current_node = new_node;

    while (current_node->next != NULL) {
        current_node = current_node->next;
        ++current_node->index;
    }

    
    sentinel->index = current_node->index;
    sentinel->prev = current_node;
    return 0;
}

void print_list (listnode *sentinel) {
    if (sentinel->next == NULL) {
        printf("[]\n");
        return;
    }

    listnode *current_node = sentinel->next;

    printf("[\n");
    while (current_node != NULL) {
        printf("\t%d - %d\n", current_node->index, current_node->value);

        current_node = current_node->next;
    }
    printf("]\n");

    return;
}

int main (void) {
    int size = 1;
    listnode *my_node;

    my_node = new_list();

    insert_node(my_node, 10, 0);
    insert_node(my_node, 20, 1);

    print_list(my_node);

    insert_node(my_node, 30, 0);
    insert_node(my_node, 40, 0);
    insert_node(my_node, 50, my_node->index + 1000);
    insert_node(my_node, 100, -1);

    print_list(my_node);

    return 0;
}
