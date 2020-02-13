/*
 *  SimpleHashTable.c
 *
 *  Created on: Aug 14, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode
{
    KeyType   Key;
    ValueType Value;
} Node;

typedef struct tagHashTable 
{
    int   TableSize;
    Node* Table;
} HashTable;

HashTable* SHT_CreateHashTable( int TableSize );
void       SHT_Set( HashTable* HT, KeyType Key, ValueType Value );
ValueType  SHT_Get( HashTable* HT, KeyType Key );
void       SHT_DestroyHashTable( HashTable* HT);
int        SHT_Hash( KeyType Key, int TableSize );


HashTable* SHT_CreateHashTable( int TableSize )
{
    HashTable* HT = (HashTable*)malloc( sizeof(HashTable) );
    HT->Table     = (Node*)malloc( sizeof(Node) * TableSize);
    HT->TableSize = TableSize;

    return HT;
}

void SHT_Set( HashTable* HT, KeyType Key, ValueType Value )
{
    int Address = SHT_Hash( Key, HT->TableSize );

    HT->Table[Address].Key   = Key;
    HT->Table[Address].Value = Value;
}

ValueType SHT_Get( HashTable* HT, KeyType Key )
{
    int Address = SHT_Hash( Key, HT->TableSize );

    return HT->Table[Address].Value;
}

void SHT_DestroyHashTable( HashTable* HT)
{
    free ( HT->Table );
    free ( HT );
}

int SHT_Hash( KeyType Key, int TableSize )
{
    return Key % TableSize;
}

int main( void )
{
    HashTable* HT = SHT_CreateHashTable( 193 );

    SHT_Set( HT, 418,   32114);
    SHT_Set( HT, 9,    514);
    SHT_Set( HT, 27,   8917);
    SHT_Set( HT, 1031, 286);

    printf("Key:%d, Value:%d\n", 418,  SHT_Get( HT, 418 ) );
    printf("Key:%d, Value:%d\n", 9,    SHT_Get( HT, 9 ) );
    printf("Key:%d, Value:%d\n", 27,   SHT_Get( HT, 27 ) );
    printf("Key:%d, Value:%d\n", 1031, SHT_Get( HT, 1031 ) );

    SHT_DestroyHashTable( HT );

    return 0;
}
