//  
// 20.04.2025

#include "doubly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n");
}

void free_list(StringNode* head) {
    while (head) {
        StringNode* old_head = head;
        head = old_head->next;
        free(old_head);
    }
}

StringNode* delete_element(StringNode* node) {
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }

    StringNode* next_node = node->next;
    free(node);
    return next_node;
}

void delete_word(StringNode* node) {
    const char* to_delete = node->str;
    node = node->next;
    while (node) {
        if (strcmp(to_delete, node->str) == 0) {
            node = delete_element(node);
        } else {
            node = node->next;
        }
    }
}
