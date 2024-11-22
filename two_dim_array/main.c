#include <stdio.h>

#define n 5

void input_matrix(long arr[n][n]);

void print_matrix(long arr[n][n]);

void print_matrix_in_order(long arr[n][n]);

int main(void) {
    long arr[n][n];
    input_matrix(arr);
    print_matrix(arr);
    print_matrix_in_order(arr);
    return 0;
}

void input_matrix(long arr[n][n]) {
    printf("Input matrix:\n");
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            scanf("%ld", &arr[i][j]);
        }
    }
}

void print_matrix(long arr[n][n]) {
    printf("Matrix:\n");
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_in_order(long arr[n][n]) {
    long i = n - 1, j = n - 1;
    long direction = 0;
    long cnt = 0;

    long left = 0, up = 0, right = n - 1, down = n - 2;
    while (cnt < n * n) {
        printf("%ld ", arr[i][j]);

        if (j == left && direction == 0) {
            ++left;
            direction = (direction + 1) % 4;
        } else if (i == up && direction == 1) {
            ++up;
            direction = (direction + 1) % 4;
        } else if (j == right && direction == 2) {
            --right;
            direction = (direction + 1) % 4;
        } else if (i == down && direction == 3) {
            --down;
            direction = (direction + 1) % 4;
        }

        if (direction == 0) {
            --j;
        } else if (direction == 1) {
            --i;
        } else if (direction == 2) {
            ++j;
        } else if (direction == 3) {
            ++i;
        }

        ++cnt;
    }
}

/*
11 12 13 14 15
21 22 23 24 25
31 32 33 34 35
41 42 43 44 45
51 52 53 54 55
*/
