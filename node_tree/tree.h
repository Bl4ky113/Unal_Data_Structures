
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef TREE_DATA_TYPE
typedef TREE_DATA_TYPE tree_data_type;
#else
typedef struct tree_data_type tree_data_type;
#endif /* TREE_DATA_TYPE */

#ifdef TREE_KEY_TYPE
typedef TREE_KEY_TYPE tree_key_type;
#else

#define TREE_KEY_TYPE int
#define TREE_KEY_FORMAT "%d"
typedef int tree_key_type;

#endif /* TREE_KEY_TYPE */

typedef struct tree_node {   
    tree_data_type *value;
    tree_key_type *key;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;
extern tree_node *create_tree ();
extern int is_tree_empty (tree_node *root);
extern int insert_tree (tree_node *root, tree_key_type *insert_key, tree_data_type *insert_value);
extern tree_data_type *search_tree (tree_node *root, tree_key_type *query_key);
extern tree_node *node_predecessor_tree (tree_node *base_node);
extern tree_node *key_predecessor_tree (tree_node *root, tree_key_type *query_key);
extern tree_node *node_successor_tree (tree_node *base_node);
extern tree_node *key_successor_tree (tree_node *root, tree_key_type *query_key);
extern tree_data_type *delete_tree (tree_node *root, tree_key_type *query_key);
extern void count_nodes_tree (tree_node *root, int *node_count);
extern int greater_left_depth (tree_node *base_node);
extern int greater_right_depth (tree_node *base_node);
extern int height_tree (tree_node *base_node);
extern void print_tree_ptr (tree_node *root);

#ifdef TREE_DATA_FORMAT
#ifdef TREE_DATA_TYPE
#ifdef TREE_KEY_FORMAT
#ifdef TREE_KEY_TYPE

void print_tree_recursive (tree_node *base_node, int current_depth) {
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
    printf(TREE_KEY_FORMAT, *base_node->key);
    printf("):");
    printf("(");
    printf(TREE_DATA_FORMAT, *base_node->value);
    printf(")\n");


    if (base_node->left != NULL) {
        print_tree_recursive(base_node->left, ++current_depth);
        --current_depth;
    }

    if (base_node->right != NULL) {
        print_tree_recursive(base_node->right, ++current_depth);
    }

    return;
}

extern void print_tree (tree_node *root) {
    int placeholder = 0;
    print_tree_recursive(root, placeholder);
    return;
}

#endif /* TREE_KEY_TYPE */
#endif /* TREE_KEY_FORMAT */
#endif /* TREE_DATA_TYPE */
#endif /* TREE_DATA_FORMAT */

#endif /* _TREE_H_*/
