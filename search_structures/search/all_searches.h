// 
// 24.04.2025

#ifndef ALL_SEARCHES_H
#define ALL_SEARCHES_H
#include "linear_search.h"
#include "binary_search.h"
#include "red_black_search.h"
#include "../record.h"

typedef Record (*search_type)(Record array[]);

struct SearchType {
    search_type search;
    char* name;
};

const struct SearchType options[] = {
    {linear_search, "linear_search"},
    {binary_search, "binary_search"},
    {red_black_search, "red_black_search"}
};

#endif //ALL_SEARCHES_H
