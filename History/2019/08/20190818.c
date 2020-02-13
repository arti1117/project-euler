/*
 *  20190818.c
 *  
 *  Created on: Aug 18, 2019
 *      Author: arti
 */

// Fibonacci by Dynamic Programming

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

ULONG Fibonacci( int N ) 
{
    int    i;
    ULONG  Result;
    ULONG* FibonacciTable;

    if ( N==0 || N==1 )
        return N;

    FibonacciTable = (ULONG*)malloc( sizeof( ULONG ) * (N+1) );

    FibonacciTable[0] = 0;
    FibonacciTable[1] = 1;

    for ( i=2; i<=N; i++ )
    {        
        FibonacciTable[i] = FibonacciTable[i-1] + FibonacciTable[i-2];
    }
    
    Result = FibonacciTable[N];

    free( FibonacciTable );

    return Result;
}

void test()
{
    int   N      = 46;
    ULONG Result = Fibonacci( N );

    printf("Fibonacci(%d)  = %lu \n", N, Result );

}
