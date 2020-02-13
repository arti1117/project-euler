/*
 *  20190708.c
 *  21:30 ~ 22:00
 *  Created on: Jul 8, 2019
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

#define MAX 6
#define MIN 3


char Dictionary[MAX][MIN+1];

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

int factorial(int x, int y)
{
    if (x < 2) {
        return y;
    } else {
        return factorial(x-1, y*x);
    }
}

void Permutation(char* numbers)
{
    int i;
    if (strlen(numbers) == 0) {
        return;
    } else {
        for (i = 0; i<strlen(numbers); i++) {
            Permutation(numbers);
        }
    }
}


void except(int parent, char* numbers)
{
    int i, j, l, max = strlen(numbers);
    int delimiter = factorial(max-1, 1);
    char joker;
    char* result = malloc(max-1);

    for (i=0; i<max; i++) {

        joker = numbers[i];

        j = parent + delimiter * i;
        while (j <= delimiter*(i+1)) {
            Dictionary[j][MIN-max] = numbers[i];
            Dictionary[j][MIN+1] = '\0';
            j++;
        }

        j=0; l=-1;
        while (j<max-1) {
            l++;
            if(numbers[l] == joker) {
                continue;
            } else {
                result[j] = numbers[l];
                j++;
            }
        }

        if (strlen(result)>0) {
            except(parent + (delimiter*i), result);
        }
    }
}

void test()
{
    int i;
    int index = 0;
    char* numbers = "123";

    Permutation(numbers);

    except(index, numbers);
    for (i=0; i<MAX; i++) {
        printf("%s\n", Dictionary[i]);
    }

}
