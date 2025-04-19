// 
// 11.04.2025

#include "quick_sort.h"

#include <stdio.h>

void quick_sort(struct Record array[], const cmp_type cmp, const long l, const long r) {
    if (l >= r) return;

    const long p = l; // pivot
    long i = l + 1;
    long j = r - 1;
    while (i <= j) {
        while (i <= j && cmp(&array[p], &array[i])) {
            ++i;
        }
        while (i <= j && !cmp(&array[p], &array[j])) {
            --j;
        }
        if (i < j) {
            swap(&array[i], &array[j]);
            ++i;
            --j;
        }
    }
    swap(&array[p], &array[j]);

    quick_sort(array, cmp, l, j);
    quick_sort(array, cmp, j + 1, r);
}
