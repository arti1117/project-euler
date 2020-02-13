/*
 * 20190618.c
 *
 *  Created on: Jun 18, 2019
 *      Author: arti
 */

//Starting in the top left corner of a 2×2 grid,
//and only being able to move to the right and down,
//there are exactly 6 routes to the bottom right corner.
//
//How many such routes are there through a 20×20 grid?
//https://projecteuler.net/problem=15

#include "Architects.h"

double FindPath(double x, double y)
{
	if (y==0) {
		return x;
	} else {
		return FindPath(2*x + 2, y - 1);
	}
}

void test()
{
	printf("%f\n", FindPath(0, 2));
	printf("%f\n", FindPath(0, 100));
//	6.000000
//	2535301200456458802993406410752.000000
//	The Function took 0.000062 seconds to execute.

	double x=0, y=0;
	while (y<100) {
		x = 2*x + 2;
		y++;
	}

	printf("%f\n", x);
}
