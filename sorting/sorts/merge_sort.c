// 
// 11.04.2025

#include "merge_sort.h"

#include <stdio.h>

void sort(struct Record array[], long l, long r) {
    if (l + 1 == r) {
        return;
    }
    long middle = (l + r) / 2;
    sort(array, l, middle);
    sort(array, middle, r);
    long i1 = l;
    long i2 = middle;
    long i3 = 0;
    struct Record tmp[r - l];
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
}

void merge_sort(struct Record array[], long array_size, int descending) {
    sort(array, 0, array_size);
}
