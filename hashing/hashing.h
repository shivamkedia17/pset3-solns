#ifndef HASHING_H
#define HASHING_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    unsigned int m;     // Also corresponds to the numbers of buckets in a hashtable
    unsigned int r;     // Size of Random Vector
    unsigned int* A;    // Random vector of digits in base m
}
hashFunction;

#define LARGEST_INT 50000

// unsigned int  set_r(int key, unsigned int m);
// unsigned int* changeBase(int key, unsigned int m, unsigned int r);
// unsigned int* genHashVector(unsigned int m,  unsigned int r);
// unsigned int  dotproduct(unsigned int* A, unsigned int* B, const unsigned int r);
// unsigned int  computeHash(unsigned int* K, unsigned int* A, const unsigned int r, unsigned int m);

hashFunction*   setup(unsigned int size);
void            destructHash(hashFunction* h);
unsigned int    hash(hashFunction* h, int key);
#endif