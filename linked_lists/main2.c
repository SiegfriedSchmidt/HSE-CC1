//  
// 20.04.2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doubly_linked_list.h"

int main(void) {
    char string[1024];
    fgets(string, 1024, stdin);
    unsigned long len = strlen(string);
    if (string[len - 2] == '.') {
        string[len - 2] = '\0';
    } else {
        fprintf(stderr, "Dot not exist!");
        exit(139);
    }
    len = len - 2;

    StringNode* string_list = create_node(NULL);
    StringNode* head = string_list;
    for (long i = 0; i < len; ++i) {
        long idx = 0;
        while (i < len && string[i] != ' ') {
            head->str[idx++] = string[i];
            ++i;
        }

        if (i < len) {
            head = create_node(head);
        }
    }

    print_list(string_list);
    delete_word(string_list);
    print_list(string_list);
    free_list(string_list);
    return 0;
}
