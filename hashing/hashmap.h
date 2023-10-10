#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#include "hashing.h"

typedef struct KeyValuePair;
typedef struct 
{
    KeyValuePair **table;
    size_t table_size;
} 
HashMap;

HashMap* createHashMap(size_t n);
void    insert(HashMap *map, hashFunction* h, int key, int value);
int     get(HashMap *map, hashFunction* h, int key);

#endif