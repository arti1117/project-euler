/*
 * 20190601.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//Lattice paths
//The sum of the squares of the first ten natural numbers is,
//1^2 + 2^2 + ... + 10^2 = 385
//
//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)^2 = 55^2 = 3025
//
//Hence the difference between the sum of
//the squares of the first ten natural numbers
//and the square of the sum is 3025 − 385 = 2640.
//
//Find the difference between the sum of
//the squares of the first one hundred natural numbers and the square of the sum.

#include "Architects.h"

double squares(double);

void test()
{
//	int i, j, sum;
//
//	j = sum = 0;
//
//	for (i=1; i<101; i++) {
//		j += i;
//		sum += i*i;
//	}
//	printf("%d\n", (j*j));
//	printf("%d\n", sum);
//	printf("%d\n", (j*j) - sum);

	double num, sum, diff;

	num = sum = diff = 0.0;

	double max = 101.0;

	for (num=1.0; num<max; num++) {
		diff += num;
		sum += squares(num);
	}
	printf("%.0f\n" , squares(diff) - sum);

	num = sum = diff = 0.0;

	double min;

	if (fmod(max, 2) == 0) {
		min = max / 2;
	} else {
		min = (max / 2) - 0.5;
	}

	for (num=1.0; num<=min; num++) {
		diff += num + (min + num);
		sum += squares(num) + squares(min + num);
	}
	printf("%.0f\n" , squares(diff) - sum);
}

double squares(double x)
{
	return x*x;
}

