/*
 *  KnuthMorrisPratt.c
 *
 *  Created on: Aug 15, 2019
 *      Author: arti
 */

// Execute Method
// gcc -o KnuthMorrisPratt KnuthMorrisPratt.c
// chmod a+x KnuthMorrisPratt
// ./KnuthMorrisPratt kjv.txt Faithful

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 512

int  KnuthMorrisPratt(char* Text, int TextSize, int Start, 
                      char* Pattern, int PatternSize );

void Preprocess( char* Pattern, int PatternSize, int* Border );

void Preprocess( char* Pattern, int PatternSize, int* Border ) 
{
    int i = 0;
    int j = -1;

    Border[0] = -1;

    while ( i < PatternSize )
    {
        while ( j > -1 && Pattern[i] != Pattern[j] )
        {    
            j = Border[j];
        }
        i++; 
        j++;

        Border[i] = j;
    }
}

int  KnuthMorrisPratt(char* Text, int TextSize, int Start, 
                      char* Pattern, int PatternSize )
{
    int i = Start;
    int j = 0;
    int Position = -1;
    
    int* Border = (int*)calloc( PatternSize + 1, sizeof( int ) );

    Preprocess( Pattern, PatternSize, Border );

    while ( i < TextSize )
    {
        while ( j >= 0 && Text[i] != Pattern[j] )
            j = Border[j];

        i++;
        j++;

        if ( j == PatternSize )
        {
            Position = i - j;
            break;
        }
    }

    free( Border );
    return Position;
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
            KnuthMorrisPratt( Text, strlen(Text), 0, Pattern, PatternSize );
        
        Line++;

        if ( Position >= 0 ) 
        {
            printf("line:%d, column:%d : %s", Line, Position+1, Text);
        }
    }

    fclose( fp );

    return 0;
}

