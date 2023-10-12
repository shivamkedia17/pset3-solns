#include <stdio.h>
#include <stdlib.h>
#include "../helpers/helpers.h"
#include "../prng/mt64.h"
#include "hashing.h"
#include "hashmap.h"

int main(int argc, char *argv[])
{
    // Make sure we have a seed
    if(argc != 4)
    {
        printf("Usage: %s <seed> <table_size> <array_length>\n", argv[0]);
        exit(1);
    }

    // seed the random number generator
    init_genrand64(atoi(argv[1]));

    // Size of hash table is a cmd line arg
    int size = atoi(argv[2]);
    hashFunction* h = setup(size);

    // Generate a hash table
    hashMap* map = createHashMap(h->m);
    printf("Initial Table State: \n");
    printHashMap(map);
    printf("\n");

    // Generate a randomArray to test your hash function
    int l    = atoi(argv[3]);
    unsigned int *arr = randomArray(l);
    printf("Random Array: ");
    printArray(arr, l);


    for (int i = 0; i < l; i++)
    {
        int key = arr[i];

        if (get(map, h, key) == NOT_FOUND)
        {
            assert(insert(map, h, key, hash(h, key)));
        }
    }

    printf("\n");
    printf("Final Table State: \n");
    printHashMap(map);

    free(arr);
    destructHash(h);
    freeHashMap(map);
}