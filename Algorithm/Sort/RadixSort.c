/*
 *  RadixSort.c
 *
 *  Created on: Aug 25, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int Data;
	struct _NODE *Next;
} NODE;

NODE *Front[10];
NODE *Rear[10];
NODE *ptrNode;
int Buf[MAX];

void MakeRandomNumber(void);
void RadixSort(void);
void DisplayBuffer(void);
int IsNumberExit(int, int);
void InitializeQueue(void);
void Put(int, int);
int Get(int);

void MakeRandomNumber(void)
{
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < MAX) {
		Num = rand() % 100;

		if (!IsNumberExit(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void RadixSort(void)
{
	int i, num, digit, j;
	j = 0;

	for (i = 0; i < MAX; i++) {
		num = Buf[i];
		digit = num % MAX;
		Put(digit, num);
	}

	printf("1의 자릿수로 정렬된 숫자 리스트\n");

	for (i = 0; i < MAX; i++) {
		printf("\n%d의 자리: ", i);

		while (1) {
			num = Get(i);

			if (num != -1) {
				printf("%3d ", num);
				Buf[j++] = num;
			}

			else
				break;
		}
	}

	printf("\n\n1차 정렬 후 Buf 안의 데이터들\n");
	DisplayBuffer();

	j = 0;

	for (i = 0; i < MAX; i++) {
		num = Buf[i];
		digit = num / MAX;
		Put(digit, num);
	}

	printf("10의 자릿수로 정렬된 숫자 리스트\n");

	for (i = 0; i < MAX; i++) {
		printf("\n%d의 자리 : ", i);
		while (1) {
			num = Get(i);

			if (num != -1) {
				printf("%3d ", num);
				Buf[j++] = num;
			}

			else
				break;
		}
	}

	printf("\n\n2차 정렬 후 Buf 안의 데이터들\n");
	DisplayBuffer();
}

void DisplayBuffer(void)
{
	int i;

	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d ", Buf[i]);
	}

	printf("\n");
}

int IsNumberExit(int number, int index)
{
	int i;

	for (i = 0; i < index; i++) {
		if (Buf[i] == number || number == 0)
			return TRUE;
	}

	return FALSE;
}

void InitializeQueue(void)
{
	int i;

	for (i = 0; i < MAX; i++) {
		Front[i] = (NODE *)malloc(sizeof(NODE));
		Rear[i] = (NODE *)malloc(sizeof(NODE));
		Front[i]->Next = Rear[i];
		Rear[i]->Next = Rear[i];
	}
}

void Put(int index, int num)
{
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;

	if (Front[index]->Next == Rear[index]) {
		Front[index]->Next = ptrNode;
		ptrNode->Next = Rear[index];
		Rear[index]->Next = ptrNode;
	}

	else {
		Rear[index]->Next->Next = ptrNode;
		ptrNode->Next = Rear[index];
		Rear[index]->Next = ptrNode;
	}
}

int Get(int index)
{
	int ret;
	NODE *deleteNode;

	if (Front[index]->Next == Rear[index])
		return -1;

	else {
		deleteNode = Front[index]->Next;
		Front[index]->Next = deleteNode->Next;
		ret = deleteNode->Data;

		free(deleteNode);
	}

	return ret;
}

void main()
{
	InitializeQueue();
	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber();
	DisplayBuffer();
	RadixSort();

	printf("\n\n");
	printf("\n");
}
