/*
 * 20190613.c
 *
 *  Created on: Jun 13, 2019
 *      Author: arti
 */

#include "Architects.h"

//void swap(int* x, int* y)
//{
//	int t = *x;
//	*x = *y;
//	*y = t;
//}
//
//void test()
//{
//    int array[] = {3, 5, 1, 4, 6, 2};
//    int done = 0;
//    int i;
//
//    while (done == 0)
//    {
//        done  = 1;
//        for (i = 0; i <= 4; i++)
//        {
//            if (array[i] < array[i+1])
//            {
//                swap(&array[i], &array[i+1]);
//                done = 0;
//            }
//        }
//        for (i = 5; i >= 1; i--)
//        {
//            if (array[i] > array[i-1])
//            {
//                swap(&array[i], &array[i-1]);
//                done = 0;
//            }
//        }
//    }
//
//    printf("%d\n", array[3]);
//}

//Faster access to non-local variables is achieved using an array of pointers to activation records, called a activation tree.

//Activation Records are required to keep the information of subroutine calls.
//The languages which allow subroutine calls create an activation record whenever a subroutine call is made.
//
//Assembler maintains a location counter to assign storage addresses to each instruction of our program.
//
//Reference counter tracks for each object, counts the number of references made by it
//and when the count reaches zero, the object becomes inaccessible and gets destroyed.
//
//A linking loader generally performs the reallocation of code.

//Continue until complete declaration has been parsed.
//
//At First, we convert the following given declaration into postfix:
//
//int ( * f) (int * )
//
//Since there is no innermost bracket, so first we take declaration name f,
//so print “f” and then go to the right, since there is nothing to parse,
//so go to the left. There is * at the left side, so print “*”.Come out of parenthesis.
//
//Hence postfix notation of given declaration can be written as follows:
//
//f * (int * ) int
//
//Meaning: f is a pointer to function (which takes one argument of int pointer type) returning int .

//void test()
//{
//	int k=5;
//	int *p=&k;
//	int **m=&p;
//	printf("%d %d %d\n",k,*p,**m);
//}

//References cannot be null, whereas pointers can; every reference refers to some object,
//although it may or may not be valid. A reference can never be re-assigned once it is established.

//int * f [ ] ( ); is an array of functions returning pointers to integers

//int (*f())[ ]; declares a function returning a pointer to an array of integers.

//char ∗(∗(∗ a[N]) ( )) ( );
//a pointer to a function returning array of n pointers to function returning character pointers;
//a function return array of N pointers to functions returning pointers to characters;
//an array of n pointers to function returning pointers to characters;
//an array of n pointers to function returning pointers to functions returning pointers to characters.

//void test()
//{
//	char g[] = "geeskforgaaks";
//	printf("%s\n", g);
//	printf("%d\n", g[6] - g[8]);
//	printf("%s\n", g + 8);
//	printf("%s\n", g + g[6] - g[8]);
//}
//
// g[6] is 'o' and g[8] is 'g'.
// g[6] - g[8] = ASCII value of 'o' - ASCII value of 'g' = 8
// So the expression  g + g[6] - g[8] becomes g + 8 which is
// base address of string "gaaks"

