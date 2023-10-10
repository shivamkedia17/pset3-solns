#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashmap.h"

#define NOT_FOUND INT32_MIN-5

// Define the structure for a key-value pair
typedef struct 
{
    int key;
    int value;
} 
KeyValuePair;

// Create a new hashmap
HashMap* createHashMap(size_t n) 
{
    HashMap *map    = (HashMap*)        malloc(sizeof(HashMap));
    map->table      = (KeyValuePair**)  calloc(n, sizeof(KeyValuePair*));
    map->table_size = n;
    return map;
}

// Insert a key-value pair into the hashmap
void insert(HashMap *map, hashFunction* h, int key, int value) 
{
    assert(map != NULL);
    assert(h   != NULL); // Ensure Hash Function has been setup before calling

    unsigned int index = hash(h, key);

    assert(index == NULL);
    /*
    while (map->table[index] != NULL) 
    {
        // Linear probing: Move to the next slot if collision occurs
        index = (index + 1) % map->table_size;
    }
    */

    // Create a new key-value pair
    KeyValuePair* pair = (KeyValuePair*) malloc(sizeof(KeyValuePair));
    pair->key   = key;
    pair->value = value;
    
    map->table[index] = pair;
}

// Retrieve a value from the hashmap using a key
int get(HashMap *map, hashFunction* h, int key) 
{
    assert(map != NULL);
    assert(h   != NULL); // Ensure Hash Function has been setup before calling

    unsigned int index = hash(h, key);

    if (map->table[index]->key == key)
    {
        return map->table[index]->value;
    }

    /* 
    while (map->table[index] != NULL) {
        if (strcmp(map->table[index]->key, key) == 0) {
            return map->table[index]->value;
        }
        // Linear probing: Move to the next slot if the key is not found
        index = (index + 1) % map->table_size;
    } */

    return NOT_FOUND; // Key not found
}

// Free memory allocated for the hashmap
void freeHashMap(HashMap *map) 
{
    for (int i = 0; i < map->table_size; i++) 
    {
        if (map->table[i] != NULL) 
        {
            free(map->table[i]->key);
            free(map->table[i]);
        }
    }
    free(map->table);
    free(map);
}