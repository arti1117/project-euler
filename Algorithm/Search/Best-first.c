/*
 *  Best-first.c
 *  
 *  Created on: Aug 5, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 256
#define TRUE 1
#define START 1
#define GOAL 999

typedef struct int_node
{
    int data;
    int root;
    double value;
} inode;

inode olist[LIMIT];
int ostep = 0;
inode clist[LIMIT];
int cstep = 0;

double heuristic[] = {0, 5.7, 4.5, 2.8, 4.1, 2, 4, 4, 0};

void initList();
void printList();
void expand(int);
void moveToFirst();
void removeFirst();
int check(int);
void printRoute(int);
void sortOpenList();
int cmp(const void*, const void*);

int main()
{
    initList();
    printList();

    while (TRUE) {
        if (olist == 0) {
            printf("\nCan't find target node.\n");
            break;
        }

        if (olist[0].data == GOAL) {
            printf("\nFound the target node!.\n");
            printf("%d[%d]", olist[0].data, olist[0].root);
            printRoute(olist[0].root);
            break;
        }

        expand(olist[0].data);
        moveToFirst();
        sortOpenList();
        printList();
    }

    return 0;
}

void sortOpenList()
{
    qsort(olist, ostep, sizeof(inode), cmp);
}

int cmp(const void *a, const void *b)
{
    inode *x, *y;
    x = (inode *)a;
    y = (inode *)b;

    if ((x->value) < (y->value)) return -1;
    else if ((x->value) > (y->value)) return 1;
    else return 0;
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
    int res = 0;

    for (i=0; i<ostep; ++i)
        if (olist[i].data == data)
            res = TRUE;
    
    for (i=0; i<cstep; ++i)
        if (clist[i].data == data)
            res = TRUE;
    
    return res;
}

void removeFirst()
{
    int i;
    for (i=0; i<ostep; ++i)
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
         {1, 2, 4}
        ,{2, 6}
        ,{3, 6, 999}
        ,{4, 3}
        ,{5, 7, 999}
        ,{0}
    };

    int i = 0;
    int j;

    while (tree[i][0] != 0) {
        if (tree[i][0] == data) {
            for (j=1; tree[i][j] != 0; ++j) {
                if (check(tree[i][j]) != TRUE) {
                    olist[ostep].data = tree[i][j];
                    olist[ostep].root = data;
                    olist[ostep++].value = heuristic[tree[i][j]];
                }
            }
            break;
        }
        ++i;
    }
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
        printf("%d[%d, %.1lf],", olist[i].data
                                , olist[i].root
                                , olist[i].value);

    printf("\n");

    printf("ClosedList ");
    for (i=0; i<cstep; ++i)
        printf("%d[%d],", clist[i].data, clist[i].root);

    printf("\n");
}