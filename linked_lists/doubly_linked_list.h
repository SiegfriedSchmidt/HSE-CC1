//  
// 20.04.2025

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#define STRWORDLEN 64

typedef struct StringNode {
    char str[STRWORDLEN];
    struct StringNode* next;
    struct StringNode* prev;
} StringNode;

StringNode* create_node(StringNode*);
void print_list(StringNode*);
void free_list(StringNode*);
StringNode* delete_element(StringNode*);
void delete_word(StringNode*);

#endif //DOUBLY_LINKED_LIST_H
