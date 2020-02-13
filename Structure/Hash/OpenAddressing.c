/*
 *  OpenAddressing.c
 *
 *  Created on: Aug 14, 2019
 *      Author: arti
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

enum ElementStatus
{
    EMPTY    = 0,
    OCCUPIED = 1
};

typedef struct tagElementType
{
    KeyType    Key;
    ValueType  Value;

    enum ElementStatus Status;
} ElementType;

typedef struct tagHashTable 
{
    int           OccupiedCount;
    int           TableSize;

    ElementType*  Table;
} HashTable;

HashTable* OAHT_CreateHashTable( int TableSize );
void       OAHT_DestroyHashTable( HashTable* HT );
void       OAHT_ClearElement( ElementType* Element );

void       OAHT_Set( HashTable** HT, KeyType Key, ValueType Value );
ValueType  OAHT_Get( HashTable* HT, KeyType Key );
int        OAHT_Hash ( KeyType Key, int KeyLength, int TableSize );
int        OAHT_Hash2( KeyType Key, int KeyLength, int TableSize );

void       OAHT_Rehash( HashTable** HT );

HashTable* OAHT_CreateHashTable( int TableSize )
{
    HashTable* HT = (HashTable*)malloc( sizeof(HashTable) );
    HT->Table     = (ElementType*)malloc( sizeof(ElementType) * TableSize);

    memset(HT->Table, 0, sizeof(ElementType) * TableSize );

    HT->TableSize = TableSize;
    HT->OccupiedCount = 0;

    return HT;
}

void OAHT_Set( HashTable** HT, KeyType Key, ValueType Value )
{
    int    KeyLen, Address, StepSize;
    double Usage;

    Usage = (double)(*HT)->OccupiedCount / (*HT)->TableSize;

    if ( Usage > 0.5 )
    {
        OAHT_Rehash( HT );
    }

    KeyLen    = strlen(Key);
    Address   = OAHT_Hash( Key, KeyLen, (*HT)->TableSize );
    StepSize  = OAHT_Hash2( Key, KeyLen, (*HT)->TableSize );
    
    while ( (*HT)->Table[Address].Status != EMPTY && 
                strcmp((*HT)->Table[Address].Key, Key) != 0 )
    {
        printf("Collision occured! : Key(%s), Address(%d), StepSize(%d)\n", 
                Key, Address, StepSize );

        Address = (Address + StepSize) % (*HT)->TableSize;
    }

    (*HT)->Table[Address].Key = (char*)malloc( sizeof(char) * (KeyLen + 1) );
    strcpy( (*HT)->Table[Address].Key, Key );

    (*HT)->Table[Address].Value = (char*)malloc( sizeof(char) * (strlen(Value) + 1) );
    strcpy( (*HT)->Table[Address].Value, Value );

    (*HT)->Table[Address].Status = OCCUPIED;

    (*HT)->OccupiedCount++;

    printf("Key(%s) entered at address(%d)\n", Key, Address );
}

ValueType OAHT_Get( HashTable* HT, KeyType Key )
{
    int KeyLen    = strlen(Key);

    int Address   = OAHT_Hash( Key, KeyLen, HT->TableSize );
    int StepSize  = OAHT_Hash2( Key, KeyLen, HT->TableSize );
    
    while ( HT->Table[Address].Status != EMPTY && 
                strcmp(HT->Table[Address].Key, Key) != 0 )
    {
        Address = (Address + StepSize) % HT->TableSize;
    }

    return HT->Table[Address].Value;
}

void OAHT_ClearElement( ElementType* Element )
{
    if ( Element->Status == EMPTY)
        return;

    free(Element->Key);
    free(Element->Value);
}

void OAHT_DestroyHashTable( HashTable* HT)
{
    /*  1. �� ��ũ�� ����Ʈ�� ���� ����ҿ��� �����ϱ� */
    int i = 0;
    for ( i=0; i<HT->TableSize; i++ )
    {
        OAHT_ClearElement( &(HT->Table[i]) );
    }

    /*  2, �ؽ� ���̺��� ���� ����ҿ��� �����ϱ�. */
    free ( HT->Table );
    free ( HT );
}

