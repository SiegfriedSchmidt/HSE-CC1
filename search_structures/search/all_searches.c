// 
// 25.04.2025

#include "all_searches.h"

#include <stdio.h>

#include "../generate.h"
#include <string.h>
#include <stdlib.h>

#include "binary_search.h"
#include "linear_search.h"
#include "red_black_search.h"

const char *options[] = {
    "linear_search", "binary_search", "red_black_search"
};

PreparedData generate_prepared_data(const long size) {
    Record *records = malloc(sizeof(Record) * size);

    Node *root = NULL;
    for (int record_idx = 0; record_idx < size; ++record_idx) {
        records[record_idx] = generate_record();
        insert(&root, &records[record_idx]);
    }

    Record *sorted_records = malloc(sizeof(Record) * size);
    memcpy(sorted_records, records, sizeof(Record) * size);
    qsort(sorted_records, size, sizeof(Record), cmp_ascending);

    return (PreparedData){size, records, sorted_records, root};
}

Record search(const PreparedData prepared_data, char *key, const long option) {
    if (option == 0) {
        return linear_search(prepared_data.records, key, prepared_data.size);
    }
    if (option == 1) {
        return binary_search(prepared_data.sorted_records, key, prepared_data.size);
    }
    if (option == 2) {
        return red_black_search(prepared_data.root, key);
    }
    fprintf(stderr, "Unrecognized option %ld!", option);
    exit(0);
}

void free_prepared_data(const PreparedData prepared_data) {
    free(prepared_data.records);
    free(prepared_data.sorted_records);
    free_tree(prepared_data.root);
}
