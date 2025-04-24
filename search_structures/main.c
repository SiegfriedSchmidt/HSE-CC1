#include <stdio.h>
#include "generate.h"
#include <stdlib.h>
#include <time.h>

#include "display.h"
#include "search/all_searches.h"

int main(void) {
    // srand(time(NULL));
    srand(3);

    printf("1 - linear_search\n2 - binary_search\n3 - red_black_search\nChoose search algorithm: ");
    int option;
    scanf("%i", &option);
    --option;

    printf("Write a key to search: ");
    char key[192];
    scanf("%s", &key);

    const long size = 50;

    Record* records = malloc(sizeof(Record) * size);
    for (int i = 0; i < size; ++i) {
        records[i] = generate_record();
    }

    options[option].search(records);

    print_table_head();
    for (int i = 0; i < size; ++i) {
        print_record_data(&records[i], i);
    }

    printf("Selected search algorithm and key: %s, %s", options[option].name, key);

    free(records);
    return 0;
}
