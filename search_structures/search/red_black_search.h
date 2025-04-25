// 
// 24.04.2025

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include "../record.h"

typedef enum { RED, BLACK } Color;

typedef struct Node {
    Record *record;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node *create_node(Record *);

void rotate_left(Node **, Node *);

void rotate_right(Node **, Node *);

void fix_violation(Node **, Node *);

void insert(Node **, Record *);

void tree_inorder_pass(Node *);

Record red_black_search(Node *, char *);

void free_tree(Node *);
#endif //RED_BLACK_TREE_H
