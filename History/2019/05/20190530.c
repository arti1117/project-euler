/*
 * 20190530.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//A palindromic number reads the same both ways.
//The largest palindrome made from the product
//of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

#include "Architects.h"

int IsPalindrom(int);

void test() {

	int x, z, y=999;
	int result=0;
	int a, b;

	while (100 < y) {
		y--;
		x=999;
		while (100 < x) {
			x--;
			z = x*y;
			if (!IsPalindrom(z)) {
				if (z>result) {
					result = z;
					a = x;
					b = y;
				}
			}
		}
	}
	printf("%d x %d = %d\n", a, b, result);
}

int IsPalindrom(int x) {

	int i=x, reverse=0;

	while (i != 0) {
	  reverse = reverse * 10;
	  reverse = reverse + i%10;
	  i = i/10;
	}

	if (x==reverse) {
		return 0;
	} else {
		return 1;
	}
}

