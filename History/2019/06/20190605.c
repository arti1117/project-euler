/*
 * 20190605.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//a^2 + b^2 = c^2
//
//For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

#include "Architects.h"

#define MAX 1000

int GetPower(int x)
{
	int y = 1;
	while (x>0) {
		x--;
		y *= 10;
	}
	return y;
}

int GetDigit(int x)
{
	int y=0;
	while (x>0) {
		y++;
		x /= 10;
	}
	return y;
}

int GetSquare(int x)
{
	int y=0, z, w, k;
	z = GetDigit(x);
//	below the code using int trick
	w = (z+1) / 2;
//	if (z%2==0) {
//		w = z/2;
//	} else {
//		w = (z+1) / 2;
//	}

	k = GetPower(w);

	while (y<k) {
		y++;
		if (y*y == x) {
			return y;;
		}
	}
	return 0;
}

void test()
{
	int i, j, k;
	int a=1, b=2, c=3, thou=1000;

	for (i=1; i<MAX; i++) {
		for (j=i+1; j<MAX; j++) {
			k = GetSquare(i*i + j*j);
			if (i+j+k > 1000) {
				break;
			}
			if (j<k && i+j+k == thou) {
				break;
			}
		}
		if (i+j+k == thou) {
			a = i; b = j; c = k;
			break;
		}
	}
//	printf("%d\n", GetDigit(1000));
//	printf("%d\n", GetSquare(10000));
	printf("%d^2 + %d^2 = %d^2\n%d + %d + %d = %d\n", a, b, c, a, b, c, thou);
}

//200^2 + 375^2 = 425^2
//200 + 375 + 425 = 1000
//The Function took 31.754415 seconds to execute.

