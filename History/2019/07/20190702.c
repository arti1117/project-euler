/*
 *  20190702.c
 *  21:30 ~ 22:20
 *  Created on: Jul 02, 2019
 *      Author: arti
 */

// Lexicographic permutations
// Problem 24

// A permutation is an ordered arrangement of objects.
// For example, 3124 is one possible permutation of the digits 
// 1, 2, 3 and 4. If all of the permutations are listed
// numerically or alphabetically, we call it lexicographic order.
// The lexicographic permutations of 0, 1 and 2 are:

// 012   021   102   120   201   210

// What is the millionth lexicographic permutation of 
// the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

#include "Architects.h"

#define MAX 3628800

char* Dictionary[MAX];

char* concatenate(char* x, char* y)
{
    int i = 0;
    char* z = malloc(strlen(x) + strlen(y) + 1);

    while(*x) {
        z[i] = *x;
        x++;
        i++;
    }
    
    while(*y) {
        z[i] = *y;
        y++;
        i++;
    }
    z[i] = '\0';
    
    return z;    
}

char* Permutation(char x, char* numbers)
{
    return numbers;
}

void test()
{
    char* numbers = "1234";
    char* x = "1";
    char* y = "2";
    
    // Permutation(numbers);
    
    
    // strcat(x, y);
    
    printf("%s\n", numbers);
    printf("%c\n", numbers[0]);
    printf("%s\n", Permutation('1', numbers));
    // printf("%d\n", strlen(numbers));
    printf("%s\n",concatenate(x, y));
    
}

// memo
/*
    01234567 89
    01234567 98

    0123456 789
    0123456 798
    0123456 879
    0123456 897
    0123456 978
    0123456 987

    012345 6789
    012345 6798
    012345 6879
    012345 6897
    ....

    char? int? 
 */