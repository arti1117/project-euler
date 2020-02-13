/*
 *  Breadth-first.c
 *  
 *  Created on: Aug 5, 2019
 *      Author: arti
 */

#include <stdio.h>

#include "/home/arti/Projects/algo/Structure/Node/HistoryNode.c"

#define LIMIT 256
#define TRUE 1
#define START 1
#define GOAL 999

inode olist[LIMIT];
int ostep = 0;

inode clist[LIMIT];
int cstep = 0;

void init();
void printList();
void expand(int);
void moveToFirst();
void removeFirst();
int check(int);
void printRoute();

void main()
{
    init();
    printList();

    while (TRUE)
    {
        if (ostep == 0)
        {
            printf("Cannot Find The Target Node.\n");
            break;
        }

        if (olist[0].data == GOAL)
        {
            printf("\nFound The Target Node.\n");
            printf("%d[%d]", olist[0].data, olist[0].root);
            printRoute(olist[0].root);
            break;
        }

        expand(olist[0].data);

        moveToFirst();

        printList();

    }
}

void printRoute(int data)
{
    int i;

    for (i=0; i<cstep; i++)
        if (clist[i].data == data)
        {
            printf("<-%d[%d]", clist[i].data, clist[i].root);
            break;
        }

        if (clist[i].root != 0)
            printRoute(clist[i].root);
        printf("\n");
}

int check(int data)
{
    int i;
    int result = 0;

    for (i=0; i<ostep; i++)
        if (olist[i].data == data)
            result = TRUE;
    
    for (i=0; i<cstep; i++)
        if (clist[i].data == data)
            result = TRUE;
    
    return result;
}

void removeFirst()
{
    int i;

    for (i=0; i<ostep; i++)
        olist[i] = olist[i+1];

    --ostep;
}

void moveToFirst()
{
    clist[cstep++] = olist[0];

    removeFirst();
}

void expand(int data)
{
    int tree[][5] = {
        {1, 2, 3, 5},
        {2, 4},
        {3, 6, 7},
        {5, 4, 8},
        {8, 7, 999},
        {0}
    };

    int i = 0;
    int j;

    while (tree[i][0] != 0)
    {
        if (tree[i][0] == data)
        {
            for (j=1; tree[i][j] != 0; j++)
            {
                if (check(tree[i][j]) != TRUE)
                {
                    olist[ostep].data = tree[i][j];
                    olist[ostep++].root = data;
                }
            }
            break;
        }
        i++;
    }
}

void init()
{
    olist[0].data = START;
    olist[0].root = 0;
    ++ostep;
}

void printList()
{
    int i;

    printf("\nOpen List");
    for (i=0; i<ostep; i++)
        printf("%d[%d],", olist[i].data, olist[i].root);
    printf("\n");

    printf("\nClosed List");
    for (i=0; i<cstep; i++)
        printf("%d[%d],", clist[i].data, clist[i].root);
    printf("\n");

}
