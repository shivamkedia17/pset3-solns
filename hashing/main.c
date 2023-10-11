#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../helpers/helpers.h"
#include "../prng/mt64.h"
#include "hashing.h"
#include "hashmap.h"

int main(int argc, char *argv[]) 
{
    // Make sure we have a seed
    if(argc != 3) 
    {
        printf("Usage: %s <seed> <table_size>\n", argv[0]);
        exit(1);
    }

    // seed the random number generator
    init_genrand64(atoi(argv[1]));

    // Size of hash table is a cmd line arg
    int size = atoi(argv[2]);
    hashFunction* h = setup(size);

    // Generate a hash table
    hashMap* map = createHashMap(h->m);
    printHashMap(map);

    // Generate a randomArray to test your hash function
    int l    = 10;
    int *arr = randomArray(l);
    printArray(arr, l);


    for (int i = 0; i < l; i++) 
    {
        int key = arr[i];
        
        if (get(map, h, key) == NOT_FOUND) {
            insert(map, h, key, hash(h, key));
        }
    }

    printHashMap(map);

    free(arr);
    destruct(h);
    freeHashMap(map);
}