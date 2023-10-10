#ifndef HASHING_H
#define HASHING_H

typedef struct {
    unsigned int m;
    unsigned int r;
    unsigned int* A;
}
hashFunction;

// unsigned int  set_r(int key, unsigned int m);
// unsigned int* changeBase(int key, unsigned int m, unsigned int r);
// unsigned int* genHashVector(unsigned int m,  unsigned int r);
// unsigned int  dotproduct(unsigned int* A, unsigned int* B, const unsigned int r);
// unsigned int  computeHash(unsigned int* K, unsigned int* A, const unsigned int r, unsigned int m);

hashFunction*   setup(unsigned int size);
void            destruct(hashFunction* h);
unsigned int    hash(hashFunction* h, int key);
#endif