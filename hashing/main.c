#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../helpers/helpers.h"
#include "hashing.h"

int main(int argc, char *argv[]) 
{
    // Make sure we have a seed
    if(argc != 3) 
    {
        printf("Usage: %s <seed> <array_length>\n", argv[0]);
        exit(1);
    }

    // seed the random number generator
    init_genrand64(atoi(argv[1]));

    // Size of hash table is a cmd line arg
    int size = atoi(argv[2]);
    setup(size);

    // Generate a randomArray to test your hash function
    int *arr = randomArray(10);
    printf("")
}