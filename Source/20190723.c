/*
 *  20190723.c
 *  19:00 ~ 22:00
 *  Created on: Jul 23, 2019
 *      Author: arti
 */

// Gruenberger Problem

// 1. Choose any number.
// 2. Reverse the number that you've choosed at <1>
//    And add the numbers.
// 3. If the result of sum is Palindrome then get bact to <2> repeat it,
//    if not end this algorithm.

#include "Architects.h"

void test()
{
    long double num = 13;

    long double digit;

    long double rev;

    do {

        digit = getDigit(num);
        
        rev = reverse(num, digit);
        
        num += rev;
        
        digit = getDigit(num);
    
    } while (!isPalindrome(num, digit));

    char* str;

    str = (char *)malloc(digit);
    
}

double getDigit(double num)
{

}

double reverse(double num, double digit)
{

}

int isPalindrome(double num, double digit)
{

}

void getChars(double num)
{

}