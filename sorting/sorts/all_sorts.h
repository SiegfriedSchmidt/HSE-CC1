// 
// 19.04.2025

#ifndef ALL_SORTS_H
#define ALL_SORTS_H
#include "heap_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "../record.h"

typedef void (*sort_type)(struct Record array[], cmp_type cmp, long l, long r);

struct SortType {
    sort_type sort;
    char *name;
};

const struct SortType options[] = {
    {merge_sort, "merge_sort"},
    {quick_sort, "quick_sort"},
    {heap_sort, "heap_sort"}
};

struct DirectionType {
    cmp_type cmp;
    char *name;
};

const struct DirectionType directions[] = {
    {cmp_ascending, "ascending"},
    {cmp_descending, "descending"},
};


#endif //ALL_SORTS_H
