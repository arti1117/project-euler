/*
 * 20190524.c
 *
 *  Created on: May 24, 2019
 *      Author: arti
 */

#include <stdio.h>

#define INPUT_FILE "..//IO_files/2019/201905/i_20190524.txt"
#define OUTPUT_FILE "..//IO_files/2019/201905/o_20190524.txt"
#define MAXLINE 100
#define MAXWEIGHT 1000
#define MAXVALUE (5000 * MAXWEIGHT)

int T, E, F, N;
int P[MAXLINE], W[MAXLINE];
int S[MAXWEIGHT];
FILE *inf, *ouf;

void input_data(void)
{
	int i;
	fscanf(inf, "%d %d\n", &E, &F);
	fscanf(inf, "%d\n", &N);

	for (i=0; i<N; i++) {
		fscanf(inf, "%d %d\n", &P[i], &W[i]);
	}
}

void initialize_S(void)
{
	int i;
	S[0] = 0;

	for (i=1;i<= F - E; i++)
		S[i] = MAXVALUE;
}

void solve(void)
{
	int i, j;
	initialize_S();

	for (i=0;i<N; i++)
		for (j=0;j<=F-E-W[i]; j++)
			if (S[j] + P[i] < S[j + W[i]])
				S[j + W[i]] = S[j] + P[i];
}

void output_result(void)
{
	if(S[F-E] == MAXVALUE)
		fprintf(ouf, "-1\n");
	else
		fprintf(ouf, "The Minimum execution time of smart phone : %d\n", S[F-E]);
}

void test()
{
	int i;
	inf = fopen(INPUT_FILE, "r");
	ouf = fopen(OUTPUT_FILE, "w");
	fscanf(inf, "%d\n", &T);

	for (i=0; i<T; i++) {
		input_data();
		solve();
		output_result();
	}

	fclose(inf);
	fclose(ouf);
}
