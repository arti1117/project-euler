/*
 *  20190704.c
 *  19:30 ~ 23:00
 *  Created on: Jul 4, 2019
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
#define MIN 10


char Dictionary[MAX][MIN];

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

void except(int parent, char number, char* numbers)
{
    int i, j = 0, max = strlen(numbers);
    char* result = malloc(max - 1);

    if (max==0) {
        Dictionary[parent][10] = '\0';
        return;
    } else if (max==1) {
        Dictionary[parent][9] = numbers[0];
        return;
    } else {
        for (i=0; i<max; i++) {
            Dictionary[parent][MIN-max] = numbers[i];
            j=0;
            while (j<max-1) {
                if(j!=i) {
                    result[j] = numbers[i];
                }
            }
        }
    }
}

void Permutation(int index, char* numbers)
{
    int i;
}

void test()
{
    int index = 0;
    char* numbers = "1234";

    // printf("%s\n", except('2', numbers));
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