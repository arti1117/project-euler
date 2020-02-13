/*
 *  HeapSort.c
 *
 *  Created on: Aug 25, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_INT 65536
#define MAX 100

void MakeRandomNumber(void);
void HeapSort(int);
void DisplayBuffer(void);
int IsNumberExit(int, int);
void upheap(int);
void downheap(int);
void InsertData(int);
int RemoveData(void);

int Buf[MAX];
int Data[MAX];
int temp[MAX];
int NUM;

void MakeRandomNumber(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Data[0] = 100;

	while (i < MAX) {
		Num = rand() % MAX;

		if (!IsNumberExit(Num, i)) {
			Data[i] = Num;
			i++;
		}
	}
}

void HeapSort(int N)
{
	int i;

	for (i = 0; i < MAX; i++)
		InsertData(Data[i]);
	Data[0] = 1;

	for (i = MAX - 1; i >= 0; i--)
		Data[i] = RemoveData();
}

void DisplayBuffer(void)
{
	int i;

	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d ", Data[i]);
	}

	printf("\n");
}

int IsNumberExit(int number, int index)
{
	int i;

	for (i = 0; i < index; i++) {
		if (Data[i] == number || number == 0)
			return TRUE;
	}

	return FALSE;
}

void upheap(int k)
{
	int v;
	v = Buf[k];
	Buf[0] = MAX_INT;

	while (Buf[k / 2] <= v) {
		Buf[k] = Buf[k / 2];
		k = k / 2;
	}

	Buf[k] = v;
}

void downheap(int k)
{
	int i, v;
	v = Buf[k];

	while (k <= NUM / 2) {
		i = 2 * k;

		if (i < NUM && Buf[i] < Buf[i + 1])
			i++;

		if (v >= Buf[i])
			break;

		Buf[k] = Buf[i];
		k = i;
	}

	Buf[k] = v;
}

void InsertData(int v)
{
	Buf[++NUM] = v;
	upheap(NUM);
}

int RemoveData(void)
{
	int v = Buf[1];
	Buf[1] = Buf[NUM--];
	downheap(1);

	return v;
}

void main()
{
	NUM = MAX;

	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber();
	DisplayBuffer();
	printf("정렬 후 데이터\n");

	HeapSort(NUM);
	DisplayBuffer();
	printf("\n");
}
