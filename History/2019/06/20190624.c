/*
 * 20190624.c
 *
 *  Created on: Jun 24, 2019
 *      Author: arti
 */

// Amicable numbers
// Problem 21

// Let d(n) be defined as the sum of proper divisors of 
// n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are 
// an amicable pair and each of a and b are called amicable numbers.

// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 
// and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142;
// so d(284) = 220.

// Evaluate the sum of all the amicable numbers under 10000.

#include "Architects.h"

#define MAX 10000

int d(int n) {
    int i;
    int result = 0;

    for (i=1; i<n; i++) {
        if (n % i == 0) {
            result += i;
        }
    }

    return result;
}

void test()
{
    int i = 2;
    int count = 0;
    int amicable[MAX];
    long double total = 0;

    while (i<=10000) {

        if (i==d(d(i)) && i!=d(i)) {
            amicable[count] = i;
            total += i;
            count++;
        }

        i++;
    }
    printf("The sum of all the amicable numbers under 10000 is %.0Lf.\n", total);
    printf("The number of all the amicable numbers under 10000 is %d.\n", count);
    printf("The List of the amicable number.\n");
    for (i=0; i<count; i++) {
        printf("%d ", amicable[i]);
    }
    printf("\n");
}