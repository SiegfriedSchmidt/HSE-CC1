// 
// 24.04.2025

#include "time_measure.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search/all_searches.h"

#define SIZES_LEN 7
#define OPTIONS_LEN 3

const long sizes[SIZES_LEN] = {100, 1000, 10000, 50000, 100000, 200000, 300000};

void time_measure(Result results[]) {
    srand(time(NULL));

    for (int size_idx = 0; size_idx < SIZES_LEN; ++size_idx) {
        const PreparedData prepared_data = generate_prepared_data(sizes[size_idx]);

        for (int option = 0; option < OPTIONS_LEN; ++option) {
            char *key = "Sorokina Maksim Igorevna";

            const clock_t start = clock();
            search(prepared_data, key, option);
            const clock_t end = clock();
            const double seconds = (double) (end - start) / CLOCKS_PER_SEC;

            strcpy(results[option * SIZES_LEN + size_idx].name, options[option]);
            results[option * SIZES_LEN + size_idx].size = prepared_data.size;
            results[option * SIZES_LEN + size_idx].time = seconds;
        }
        free_prepared_data(prepared_data);
    }
}
