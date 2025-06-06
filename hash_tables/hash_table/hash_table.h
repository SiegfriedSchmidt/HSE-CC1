//  
// 06.06.2025

#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "hash_functions.h"

typedef struct HashTableEntry {
    char* key;
    void* value;
} HashTableEntry;

typedef struct HashTable {
    HashTableEntry* entries;
    hash_func_type hash_func;
    long capacity; // количество ячеек
    long size; // текущее количество элементов
    long collisions;
} HashTable;

HashTable* create_hash_table(long capacity, hash_func_type hash_func);

void destroy_hash_table(HashTable* hash_table);

void hash_table_set(HashTable* hash_table, char* key, void* value);

void* hash_table_get(HashTable* hash_table, char* key);


#endif //HASH_TABLE_H
