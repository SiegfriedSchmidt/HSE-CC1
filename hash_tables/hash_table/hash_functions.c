//  
// 06.06.2025

#include "hash_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* options[] = {
    "hash_1", "hash_2", "hash_3", "hash_4"
};

hash_type hash_1(const char* data) {
    unsigned long long hash = 5381;
    char c;

    while ((c = *data++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

// hash_type hash_1(const char* data) {
//     hash_type hash = 0;
//     while (*data) {
//         hash ^= *data++;
//     }
//     return hash;
// }


hash_type hash_2(const char* data) {
    unsigned long long hash = 0;
    char c;

    while ((c = *data++)) {
        hash ^= c;
        hash *= 0x5bd1e995;
        hash ^= hash >> 15;
    }

    return hash;
}

// hash_type hash_2(const char* data) {
//     hash_type hash = 2166136261u;
//     while (*data) {
//         hash ^= *data++;
//         hash *= 16777619u;
//     }
//     return hash;
// }


hash_type hash_3(const char* data) {
    unsigned long long hash = 2166136261u; // FNV_offset_basis
    char c;

    while ((c = *data++)) {
        hash ^= c;
        hash *= 16777619u; // FNV_prime
    }

    return hash;
}
//
// hash_type hash_3(const char* data) {
//     unsigned long long hash = 0;
//     char c;
//
//     while ((c = *data++)) {
//         hash += c;
//         hash *= 0x5bd1e995;
//     }
//
//     return hash;
// }


hash_type hash_4(const char* data) {
    return 1ull;
}

hash_func_type get_hash_func(const long option) {
    if (option == 0) {
        return hash_1;
    }
    if (option == 1) {
        return hash_2;
    }
    if (option == 2) {
        return hash_3;
    }
    if (option == 3) {
        return hash_4;
    }
    fprintf(stderr, "Unrecognized option %ld!", option);
    exit(0);
}
