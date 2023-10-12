#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "bloomfilter.h"

// Initialise a bit array of filter_size
bool*           generateBitArray(unsigned int filter_size)
{
    bool *f = (bool *) calloc(filter_size, sizeof(bool));
    return f;
}

// Setup k different hash functions each with size in sizes
hashFunction**  setupHashes(unsigned int k, unsigned int* sizes)
{
    assert(sizes != NULL);

    // Allocate memory for an array of hash functions
    hashFunction** hashes = (hashFunction**) calloc(k, sizeof(hashFunction*));

    for (int i = 0; i < k; i++)
    {
        size_t size = sizes[i];
        hashes[i]   = setup(size);
    }

    return hashes;
}

bloomFilter*    createFilter(unsigned int k, unsigned int* sizes, unsigned int fs)
{
    assert(sizes != NULL);
    assert(k > 0);
    assert(fs > 0);

    fs              = getPrime_fromFile(fs);
    bloomFilter* bf = malloc(sizeof(bloomFilter));
    bf->filter      = generateBitArray(fs);
    bf->hashes      = setupHashes(k, sizes);
    bf->fs          = fs;
    bf->k           = k;

    return bf;
}

void            insertFilter(bloomFilter* bf, unsigned int key)
{
    assert(bf != NULL);
    printf("Inserting: %u\n", key);
    for (int i = 0; i < bf->k; i++) 
    {
        unsigned int index = hash(bf->hashes[i], key) % bf->fs; 
        // Set the bit to 1 at all indices where key hashes to.
        bf->filter[index] = true;
    }
    return;
}

bool            searchFilter(bloomFilter* bf, unsigned int key)
{
    assert(bf != NULL);
    assert(key <= LARGEST_INT);

    // First assume that the key is probably in the filter
    bool result = true; 

    for (int i = 0; i < bf->k; i++) 
    {
        unsigned int index = hash(bf->hashes[i], key) % bf->fs;
        // Indicates key is DEFINITELY not in filter
        if (bf->filter[index] == false)     {return false;} 
    }
    return(result);
}

void            printFilter(bloomFilter* bf)
{
    assert(bf != NULL);

    printf("Filter: ");
    for (int i = 0; i < bf->fs; i++) 
    {   
        printf(i? ", %u":"%u", bf->filter[i]);
    }
    printf("\n");
}

void            freeFilter(bloomFilter* bf)
{
    assert(bf != NULL);
    for (int i = 0; i < bf->k; i++)
    {
        destructHash(bf->hashes[i]);
    }
    free(bf->hashes);
    free(bf->filter);
    free(bf);
}