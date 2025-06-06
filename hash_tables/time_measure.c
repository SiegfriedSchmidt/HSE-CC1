// 
// 24.04.2025

#include "time_measure.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generate.h"
#include "record.h"
#include "hash_table/hash_functions.h"
#include "hash_table/hash_table.h"

#define SIZES_LEN 7
#define OPTIONS_LEN 3
#define SEARCHES_NUMBER 10000

const long sizes[7] = {1000, 10000, 50000, 100000, 200000, 500000, 1000000};

void time_measure(Result results[]) {
    printf("Start measure...\n");
    srand(time(NULL));

    for (int size_idx = 0; size_idx < SIZES_LEN; ++size_idx) {
        printf("Size %ld\n", sizes[size_idx]);

        const long size = sizes[size_idx];

        Record** records = malloc(sizeof(Record*) * size);
        for (int i = 0; i < size; i++) {
            records[i] = generate_record();
        }

        for (int option = 0; option < OPTIONS_LEN; ++option) {
            HashTable* hash_table = create_hash_table(size * 2, get_hash_func(option));
            for (int i = 0; i < size; i++) {
                hash_table_set(hash_table, records[i]->name, records[i]);
            }

            const clock_t start = clock();
            for (int i = 0; i < SEARCHES_NUMBER; ++i) {
                char *key = generate_record()->name;
                const Record* record = hash_table_get(hash_table, key);
            }
            const clock_t end = clock();
            const double seconds = (double) (end - start) / CLOCKS_PER_SEC;

            strcpy(results[option * SIZES_LEN + size_idx].name, options[option]);
            results[option * SIZES_LEN + size_idx].size = size;
            results[option * SIZES_LEN + size_idx].time = seconds;
            results[option * SIZES_LEN + size_idx].collisions = hash_table->collisions;
            destroy_hash_table(hash_table);
        }

        for (int i = 0; i < size; i++) {
            free(records[i]);
        }
        free(records);
    }
}
