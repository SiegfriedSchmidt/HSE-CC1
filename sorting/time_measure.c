// 
// 19.04.2025

#include "time_measure.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generate.h"
#include "sorts/all_sorts.h"

#define SIZES_LEN 7
#define OPTIONS_LEN 3

const long sizes[SIZES_LEN] = {100, 1000, 10000, 50000, 100000, 200000, 300000};

void time_measure(struct Result results[]) {
    srand(time(NULL));

    for (int size_idx = 0; size_idx < SIZES_LEN; ++size_idx) {
        const long size = sizes[size_idx];

        for (int option = 0; option < OPTIONS_LEN; ++option) {
            struct Record *records = malloc(sizeof(struct Record) * size);
            for (int record_idx = 0; record_idx < size; ++record_idx) {
                records[record_idx] = generate_record();
            }
            const clock_t start = clock();
            options[option].sort(records, directions[0].cmp, 0, size);
            const clock_t end = clock();
            const double seconds = (double) (end - start) / CLOCKS_PER_SEC;

            strcpy(results[option * SIZES_LEN + size_idx].name, options[option].name);
            results[option * SIZES_LEN + size_idx].size = size;
            results[option * SIZES_LEN + size_idx].time = seconds;

            free(records);
        }
    }
}
