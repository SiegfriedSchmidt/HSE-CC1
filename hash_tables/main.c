#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "generate.h"
#include "hash_table/hash_table.h"

int main(void) {
    // srand(time(NULL));
    srand(3);

    const long size = 100000;

    Record** records = malloc(sizeof(Record*) * size);
    for (int i = 0; i < size; i++) {
        records[i] = generate_record();
    }

    print_table_head();
    for (int i = 0; i < size; ++i) {
        print_record_data(records[i], i);
    }

    printf("\nhash_1, hash_2, hash_3, hash_4\nChoose hash function: ");
    int option;
    scanf("%i", &option);
    getchar();
    --option;

    HashTable* hash_table = create_hash_table(size * 2, get_hash_func(option));
    for (int i = 0; i < size; i++) {
        hash_table_set(hash_table, records[i]->name, records[i]);
    }

    printf("Write a key to search: ");
    char key[192];
    fgets(key, 192, stdin);
    key[strlen(key) - 1] = '\0';

    const Record* record = hash_table_get(hash_table, key);
    printf("Selected hash function and key: %s, %s\n\n", options[option], key);

    printf("RECORD:\n");
    if (record == NULL) {
        printf("Key not found!\n");
    } else {
        print_record_data(record, -1);
    }
    printf("Collisions: %ld\n", hash_table->collisions);

    destroy_hash_table(hash_table);
    for (int i = 0; i < size; i++) {
        free(records[i]);
    }
    free(records);
    return 0;
}
