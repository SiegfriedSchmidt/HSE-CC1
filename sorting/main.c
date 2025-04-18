#include <stdio.h>
#include "generate.h"
#include <stdlib.h>
#include <time.h>

#include "display.h"
#include "sorts/merge_sort.h"


int main(void) {
    // srand(time(NULL));
    srand(3);

    struct Record records[10];
    for (int i = 0; i < 10; ++i) {
        records[i] = generate_record();
    }
    merge_sort(records, 10, 0);
    print_table_head();
    for (int i = 1; i < 10; ++i) {
        print_record_data(records[i], i);
    }
    return 0;
}
