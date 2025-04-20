//  
// 20.04.2025

#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PolynomialNode* create_node(PolynomialNode* old_node) {
    PolynomialNode* new_node = malloc(sizeof(struct PolynomialNode));
    if (old_node) {
        old_node->next = new_node;
    }
    new_node->next = NULL;
    return new_node;
}

void print_list(PolynomialNode* head) {
    char result[1024] = "";
    long power = 0;
    int first = 1;
    while (head) {
        if (head->coef) {
            char string_coef[32] = "";
            if (first) {
                first = 0;
                if (power == 0) {
                    sprintf(string_coef, "%0.2f", head->coef);
                } else if (power == 1) {
                    sprintf(string_coef, "%0.2fx", head->coef);
                } else {
                    sprintf(string_coef, "%0.2fx^%ld", head->coef, power);
                }
            } else {
                if (head->coef > 0) {
                    if (power == 0) {
                        sprintf(string_coef, "+%0.2f", head->coef);
                    } else if (power == 1) {
                        sprintf(string_coef, "+%0.2fx", head->coef);
                    } else {
                        sprintf(string_coef, "+%0.2fx^%ld", head->coef, power);
                    }
                } else {
                    if (power == 0) {
                        sprintf(string_coef, "%0.2f", head->coef);
                    } else if (power == 1) {
                        sprintf(string_coef, "%0.2fx", head->coef);
                    } else {
                        sprintf(string_coef, "%0.2fx^%ld", head->coef, power);
                    }
                }
            }
            strcat(result, string_coef);
        }
        ++power;
        head = head->next;
    }
    printf("%s\n", result);
}

PolynomialNode* create_anti_derivative(PolynomialNode* head) {
    PolynomialNode* new_list = create_node(NULL);
    PolynomialNode* new_head = new_list;
    new_head->coef = 0;
    long power = 0;
    while (head) {
        new_head = create_node(new_head);
        new_head->coef = head->coef / (float)(power + 1);
        ++power;
        head = head->next;
    }
    return new_list;
}

void free_list(PolynomialNode* head) {
    while (head) {
        PolynomialNode* old_head = head;
        head = old_head->next;
        free(old_head);
    }
}
