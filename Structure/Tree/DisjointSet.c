/*
 *  DisjointSet.c
 *
 *  Created on: Aug 11, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjointSet
{
    struct tagDisjointSet* Parent;
    void*                  Data;
} DisjointSet;

void DS_UnionSet( DisjointSet* Set1, DisjointSet* Set2 );
DisjointSet* DS_FindSet( DisjointSet* Set );
DisjointSet* DS_MakeSet( void* NewData );
void DS_DestroySet( DisjointSet* Set );


void DS_UnionSet( DisjointSet* Set1, DisjointSet* Set2 )
{
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}

DisjointSet* DS_FindSet( DisjointSet* Set )
{
    while ( Set->Parent != NULL )
    {
        Set = Set->Parent;
    }

    return Set;
}

DisjointSet* DS_MakeSet( void* NewData )
{
    DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
    NewNode->Data   = NewData;
    NewNode->Parent = NULL;

    return NewNode;
}

void DS_DestroySet( DisjointSet* Set )
{
    free( Set );
}


int main( void )
{
	int a=1, b=2, c=3, d=4;
	DisjointSet* Set1 = DS_MakeSet(&a);
	DisjointSet* Set2 = DS_MakeSet(&b);
	DisjointSet* Set3 = DS_MakeSet(&c);
	DisjointSet* Set4 = DS_MakeSet(&d);

    printf("Set1 == Set2 : %d \n", DS_FindSet( Set1 ) == DS_FindSet( Set2 ) );

	DS_UnionSet( Set1, Set3 );
    printf("Set1 == Set3 : %d \n", DS_FindSet( Set1 ) == DS_FindSet( Set3 ) );

    DS_UnionSet( Set3, Set4 );
    printf("Set3 == Set4 : %d \n", DS_FindSet( Set3 ) == DS_FindSet( Set4 ) );

	return 0;
}