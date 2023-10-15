#ifndef HELPERS_H
#define HELPERS_H

#include <stddef.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

unsigned int*   randomArray(size_t n);
unsigned int*   duplicateArray(unsigned int* A, unsigned int n);
void            printArray(unsigned int* A, size_t n);
void            sortArray(unsigned int* A, size_t n);
unsigned int    getPrime_fromFile(unsigned int size);

#endif