/*
 * 20190606.c
 *
 *  Created on: Jun 6, 2019
 *      Author: arti
 */

#include "Architects.h"

#define INPUT_FILE "..//IO_files/2019/201906/i_20190606.txt"
#define OUTPUT_FILE "..//IO_files/2019/201906s/o_20190606.txt"
#define MAX 6
#define FIRE_MAX MAX*MAX
#define FALSE 0
#define TRUE (!FALSE)

typedef int BOOL;

int M, N, X;
int BUILD[MAX][MAX], PATH[MAX][MAX], ROOT[MAX][MAX];
int MyQueue[FIRE_MAX][2];
char DIR[5] = {' ', 'U', 'L', 'R', 'D'}, RESULT[FIRE_MAX];
int res_n, res_y, res_x, stx, sty, front, rear;

BOOL found;

void Input_data()
{
	int i, j;
	char ch;
	FILE *inf;
	inf = fopen(INPUT_FILE, "r");
	fscanf(inf, "%d %d %d\n", &M, &N, &X);

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			fscanf(inf, "%c", &ch);

			if (ch == 'F') {
				BUILD[i][j] = FIRE_MAX;
			}
			if (ch == 'Y') {
				sty = i;
				stx = j;
			}
			if (ch == 'E') {
				BUILD[i][j] = -1;
			}
		}
		fscanf(inf, "\n");
	}
	fclose(inf);
}

void InsertData(int y, int x, int dir, int count)
{
	MyQueue[rear][0] = y;
	MyQueue[rear][1] = x;

	if (BUILD[y][x] == -1) {
		found = TRUE;
		res_y = y;
		res_x = x;
	}

	BUILD[y][x] = count;
	ROOT[y][x] = dir;
	rear++;
}

void RemoveData(int *y, int *x)
{
	*y = MyQueue[front][0];
	*x = MyQueue[front][1];
	front++;
}

void Fire()
{
	int i, j;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (BUILD[i][j] == FIRE_MAX) {
				if (i>0)
					PATH[i-1][j] = FIRE_MAX;
				if (j>0)
					PATH[i][j-1] = FIRE_MAX;
				if (i<M-1)
					PATH[i+1][j] = FIRE_MAX;
				if (j<N-1)
					PATH[i][j+1] = FIRE_MAX;
			}
		}
	}

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (PATH[i][j] == FIRE_MAX) {
				BUILD[i][j] = FIRE_MAX;
			}
		}
	}
}

void SearchPath()
{
	int x, y;
	int bound;
	int count = 0;
	InsertData(sty, stx, 0, count+1);
	bound = rear + 1;
	while (rear >= front) {
		RemoveData(&y, &x);
		if (front >= bound) {
			count++;
			if ((count>X) && ((count-1) % X == 0)) {
				Fire();
			}
			bound = rear + 1;
		}

		if (BUILD[y][x] == FIRE_MAX)
			continue;

		if ((y>0) && (BUILD[y-1][x] <= 0))
			InsertData(y-1, x, 4, count+2);

		if ((y<M-1) && (BUILD[y+1][x] <= 0))
			InsertData(y+1, x, 1, count+2);

		if ((x>0) && (BUILD[y][x-1] <= 0))
			InsertData(y, x-1, 3, count+2);

		if ((x<N-1) && (BUILD[y][x+1] <= 0))
			InsertData(y, x+1, 2, count+2);

		if (found) {
			res_n = count + 1;
			break;
		}
	}
}

void next(int *y, int *x)
{
	int temp = ROOT[*y][*x];
	switch(temp) {
	case 1 :
		(*y)--;
		break;
	case 2 :
		(*x)--;
		break;
	case 3 :
		(*x)++;
		break;
	case 4 :
		(*y)++;
		break;
	}
}

void Output_result()
{
	int i;
	FILE *ouf;
	ouf = fopen(OUTPUT_FILE, "w");

	if (!found)
		fprintf(ouf, "Impossible\n");
	else {
		fprintf(ouf, "%d\n", res_n);
		RESULT[res_n] = '\0';

		for(i=res_n-1; i>=0; i--) {
			RESULT[i] = DIR[5-ROOT[res_y][res_x]];
			next(&res_y, &res_x);
		}

		fprintf(ouf, "%s\n", RESULT);
	}
	fclose(ouf);
}

void test()
{
	Input_data();
	SearchPath();
	Output_result();
}

