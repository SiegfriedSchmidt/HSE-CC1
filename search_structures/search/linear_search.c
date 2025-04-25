// 
// 24.04.2025

#include "linear_search.h"

#include <string.h>

Record linear_search(Record array[], char *key, long size) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(array[i].name, key) == 0) {
            return array[i];
        }
    }
    return (Record){};
}
