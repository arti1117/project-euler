/*
============================================================================
 Name        : Algorithm.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
============================================================================

O(1) constant :
 Determining if a binary number is even or odd; Calculating (−1)^n;
 Using a constant-size lookup table

O(loglogN) double logarithmic :
 Number of comparisons spent finding an item 
 using interpolation search in a sorted array of uniformly distributed values

O(logN) logarithmic :
 Finding an item in a sorted array with a binary search 
 or a balanced search tree as well as all operations in a Binomial heap

O((logN)^C) {1 < C} polylogarithmic :
 Matrix chain ordering can be solved in polylogarithmic time
 on a parallel random-access machine

O(N^C) {0 < C < 1} fractional power :
 Searching in a k-d tree

O(N) linear :
 Finding an item in an unsorted list or in an unsorted array;
 adding two n-bit integers by ripple carry

O(Nlog*N) n log-star n :
 Performing triangulation of a simple polygon using Seidel's algorithm,
 or the union–find algorithm.
 Note that log∗(N) = {0, if(N≤1)}, {1 + log∗⁡(logN), if(N>1)}

O(NlogN) = O(logN!) linearithmic, loglinear, or quasilinear :
 Performing a fast Fourier transform; Fastest possible comparison sort;
 heapsort and merge sort

O(N^2) quadratic :
 Multiplying two n-digit numbers by a simple algorithm; simple sorting algorithms,
 such as bubble sort, selection sort and insertion sort;
 (worst case) bound on some usually faster sorting algorithms such as quicksort, 
 Shellsort, and tree sort

O(N^C) {1 < C} polynomial or algebraic :
 Tree-adjoining grammar parsing; maximum matching for bipartite graphs;
 finding the determinant with LU decomposition

Ln[α, C] = e^(C + O(1))*(ln*n)^(α)*(ln*ln*n)^(1−α) {0 < α < 1}
 L-notation or sub-exponential :
 Factoring a number using the quadratic sieve or number field sieve

O(C^N) {1 < C} exponential :
 Finding the (exact) solution to the travelling salesman problem 
 using dynamic programming;
 determining if two logical statements are equivalent using brute-force search

O(N!) factorial :
 Solving the travelling salesman problem via brute-force search;
 generating all unrestri1cted permutations of a poset; 
 finding the determinant with Laplace expansion;
 enumerating all partitions of a set
*/

// https://projecteuler.net

// #include "20190818.c"

#include "Architects.h"

int main(void) {

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	clock_t start = clock();

	test();

	clock_t end = clock();

	double time = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("The Function took %f seconds to execute.", time);

	return EXIT_SUCCESS;
}
