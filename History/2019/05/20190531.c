/*
 * 20190531.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//2520 is the smallest number that can be divided
//by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number
//that is evenly divisible by all of the numbers from 1 to 20?

#include "Architects.h"

int IsSmallest(double, int, int);

void test() {

	int x=1, y=20;
	double number=y;

	while (1) {
		if (!IsSmallest(number, x, y)) {
			break;
		}
		number += y;
	}

	printf("%d\n", IsSmallest(number, x, y));
	printf("%.0f\n", number);

}

int IsSmallest(double number, int fr, int to) {

	int i=to;

	while (fr<=i) {
		if (fmod(number,i)!=0) {
			return 1;
		}
		i--;
	}
	return 0;

}
