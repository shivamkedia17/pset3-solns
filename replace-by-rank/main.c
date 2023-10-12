#include <stdio.h>
#include <stdlib.h>
#include "../hashing/hashing.h"
#include "../hashing/hashmap.h"
#include "../prng/mt64.h"
#include "../helpers/helpers.h"

void replace_by_rank(unsigned int* A, unsigned int n) 
{
    hashFunction* h = setup(n);
    hashMap* map = createHashMap(n);

    for (unsigned i = 0; i < n; i++)
    {
        unsigned int key = A[i];
        unsigned int val = i;
        // assert(insert(map, h, key, val));
        if (!insert(map, h, key, val)) 
        {
            printHashMap(map);
        }
    }
    
    unsigned int* B = duplicateArray(A, n);
    sortArray(B, n);

    // Replace by rank 
    for (unsigned i = 0; i < n; i++)
    {
        // rank starts from 1, i starts from 0
        
        // Here our 'value' in the hashmap will be the index of the element in A whose rank is i+1
        unsigned int value = get(map, h, B[i]);
        assert(value != NOT_FOUND);
        A[value] = i+1;
    }
    
    free(B);
    destructHash(h);
    freeHashMap(map);
    return; 
}

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

    printf("Sorted: \t");
    unsigned int *C = duplicateArray(A, n);
    sortArray(C, n);
    printArray(C, n);
    replace_by_rank(C, n);
    printf("Sorted: \t");
    printArray(C, n);

    replace_by_rank(A, n);

    printf("Output: \t");
    printArray(A, n);


    free(A);
}
