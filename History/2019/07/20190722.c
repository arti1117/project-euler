/*
 *  20190722.c
 *  20:00 ~ 22:00
 *  Created on: Jul 22, 2019
 *      Author: arti
 */

// Palindrome And Get Day Funtions from [누워서 읽는 알고리즘]

#include "Architects.h"

int isPalindrome(char[]);

void test()
{
    char s[] = "SES";
    printf("%d\n", isPalindrome(s));
    printf("%d\n", isLeapYear(2100));
}

int isPalindrome(char s[])
{
    int i, j, k, length;

    /* Getting Strings Length */
    for (length=0; s[length] != '\0'; length++) {
        ;
    }

    j = length / 2;
    k = length - 1;

    for (i=0; i < j; i++) {
        if (s[i] != s[k-i]) {
            return 0;
        }
    }

    return 1;
}

int isLeapYear(int x)
{
    return (x % 100 == 0 && x % 400 != 0) ? 0 : (x % 4 == 0) ? 1 : 0;
}

