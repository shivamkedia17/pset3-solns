#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <stddef.h>
#include "../helpers/helpers.h"
#include "../prng/mt64.h"
#include "../hashing/hashing.h"
#include "../hashing/hashmap.h"

typedef struct
{
    hashFunction** hashes;      // Array of k different hash functions
    bool *filter;               // bit array
    unsigned int k;             // k
    unsigned int fs;            // filter_size
} 
bloomFilter;

bloomFilter*    createFilter(unsigned int k, unsigned int* sizes, unsigned int fs);
bool            searchFilter(bloomFilter* bf, unsigned int);
void            insertFilter(bloomFilter* bf, unsigned int);
void            printFilter(bloomFilter* bf);
void            freeFilter(bloomFilter* bf);


#endif

