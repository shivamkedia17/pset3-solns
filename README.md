# CS-1203-1 Assignment 3
Data Structures, Ashoka University  
Instructor: Debayan Gupta  
Monsoon 2023  

## Question 1 - Universal Hashing
Assume you are only given integers. Implement the following dot-product hash family:
$$ h(k) = a.k \mod p $$
Review the [dot-product hash family.](https://youtu.be/z0lJ2k0sl1g)

## Question 2 - Isomorphic Numbers
Check whether two given numbers are isomorphic. Your solution should run in $O(n)$ time. Note that this rules out a brute force solution. You are expected to use hashing. 
Assume that two numbers are isomorphic if there exists a one-one correspondence between the digits of the two numbers. Numbers of unequal length are not isomorphic by default.

**Examples:**  
`a = 458109004` and `b = 197356551` are isomorphic. 
$$ digit\ in\ a \rightarrow digit\ in\ b $$
$$ 0 \rightarrow 5 $$
$$ 1 \rightarrow 3 $$
$$ 4 \rightarrow 1 $$
$$ 5 \rightarrow 9 $$
$$ 8 \rightarrow 7 $$
$$ 9 \rightarrow 6 $$

`p = 1234567890` and `q = 0987456231` are isomorphic.

`k = 1234556777890` and `l = 0987495660231` are **not** isomorphic since there is no unique correspondence for digits `5` and `7` in `k` to the digits in `l`.

There need to be a pattern in the way the digits are mapped, as long as each unique digit maps to some other unique digit. 

Your output should look like:
```C
    12345 and 54312 are isomorphic.
    67980 and 67890 are isomorphic.
    132477 and 123477 are isomorphic.
    458109004 and 197356551 are isomorphic. 
    1234567890 and 0987456231 are isomorphic.

    2345654 and 1453 are NOT isomorphic.
    2345654 and 2435663 are NOT isomorphic.
    1234556777890 and 0987495660231 are NOT isomorphic.
```

## Question 3 - Replace by Rank
You are given a set of numbers 
$$ n_0, n_1, n_3, \dots, n_k $$

Assume the numbers are distinct. Replace each number by their rank. For e.g:
```
    Input : 123, 47, 698, 7, 80
    Output: 4, 2, 5, 1, 3
```

Note that ranks are numbered starting from `1`. Your `output` should be exactly of the above form,  
i.e, for an input of 4 numbers:
```
    Output: Rank, Rank, Rank, Rank
```

## Question 4 - Bloom Filter
Create a bloom filter with the following components: 
+ `k` distinct hash functions: Create instances of $h(x)$ from `Question 1`.
+ A bit array of size `n`

The filter should support the following operations:
+ **Creation**:  Initialise a new bloom filter and the necessary components.
+ **Insertion**: Update the state of your filter after *seeing* a new element `x`.
+ **Search**: Return whether a given `x` is ***definitely not*** in the filter or ***probably*** in the filter.
+ **Display**: Print the current state of the filter.

The autograder will show you the required output format.

Hints: 
- Think about what data structure to use for keeping your `k` hash functions.


--- 
**Tips**:
- Carefully peruse the structure of the boilerplate code given. It will make a lot of things clear.
- These are **not** difficult to code up. However, you must be clear with what's going on in each function to be able to write it up.
- If you're unclear on what hashing is, what hash families are, 
    + re-watch the lecture(s) on hashing
    + come to OH and clarify the math / functional components

---

## Usage:
1. Each directory contains a `main.c` which is the entry point of your code.
