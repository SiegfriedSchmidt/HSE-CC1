//  
// 06.06.2025

#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

typedef unsigned long long hash_type;
typedef hash_type (*hash_func_type)(const char*);

hash_type hash_1(const char*);
hash_type hash_2(const char*);
hash_type hash_3(const char*);
hash_type hash_4(const char*);

hash_func_type get_hash_func(long option);
extern const char* options[4];
#endif //HASH_FUNCTIONS_H
