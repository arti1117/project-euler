/*
 * 20190523.c
 *
 *  Created on: May 23, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);
int lcm(int, int);

void test()
{
	printf("This is get the least common multiple program.\nPlease Input what you want to find it!.\n");
	int a, b, c;
	scanf("%d %d", &a, &b);

	c = lcm(a, b);
	printf("The least common multiple between %d and %d is %d.\n", a, b, c);
}

int lcm(int x, int y)
{
	return (x * y) / gcd(x, y);
}

int gcd(int x, int y)
{
	if (y != 0) {
		return gcd(y, x % y);
	} else {
		return x;
	}
}
