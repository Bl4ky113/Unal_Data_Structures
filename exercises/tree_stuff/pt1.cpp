
#include<iostream>
#include<stack>

using namespace std; 

class AVLTree {
    public:
        struct tree_node {
            int key;
            int value;
            int height;
    
            struct tree_node *left;
            struct tree_node *right;
        };
    
        int height;
        int nodes;

        AVLTree () {
            height = 0;
            nodes = 0;
        }

        int insert(int new_key, int new_value);
        tree_node *get(int key);
        int remove(int key);
        void print();

        tree_node *first();
        tree_node *last();

        tree_node *poll_first();
        tree_node *poll_last();

        tree_node *floor (int input_key);
        tree_node *ceiling (int input_key);

    protected:
        tree_node *root = NULL;

        void rotate_left(tree_node *node);
        void rotate_right(tree_node *node);

        void print_recursive(tree_node *node, int current_depth);

        int get_node_height(tree_node *node);
        void update_node_height(tree_node *node);

        tree_node *node_successor(tree_node *node);
};

void AVLTree::rotate_left (AVLTree::tree_node *node) {
    AVLTree::tree_node *tmp_node;
    int tmp_key;

    tmp_node = node->left;
    tmp_key = node->key;

    node->left = node->right;
    node->key = node->right->key;

    node->right = node->left->right;
    node->left->right = node->left->left;

    node->left->left = tmp_node;
    node->left->key = tmp_key;
}

void AVLTree::rotate_right (AVLTree::tree_node *node) {
    AVLTree::tree_node *tmp_node;
    int tmp_key;

    tmp_node = node->right;
    tmp_key = node->key;

    node->right = node->left;
    node->key = node->left->key;

    node->left = node->right->left;
    node->right->left = node->right->right;

    node->right->right = tmp_node;
    node->right->key = tmp_key;
}

int AVLTree::get_node_height (AVLTree::tree_node *node) {
    if (node != NULL) {
        return node->height;
    }

    return -1;
}

void AVLTree::update_node_height (AVLTree::tree_node *node) {
    int left_height, right_height;

    left_height = get_node_height(node->left);
    right_height = get_node_height(node->right);
    
    if (left_height > right_height) {
        node->height = left_height + 1;
    } else {
        node->height = right_height + 1;
    }

    return;
}

AVLTree::tree_node *AVLTree::node_successor (AVLTree::tree_node *node) {
    tree_node *current_node, *tmp_node;

    tmp_node = node->right;
    while (tmp_node != NULL) {
        current_node = tmp_node;
        tmp_node = tmp_node->left;
    }

    return current_node;
}

int AVLTree::insert (int new_key, int new_value) {
    // Create New Node
    tree_node *new_node = new AVLTree::tree_node;
    new_node->height = 0;
    new_node->key = new_key;
    new_node->value = new_value;

    // Trivial case, insert in root
    if (height == 0 && root == NULL) {
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
        return 0;
    }

    // Search path for insert
    stack<tree_node *> insert_path;
    tree_node *current_node, *tmp_node;
    tmp_node = root;
    while (tmp_node != NULL) {
        insert_path.push(tmp_node);
        current_node = tmp_node;

        if (tmp_node->key < new_key) {
            tmp_node = tmp_node->left;
        } else if (tmp_node->key > new_key) {
            tmp_node = tmp_node->right;
        } else {
            break;
        }
    }

    if (current_node->key == new_key) {
        return -1;
    } else if ( current_node->key < new_key ) {
        new_node->left = current_node->left;
        current_node->left = new_node;
    } else {
        new_node->right = current_node->right;
        current_node->right = new_node;
    }

    int balancing_done = 0;
    while (!balancing_done && !insert_path.empty()) {
        int old_height;
        
        current_node = insert_path.top();
        insert_path.pop();
        old_height = get_node_height(current_node);

        if (get_node_height(current_node->left) - get_node_height(current_node->right) == 2) {
            if (get_node_height(current_node->left->left) - get_node_height(current_node->left->right) == 1) {
                rotate_right(current_node);

                update_node_height(current_node->right);
                update_node_height(current_node);
            } else {
                rotate_left(current_node->left);
                rotate_right(current_node);

                update_node_height(current_node->left);
                update_node_height(current_node->right);
                update_node_height(current_node);
            }
        } else if (get_node_height(current_node->left) - get_node_height(current_node->right) == -2) {
            if (get_node_height(current_node->right->right) - get_node_height(current_node->right->left) == 1) {
                rotate_left(current_node);

                update_node_height(current_node->left);
                update_node_height(current_node);
            } else {
                rotate_right(current_node->right);
                rotate_left(current_node);
                
                update_node_height(current_node->left);
                update_node_height(current_node->right);
                update_node_height(current_node);
            }
        } else {
            update_node_height(current_node);

            if (get_node_height(current_node) == old_height) {
                balancing_done = 1;
            }
        }
    }
    
    ++nodes;
    height = get_node_height(root);
    return 0;
}

