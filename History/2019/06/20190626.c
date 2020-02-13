/*
 * 20190626.c
 *
 *  Created on: Jun 26, 2019
 *      Author: arti
 */

// Non-abundant sums
// Problem 23

// A perfect number is a number for which the sum of its 
// proper divisors is exactly equal to the number. 
// For example, the sum of the proper divisors of 28 
// would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

// A number n is called deficient if the sum of its 
// proper divisors is less than n and it is called abundant if this sum exceeds n.

// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 
// the smallest number that can be written as the sum of two abundant numbers is 24. 
// By mathematical analysis, 
// it can be shown that all integers greater than 28123 
// can be written as the sum of two abundant numbers.
// However, this upper limit cannot be reduced any further 
// by analysis even though it is known that the greatest number 
// that cannot be expressed as the sum of two abundant numbers is 
// less than this limit.

// Find the sum of all the positive integers which cannot be written 
// as the sum of two abundant numbers.

#include "Architects.h"

int IsAbundant(int n) {
    int i;
    int sum=0;

    for (i=n/2; i>0; i--) {
        if (n%i==0) {
            sum += i;
        }
    }

    if (sum > n) {
        return 1;
    } else {
        return 0;
    }
}

void test()
{
    int sum = 0;
    int count = 0;
    int limit = 28123;
    int result[limit];
    int abundant[limit];
    int i, j, k=0, l=0;

    for (i=0; i<limit; i++) {
        result[i] = 0;
    }

    for (i=1; i<=limit; i++) {
        if (IsAbundant(i)) {
            abundant[count] = i;
            count++;
        }
    }

    for (i=0; i<count; i++) {
        for (j=i; j<count; j++) {
            if ((l=abundant[i] + abundant[j]) < limit) {
                result[l] = 1;
                k++;
            } else {
                break;
            }
        }
    }

    for (i=0; i<limit; i++) {
        if (result[i] == 0) {
            sum += i;
        }
    }



    printf("The sum of the positive integers, ");
    printf("which cannot be written as the sum of two abundant numbers is %d.\n", sum);

    
}