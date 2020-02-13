/*
 * 20190612.c
 *
 *  Created on: Jun 12, 2019
 *      Author: arti
 */

#include "Architects.h"

//void test()
//{
//	printf("%lu\n",sizeof(int));
//	printf("%lu\n",sizeof(int*));
//	printf("%lu\n",sizeof(int**));
//
//	char *pChar;
//	int *pInt;
//	float *pFloat;
//
//	printf("%lu\n",sizeof(pChar));
//	printf("%lu\n",sizeof(pInt));
//	printf("%lu\n",sizeof(pFloat));
//}

//In the below statement, ptr1 and ptr2 are uninitialized pointers to int i.e.
//they are pointing to some random address that may or may not be valid address.
//
//int* ptr1, ptr2;
//
//Answer: FALSE
//Explanation: Even though * is placed closer to int, * would be associated to ptr1 only but not to ptr2.
//It means that “int* ptr1” is equal to “int *ptr1”. That’s why only ptr1 is uninitialized pointer to int.
//Basically, though both ptr1 and ptr2 are uninitialized variables yet ptr1 is pointer to int while ptr2 is variable of type int.
//If we really want to make both variables as pointers, we need to mention them as “int *ptr1, *ptr2;”

//void test()
//{
//	int var;  /*Suppose address of var is 2000 */
//
//	void *ptr = &var;
//	*ptr = 5;
//	printf("var=%d and *ptr=%d\n",var,*ptr);
//}
//
//Explanation: Key point in the above snippet is dereferencing of void pointer.
//It should be noted that dereferencing of void pointer isn’t allowed because void is an incomplete data type.
//The correct way to assign value of 5 would be first to typecast void pointer and then use it.
//So instead of *ptr, one should use *(int *)ptr. Correct answer is Compiled Error.

//void mystery(int *ptra, int *ptrb)
//{
//   int *temp;
//   temp = ptrb;
//   ptrb = ptra;
//   ptra = temp;
//}
//
//void test()
//{
//    int a=2016, b=0, c=4, d=42;
//    mystery(&a, &b);
//    if (a < c)
//       mystery(&c, &a);
//    mystery(&a, &d);
//    printf("%d\n", a);
//}

//void f(int* p, int m)
//{
//    m = m + 5;
//    *p = *p + m;
//    return;
//}
//
//void test
//{
//    int i=5, j=10;
//    f(&i, j);
//    printf("%d\n", i+j);
//}

//# define swap1(a,  b) tmp = a; a = b; b = tmp
//void swap2 ( int a, int b)
//{
//	int tmp;
//	tmp = a; a = b; b = tmp;
// }
//
//void swap3 (int*a, int*b)
//{
//	int tmp;
//	tmp = *a; *a = *b; *b = tmp;
//}
//
//void test()
//{
//	int num1 = 5, num2 = 4, tmp;
//	if (num1 < num2) {swap1 (num1, num2);}
//	if (num1 < num2) {swap2 (num1 + 1, num2);}
//	if (num1 >= num2) {swap3 (&num1, &num2);}
//	printf ("%d, %d\n", num1, num2);
//}

//void test()
//{
//    int array[5][5];
//    printf("%d\n",( (array == *array) && (*array == array[0]) ));
//}
//Given is a 2d array array[5][5].
//Suppose base address of array is 2000
//
//array = 2000
//*array = 2000
//
//array[0] = 2000
//
//So expression is something like 2000==2000 && 2000==2000 i.e. 1&&1 will return 1.


//void test()
//{
//int a = 300;
//char *b = (char *)&a;
//*++b = 2;
//printf("%d\n",a);
//}
//Ans is 556 as char pointer will change the second byte of the integer in the memory
//and when you print it as a whole integer using %d , its value will be 556 considering little endian scenario.

//Endianness is about byte address order. Little endian means the lower significant bytes gets the lower addresses.
//Big endian means the other way around.
//So it's about the bytes (8-bit chunks) not nibbles (4-bit chunks).
//Most computers we use (there are a few exceptions) address bytes at the single address level.
//
//Taking the -12 example:
//
//Little endian, in memory, would be:
//000000: F4
//000001: FF

//Big endian, in memory, would be:
//000000: FF
//000001: F4

//The purpose of big-endian is to print hex on computer screens left-to-right
//so they are easier to read by low-level or newb programmers; in other words,
//because the hex gets printed from low memory addresses to high,
//the hex gets flipped unless you change it in software.
//
//The purpose of Little-endian is to not be a wingnut and leave the bytes in sequential order
//so you don't make extra work for developers and instead make
//the VERY limited number of people who care flip the bytes around in software!
//
//It is STRONGLY ADVISED to never use big-endian.
//CPUs today are dual-endian and can handle both big and little endian
//so unless you're interfacing with legacy hardware almost
//the entire industry uses little-endian and big-endian has been scheduled to be completely discontinued by developers.
//
//Little-Endian Without Software Formatting
//    In RAM      Printed
//    +----+     0x01000000
//0x4 | 00 |
//    | 00 |
//    | 00 |
//0x0 | 01 |
//    +----+
//
//Big-Endian Without Software Formatting
//    In RAM      Printed
//    +----+     0x00000010
//0x4 | 01 |
//    | 00 |
//    | 00 |
//0x0 | 00 |
//    +----+
//
//Little-Endian With Software Formatting
//    In RAM      Printed
//    +----+     0x00000010
//0x4 | 00 |
//    | 00 |
//    | 00 |
//0x0 | 01 |
//    +----+
//
//Origins of Endian
//The word Endian is actually an ancient Native Tribe of North America.
//I can't remember exactly how the story went so please post comments filling in the holes,
//but the story is that there were two tribes of Endians engaged in a family feud over
//something silly and eventually the reason why they where feuding was long gone
//but they where still fighting just because of they were still mad.
//
//This is Bananas!
//The term bananas refer to a famous unscientific study alleged to have been done with monkeys.
//The "scientists" put a ladder in a room with a bunch of monkeys and put bananas at the top of the ladder.
//If any of the monkeys tried to climb up the ladder, the mean scientists would spray the all the monkeys with a water.
//The monkeys learned to beat up any of the monkeys that tried to climb up
//the ladder to save themselves from getting sprayed. Eventually, the scientists stopped spraying the monkeys,
//but the monkeys continued to beat up anyone who tried to climb up the ladder.
//The funny thing about this story is that someone just made it up.
//This is what it means when something is completely bananas, such as the war on drugs.
//
//Admittidly, if you sprayed monkeys with a firehose there is a good chance
//the story would be true because the original story didn't inflict enough pain to overcome monkey's love of bananas,
//but it seams as though real scientists aren't that mean.
//
//To see exactly how banans Big-endian is, Lets look at the origins of big-endian.
//Back in the dawn of microprocessors when they were still making the masks and machines by hand,
//the Company Motorola briefly found it was faster at the time to use big endian.
//At the time Motorola CPUs where the fastest, and they developed a firmly entrenched camp of Big-Endianers.
//Not long after when they reduced the size of the integrated circuits this performance increase
//became irrelevant and modern CPUs now are dual-endian and can change endian upon boot.
//This would mirror identically the Bananas story. Someone misunderstood something,
//it became popular with people who don't know what they're doing,
//and now the logic is COMPLETELY BANANAS!!! #DeleteBigEndian

//void printxy(int x, int y)
//{
//    int *ptr;
//    x = 0;
//    ptr = &x;
//    y = *ptr;
//    *ptr = 1;
//    printf("%d,%d\n", x, y);
//}
//
//void test()
//{
//	printxy(1, 1);
//}


