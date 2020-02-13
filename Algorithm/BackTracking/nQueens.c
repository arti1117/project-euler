/*
 *  nQueens.c
 *
 *  Created on: Aug 18, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

void PrintSolution( int Columns[], int NumberOfQueens );
int  IsThreatened ( int Columns[], int NewRow );
void FindSolutionForQueen( int Columns[], int Row, 
                           int NumberOfQueens, int* SolutionCount );

void FindSolutionForQueen(int Columns[], int Row, 
                          int NumberOfQueens, int* SolutionCount) 
{
    if ( IsThreatened( Columns, Row ) )
        return;
    
    if ( Row == NumberOfQueens-1 )
    {
        printf("Solution #%d : \n", ++(*SolutionCount));
        PrintSolution( Columns, NumberOfQueens );
    }
    else
    {
        int i;

        for ( i=0; i<NumberOfQueens; i++ )
        {
            Columns[Row+1] = i;
            FindSolutionForQueen ( Columns, Row+1, 
                                   NumberOfQueens, SolutionCount );
        }
    }
}

int IsThreatened ( int Columns[], int NewRow )
{
    int CurrentRow = 0;
    int Threatened = 0;

    while ( CurrentRow < NewRow )
    { 
        if ( Columns[NewRow] == Columns[CurrentRow]
             || abs (Columns[NewRow] - Columns[CurrentRow]) 
               == abs(NewRow - CurrentRow))        
        {
            Threatened = 1;
            break;
        }

       CurrentRow++;
    }

    return Threatened;
}

void PrintSolution( int Columns[], int NumberOfQueens ) 
{
    int i=0;
    int j=0;

    for ( i=0; i<NumberOfQueens; i++ )
    {
        for ( j=0; j<NumberOfQueens; j++ )
        {
            if ( Columns[i] == j )
                printf("Q");
            else
                printf(".");
        }

        printf("\n");
    }
    printf("\n");
}

int main(int argc, char* argv[]) 
{
    int i              = 0;
    int NumberOfQueens = 0; 
    int SolutionCount  = 0;
    int* Columns;

    if ( argc < 2 )
    {
        printf("Usage: %s <Number Of Queens>", argv[0]);
        return 1;
    }
    
    NumberOfQueens = atoi(argv[1]); 
    Columns = (int*)calloc( NumberOfQueens, sizeof(int) );
        
    for ( i=0; i<NumberOfQueens; i++ )
    {
        Columns[0] = i;
        FindSolutionForQueen(Columns, 0, NumberOfQueens, &SolutionCount);
    }    

    free ( Columns );

    return 0;
}