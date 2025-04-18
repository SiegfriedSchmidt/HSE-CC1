#include <stdio.h>
#include "generate.h"
#include <stdlib.h>
#include <time.h>

#include "display.h"
#include "sorts/merge_sort.h"


int main(void) {
    // srand(time(NULL));
    srand(3);
    const long size = 300000;

    struct Record *records = malloc(sizeof(struct Record) * size);
    for (int i = 0; i < size; ++i) {
        records[i] = generate_record();
    }
    merge_sort(records, cmp_descending, 0, size);
    print_table_head();
    for (int i = 0; i < size; ++i) {
        print_record_data(records[i], i);
    }
    free(records);
    return 0;
}
