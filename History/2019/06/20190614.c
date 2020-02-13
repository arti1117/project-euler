/*
 * 20190614.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//If we list all the natural numbers below 10 that are multiples of 3 or 5,
//we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

#include "Architects.h"

void test()
{
	int sum=0, i=0;

	while (i<999) {
		i++;
		if (i%3 == 0 || i%5 == 0) {
			sum += i;
			continue;
		}
	}

	printf("%d\n", sum);
}

