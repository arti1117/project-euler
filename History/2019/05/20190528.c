/*
 * 20190528.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?

#include "Architects.h"

#define MAX 100000

double IsPrime(double);
double GetFactors(double);

double Factors[MAX];
int index = 0;
double factor = 2;

void test() {

//	double num = 600851475143;
	double x = 600851475143;
//	double x = 13195;

//	printf("%f\n", num);

	while (factor <= x) {
		x = GetFactors(x);
	}
	printf("%.0f\n", Factors[index-1]);
	printf("%.0f\n", IsPrime(6857));
}

double IsPrime(double x) {
	double i=2, cnt=0;
	while (cnt<1) {
		i++;
		if (fmod(x,2) == 0) {
			return 1;
		}
		else if (fmod(x,i) == 0) {
			cnt++;
		} else {
			if (i+1 == x) {
				return 0;
			}
		}
	}
	return 1;
}

double GetFactors(double x) {
	if (fmod(x,factor) == 0) {
		if (!IsPrime(factor)) {
			if (Factors[index] != factor) {
				Factors[index] = factor;
				index++;
				return x/factor;
			}
		}
	}
	factor++;
	return x;
}
