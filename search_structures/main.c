#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "search/all_searches.h"

int main(void) {
    // srand(time(NULL));
    srand(3);

    const long size = 50;
    PreparedData prepared_data = generate_prepared_data(size);
    print_table_head();
    for (int i = 0; i < size; ++i) {
        print_record_data(&prepared_data.records[i], i);
    }

    printf("\n1 - linear_search\n2 - binary_search\n3 - red_black_search\nChoose search algorithm: ");
    int option;
    scanf("%i", &option);
    getchar();
    --option;

    printf("Write a key to search: ");
    char key[192];
    fgets(key, 192, stdin);
    key[strlen(key) - 1] = '\0';

    Record record = search(prepared_data, key, option);

    print_record_data(&record, -1);
    printf("Selected search algorithm and key: %s, %s", options[option], key);
    free_prepared_data(prepared_data);
    return 0;
}
