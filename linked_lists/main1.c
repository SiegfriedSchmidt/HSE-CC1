#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"

int main(void) {
    printf("Choose max power: ");
    long max_power = 0;
    scanf("%ld", &max_power);

    PolynomialNode* linked_list_head = create_node(NULL);
    PolynomialNode* head = linked_list_head;
    for (long i = 0; i < max_power + 1; ++i) {
        printf("Coefficient with power %ld: ", i);
        scanf("%f", &head->coef);
        if (i < max_power) {
            head = create_node(head);
        }
    }
    PolynomialNode* anti_derivative_list = create_anti_derivative(linked_list_head);
    print_list(linked_list_head);
    print_list(anti_derivative_list);

    free_list(linked_list_head);
    free_list(anti_derivative_list);
    return 0;
}