int AVLTree::remove (int delete_key) {
    if (height == 0 || root == NULL) {
        return -1;
    } else if (root->key == delete_key) {
        tree_node *succesor_node, *replacement_node;
        succesor_node = node_successor(root);

        replacement_node = new AVLTree::tree_node;
        replacement_node->key = succesor_node->key;
        replacement_node->value = succesor_node->value;

        remove(succesor_node->key);

        replacement_node->left = root->left;
        replacement_node->right = root->right;
        
        delete root;
        root = replacement_node;

        return 0;
    }

    tree_node *delete_node, *current_node, *prev_node, *tmp_node;
    stack<tree_node *> delete_path;
    int prev_movement, balancing_done;

    tmp_node = root;
    delete_node = root;

    while (tmp_node != NULL) {
        delete_path.push(delete_node);
        delete_node = tmp_node;

        if (tmp_node->key < delete_key) {
            tmp_node = tmp_node->left;
            prev_movement = -1;
        } else if (tmp_node->key > delete_key) {
            tmp_node = tmp_node->right;
            prev_movement = 1;
        } else {
            break;
        }
    }

    if (delete_node->key != delete_key) {
        return -1;
    }

    prev_node = delete_path.top();

    if (delete_node->right == NULL && delete_node->left == NULL) { // Deleting leaf
        if (prev_movement > 0) {
            prev_node->right = NULL;
        } else {
            prev_node->left = NULL;
        }                                        
    } else if (delete_node->right == NULL && delete_node->left != NULL) { // Deleting with left child
        if (prev_movement > 0) {
            prev_node->right = delete_node->left;
        } else {
            prev_node->left = delete_node->left;
        }                                        
    } else if (delete_node->left == NULL && delete_node->right != NULL) { // Deleting with right child
        if (prev_movement > 0) {
            prev_node->right = delete_node->right;
        } else {
            prev_node->left = delete_node->right;
        }                                        
    } else { // Deleting with both childs
        tree_node *succesor_node, *replacement_node;
        succesor_node = node_successor(delete_node);

        replacement_node = new AVLTree::tree_node;
        replacement_node->key = succesor_node->key;
        replacement_node->value = succesor_node->value;

        remove(succesor_node->key);

        replacement_node->left = delete_node->left;
        replacement_node->right = delete_node->right;

        if (prev_movement > 0) {
            prev_node->right = replacement_node;
        } else {
            prev_node->left = replacement_node;
        }
    }

    delete delete_node;

    balancing_done = 0;
    while (!balancing_done && !delete_path.empty()) {
        int old_height;
        
        current_node = delete_path.top();
        delete_path.pop();
        old_height = get_node_height(current_node);

        if (get_node_height(current_node->left) - get_node_height(current_node->right) == 2) {
            if (get_node_height(current_node->left->left) - get_node_height(current_node->left->right) == 1) {
                rotate_right(current_node);

                update_node_height(current_node->right);
                update_node_height(current_node);
            } else {
                rotate_left(current_node->left);
                rotate_right(current_node);

                update_node_height(current_node->left);
                update_node_height(current_node->right);
                update_node_height(current_node);
            }
        } else if (get_node_height(current_node->left) - get_node_height(current_node->right) == -2) {
            if (get_node_height(current_node->right->right) - get_node_height(current_node->right->left) == 1) {
                rotate_left(current_node);

                update_node_height(current_node->left);
                update_node_height(current_node);
            } else {
                rotate_right(current_node->right);
                rotate_left(current_node);
                
                update_node_height(current_node->left);
                update_node_height(current_node->right);
                update_node_height(current_node);
            }
        } else {
            update_node_height(current_node);

            if (get_node_height(current_node) == old_height) {
                balancing_done = 1;
            }
        }
    }

    --nodes;
    height = get_node_height(root);
    return 0;
}

