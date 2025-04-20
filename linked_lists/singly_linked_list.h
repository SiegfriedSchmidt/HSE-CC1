//  
// 20.04.2025

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct PolynomialNode {
    float coef;
    struct PolynomialNode* next;
} PolynomialNode;

PolynomialNode* create_node(PolynomialNode*);
PolynomialNode* create_anti_derivative(PolynomialNode*);

void print_list(PolynomialNode*);
void free_list(PolynomialNode*);
#endif //SINGLY_LINKED_LIST_H
