/*
 * 20190625.c
 *
 *  Created on: Jun 25, 2019
 *      Author: arti
 */

// Names scores
// Problem 22

// Using i_20190625.txt (right click and 'Save Link/Target As...'), 
// a 46K text file containing over five-thousand first names, 
// begin by sorting it into alphabetical order. 

// Then working out the alphabetical value for each name, 
// multiply this value by its alphabetical position in 
// the list to obtain a name score.

// For example, when the list is sorted into alphabetical order, 
// COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, 
// is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

// What is the total of all the name scores in the file?

#include "Architects.h"

#define INPUT_FILE "..//IO_files/2019/201906/i_20190625.txt"

int compare(const void *x, const void *y);

void test(void)
{
  int i;
  FILE *fp;
  char **names;
  int sum = 0;
  int count = 0;

  fp = fopen(INPUT_FILE, "r");

  if (!fp) {
    perror(INPUT_FILE);
  }

  /* parse names.txt */
  names = malloc(8192 * sizeof *names);
  names[count] = malloc(16);

  while (fscanf(fp, "\"%[^\"]\",", names[count]) != EOF) {
    names[++count] = malloc(16);
  }

  free(names[count]);
  fclose(fp);

  qsort(names, count, sizeof *names, compare);

  int j, s;

  for (i = 0; i < count; i++) {
    s = 0;
    for (j = 0; names[i][j] != 0; j++) {
      s += names[i][j]-'A'+1;
    }
    sum += s * (i+1);

    free(names[i]);
  }
  free(names);

  printf("The total of all the name scores in the file is %d\n", sum);
}

int compare(const void *x, const void *y)
{
  return strcmp(*(char * const *)x, *(char * const *)y);
}
