#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    int n; // Array length
    int min_val; // minimal value
    printf("Input array length: ");
    scanf("%d", &n);
    printf("Input minimum value: ");
    scanf("%d", &min_val);

    int *array = create_array(n);
    fill_array(array, n);
    array = modify_array(array, &n, min_val);
    print_array(array, n);

    free(array);

    return 0;
}

int *create_array(int n) {
    int *array = malloc(sizeof(int) * n);
    if (array == NULL) {
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(1);
    }
    return array;
}

void fill_array(int *array, int n) {
    printf("Input array: \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", array + i);
    }
}

void print_array(const int *array, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
}

int *delete_element(int *array, int *n, int idx) {
    if (idx < 0 || idx >= *n) return array;

    for (int i = idx + 1; i < *n; ++i) {
        array[i - 1] = array[i];
    }

    --*n;
    int *new_p = realloc(array, sizeof(int) * *n);

    if (new_p == NULL) {
        fprintf(stderr, "Cannot reallocate memory!\n");
        exit(1);
    }
    return new_p;
}

int *modify_array(int *array, int *n, int min_val) {
    for (int i = 1; i < *n - 1; ++i) {
        if (abs(array[i]) % 2 == 0 && abs(array[i]) < min_val) {
            array = delete_element(array, n, i);
            --i;
        }
    }
    return array;
}

/*
Input array length: 10
Input minimum value: 6
Input array:
2 4 2 -2 4 8 9 10 -4 4
*/
