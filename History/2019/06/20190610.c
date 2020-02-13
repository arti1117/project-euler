/*
 * 20190610.c
 *
 *  Created on: Jun 10, 2019
 *      Author: arti
 */

#include "Architects.h"

//void fun1(int x)
//{
//    x = 30;
//}
//
//void test()
//{
//  int y = 20;
//  fun1(y);
//  printf("%d\n", y);
//}

//void fun2(int *ptr)
//{
//    *ptr = 30;
//}
//
//void test()
//{
//  int y = 20;
//  fun2(&y);
//  printf("%d\n", y);
//
//}

//void test()
//{
//    int *ptr;
//    int x;
//
//    ptr = &x;
//    *ptr = 0;
//
//    printf(" x = %d\n", x);
//    printf(" *ptr = %d\n", *ptr);
//
//    *ptr += 5;
//    printf(" x  = %d\n", x);
//    printf(" *ptr = %d\n", *ptr);
//
//    (*ptr)++;
//    printf(" x = %d\n", x);
//    printf(" *ptr = %d\n", *ptr);
//
//}

//void test()
//{
//    int arri[] = {1, 2 ,3};
//    int *ptri = arri;
//
//    char arrc[] = {1, 2 ,3};
//    char *ptrc = arrc;
//
//    printf("sizeof arri[] = %lu\n ", sizeof(arri));
//    printf("sizeof ptri = %lu\n", sizeof(ptri));
//
//    printf("sizeof arrc[] = %lu\n", sizeof(arrc));
//    printf("sizeof ptrc = %lu\n", sizeof(ptrc));
//}

//void test()
//{
//    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
//    float *ptr1 = &arr[0];
//    float *ptr2 = ptr1 + 1;
//
//    printf("%f\n", *ptr2);
//    printf("%lu\n", ptr2 - ptr1);
//}

//void test()
//{
//    int arr[] = {10, 20, 30, 40, 50, 60};
//    int *ptr1 = arr;
//    int *ptr2 = arr + 5;
//    printf("Number of elements between two pointer are: %lu.\n", (ptr2 - ptr1));
//    printf("Number of bytes between two pointers are: %lu\n", (char*)ptr2 - (char*)ptr1);
//}

//void test()
//{
//   int a;
//   char *x;
//   x = (char *) &a;
//   a = 512;
//   x[0] = 1;
//   x[1] = 2;
//   printf("%d\n",a);
//}

//void test()
//{
//	char *ptr = "GeeksQuiz";
//	printf("%c\n", *&*&*ptr);
//}

//void fun(int arr[])
//{
//  int i;
//  int arr_size = sizeof(arr)/sizeof(arr[0]);
//  for (i = 0; i < arr_size; i++)
//      printf("%d\n", arr[i]);
//
//  printf("%d\n", (int)sizeof(arr));
//  printf("%lu\n", sizeof(arr[0]));
//}
//
//void test()
//{
//  int i;
//  int arr[4] = {10, 20 ,30, 40};
//  fun(arr);
//}

//The reason for using pointers in a Cprogram is All of these.
//(A) Pointers allow different functions to share and modify their local variables.
//(B) To pass large structures so that complete copy of the structure can be avoided.
//(C) Pointers enable complex “linked” data structures like linked lists and binary trees.
//
//Explanation: See below explanation
//(A) With pointers, address of variables can be passed different functions can use this address to access the variables.
//(B) When large structure variables passed or returned, they are copied as everything is passed and returned by value in C. This can be costly with structure containing large data. To avoid this copying of large variables, we generally use poitner for large structures so that only address is copied.
//(C) With pointers, we can implement “linked” data structures. Java uses reference variables to implement these data structures. Note that C doesn’t support reference variables.


