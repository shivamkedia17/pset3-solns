#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "../prng/mt64.h"
#include "../helpers/helpers.h"
#include "hashing.h"

// determine the length of the largest possible key-vector
unsigned int set_r(int largest_key, unsigned int m)
{
    if (m == 0)     {return -1;}

    unsigned int r;
    for (r = 1; largest_key > 0; r++)    {largest_key = largest_key/m;}
    // assert(pow(m,r) > largest_key);
    return r;
}


// generate an A[] of size r, with each 0 ≤ A_i ≤ m-1
// A is the vector (aka array of random digits) that is used to compute the hash
unsigned int* genHashVector(unsigned int m,  unsigned int r)
{
    unsigned int *A = (unsigned int*) calloc(r, sizeof(unsigned int));

    // Generate r many random digits
    for (int i = 0; i < r; i++)
    {
        // Generate a random number in range(0, m)
        unsigned int x = genrand64_int64() % m;
        // printf("x: %d\n", x);
        A[i] = x;
        assert(A[i] < m);
    }
    // printArray(A, r);
    return A;
}

// Converts 'key' in base 10 to a vector with digits in base m
unsigned int* changeBase(int key, unsigned int m, unsigned int r)
{
    unsigned int* K = (unsigned int*) calloc(r, sizeof(unsigned int));
    if (m == 0)     {return NULL;}
    for (int i = r-1; i >= 0; i--)
    {
        K[i] = key % m; // Possible Values 0...m-1
        assert(K[i] < m);
        key = key/m;
    }

    return K;
}

// Find <A,B> given vectors A and B. Assuming Sizes of A and B are the same
unsigned int dotproduct(unsigned int* A, unsigned int* B, const unsigned int r)
{
    if (r == 0)        {return 0;} // Dot product of zero vectors is 0.

    unsigned int sum = 0;
    for (int i = 0; i < r; i++) {sum = sum + (A[i] * B[i]);}

    return (sum);
}

// Compute Dot-Product Hash
unsigned int computeHash(unsigned int* K, unsigned int* A, const unsigned int r, unsigned int m)
{
    // Returned remainder will never be negative.
    // Compute the index of an element in the hash table.
    unsigned int index = dotproduct(K, A, r) % m;
    assert(index >= 0 && index < m);
    return index;
}

// Use this to "setup" a hash function
hashFunction* setup(unsigned int size)
{
    hashFunction* h = (hashFunction*) malloc(sizeof(hashFunction));

    // file containing all primes before 500000
    // actual size of m is a prime, read from given file
    h->m = getPrime_fromFile(size);
    // printf("Prime: %d\n", h->m);

    // Size of hash-vector
    // int largest_int = INT32_MAX;
    h->r = set_r(LARGEST_INT, h->m);
    // generate the vector of random digits in base m
    h->A = genHashVector(h->m, h->r);

    return h;
}

// Provide an interface to use the functions in this file
// Return hash(key) under hash function h
unsigned int hash(hashFunction* h, int key)
{
    unsigned int* K = changeBase(key, h->m, h->r);
    unsigned int index = computeHash(K, h->A, h->r, h->m);

    assert(index < h->m);
    free(K);
    return index;
}

void destructHash(hashFunction* h)
{
    free(h->A);
    free(h);
}