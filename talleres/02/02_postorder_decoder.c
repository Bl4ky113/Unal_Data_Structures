
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree_node {
    int key;
    int height;

    struct tree_node* left;
    struct tree_node* right;
} tree_node;

int *handle_postorder_list_input (int *num_nodes) {
    int *input_list;
    int num_inputs, tmp_input;

    scanf("%d\n", &num_inputs);

    input_list = (int *) malloc(sizeof(int) * num_inputs);

    for (int i = 0; i < num_inputs; ++i) {
        scanf("%d\n", &tmp_input);

        input_list[i] = tmp_input;
    }

    *num_nodes = num_inputs;
    return input_list;
}

int *sort_list (int *int_list, int size_list) {
    int *sorted_list = (int *) malloc(sizeof(int) * size_list);

    for (int i = 0; i < size_list; i++) {
        sorted_list[i] = int_list[i];
    }

    for (int i = 0; i < size_list; i++) {
        for (int j = i + 1; j < size_list; j++) {
            if (sorted_list[j] < sorted_list[i]) {
                int temp = sorted_list[i];
                sorted_list[i] = sorted_list[j];
                sorted_list[j] = temp;
            }
        }
    }

    return sorted_list;
}

tree_node *insert_node (tree_node *node, int new_key, int *insert_side) {
    tree_node *new_node = (tree_node *) malloc(sizeof(tree_node));
    new_node->key = new_key;

    if (new_key < node->key) {
        new_node->left = node->left;
        node->left = new_node;

        if (*insert_side > 0) {
            *insert_side = -1;
        } else {
            --(*insert_side);
        }
    } else {
        new_node->right = node->right;
        node->right = new_node;
        if (*insert_side < 0) {
            *insert_side = 1;
        } else {
            ++(*insert_side);
        }
    }

    return new_node;
}

tree_node *decode_tree (int *postorder_list, int *inorder_list, int num_nodes) {
    tree_node *root, *tmp_node, *last_pivot;
    int root_index, left_index, right_index, insert_side, update_pivot;

    root = (tree_node *) malloc(sizeof(tree_node));
    root->key = postorder_list[num_nodes - 1];

    if (num_nodes % 2 == 0) {
        root_index = ((int) ceil((double) (num_nodes - 1) / 2.0));
    } else {
        root_index = (num_nodes - 1) / 2;
    }
    left_index = root_index - 1;
    right_index = num_nodes - 2;

    tmp_node = root;
    last_pivot = root;
    update_pivot = 1; // First child will be a pivot, then the next subleft-tree
    insert_side = 0;
    while (right_index >= root_index) {
        if (postorder_list[right_index] < last_pivot->key) {
            tmp_node = last_pivot;
            update_pivot = 1;
        }
        
        tmp_node = insert_node(tmp_node, postorder_list[right_index], &insert_side);

        if (update_pivot) {
            last_pivot = tmp_node;
            update_pivot = 0;
        }
        --right_index;
    }

    tmp_node = root;
    last_pivot = root;
    update_pivot = 1; // First child will be a pivot, then the next subright-tree
    insert_side = 0;
    while (left_index >= 0) {
        if (postorder_list[left_index] < last_pivot->key) {
            tmp_node = last_pivot;
            update_pivot = 1;
        }
        
        tmp_node = insert_node(tmp_node, postorder_list[left_index], &insert_side);

        if (update_pivot) {
            last_pivot = tmp_node;
            update_pivot = 0;
        }
        --left_index;
    }

    return root;
}

int get_node_height (tree_node *base_node) {
    int left_height, right_height;

    if (base_node == NULL) {
        return -1;
    }

    left_height = get_node_height(base_node->left);
    right_height = get_node_height(base_node->right);

    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

int check_if_avl (tree_node *base_node) {
    int left_height, right_height;

    left_height = get_node_height(base_node->left);
    right_height = get_node_height(base_node->right);

    if (left_height - right_height < 1 && left_height - right_height > -1) {
        return 1;
    } else {
        return 0;
    }
}

void print_list (int* int_list, int list_size) {
    for (int i = 0; i < list_size; i++) {
        printf("%d\t", int_list[i]);
    }
    printf("\n");

    return;
}

void print_tree (tree_node *base_node, int current_depth, char direction_char) {
    if (base_node == NULL) {
        return;
    }

    int i = 1;
    if (current_depth > 0) {
        printf("|");
        for (; i < current_depth; i++) {
            printf("\t|");
        }
        printf("\t%c", direction_char);
    }

    printf("(");
    printf("%d", base_node->key);
    printf(")\n");

    if (base_node->left != NULL) {
        print_tree(base_node->left, current_depth + 1, 'l');
    }

    if (base_node->right != NULL) {
        print_tree(base_node->right, current_depth + 1, 'r');
    }

    return;
}

void tranversal_inorder_tree (tree_node *base_node, int *value_list, int *value_list_index) {
    if (base_node == NULL) {
        return;
    }

    tranversal_inorder_tree(base_node->left, value_list, value_list_index);

    value_list[(*value_list_index)++] = base_node->key;

    tranversal_inorder_tree(base_node->right, value_list, value_list_index);

    return;
}

void tranversal_postorder_tree (tree_node *base_node, int *value_list, int *value_list_index) {
    if (base_node == NULL) {
        return;
    }

    tranversal_postorder_tree(base_node->left, value_list, value_list_index);

    tranversal_postorder_tree(base_node->right, value_list, value_list_index);

    value_list[(*value_list_index)++] = base_node->key;

    return;
}

int main (int args, char **vargs) {
    tree_node *root;
    int *postorder_list, *inorder_list, *test_list;
    int num_nodes, node_count, is_avl;

    postorder_list = handle_postorder_list_input(&num_nodes);
    inorder_list = sort_list(postorder_list, num_nodes);

    print_list(postorder_list, num_nodes);
    print_list(inorder_list, num_nodes);

    root = decode_tree(postorder_list, inorder_list, num_nodes);
    print_tree(root, 0, 'c');

    test_list = (int *) malloc(sizeof(int) * num_nodes);
    node_count = 0;
    tranversal_postorder_tree(root, test_list, &node_count);
    print_list(test_list, num_nodes);

    node_count = 0;
    tranversal_inorder_tree(root, test_list, &node_count);
    print_list(test_list, num_nodes);

    is_avl = check_if_avl(root);
    if (is_avl) {
        printf("El Árbol es AVL\n");
    } else {
        printf("El Árbol NO es AVL\n");
    }

    return 0;
}
