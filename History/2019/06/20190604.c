/*
 * 20190604.c
 *
 *  Created on: Jun 4, 2019
 *      Author: arti
 */

#include "Architects.h"

#define INPUT_FILE "..//IO_files/2019/201906/i_20190604.txt"
#define OUTPUT_FILE "..//IO_files/2019/201906/o_20190604.txt"
#define MAX 10

int M, N, X, F, Y , O, E;
int a, b, c, d, max, cnt = 1;
int leng=0;

int BEFORE[MAX][MAX];
int AFTER[MAX][MAX];
char MAP[MAX][MAX];

char RESULT[MAX][2];

FILE *inf, *ouf;

void inputs()
{
	int i, j;
	char z;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			fscanf(inf, "%c", &z);
			if (z == 'F') {
				BEFORE[i][j] = max;
				AFTER[i][j] = max;
			} else if (z == 'O') {
				BEFORE[i][j] = 0;
				AFTER[i][j] = 0;
			} else if (z == 'Y') {
				BEFORE[i][j] = 1;
				AFTER[i][j] = 1;
				a=i, b=j;
			} else if (z == 'E') {
				BEFORE[i][j] = -1;
				AFTER[i][j] = -1;
				c=i, d=j;
			}
			MAP[i][j] = '-';
		}
		fscanf(inf,"\n");
	}
}

void checking()
{

}

void turningback()
{

}

void searching()
{
	if (cnt>2) {
		if (RESULT[leng][0] != 'D' && a+1<M && BEFORE[a+1][b] == cnt-1) {
			RESULT[leng][0] = 'D';
		}
		if (RESULT[leng][0] != 'R' && b+1<N && BEFORE[a][b+1] == cnt-1) {
			RESULT[leng][0] = 'R';
		}
		if (RESULT[leng][0] != 'D' && 0<a && BEFORE[a-1][b] == cnt-1) {
			RESULT[leng][0] = 'D';
		}
		if (RESULT[leng][0] != 'L' && 0<b && BEFORE[a][b-1] == cnt-1) {
			RESULT[leng][0] = 'L';
		}
	}
}

void moving()
{
	cnt++;
	int i, j;
	searching();
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (BEFORE[i][j] == cnt-1) {
				if (j+1<N && (BEFORE[i][j+1] == 0 || BEFORE[i][j+1] == -1)) {
					AFTER[i][j+1] = cnt;
				}
				if (0<j && (BEFORE[i][j-1] == 0 || BEFORE[i][j-1] == -1)) {
					AFTER[i][j-1] = cnt;
				}
				if (i+1<M && (BEFORE[i+1][j] == 0 || BEFORE[i+1][j] == -1)) {
					AFTER[i+1][j] = cnt;
				}
				if (0<i && (BEFORE[i-1][j] == 0 || BEFORE[i-1][j] == -1)) {
					AFTER[i-1][j] = cnt;
				}
			}
		}
	}

	if (cnt>X && (cnt-2) % X == 0) {
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				if (BEFORE[i][j] == max) {
					if (i+1<M) {
						AFTER[i+1][j] = max;
					}
					if (j+1<N) {
						AFTER[i][j+1] = max;
					}
					if (0<i) {
						AFTER[i-1][j] = max;
					}
					if (0<j) {
						AFTER[i][j-1] = max;
					}
				}
			}
		}
	}
	leng++;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (AFTER[i][j] == cnt) {
				MAP[i][j] = '+';
			}
		}
	}

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			BEFORE[i][j] = AFTER[i][j];
		}
	}
}

void solve()
{
//	while (AFTER[c][d] == -1) {
//		moving();
//	}
	int i = 8;
	while (0<i) {
		moving();
		i--;
	}
	MAP[a][b] = '@';
	MAP[c][d] = '#';
}

void outputs()
{
	int i, j;
	fprintf(ouf, "%d\n", cnt-1);
	fprintf(ouf, "----------------------------------------------------\n");
	for (i=0; i<cnt-1; i++) {
		fprintf(ouf, "%2c", RESULT[i][1]);
	}
	fprintf(ouf, "\n----------------------------------------------------\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			fprintf(ouf, "%3d", AFTER[i][j]);
		}
		fprintf(ouf, "\n");
	}
	fprintf(ouf, "----------------------------------------------------\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			fprintf(ouf, "%2c ", MAP[i][j]);
		}
		fprintf(ouf, "\n");
	}
}

void test()
{
	inf = fopen(INPUT_FILE, "r");
	ouf = fopen(OUTPUT_FILE, "w");

	fscanf(inf, "%d %d %d\n", &M, &N, &X);
	max = M * N;

	inputs();
	solve();
	outputs();

	fclose(inf);
	fclose(ouf);
}
