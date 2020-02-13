/*
 *  20190701.c
 *  19:30 ~ 20:30
 *  Created on: Jul 01, 2019
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

char* Lexicographic(char* order) {
    
    printf("%s\n", order);
}

void test()
{
    int i;
    char* order[10];

    for (i=0; i<10; i++) {
        order[0][i] = i + '0';
    }
    order[0][10] = '\0';

    Lexicographic(order[0]);




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