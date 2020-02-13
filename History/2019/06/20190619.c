/*
 * 20190619.c
 *
 *  Created on: Jun 19, 2019
 *      Author: arti
 */

//Power digit sum
//
//2^15 = 32768 and the sum of its digits is
//3 + 2 + 7 + 6 + 8 = 26.
//
//What is the sum of the digits of the number 2^1000?

#include "Architects.h"

void test()
{
	long double x=2l, y=1l;
	double z=0;
	int i=0, j=0, w=0;

	// if i<16384 then the result will be infinite.
	while (i<16383) {
		i++;
		y *= x;
	}

	x=y;
	while (y>1) {
		y /= 10;
		j++;
	}

	y=1;
	while (j>1) {
		y *= 10;
		j--;
	}

	while (y>0) {
		w = x/y;
		x -= w*y;
		y /= 10;
		z += w;
	}
	printf("%.0f\n", z);
}
