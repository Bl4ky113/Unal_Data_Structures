
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_data_type tree_data_type;
typedef struct tree_key_type tree_key_type;
typedef struct tree_node {
    tree_data_type *value;
    tree_key_type *key;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

int compare_tree_key (tree_key_type *key1, tree_key_type *key2);

tree_node *create_tree () {
    tree_node *new_tree = (tree_node *) malloc(sizeof(tree_node));
    new_tree->key = NULL;
    new_tree->value = NULL;
    new_tree->left = NULL;
    new_tree->right = NULL;

    return new_tree;
}

int is_tree_empty (tree_node *root) {
    if (root->left == NULL && root->right == NULL && root->value == NULL) {
        return 1;
    }

    return 0;
}

int insert_tree (tree_node *root, tree_key_type *insert_key, tree_data_type *insert_value) {
    if (is_tree_empty(root)) {
        root->value = insert_value;
        root->key = insert_key;

        return 0;
    }

    tree_node *prev_node, *current_node, *new_node;
    current_node = root;

    while (current_node != NULL) {
        prev_node = current_node;
        if (compare_tree_key(insert_key, current_node->key) == -1) {
            current_node = current_node->left;
        } else if (compare_tree_key(insert_key, current_node->key) == 1) {
            current_node = current_node->right;
        } else {
            return -1;
        }
    }

    if (compare_tree_key(insert_key, prev_node->key) == 0) {
        return -1; /* Key already on tree. Returning error */
    }
    
    new_node = (tree_node *) malloc(sizeof(tree_node));
    new_node->key = insert_key;
    new_node->value = insert_value;
    new_node->left = NULL;
    new_node->right = NULL;
    
    if (compare_tree_key(insert_key, prev_node->key) == -1) { 
        prev_node->left = new_node;
    } else {
        prev_node->right = new_node;
    }

    return 0;
}

tree_data_type *search_tree (tree_node *root, tree_key_type *query_key) {
    if (is_tree_empty(root)) {
        return NULL;
    }

    tree_node *prev_node, *current_node;
    current_node = root;

    while (current_node != NULL) {
        prev_node = current_node;
        if (compare_tree_key(query_key, current_node->key) == -1) {
            current_node = current_node->left;
        } else if (compare_tree_key(query_key, current_node->key) == 1) {
            current_node = current_node->right;
        } else {
            return current_node->value;
        }
    }

    if (compare_tree_key(query_key, prev_node->key) == 0) {
        return prev_node->value;
    }

    return NULL;
}

/* base_node might not be root */
tree_node *node_predecessor_tree (tree_node *base_node) {
    tree_node *prev_node, *current_node;
    
    current_node = base_node->left;
    prev_node = current_node;
    while (current_node != NULL) {
        prev_node = current_node;
        current_node = current_node->right;
    }

    return prev_node; /* might be null */
}

tree_node *key_predecessor_tree (tree_node *root, tree_key_type *query_key) {
    tree_node *current_node;

    current_node = root;

    while (current_node != NULL) {
        if (compare_tree_key(query_key, current_node->key) == -1) {
            current_node = current_node->left;
        } else if (compare_tree_key(query_key, current_node->key) == 1) {
            current_node = current_node->right;
        } else {
            break;
        }
    }

    if (compare_tree_key(query_key, current_node->key) != 0) {
        return NULL;
    }

    return node_predecessor_tree(current_node);
}

/* base_node might not be root */
tree_node *node_successor_tree (tree_node *base_node) {
    tree_node *prev_node, *current_node;
    
    current_node = base_node->right;
    prev_node = current_node;
    while (current_node != NULL) {
        prev_node = current_node;
        current_node = current_node->left;
    }

    return prev_node; /* might be null */
}

tree_node *key_successor_tree (tree_node *root, tree_key_type *query_key) {
    tree_node *current_node;

    current_node = root;

    while (current_node != NULL) {
        if (compare_tree_key(query_key, current_node->key) == -1) {
            current_node = current_node->left;
        } else if (compare_tree_key(query_key, current_node->key) == 1) {
            current_node = current_node->right;
        } else {
            break;
        }
    }

    if (compare_tree_key(query_key, current_node->key) == 0) {
        return NULL;
    }

    return node_successor_tree(current_node);
}

tree_data_type *delete_tree (tree_node *root, tree_key_type *query_key) {
    tree_node *prev_node, *current_node;
    tree_data_type *deleted_value;
    int previous_movement;

    current_node = root;
    prev_node = current_node;
    previous_movement = 0;
    while (current_node->left != NULL || current_node->right != NULL) {
        if (compare_tree_key(query_key, current_node->key) == -1) {
            prev_node = current_node;
            current_node = current_node->left;
            previous_movement = -1;
        } else if (compare_tree_key(query_key, current_node->key) == 1) {
            prev_node = current_node;
            current_node = current_node->right;
            previous_movement = 1;
        } else {
            break;
        }
    }
    
    if (compare_tree_key(query_key, current_node->key) != 0) {
        return NULL; /* key doesn't exist */
    }

    /* Deleting a leaf */
    if (current_node->left == NULL && current_node->right == NULL) {
        if (previous_movement > 0) {
            prev_node->right = NULL;
        } else {
            prev_node->left = NULL;
        }
    } else if (current_node->left != NULL && current_node->right == NULL) { 
        /* not a leaf, only left child */
        if (previous_movement > 0) {
            prev_node->right = current_node->left;
        } else {
            prev_node->left = current_node->left;
        }
    } else if (current_node->right != NULL && current_node->left == NULL) {
        /* not a leaf, only right child */
        if (previous_movement > 0) {
            prev_node->right = current_node->right;
        } else {
            prev_node->left = current_node->right;
        }
    } else {
        /* not a leaf, both childs, might be root */
        tree_node *succesor_node, *replacement_node;
        succesor_node = node_successor_tree(current_node);

        replacement_node = (tree_node *) malloc(sizeof(tree_node));
        replacement_node->key = succesor_node->key;
        replacement_node->value = succesor_node->value;

        delete_tree(root, succesor_node->key);

        replacement_node->left = current_node->left;
        replacement_node->right = current_node->right;

        if (previous_movement > 0) {
            prev_node->right = replacement_node;
        } else {
            prev_node->left = replacement_node;
        }
    }

    deleted_value = current_node->value;
    free(current_node);
    return deleted_value;
}

/* base_node might not be root */
void count_nodes_tree (tree_node *base_node, int *num_nodes) { 
    tree_node *current_node;

    /* left side */
    current_node = base_node->left;
    while (current_node != NULL) {
        if (current_node->right != NULL) {
            count_nodes_tree(current_node->right, num_nodes);
        }
        
        current_node = current_node->left;
        ++(*num_nodes);
    }

    /* right side */
    current_node = base_node->right;
    while (current_node != NULL) {
        if (current_node->left != NULL) {
            count_nodes_tree(current_node->left, num_nodes);
        }
        
        current_node = current_node->right;
        ++(*num_nodes);
    }

    ++(*num_nodes); /* The base_node */
    return;
}

/* base_node might not be root */
int greater_left_depth (tree_node *base_node) {
    tree_node *current_node;
    int left_depth, recursive_left_depth;

    current_node = base_node;
    left_depth = 0;
    recursive_left_depth = 0;

    while (current_node != NULL) {
        if (current_node->right != NULL) {
            recursive_left_depth = greater_left_depth(current_node->right);
        }
        current_node = current_node->left;

        ++left_depth;
    }

    if (recursive_left_depth > left_depth) {
        return recursive_left_depth;
    }

    return left_depth;
}

/* base_node might not be root */
int greater_right_depth (tree_node *base_node) {
    tree_node *current_node;
    int right_depth, recursive_right_depth;

    current_node = base_node;
    right_depth = 0;
    recursive_right_depth = 0;

    while (current_node != NULL) {
        if (current_node->left != NULL) {
            recursive_right_depth = greater_right_depth(current_node->left);
        }
        current_node = current_node->right;

        ++right_depth;
    }

    if (recursive_right_depth > right_depth) {
        return recursive_right_depth;
    }

    return right_depth;
}

/* base_node might not be root */
int height_tree (tree_node *base_node) {
    if (base_node == NULL) {
        return -1;
    }

    int left_height, right_height;

    left_height = height_tree(base_node->left);
    right_height = height_tree(base_node->right);

    if (left_height < right_height) {
        return right_height + 1;
    } 

    return left_height + 1;
}

void print_tree_ptr_recursive (tree_node *base_node, int current_depth) {
    if (is_tree_empty(base_node)) {
        return;
    } else if (base_node == NULL) {
        return;
    }

    int i = 1;
    if (current_depth > 0) {
        printf("|");
        for (; i < current_depth; i++) {
            printf("\t|");
        }
        printf("\t");
    }

    printf("(");
    printf("%p", base_node->key);
    printf("):");
    printf("(");
    printf("%p", base_node->value);
    printf(")\n");

    if (base_node->left != NULL) {
        print_tree_ptr_recursive(base_node->left, ++current_depth);
        --current_depth;
    }

    if (base_node->right != NULL) {
        print_tree_ptr_recursive(base_node->right, ++current_depth);
    }

    return;
}

void print_tree_ptr (tree_node *root) {
    int placeholder = 0;
    print_tree_ptr_recursive(root, placeholder);
    return;
}
