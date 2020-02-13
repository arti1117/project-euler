/*
 * 20190522.c
 *
 *  Created on: May 23, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);

void test()
{
	printf("This is get the greatest common denominator program.\nPlease Input what you want to find it!.\n");
	int a, b, c;
	scanf("%d %d", &a, &b);

	c = gcd(a, b);
	printf("The greatest common denominator between %d and %d is %d.\n", a, b, c);
}

int gcd(int x, int y)
{
	if (y != 0) {
		return gcd(y, x % y);
	} else {
		return x;
	}
}
