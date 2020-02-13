/*
 *  MergeSort1.c
 *
 *  Created on: Aug 25, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNumber(void);
void MergeSort(int[], int, int);
void DisplayBuffer(void);
int IsNumberExit(int, int);
int Buf[MAX];
int temp[MAX];

void MakeRandomNumber(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while (i < MAX) {
		Num = rand() % MAX;

		if (!IsNumberExit(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void MergeSort(int data[], int left, int right)
{
	int i, j, k, middle;
	if (right > left) {
		middle = (left + right) / 2;

		MergeSort(data, left, middle);
		MergeSort(data, middle + 1, right);

		for (i = middle + 1; i > left; i--)
			temp[i - 1] = data[i - 1];

		for (j = middle; j < right; j++)
			temp[right + middle - j] = data[j + 1];

		for (k = left; k <= right; k++)
			data[k] = (temp[i] < temp[j]) ? temp[i++] : temp[j--];
	}
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

void main()
{
	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber();
	DisplayBuffer();
	printf("정렬 후 데이터\n");

	MergeSort(Buf, 0, MAX - 1);
	DisplayBuffer();
	printf("\n");
}
