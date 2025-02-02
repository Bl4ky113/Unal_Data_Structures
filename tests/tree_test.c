
#define TREE_DATA_TYPE double
#define TREE_DATA_FORMAT "%lf"

#define TREE_KEY_TYPE double
#define TREE_KEY_FORMAT "%lf"

#include <stdio.h>

#include <tree.h>

typedef TREE_KEY_TYPE tree_key_type;

int compare_tree_key (tree_key_type *key1, tree_key_type *key2) {
    if ((*key1) > (*key2)) {
        return 1;
    } else if ((*key1) < (*key2)) {
        return -1;
    }

    return 0;
}

void print_list (tree_data_type **list, int list_size) {
    int i;
    printf("[");
    for (i = 0; i < list_size; i++) {
        if (i != 0) {
            printf(", ");
        }

        printf(TREE_DATA_FORMAT, *list[i]);
    }
    printf("]\n");

    return;
}

int main (int args, char **kargs) {
    tree_node *my_tree, *node;
    tree_data_type *search, *deleted;
    tree_data_type **value_list;
    double foo = 123.123;
    double bar = 456.321;
    double qux = 789.213;
    double foo_inv = -1 * foo;
    double bar_inv = -1 * bar;
    double qux_inv = -1 * qux;
    double foo_1 = (bar - foo);
    double foo_2 = (qux - foo);
    double foo_3 = (bar_inv + foo);
    double foo_4 = (qux_inv + foo);

    my_tree = create_tree();
    insert_tree(my_tree, &foo, &foo);
	insert_tree(my_tree, &bar, &bar);
	insert_tree(my_tree, &qux, &qux);

    int result = 0;
    result = height_tree(my_tree);
    printf("height: %d\n", result);

	result = insert_tree(my_tree, &bar, &bar);
    if (result != 0) {
        printf("ERR INSERTING %lf\n", bar);
    }
	result = insert_tree(my_tree, &qux, &qux);
    if (result != 0) {
        printf("ERR INSERTING %lf\n", qux);
    }

    insert_tree(my_tree, &foo_inv, &foo_inv);
	insert_tree(my_tree, &bar_inv, &bar_inv);
	insert_tree(my_tree, &qux_inv, &qux_inv);

    insert_tree(my_tree, &foo_1, &foo_1);
	insert_tree(my_tree, &foo_2, &foo_2);
    insert_tree(my_tree, &foo_3, &foo_3);
	insert_tree(my_tree, &foo_4, &foo_4);

    print_tree_ptr(my_tree);
    print_tree(my_tree);

    search = search_tree(my_tree, &qux);
    if (search != NULL) {
        printf("%lf\n", *search);
    }

    search = search_tree(my_tree, &bar);
    if (search != NULL) {
        printf("%lf\n", *search);
    }

    search = search_tree(my_tree, &foo_3);
    if (search != NULL) {
        printf("%lf\n", *search);
    }

    node = key_predecessor_tree(my_tree, &qux);
    if (node != NULL) {
        printf("predecesor %lf: %lf:%lf\n", qux, *node->key, *node->value);
    }

    node = key_predecessor_tree(my_tree, &foo);
    if (node != NULL) {
        printf("predecesor %lf: %lf:%lf\n", foo, *node->key, *node->value);
    }

    node = key_successor_tree(my_tree, &foo);
    if (node != NULL) {
        printf("succesor %lf: %lf:%lf\n", foo, *node->key, *node->value);
    }

    node = key_successor_tree(my_tree, &qux_inv);
    if (node != NULL) {
        printf("succesor %lf: %lf:%lf\n", -1 * qux, *node->key, *node->value);
    }

    result = 0;
    count_nodes_tree(my_tree, &result);
    printf("nodes: %d\n", result);

    deleted = delete_tree(my_tree, &qux);
    if (deleted != NULL) {
        printf("deleted %lf: %lf\n", qux, *deleted);
    } else {
        printf("not deleted %lf: %p\n", qux, deleted);
    }

    deleted = delete_tree(my_tree, &qux);
    if (deleted != NULL) {
        printf("deleted %lf: %lf\n", qux, *deleted);
    } else {
        printf("not deleted %lf: %p\n", qux, deleted);
    }
    deleted = delete_tree(my_tree, &qux);
    if (deleted != NULL) {
        printf("deleted %lf: %lf\n", qux, *deleted);
    } else {
        printf("not deleted %lf: %p\n", qux, deleted);
    }
    search = search_tree(my_tree, &qux);
    if (search == NULL) {
        printf("NOT FOUND %lf, %p\n", qux, search);
    }

    deleted = delete_tree(my_tree, &bar_inv);
    if (deleted != NULL) {
        printf("deleted %lf: %lf\n", -1 * bar, *deleted);
    } else {
        printf("not deleted %lf: %p\n", -1 * bar, deleted);
    }
    search = search_tree(my_tree, &bar_inv);
    if (search == NULL) {
        printf("NOT FOUND %lf, %p\n", -1 * bar, search);
    }
    search = search_tree(my_tree, &foo_3);
    if (search == NULL) {
        printf("NOT FOUND %lf, %p\n", (-1 * bar) + foo, search);
    } else {
        printf("FOUND %lf, %lf\n", (-1 * bar) + foo, *search);
    }

    result = 0;
    result = greater_left_depth(my_tree);
    printf("greater_left_depth: %d\n", result);

    result = 0;
    result = greater_right_depth(my_tree);
    printf("greater_right_depth: %d\n", result);

    result = 0;
    result = height_tree(my_tree);
    printf("height: %d\n", result);

    result = 0;
    count_nodes_tree(my_tree, &result);
    printf("nodes: %d\n", result);

    print_tree_ptr(my_tree);
    print_tree(my_tree);

    result = 0;
    int node_count = 0;
    count_nodes_tree(my_tree, &result);
    value_list = (tree_data_type **) malloc(sizeof(tree_data_type *) * result);
    tranversal_inorder_tree(my_tree, value_list, &node_count);
    printf("nodes tranversal inorder: %d\n", node_count);
    print_list(value_list, node_count);

    node_count = 0;
    tranversal_preorder_tree(my_tree, value_list, &node_count);
    printf("nodes tranversal preorder: %d\n", node_count);
    print_list(value_list, node_count);

    node_count = 0;
    tranversal_postorder_tree(my_tree, value_list, &node_count);
    printf("nodes tranversal postorder: %d\n", node_count);
    print_list(value_list, node_count);

    return 0;
}
