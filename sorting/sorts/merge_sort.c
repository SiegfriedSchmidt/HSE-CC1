// 
// 11.04.2025

#include "merge_sort.h"

#include <stdlib.h>

void merge_sort(struct Record array[], const cmp_type cmp, const long l, const long r) {
    if (l + 1 == r) {
        return;
    }
    const long middle = (l + r) / 2;
    merge_sort(array, cmp, l, middle);
    merge_sort(array, cmp, middle, r);
    long i1 = l;
    long i2 = middle;
    long i3 = 0;
    struct Record *tmp = malloc(sizeof(struct Record) * (r - l));
    while (i3 < r - l) {
        if (i2 < r && cmp(&array[i1], &array[i2]) || i1 == middle) {
            tmp[i3] = array[i2];
            ++i2;
            ++i3;
        } else {
            tmp[i3] = array[i1];
            ++i1;
            ++i3;
        }
    }
    for (int i = 0; i < r - l; ++i) {
        array[l + i] = tmp[i];
    }
    free(tmp);
}
