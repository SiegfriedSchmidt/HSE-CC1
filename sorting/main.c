#include <stdio.h>
#include "generate.h"
#include <stdlib.h>
#include <time.h>

#include "display.h"
#include "sorts/all_sorts.h"


int main(void) {
    // srand(time(NULL));
    srand(3);

    printf("1 - merge_sort\n2 - quick_sort\n3 - heap_sort\nChoose sort: ");
    int option;
    scanf("%i", &option);
    --option;

    printf("1 - ascending\n2 - descending\nChoose sort direction: ");
    int direction;
    scanf("%i", &direction);
    --direction;

    const long size = 50;

    struct Record *records = malloc(sizeof(struct Record) * size);
    for (int i = 0; i < size; ++i) {
        records[i] = generate_record();
    }

    options[option].sort(records, directions[direction].cmp, 0, size);

    print_table_head();
    for (int i = 0; i < size; ++i) {
        print_record_data(records[i], i);
    }

    printf("Selected sort: %s %s", directions[direction].name, options[option].name);

    free(records);
    return 0;
}
