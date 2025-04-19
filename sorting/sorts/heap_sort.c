// 
// 11.04.2025

#include "heap_sort.h"

void heapify(struct Record array[], const long n, const long i, const cmp_type cmp) {
    long largest = i;
    long left = 2 * i + 1;
    long right = 2 * i + 2;

    if (left < n && cmp(&array[largest], &array[left])) {
        largest = left;
    }

    if (right < n && cmp(&array[largest], &array[right])) {
        largest = right;
    }

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest, cmp);
    }
}

void build_max_heap(struct Record array[], const long n, const cmp_type cmp) {
    for (long i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i, cmp);
    }
}

void heap_sort(struct Record array[], const cmp_type cmp, const long l, const long r) {
    const long n = r - l;

    if (n <= 1) return;

    build_max_heap(array, n, cmp);

    for (long i = n - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0, cmp);
    }
}
