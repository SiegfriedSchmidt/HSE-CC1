// 
// 25.04.2025

#ifndef ALL_SEARCHES_H
#define ALL_SEARCHES_H

#include "../record.h"

typedef struct PreparedData {
    long size;
    Record *records;
    Record *sorted_records;
} PreparedData;

PreparedData generate_prepared_data(long);

Record search(PreparedData, char *, long);

void free_prepared_data(PreparedData);

extern const char *options[3];
#endif //ALL_SEARCHES_H
