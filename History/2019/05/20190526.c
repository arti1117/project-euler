/*
 * 20190526.c
 *
 *  Created on: Jun 15, 2019
 *      Author: arti
 */

//Each new term in the Fibonacci sequence is generated
//by adding the previous two terms. By starting with 1 and 2,
//the first 10 terms will be:
//
//1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
//By considering the terms in the Fibonacci sequence
//whose values do not exceed four million,
//find the sum of the even-valued terms.

#include "Architects.h"

//void test()
//{
//	setlocale(LC_NUMERIC, "");
//
////    printf("%'d\n", 4000000);
//	int a, b, c;
//	double sum = 2.0;
//	int cnt;
//	a = 1;
//	b = 2;
//	c = 0;
//	cnt=0;
//	printf("1, 2, ");
//	while (c < 4000000) {
//		cnt++;
//		c = a+b;
//		a = b;
//		b = c;
//		if (c%2==0) {
//			sum += (double)c;
//		}
//		printf("%d, ", c);
//		if (cnt % 10 == 0) {
//			printf("\n");
//		}
//	}
//	printf("\n %'.0f\n", sum);
//}

void test()
{
	setlocale(LC_NUMERIC, "");

//    printf("%'d\n", 4000000);
	double a, b, c;
	double sum = 2.0;
	a = 1;
	b = 2;
	c = 0;
	while (c<1000000000) {
		c = a+b;
		a = b;
		b = c;
		if (fmod(c, 2) == 0.0) {
			sum += c;
		}
	}
	printf("%'.0f\n", sum);
}