int OAHT_Hash( KeyType Key, int KeyLength, int TableSize )
{
    int i=0;
    int HashValue = 0;

    for ( i=0; i<KeyLength; i++ )
    {
        HashValue = (HashValue << 3) + Key[i];
    }

    HashValue = HashValue % TableSize;

    return HashValue;
}

int OAHT_Hash2( KeyType Key, int KeyLength, int TableSize )
{
    int i=0;
    int HashValue = 0;

    for ( i=0; i<KeyLength; i++ )
    {
        HashValue = (HashValue << 2) + Key[i];
    }

    HashValue = HashValue % ( TableSize - 3 );

    return HashValue + 1;
}
                              
void OAHT_Rehash( HashTable** HT )
{
    int i = 0;
    ElementType* OldTable = (*HT)->Table;

    /*  �� �ؽ� ���̺��� �����, */
    HashTable* NewHT = OAHT_CreateHashTable( (*HT)->TableSize * 2 );
    
    printf("\nRehashed. New table size is : %d\n\n", NewHT->TableSize );

    /*  ������ �ؽ����̺��� �ִ� �����͸� �� �ؽ����̺��� �ű��. */
    for ( i=0; i<(*HT)->TableSize; i++ )
    {
        if ( OldTable[i].Status == OCCUPIED )
        {
            OAHT_Set( &NewHT, OldTable[i].Key, OldTable[i].Value );
        }
    }

    /*  ������ �ؽ����̺��� �Ҹ��Ų��. */
    OAHT_DestroyHashTable( (*HT) );

    /*  HT �����Ϳ��� ���� �ؽ����̺��� �ּҸ� �����Ѵ�. */
    (*HT) = NewHT;
}


int main( void )
{
    HashTable* HT = OAHT_CreateHashTable( 11 );

    OAHT_Set( &HT, "MSFT",   "Microsoft Corporation");
    OAHT_Set( &HT, "JAVA",   "Sun Microsystems");
    OAHT_Set( &HT, "REDH",   "Red Hat Linux");
    OAHT_Set( &HT, "APAC",   "Apache Org");
    OAHT_Set( &HT, "ZYMZZ",  "Unisys Ops Check"); /*  APAC�� �浹 */
    OAHT_Set( &HT, "IBM",    "IBM Ltd.");
    OAHT_Set( &HT, "ORCL",   "Oracle Corporation");
    OAHT_Set( &HT, "CSCO",   "Cisco Systems, Inc.");
    OAHT_Set( &HT, "GOOG",   "Google Inc.");
    OAHT_Set( &HT, "YHOO",   "Yahoo! Inc.");
    OAHT_Set( &HT, "NOVL",   "Novell, Inc.");

    printf("\n");
    printf("Key:%s, Value:%s\n", "MSFT",   OAHT_Get( HT, "MSFT" ) );
    printf("Key:%s, Value:%s\n", "REDH",   OAHT_Get( HT, "REDH" ) );
    printf("Key:%s, Value:%s\n", "APAC",   OAHT_Get( HT, "APAC" ) );
    printf("Key:%s, Value:%s\n", "ZYMZZ",  OAHT_Get( HT, "ZYMZZ" ) );
    printf("Key:%s, Value:%s\n", "JAVA",   OAHT_Get( HT, "JAVA" ) );
    printf("Key:%s, Value:%s\n", "IBM",    OAHT_Get( HT, "IBM" ) );
    printf("Key:%s, Value:%s\n", "ORCL",   OAHT_Get( HT, "ORCL" ) );
    printf("Key:%s, Value:%s\n", "CSCO",   OAHT_Get( HT, "CSCO" ) );
    printf("Key:%s, Value:%s\n", "GOOG",   OAHT_Get( HT, "GOOG" ) );
    printf("Key:%s, Value:%s\n", "YHOO",   OAHT_Get( HT, "YHOO" ) );
    printf("Key:%s, Value:%s\n", "NOVL",   OAHT_Get( HT, "NOVL" ) );

    OAHT_DestroyHashTable( HT );

    return 0;
}
