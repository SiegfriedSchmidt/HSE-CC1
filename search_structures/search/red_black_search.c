// 
// 24.04.2025

#include "red_black_search.h"

#include <stdlib.h>
#include <string.h>

#include "../display.h"

Node *create_node(Record *record) {
    Node *newNode = malloc(sizeof(Node));
    newNode->record = record;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void rotate_left(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rotate_right(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void fix_violation(Node **root, Node *z) {
    while (z != *root && z->parent->color == RED) {
        Node *grandparent = z->parent->parent;

        if (z->parent == grandparent->left) {
            Node *uncle = grandparent->right;

            // red uncle
            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                // uncle black and z right child
                if (z == z->parent->right) {
                    z = z->parent;
                    rotate_left(root, z);
                }

                // uncle black and z left child
                z->parent->color = BLACK;
                grandparent->color = RED;
                rotate_right(root, grandparent);
            }
        } else {
            Node *uncle = grandparent->left;

            // uncle red
            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                // uncle black and z left child
                if (z == z->parent->left) {
                    z = z->parent;
                    rotate_right(root, z);
                }

                // uncle black and z right child
                z->parent->color = BLACK;
                grandparent->color = RED;
                rotate_left(root, grandparent);
            }
        }
    }

    (*root)->color = BLACK;
}

void insert(Node **root, Record *record) {
    Node *z = create_node(record);
    Node *y = NULL;
    Node *x = *root;

    // binary search
    while (x != NULL) {
        y = x;
        if (strcmp(record->name, x->record->name) < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NULL) {
        *root = z;
    } else if (strcmp(record->name, y->record->name) < 0) {
        y->left = z;
    } else {
        y->right = z;
    }

    fix_violation(root, z);
}

void tree_inorder_pass(Node *root) {
    if (root == NULL) return;
    tree_inorder_pass(root->left);
    print_record_data(root->record, -1);
    tree_inorder_pass(root->right);
}

Record red_black_search(Node *root, char *key) {
    Node *current = root;
    while (current != NULL) {
        const int cmp = strcmp(key, current->record->name);
        if (cmp == 0) {
            return *current->record;
        }
        if (cmp < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return (Record){};
}

void free_tree(Node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
