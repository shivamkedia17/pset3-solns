#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashmap.h"

// Create a new hashmap
hashMap* createHashMap(size_t n)
{
    hashMap *map    = (hashMap*)        malloc(sizeof(hashMap));
    map->table      = (KeyValuePair**)  calloc(n, sizeof(KeyValuePair*));
    map->table_size = n;
    return map;
}

// Insert a key-value pair into the hashmap
bool insert(hashMap *map, hashFunction* h, int key, int value)
{
    assert(map != NULL);
    assert(h   != NULL); // Ensure Hash Function has been setup before calling

    // IMPORTANT: assume that our hash function returns indicies greater than map->table_size
    // Adjust the indices accordingly
    unsigned int index = hash(h, key) % map->table_size;

    /*
    if (map->table[index] != NULL) {
        printf("Collision:\nInserting at Index: %d \t key: %d \t value: %d\n", index, key, value);
        printf("Already present: \t");
        printKeyValuePair(map->table[index]);
        return;
    }
    */

    // Begin linear probing
    for (unsigned int n_visited = 0; n_visited < map->table_size; n_visited++)
    {
        if (map->table[index] != NULL) // Current index has some key-value pair
        {
            index = (index + 1) % map->table_size;
            continue;
        }
        else                           // Current index in table is empty
        {
            // Create a new key-value pair to insert here
            KeyValuePair* pair = (KeyValuePair*) malloc(sizeof(KeyValuePair));
            pair->key   = key;
            pair->value = value;

            // printKeyValuePair(pair);
            map->table[index] = pair;
            return true;
        }
    }

    // if function hasn't returned yet, means table is full
    return false;
}

// Retrieve a value from the hashmap using a key
unsigned int get(hashMap *map, hashFunction* h, int key)
{
    assert(map != NULL);
    assert(h   != NULL); // Ensure Hash Function has been setup before calling

    unsigned int index = hash(h, key) % map->table_size;

    if (map->table[index] == NULL)
    {
        return NOT_FOUND;
    }

    // Begin linear probing
    unsigned int n_visited = 0;
    while (map->table[index] != NULL && n_visited < map->table_size)
    {
        if (map->table[index]->key == key)
        {
            return map->table[index]->value;
        }
        n_visited++;
        index = (index + 1) % map->table_size;
    }

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