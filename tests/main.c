#include <stdio.h>
#include <stdlib.h>
#include "../hashing/hashing.h"
#include "../hashing/hashmap.h"
#include "../prng/mt64.h"
#include "../helpers/helpers.h"

int main(int argc, char *argv[]) 
{
    //Make sure we have a seed
    if(argc != 3) 
    {
        printf("Usage: %s <seed> <array_length>\n", argv[0]);
        exit(1);
    }

    // seed the random number generator
    init_genrand64(atoi(argv[1]));

    // Size of array is a cmd line arg
    unsigned int n = atoi(argv[2]);

    // Create a random array of size n
    unsigned int* A = randomArray(n);

    printf("Input:  \t");
    printArray(A, n);
    sortArray(A, n);
    printf("Sorted: \t");
    printArray(A, n);

    free(A);
}
