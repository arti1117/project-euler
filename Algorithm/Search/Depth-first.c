/*
 *  Depth-first.c
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

void initList();
void printList();
void expand(int);
void removeFirst();
int check(int);
void printRoute(int);

void checkOpenList(int);
void addOpenList();

int main()
{
    inode curr;

    initList();
    printList();

    while (TRUE)
    {
        if (olist == 0)
        {
            printf("Cannot Find The Target Node.\n");
            break;
        }

        if (olist[0].data == GOAL) {
            printf("\nFound The Target Node.\n");
            printf("%d[%d]", olist[0].data, olist[0].root);
            
            printRoute(olist[0].root);
            break;
        }

        curr = olist[0];
        removeFirst();

        expand(curr.data);

        clist[cstep++] = curr;

        printList();
    }

    return 0;
}

void printRoute(int data)
{
    int i;

    for (i=0; i<cstep; ++i)
        if (clist[i].data == data) {
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
    
    for (i=0; i<cstep; ++i)
        if (clist[i].data == data)
            result = TRUE;
    
    return result;
}

void checkOpenList(int data)
{
    int i, j;

    for (i=1; i<ostep; ++i)
        if (olist[i].data == data) {
            for (j=i; j<ostep; ++j)
                olist[j] = olist[j+1];
            --ostep;
            --i;
        }
}

void removeFirst()
{
    int i;

    for (i=0; i<ostep; ++i)
        olist[i] = olist[i+1];

    --ostep;
}

void expand(int data)
{
    int tree[][5] = {
         {1, 2, 3, 5}
        ,{2, 4}
        ,{3, 6, 7}
        ,{5, 4, 8}
        ,{6, 5, 7, 11, 23}
        ,{8, 19, 991, 992, 999}
        ,{0}
    };

    int i = 0;
    int j;

    while (tree[i][0] != 0) {
        if (tree[i][0] == data) {
            for (j=1; tree[i][j] != 0; ++j) {
                if (check(tree[i][j]) != TRUE) {
                    addOpenList();
                    olist[0].data = tree[i][j];
                    olist[0].root = data;
                }
                checkOpenList(tree[i][j]);
            }
            break;
        }
        ++i;
    }
}

void addOpenList()
{
    int i;

    for (i=ostep; i>0; --i)
        olist[i] = olist[i-1];

    ++ostep;
}

void initList()
{
    olist[0].data = START;
    olist[0].root = 0;
    ++ostep;
}

void printList()
{
    int i;
    
    printf("\nOpenList ");
    for (i=0; i<ostep; ++i)
        printf("%d[%d],", olist[i].data, olist[i].root);

    printf("\n");

    printf("ClosedList ");
    for (i=0; i<cstep; ++i)
        printf("%d[%d],", clist[i].data, clist[i].root);

    printf("\n");
}