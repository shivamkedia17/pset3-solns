#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "hashing.h"

#define NOT_FOUND INT32_MAX-5

typedef struct {
    int key;
    int value;
}
KeyValuePair;

typedef struct
{
    KeyValuePair **table;
    size_t table_size;
}
hashMap;

hashMap*        createHashMap(size_t n);
bool            insert(hashMap *map, hashFunction* h, int key, int value);
unsigned int    get(hashMap *map, hashFunction* h, int key);
void            printKeyValuePair(KeyValuePair* x);
void            printHashMap(hashMap* x);
void            freeHashMap(hashMap *map);

#endif