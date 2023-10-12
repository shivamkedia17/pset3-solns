#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "helpers.h"
#include "../prng/mt64.h"

int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

unsigned int* randomArray(size_t n) 
{
    unsigned int* randomNumbers = (unsigned int*) malloc(sizeof(unsigned int) * n);
    for (int i = 0; i < n; i++) {
        randomNumbers[i] = (unsigned int)(genrand64_int64() % 100);
    }
    return randomNumbers;
}

void printArray(unsigned int* A, size_t n) 
{
    for (int i = 0; i < n; i++) {   
        printf(i? ", %d":"%d", A[i]);
    }
    printf("\n");
}   

unsigned int* duplicateArray(unsigned int* A, unsigned int n)
{
    unsigned int* B = malloc(n * sizeof(unsigned int));
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
    return B;
}

void sortArray(unsigned int* A, size_t n) 
{
    qsort(A, n, sizeof(unsigned int), compare);
}

// get next largest prime number from a file, ONCE
// unsigned int getPrime_fromFile(unsigned int size, char* filename)
unsigned int getPrime_fromFile(unsigned int size)
{
    char* filepath = "../helpers/numbers.txt";
    FILE* fp = fopen(filepath, "r");
    unsigned int p = 0;
    assert(fp != NULL);
    while (true)
    {
        fscanf(fp, "%d\n", &p);
        if (p >= size) {break;}
    } 
    fclose(fp);
    return p;
}
