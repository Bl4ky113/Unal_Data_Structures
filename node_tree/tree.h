
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stack.h>

#ifdef TREE_DATA_TYPE
typedef TREE_DATA_TYPE tree_data_type;
#else
typedef struct tree_data_type tree_data_type;
#endif /* TREE_DATA_TYPE */

#ifdef TREE_KEY_TYPE
typedef TREE_KEY_TYPE tree_key_type;
#else
typedef struct tree_key_type tree_key_type;
#endif /* TREE_KEY_TYPE */

typedef struct tree_node {   
    tree_data_type *value;
    /*tree_key_type *key;*/
    tree_key_type key;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;
extern tree_node *create_tree ();
extern int is_tree_empty (tree_node *root);
extern int insert_tree (tree_node *root, tree_key_type insert_key, tree_data_type *insert_value);
extern tree_data_type *search_tree (tree_node *root, int query_key);
extern tree_node *node_predecessor_tree (tree_node *base_node);
extern tree_node *key_predecessor_tree (tree_node *root, int query_key);
extern tree_node *node_successor_tree (tree_node *base_node);
extern tree_node *key_successor_tree (tree_node *root, int query_key);
extern tree_data_type *delete_tree (tree_node *root, int query_key);
extern void count_nodes_tree (tree_node *root, int *node_count);
extern int greater_left_depth (tree_node *base_node);
extern int greater_right_depth (tree_node *base_node);
extern int height_tree (tree_node *base_node);
extern void print_tree_ptr (tree_node *root);

#ifdef TREE_DATA_FORMAT
#ifdef TREE_DATA_TYPE
#ifdef TREE_KEY_FORMAT
#ifdef TREE_KEY_TYPE

extern void print_tree (tree_node *root);

#endif /* TREE_KEY_TYPE */
#endif /* TREE_KEY_FORMAT */
#endif /* TREE_DATA_TYPE */
#endif /* TREE_DATA_FORMAT */

#endif /* _TREE_H_*/
