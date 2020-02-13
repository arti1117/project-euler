/*
 * 20190607.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//Find the sum of all the primes below two million.

#include "Architects.h"

int IsPrime(double);

void test()
{
	double max = 2000000.0;
//	142913828922
//	The Function took 3500.595640 seconds to execute.

	long double i=2.0l;
	long double sum=0.0l;

	while (i<max) {
		if (IsPrime(i)) {
			sum += i;
		}
		i++;
	}

	printf("%.0Lf\n", sum);
}

int IsPrime(double x)
{
	int i=2;

	while (i < x) {
		if (fmod(x, i) == 0) {
			return 0;
		}
		i++;
	}
	return 1;
}