AVLTree::tree_node *AVLTree::first () {
    AVLTree::tree_node *current_node, *tmp_node;
    
    tmp_node = root;
    while (tmp_node != NULL) {
        current_node = tmp_node;
        
        tmp_node = tmp_node->left;
    }
    
    return current_node;
}

AVLTree::tree_node *AVLTree::last () {
    AVLTree::tree_node *current_node, *tmp_node;
    
    tmp_node = root;
    while (tmp_node != NULL) {
        current_node = tmp_node;
        
        tmp_node = tmp_node->right;
    }
    
    return current_node;
}

AVLTree::tree_node *AVLTree::floor (int input_key) {
    AVLTree::tree_node *current_node, *tmp_node;
    
    tmp_node = root;
    while (tmp_node != NULL) {
        if (tmp_node->key < input_key) {
            current_node = tmp_node;
            tmp_node = tmp_node->left;
        } else if (tmp_node->key > input_key) {
            tmp_node = tmp_node->right;
        } else {
            break;
        }
    }
    
    return current_node;
}

AVLTree::tree_node *AVLTree::ceiling (int input_key) {
    AVLTree::tree_node *current_node, *tmp_node;
    
    tmp_node = root;
    while (tmp_node != NULL) {
        if (tmp_node->key < input_key) {
            tmp_node = tmp_node->left;
        } else if (tmp_node->key > input_key) {
            current_node = tmp_node;
            tmp_node = tmp_node->right;
        } else {
            break;
        }
    }
    
    return current_node;
}

void AVLTree::print () {
    int depth = 0;
    print_recursive(root, depth);
    return;
}

void AVLTree::print_recursive (tree_node *node, int current_depth) {
    if (nodes == 0) {
        return;
    } else if (node == NULL) {
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
    printf("%d", node->key);
    printf("):");
    printf("(");
    printf("%d", node->value);
    printf(");%d\n", node->height);

    if (node->right != NULL) {
        print_recursive(node->right, current_depth + 1);
    }

    if (node->left != NULL) {
        print_recursive(node->left, current_depth + 1);
    }

    return;
}

int main (int args, char **vargs) {
    AVLTree *foo = new AVLTree();
    int bar;
    AVLTree::tree_node *bar_2;
    bar = foo->insert(11, -10);
    bar = foo->insert(71, -10);
    bar = foo->insert(18, -10);
    bar = foo->insert(12, -10);
    bar = foo->insert(61, -10);
    bar = foo->insert(31, -10);
    bar = foo->insert(15, -10);
    bar = foo->insert(91, -10);
    bar = foo->insert(10, -10);
    bar = foo->insert(1, -10);
    bar = foo->insert(7, -10);
    bar = foo->insert(8, -10);
    bar = foo->insert(2, -10);
    bar = foo->insert(6, -10);
    bar = foo->insert(3, -10);
    bar = foo->insert(5, -10);
    bar = foo->insert(9, -10);
    bar = foo->insert(-1, -10);
    bar = foo->insert(-2, -10);
    bar = foo->insert(-3, -10);
    foo->print();
    cout << bar << "\n";
    cout << foo->height << " " << foo->nodes << "\n";
    bar_2 = foo->first();
    cout << bar_2->key << " " << bar_2->value << "\n";
    bar_2 = foo->last();
    cout << bar_2->key << " " << bar_2->value << "\n";
    bar_2 = foo->floor(32);
    cout << bar_2->key << " " << bar_2->value << "\n";    
    bar_2 = foo->ceiling(32);
    cout << bar_2->key << " " << bar_2->value << "\n";
    bar = foo->remove(2);
    cout << bar << "\t";
    bar = foo->remove(6);
    cout << bar << "\t";
    bar = foo->remove(3);
    cout << bar << "\t";
    bar = foo->remove(31);
    cout << bar << "\n";
    foo->print();
    return 0;
}
