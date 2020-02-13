/*
 * 20190611.c
 *
 *  Created on: Jun 11, 2019
 *      Author: arti
 */

#include "Architects.h"

//void f(int *p, int *q)
//{
//  p = q;
//  *p = 2;
//}
//
//int i = 0, j = 1;
//
//void test()
//{
//  f(&i, &j);
//  printf("%d %d \n", i, j);
//}

//void swap(int *px, int *py)
//{
//   *px = *px - *py;
//   *py = *px + *py;
//   *px = *py - *px;
//}
//S1: will generate a compilation error
//S2: may generate a segmentation fault at runtime depending on the arguments passed
//S3: correctly implements the swap procedure for all input pointers referring
//    to integers stored in memory locations accessible to the process
//S4: implements the swap procedure correctly for some but not all valid input pointers
//S5: may add or subtract integers and pointers.
//
//Answer: S2 and S4 Explanation:
//S2: May generate segmentation fault if value at pointers px or py is constant or px or py points to a memory location that is invalid
//S4: May not work for all inputs as arithmetic overflow can occur

//int f(int x, int *py, int **ppz)
//{
//  int y, z;
//  **ppz += 1;
//   z  = **ppz;
//  *py += 2;
//   y = *py;
//   x += 3;
//   return x + y + z;
//}
//
//void test()
//{
//   int c, *b, **a;
//   c = 4;
//   b = &c;
//   a = &b;
//   printf("%d\n", f(c, b, a));
//}

//void test()
//{
//    int a = 12;
//    void *ptr = (int *)&a;
////    printf("%d\n", *ptr);
//}

//void swap (char *x, char *y)
//{
//    char *t = x;
//    x = y;
//    y = t;
//}
//
//void test()
//{
//    char *x = "geeksquiz";
//    char *y = "geeksforgeeks";
//    char *t;
//    printf("(%p, %p)\n", x, y);
//    swap(x, y);
//    printf("(%s, %s)\n", x, y);
//    printf("(%p, %p)\n", x, y);
//    t = x;
//    x = y;
//    y = t;
//    printf("(%s, %s)\n", x, y);
//    printf("(%p, %p)\n", x, y);
//}

//void test()
//{
//    int arr[] = {1, 2, 3, 4, 5};
//    int *p = arr;
//    ++*p;
//    p += 2;
//    printf("%d\n", *p);
//}

//void f(int *p, int *q)
//{
//  p = q;
// *p = 2;
//}
//int i = 0, j = 1;
//void test()
//{
//  f(&i, &j);
//  printf("%d %d\n", i, j);
//}

//void f(char **p)
//{
//    char *t;
//    t = (p += sizeof(int))[-1];
//    printf("%s\n", t);
//}
//void test()
//{
//    char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" };
//    f(argv);
//}

//int ( * f) (int * ) ;
//(A) A function that takes an integer pointer as argument and returns an integer.
//(B) A function that takes an integer as argument and returns an integer pointer.
//(C) A pointer to a function that takes an integer pointer as argument and returns an integer.
//(D) A function that takes an integer pointer as argument and returns a function pointer
//
//Answer: (C)
//Explanation: The steps to read complicated declarations :
//
//1)Convert C declaration to postfix format and read from left to right.
//
//2)To convert expression to postfix, start from innermost parenthesis,
//  If innermost parenthesis is not present then start from declarations name and go right first.
//  When first ending parenthesis encounters then go left.
//  Once the whole parenthesis is parsed then come out from parenthesis.
//
//3)Continue until complete declaration has been parsed.
//
//At First, we convert the following given declaration into postfix:
//
//int ( * f) (int * )
//Since there is no innermost bracket, so first we take declaration name f,
//so print “f” and then go to the right, since there is nothing to parse, so go to the left.
//There is * at the left side, so print “*”.Come out of parenthesis.
//Hence postfix notation of given declaration can be written as follows:
//
//f * (int * ) int
//Meaning: f is a pointer to function (which takes one argument of int pointer type) returning int .
//

//int x;
//void Q(int z)
//{
//    z += x;
//    printf("%d\n", z);
//}
//void P(int *y)
//{
//    int x = *y + 2;
//    Q(x);
//    *y = x - 1;
//    printf("%d\n", x);
//}
//void test()
//{
//    x = 5;
//    P(&x);
//    printf("%d\n", x);
//}
