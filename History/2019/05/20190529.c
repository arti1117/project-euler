/*
 * 20190529.c
 *
 *  Created on: May 29, 2019
 *      Author: arti
 */

#include <stdio.h>

#define INPUT_FILE "..//IO_files/2019/201905/i_20190529.txt"
#define OUTPUT_FILE "..//IO_files/2019/201905/o_20190529.txt"
#define MAX 20
#define FALSE 0
#define TRUE (!FALSE)

typedef int bool;

int T, N, X;
int DNA[2][MAX];
FILE *inf, *ouf;

void inputs()
{
	int i;
	fscanf(inf, "%d\n", &N);
	for (i=0; i<N; i++) {
		fscanf(inf, "%d", &DNA[0][i]);
	}
}

void solve()
{
	int flag = 1;
	int i;

	DNA[flag][0] = DNA[flag-1][0] + DNA[flag-1][1];
	for (i=1; i<N-1; i++) {
		DNA[flag][i] = DNA[flag-1][i-1] + DNA[flag-1][i+1];
	}
	DNA[flag][i] = DNA[flag-1][i-1];

	for (i=0; i<N; i++) {
		fprintf(ouf, "%d ", DNA[0][i]);
		DNA[flag-1][i] = DNA[flag][i];
	}
}

void outputs()
{
	int i;
	for (i=0; i<(N*2)-1; i++) {
		fprintf(ouf, "=");
	}
	fprintf(ouf, "\n%dTimes Proliferation\n", T);
}

void test()
{
	int i;
	inf = fopen(INPUT_FILE, "r");
	ouf = fopen(OUTPUT_FILE, "w");

	fscanf(inf, "%d\n", &T);

	inputs();
	for (i=0; i<=T; i++) {
		solve();
		fprintf(ouf, "\n");
	}
	outputs();

	fclose(inf);
	fclose(ouf);
}
