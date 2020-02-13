/*
 *  BruteForce.c
 *
 *  Created on: Aug 15, 2019
 *      Author: arti
 */

// Execute Method
// gcc -o BruteForce BruteForce.c
// chmod a+x BruteForce
// ./BruteForce kjv.txt Faithful

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 512

int BruteForce(char* Text, int TextSize, int Start, 
               char* Pattern, int PatternSize );


int BruteForce(char* Text, int TextSize, int Start, 
               char* Pattern, int PatternSize )
{
    int i = 0;
    int j = 0;

    for ( i=Start; i<=TextSize - PatternSize ; i++ )
    {
        for ( j=0; j<PatternSize; j++ )
        {
            if ( Text[i+j] != Pattern[j] )
                break;
        }

        if ( j >= PatternSize )
            return i;
    }

    return -1;
}

int main(int argc, char** argv)
{
    char* FilePath;
    FILE* fp;

    char  Text[MAX_BUFFER];
    char* Pattern;
    int   PatternSize = 0;
    int   Line        = 0;
    
    if ( argc < 3 )
    {
        printf("Usage: %s <FilePath> <Pattern>\n", argv[0] );
        return 1;
    }

    FilePath = argv[1];
    Pattern  = argv[2];

    PatternSize = strlen( Pattern );

    if ( (fp = fopen( FilePath, "r"))  == NULL )
    {
        printf("Cannot open file:%s\n", FilePath);
        return 1;
    } 

    while ( fgets( Text, MAX_BUFFER, fp ) != NULL )
    {
        int Position = 
            BruteForce( Text, strlen(Text), 0, Pattern, PatternSize );
        
        Line++;

        if ( Position >= 0 ) 
        {
            printf("line:%d, column:%d : %s", Line, Position+1, Text);
        }
    }

    fclose( fp );

    return 0;
}
