/*
 * 20190521.c
 *
 *  Created on: May 23, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

void test()
{
	int i, j, max, cnt = 0, line = 7, digit = 11;
	printf("Input Maximum range for getting prime number from 1.\n");
	scanf("%d", &max);

	while (max > digit) {
		digit *= 10;
		line++;
	}

	printf("The prime number list from 1 to %d.\n", max);
	for (i = 1; i <= max; i++) {
		for (j=2; j < i; j++) {
			if (i%2 == 0) {
				break;
			}
			if (i%j == 0) {
				break;
			}
		}
		if (i == j) {
			printf("%d\t", i);
			cnt++;
			if (cnt % line == 0) {
				printf("\n");
			}
		}
	}
}
