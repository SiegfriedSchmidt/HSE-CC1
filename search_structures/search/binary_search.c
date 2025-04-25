// 
// 24.04.2025

#include "binary_search.h"

#include <stdio.h>
#include <string.h>

Record binary_search(Record sorted_array[], char *key, long size) {
    long l = -1;
    long r = size - 1;
    while (l + 1 < r) {
        long mid = (l + r) / 2;
        if (strcmp(sorted_array[mid].name, key) < 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (strcmp(sorted_array[r].name, key) != 0) {
        return (Record){};
    }
    return sorted_array[r];
}
