
/* 
 * Sea L una lista de enteros no negativos. Se puede aplicar sobre L, tantas veces como se desee, la siguiente operación:
 *  - Seleccionar una posición k de L entre la primera y la penúltima, inclusive.
 *  - Restar una unidad a L[k] y a L[k+1].
 * Escriba un programa que decida si, aplicando la operación anteriormente definida, es posible transformar L en una lista de ceros.
 * Aun que el profesor solo admite C++ y C++ 11. El ejercicio fue implementado solo con cosas de C.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_BUFFER 2048
#define INPUT_SEPARATOR " "
#define CORRECT_OUTPUT "SI"
#define INCORRECT_OUTPUT "NO"

// Mini-LinkedList Header File
typedef struct ListNode {
    int value;
    int index;
    struct ListNode *next;
} ListNode;
ListNode *new_list ();
int insert_node (ListNode *sentinel, int value, int index);
void print_list (ListNode *sentinel);
int free_list (ListNode *sentinel);
// No need for delete_node in this exercise.

int get_stdin_input (char **line_input, size_t *line_size) {
    if (getline(line_input, line_size, stdin) == -1) {
        return -1;
    }

    *line_size = strlen(*line_input);
    return 0;
}

int get_number_list (ListNode *number_list, char *input, size_t input_size) {
    char *curr_char;
    int i, index_number, new_number;

    i = 0;
    index_number = 0;
    new_number = 0;
    for (; i < input_size; i++) {
        *curr_char = input[i];

        if (strncmp(curr_char, INPUT_SEPARATOR, 1) == 0) {
            insert_node(number_list, new_number, number_list->index);

            index_number = 0;
            new_number = 0;
            continue;
        }

        ++index_number;
        new_number += atoi(curr_char) * index_number;
    }

    if (new_number != 0) {
        insert_node(number_list, new_number, number_list->index);
    }

    return 0;
}

void handle_user_input (ListNode *number_list) {
    char *input = NULL;
    size_t input_size = MAX_INPUT_BUFFER;

    get_stdin_input(&input, &input_size);
    get_number_list(number_list, input, input_size);
    return;
}

int check_zero_list (ListNode *sentinel) {
    ListNode *current_node, *next_node;
    int dec_number;

    current_node = sentinel;
    while (current_node->next != NULL) {
        next_node = current_node->next;

        dec_number = current_node->value * -1;
        current_node->value = 0;
        next_node->value += dec_number;

        if (next_node->value <= 0 && next_node->next != NULL) {
            return 1;
        }

        current_node = next_node;
    }

    if (current_node->value != 0) {
        return 1;
    }

    return 0;
}

int main (void) {
    ListNode *number_list = new_list();
    int is_list_zero;

    handle_user_input(number_list);

    is_list_zero = check_zero_list(number_list);

    if (!is_list_zero) {
        printf("%s", CORRECT_OUTPUT);
    } else {
        printf("%s", INCORRECT_OUTPUT);
    }

    free_list(number_list);
    return 0;
}

ListNode *new_list () {
    ListNode *list_ptr = (ListNode *) malloc(sizeof(ListNode));
    list_ptr->index = 0;
    list_ptr->next = NULL;
    return list_ptr;
}

int insert_node (ListNode *sentinel, int value, int index) {
    int i;
    ListNode *new_node, *current_node;

    if (sentinel->next == NULL) {
        new_node = (ListNode *) malloc(sizeof(ListNode));
        new_node->index = 0;
        new_node->value = value;
        new_node->next = NULL;

        sentinel->next = new_node;
        sentinel->index = 1;
        return 0; // Empty List
    }

    i = 0;
    current_node = sentinel;

    while (current_node->next != NULL && i < index) {
        i++;
        current_node = current_node->next;
    }

    new_node = (ListNode *) malloc(sizeof(ListNode));
    if (current_node == sentinel) {
        new_node->index = 0;
    } else {
        new_node->index = current_node->index + 1;
    }

    new_node->value = value;
    new_node->next = current_node->next;

    current_node->next = new_node;

    current_node = new_node;

    while (current_node->next != NULL) {
        current_node = current_node->next;
        ++current_node->index;
    }
    
    sentinel->index = current_node->index + 1;
    return 0;
}

void print_list (ListNode *sentinel) {
    if (sentinel->next == NULL) {
        printf("[]\n");
        return;
    }

    ListNode *current_node = sentinel->next;

    printf("[\n");
    while (current_node != NULL) {
        printf("\t%d - %d\n", current_node->index, current_node->value);

        current_node = current_node->next;
    }
    printf("]\n");

    return;
}

int free_list (ListNode *sentinel) {
    ListNode *current_node, *next_node;

    current_node = sentinel;
    while (current_node != NULL) {
        next_node = current_node->next;

        free(current_node);

        current_node = next_node;
    }
    
    return 0;
}
