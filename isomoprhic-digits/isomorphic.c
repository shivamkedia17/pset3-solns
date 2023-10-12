#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "isomorphic.h"
#include "../hashing/hashing.h"
#include "../hashing/hashmap.h"

unsigned int    getIntegerLength(unsigned long long n)
{
    assert(n >= 0);

    unsigned int len = 1;
    while (n > 9) 
    {
        n = n / 10;
        len++;
    }

    return len;
}

unsigned int    getLastDigit(unsigned long long n)
{
    assert(n >= 0);
    return n % 10;
}

bool            checkIsomorphic(unsigned long long a, unsigned long long b)
{
    unsigned int len_a = getIntegerLength(a);
    unsigned int len_b = getIntegerLength(b);

    if (len_a != len_b)
    {
        return false;
    }

    unsigned int n  = len_a; // since length of two numbers must be same
    hashFunction* h = setup(n);
    hashMap* map    = createHashMap(n);

    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int key    = getLastDigit(a);
        unsigned int value  = getLastDigit(b);
        a = a / 10;
        b = b / 10;
        
        unsigned int curr_val = get(map, h, key);
        if (curr_val == NOT_FOUND)
        { // No value is mapped to key, create a new mapping
            insert(map, h, key, value);
        }
        else if (curr_val != value)
        { // Indicates some other 'value' is already mapped to 'key' => digits aren't isomorphic
            return false;
        }
    }
    
    destructHash(h);
    freeHashMap(map);
    return true; 
}