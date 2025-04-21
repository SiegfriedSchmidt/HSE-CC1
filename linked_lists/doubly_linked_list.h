//  
// 20.04.2025

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct StringNode {
    char str[64];
    struct StringNode* next;
    struct StringNode* prev;
} StringNode;

StringNode* create_node(StringNode*);
void print_list(StringNode*);
void free_list(StringNode*);

#endif //DOUBLY_LINKED_LIST_H
