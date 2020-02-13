/*
 * 20190602.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//By listing the first six prime numbers:
//2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10001st prime number?

#include "Architects.h"

int IsPrime(int);

void test()
{
	int i=1, j=0;

	while (j < 10001) {
		i++;
		if (IsPrime(i)) {
			j++;
		}
	}
	printf("%d\n", j);
	printf("%d\n", i);
}

int IsPrime(int x)
{
	int i=2;

	while (i < x) {
		if (x == i) {
			break;
		}
		if (x % i == 0) {
			return 0;
		}
		i++;
	}
	return 1;
}
