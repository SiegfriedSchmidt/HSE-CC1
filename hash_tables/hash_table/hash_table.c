//  
// 06.06.2025

#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable* create_hash_table(const long capacity, const hash_func_type hash_func) {
    HashTable* hash_table = malloc(sizeof(HashTable));
    hash_table->capacity = capacity;
    hash_table->hash_func = hash_func;
    hash_table->size = 0;
    hash_table->collisions = 0;

    hash_table->entries = calloc(hash_table->capacity, sizeof(HashTableEntry));
    return hash_table;
}

void destroy_hash_table(HashTable* hash_table) {
    free(hash_table->entries);
    free(hash_table);
}

HashTableEntry* hash_table_get_entry(HashTable* hash_table, long idx, char* key) {
    while (hash_table->entries[idx].key != NULL) {
        if (strcmp(hash_table->entries[idx].key, key) == 0) {
            return &hash_table->entries[idx];
        }
        ++idx;

        if (idx >= hash_table->capacity) {
            idx = 0;
        }
    }
    return &hash_table->entries[idx];
}

void hash_table_set(HashTable* hash_table, char* key, void* value) {
    if (hash_table->size >= hash_table->capacity - 1) {
        fprintf(stderr, "Hash table is full!\n");
        exit(0);
    }

    long idx = hash_table->hash_func(key) % hash_table->capacity;
    if (hash_table->entries[idx].key != NULL && strcmp(hash_table->entries[idx].key, key) != 0) {
        hash_table->collisions++;
    }

    HashTableEntry* entry = hash_table_get_entry(hash_table, idx, key);
    entry->key = key;
    entry->value = value;
    hash_table->size++;
}

void* hash_table_get(HashTable* hash_table, char* key) {
    long idx = hash_table->hash_func(key) % hash_table->capacity;
    const HashTableEntry* entry = hash_table_get_entry(hash_table, idx, key);
    return entry->value;
}
