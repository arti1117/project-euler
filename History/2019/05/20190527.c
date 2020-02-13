/*
 * 20190527.c
 *
 *  Created on: May 27, 2019
 *      Author: arti
 */

#include <stdio.h>

#define INPUT_FILE "..//IO_files/2019/201905/i_20190527.txt"
#define OUTPUT_FILE "..//IO_files/2019/201905/o_20190527.txt"
#define MAX 20
#define FALSE 0
#define TRUE (!FALSE)

typedef int bool;

int T, N, X;
int DNA[2][MAX];
FILE *inf, *ouf;

void inputs(void)
{
	int i;
	fscanf(inf, "%d\n", &N);
	for (i=0; i<N; i++) {
		fscanf(inf, "%d", &DNA[0][i]);
	}
}

void solve(void)
{
	int flag = 0;
	int i, j;
	bool NotComplete = TRUE;
	X = -1;

	while (NotComplete) {
		DNA[1-flag][N-2] = DNA[flag][N-1];

		for (i=N-4; i>=0; i-=2)
			DNA[1-flag][i] = DNA[flag][i+1] - DNA[1-flag][i+2];

		j = 1 - i - 2;

		DNA[1-flag][j] = DNA[flag][0] - DNA[1-flag][1-j];

		for (i=j+2; i<N; i+=2)
			DNA[1-flag][i] = DNA[flag][i-1] - DNA[1-flag][i-2];

		X++;
		flag = 1-flag;

		for (i=0; i<N; i++) {
			fprintf(ouf, "%2d", DNA[flag][i]);

			if (DNA[flag][i] < 0)
				NotComplete = FALSE;
		}
		fprintf(ouf, "\n");
	}

	if (X == 0)
		X = -1;
}

void outputs(void)
{
	fprintf(ouf, "=========================================================\n");
	fprintf(ouf, "%dTimes Division\n\n", X);
}

void test()
{
	int i;
	inf = fopen(INPUT_FILE, "r");
	ouf = fopen(OUTPUT_FILE, "w");

	fscanf(inf, "%d\n", &T);

	for (i=0; i<T; i++) {
		inputs();
		solve();
		outputs();
	}

	fclose(inf);
	fclose(ouf);
}
