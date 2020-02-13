/*
 * 20190622.c
 *
 *  Created on: Jun 23, 2019
 *      Author: arti
 */

// Counting Sundays
// Problem 19

// You are given the following information, 
// but you may prefer to do some research for yourself.

//     1 Jan 1900 was a Monday.
//     Thirty days has September, April, June and November.
//     All the rest have thirty-one,
//     Saving February alone,
//     Which has twenty-eight, rain or shine.
//     And on leap years, twenty-nine.
//     A leap year occurs on any year evenly divisible by 4, 
//     but not on a century unless it is divisible by 400.

// How many Sundays fell on the first of the month 
// during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include "Architects.h"

int IsLeapYear(int x) {
    if (x % 4 == 0) {
        if (x % 400 == 0) {
            return 1;
        } else if (x % 100 == 0) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int GetMonthDays(int year, int month) {
    if (IsLeapYear(year)) {
        switch (month) {
            case 1:
                return 31;
            case 2:
                return 29;
            case 3:
                return 31;
            case 4:
                return 30;
            case 5:
                return 31;
            case 6:
                return 30;
            case 7:
                return 31;
            case 8:
                return 31;
            case 9:
                return 30;
            case 10:
                return 31;
            case 11:
                return 30;
            case 12:
                return 31;
        }
    } else {
        switch (month) {
            case 1:
                return 31;
            case 2:
                return 28;
            case 3:
                return 31;
            case 4:
                return 30;
            case 5:
                return 31;
            case 6:
                return 30;
            case 7:
                return 31;
            case 8:
                return 31;
            case 9:
                return 30;
            case 10:
                return 31;
            case 11:
                return 30;
            case 12:
                return 31;
        }
    }
}

int NextMonthFirst(int year, int month, int day) {
    int x = GetMonthDays(year, month);
    if (x==28) {
        return day;
    } else if (x==29) {
        return (day+1)%7;
    } else if (x==30) {
        return (day+2)%7;
    } else if (x==31) {
        return (day+3)%7;
    }
}

void test()
{
    int firstday = 1;
    int count = 0;
    int i, j;

    for (i=1900; i<=2000; i++) {
        for (j=1; j<=12; j++) {
            firstday = NextMonthFirst(i, j, firstday);
            if (i>1900 && firstday==0) {
                count++;
            }
        }
    }

    printf("The number of Sunday fell on the first of the Month is %d.\n", count);
}
