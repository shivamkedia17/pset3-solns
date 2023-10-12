#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "../hashing/hashing.h"
#include "../hashing/hashmap.h"
#include "../prng/mt64.h"
#include "../helpers/helpers.h"
#include "isomorphic.h"

typedef struct
{
    unsigned long long a;
    unsigned long long b;
    bool isomorphic;
}
results;

// set default values
results* createNewResult(unsigned long long a, unsigned long long b)
{
    results* newResult      = (results*) malloc(sizeof(results));
    assert(newResult != NULL);

    newResult->isomorphic   = checkIsomorphic(a, b);
    newResult->a            = a;
    newResult->b            = b;

    return newResult;
}

void printResult(results* r)
{
    if (r->isomorphic)
    {
        printf("%llu and %llu are isomorphic.\n", r->a, r->b);
    }
    else 
    {
        printf("%llu and %llu are NOT isomorphic.\n", r->a, r->b);
    }
    return;
}

int main(int argc, char *argv[]) 
{
    if(argc != 1) 
    {
        printf("Usage: %s\n", argv[0]);
        exit(1);
    }

    unsigned int n = 8;
    results** ans = (results**) malloc(n * sizeof(results*));
    
    ans[0] = createNewResult(12345, 54312);
    ans[1] = createNewResult(67980, 67890);
    ans[2] = createNewResult(132477, 123477);
    ans[3] = createNewResult(458109004, 197356551);
    ans[4] = createNewResult(1234567890, 9087456231);
    ans[5] = createNewResult(2345654, 1453);
    ans[6] = createNewResult(2345654, 2435663);
    ans[7] = createNewResult(234556777890, 987495660231);

    for (unsigned int i = 0; i < n; i++)
    {
        printResult(ans[i]);
    }
    
    free(ans);
}
