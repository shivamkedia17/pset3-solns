#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashmap.h"

// Define the structure for a key-value pair
// typedef struct 
// {
//     int key;
//     int value;
// } 
// KeyValuePair;

// Create a new hashmap
hashMap* createHashMap(size_t n) 
{
    hashMap *map    = (hashMap*)        malloc(sizeof(hashMap));
    map->table      = (KeyValuePair**)  calloc(n, sizeof(KeyValuePair*));
    map->table_size = n;
    return map;
}

// Insert a key-value pair into the hashmap
void insert(hashMap *map, hashFunction* h, int key, int value) 
{
    assert(map != NULL);
    assert(h   != NULL); // Ensure Hash Function has been setup before calling

    unsigned int index = hash(h, key);

    if (map->table[index] != NULL) {
        printf("Collision:\nInserting at Index: %d \t key: %d \t value: %d\n", index, key, value);
        printf("Already present: \t");
        printKeyValuePair(map->table[index]);
        return;
    }

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
int get(hashMap *map, hashFunction* h, int key) 
{
    assert(map != NULL);
    assert(h   != NULL); // Ensure Hash Function has been setup before calling

    unsigned int index = hash(h, key);

    if (map->table[index] == NULL) {
        return NOT_FOUND;
    }

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
void freeHashMap(hashMap *map) 
{
    for (int i = 0; i < map->table_size; i++) 
    {
        if (map->table[i] != NULL) 
        {
            free(map->table[i]);
        }
    }
    free(map->table);
    free(map);
}

void printKeyValuePair(KeyValuePair* x)
{
    if (x == NULL)
    {
        printf("Key : NULL \tValue: NULL\n");
        return;
    }
    printf("Key : %d \tValue: %d\n", x->key, x->value);
}

void printHashMap(hashMap* x)
{
    printf("\n----------Start----------\n");
    for (int i = 0; i < x->table_size; i++)
    {
        printf("Index: %d\t", i);
        printKeyValuePair(x->table[i]);
    }
    printf("----------End------------\n");
}