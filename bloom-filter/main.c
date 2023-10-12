#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "bloomfilter.h"

void print_search_result(bool result, int key)
{
    if (result) {printf ("%d is PROBABLY in the filter.\n", key);}
    else        {printf ("%d is NOT in the filter.\n", key);}
}

int main(int argc, char *argv[]) 
{
    // Make sure we have a seed
    if(argc != 3) 
    {
        printf("Usage: %s <seed> <filepath_with_filter_params.txt>\n", argv[0]);
        exit(1);
    }

    // seed the random number generator
    init_genrand64(atoi(argv[1]));

    // read file with parameters of the filter,
    char* filepath = argv[2];
    /*
    there should k + 2 lines
    the first line is k
    the second line is fs
    the next k lines are the different m's for the k different hash functions
    */

    unsigned int  k;     
    unsigned int  fs;     

    FILE* fp = fopen(filepath, "r");
    assert(fp != NULL);
    fscanf(fp, "%u\n", &k);
    fscanf(fp, "%u\n", &fs);

    unsigned int* sizes = malloc(k * sizeof(unsigned int));
    for (int i = 0; i < k; i++)
    {
        fscanf(fp, "%u\n", &(sizes[i]));
    }

    fclose(fp);

    // Setup bloomfilter
    bloomFilter* bf = createFilter(k, sizes, fs);
    printFilter(bf);

    // Generate a randomArray to test your bloom filter
    int l    = 13;
    unsigned int *arr = randomArray(l);
    printArray(arr, l);

    // for (int i = 0; i < l; i++) 
    // {
    //     int key = arr[i];
    //     printf("Inserting: %d\n", key);
    //     insertFilter(bf, key);
    //     printFilter(bf);
    // }

    insertFilter(bf, 1234);
    printFilter(bf);
    insertFilter(bf, arr[5]);
    printFilter(bf);
    insertFilter(bf, arr[8]);
    printFilter(bf);
    insertFilter(bf, arr[0]);
    printFilter(bf);
    print_search_result(searchFilter(bf, arr[5]), arr[5]);
    print_search_result(searchFilter(bf, arr[8]), arr[8]);

    insertFilter(bf, 234);
    print_search_result(searchFilter(bf, 98), 98);
    print_search_result(searchFilter(bf, 1234), 1234);

    freeFilter(bf);
    free(sizes);
}