/*
 *  20190708.c
 *  21:30 ~ 22:00
 *  Created on: Jul 8, 2019
 *      Author: arti
 */

#include "..//Structure/List/SinglyLinkedList.c"

void test()
{
    int   i        = 0;
    int   Count    = 0;
    cnode* List    = NULL;
    cnode* Current = NULL;
    cnode* NewNode = NULL;

    for ( i = 0; i<5; i++ )
    {
        NewNode = createCnode(i);
        appendCnode(&List, NewNode);
    }

    NewNode = createCnode(-1);
    insertCnode(&List, NewNode);

    NewNode = createCnode(-2);
    insertCnode(&List, NewNode);

    Count = countCnode(List);
    for ( i = 0; i<Count; i++ )
    {
        Current = getCnode(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    printf("\nInserting 127 After [2]...\n\n");

    Current = getCnode(List, 2);
    NewNode  = createCnode(127);

    afterCnode(Current, NewNode);

    Count = countCnode(List);
    for ( i = 0; i<Count; i++ )
    {
        Current = getCnode(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    printf("\nDestroying List...\n");

    for ( i = 0; i<Count; i++ )
    {
        Current = getCnode(List, 0);

        if ( Current != NULL ) 
        {
            removeCnode(&List, Current);
        }
    }

}