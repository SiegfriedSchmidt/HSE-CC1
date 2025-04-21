//  
// 20.04.2025

#include "doubly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

StringNode* create_node(StringNode* old_node) {
    StringNode* new_node = malloc(sizeof(StringNode));
    if (old_node) {
        old_node->next = new_node;
    }
    new_node->prev = old_node;
    new_node->next = NULL;
    return new_node;
}

void print_list(StringNode* head) {
    while (head) {
        printf("%s ", head->str);
        head = head->next;
    }
}

void free_list(StringNode* head) {
    while (head) {
        StringNode* old_head = head;
        head = old_head->next;
        free(old_head);
    }
}
