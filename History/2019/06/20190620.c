/*
 * 20190620.c
 *
 *  Created on: Jun 20, 2019
 *      Author: arti
 */

//Number letter counts
//Problem 17
//
//If the numbers 1 to 5 are written out in words: one, two, three, four, five,
//then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
//how many letters would be used?
//
//NOTE: Do not count spaces or hyphens.
//For example, 342 (three hundred and forty-two) contains 23 letters
//and 115 (one hundred and fifteen) contains 20 letters.
//The use of "and" when writing out numbers is in compliance with British usage.
//

#include "Architects.h"

void test()
{
    double total;

    int i;
    int x;
    int y;

    int letters[1001];

    letters[0] = 4; // zero
    letters[1] = 3; // one
    letters[2] = 3; // two
    letters[3] = 5; // three
    letters[4] = 4; // four
    letters[5] = 4; // five
    letters[6] = 3; // six
    letters[7] = 5; // seven
    letters[8] = 5; // eight
    letters[9] = 4; // nine

    // total = 0;
    // for (i=1; i<10; i++) {
    //     total += letters[i];
    // }

    letters[10] = 3; // ten
    letters[11] = 6; // eleven
    letters[12] = 6; // twelve
    letters[13] = 8; // thirteen
    letters[14] = 8; // fourteen
    letters[15] = 7; // fifteen
    letters[16] = 7; // sixteen
    letters[17] = 9; // seventeen
    letters[18] = 8; // eighteen
    letters[19] = 8; // nineteen

    // total = 0;
    // for (i=10; i<20; i++) {
    //     total += letters[i];
    // }

    letters[20] = 6; // twenty
    letters[30] = 6; // thirty
    letters[40] = 5; // forty
    letters[50] = 5; // fifty
    letters[60] = 5; // sixty
    letters[70] = 7; // seventy
    letters[80] = 6; // eighty
    letters[90] = 6; // ninety

    for (i=20; i<100; i++) {
        if (i % 10 != 0) {

            x = i / 10;
            x *= 10;
            y = i - x;

            letters[i] = letters[x] + letters[y];
        }
    }

    // total = 0;
    // for (i=20; i<100; i++) {
    //     total += letters[i];
    // }

    int _and_ = 3;
    int hundred = 7;
    int thousand = 8;

    for (i=100; i<1000; i++) {

        if (i % 100 == 0) {

            x = i / 100;

            letters[i] = hundred + letters[x];
        } else {

            x = i / 100;
            x *= 100;
            y = i - x;

            letters[i] = letters[x] + _and_ + letters[y];            
        }
    }

    // total = 0;
    // for (i=100; i<1000; i++) {
    //     total += letters[i];
    // }

    letters[1000] = letters[1] + thousand;

    total = 0;
    for (i=1; i<1001; i++) {
        total += letters[i];
    }

    printf("The sum of letters from one to one thousand is %.0f.\n", total);
}
