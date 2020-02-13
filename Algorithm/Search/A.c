#include <stdio.h>
#include <stdlib.h>

#define LIMIT 256
#define TRUE 1
#define START 1
#define FALSE 0
#define GOAL 999

struct node {
    int child;
    int parent;
    double value;
};

struct node openList[LIMIT];
int openListep = 0;
struct node closedList[LIMIT];
int closedListep = 0;
double h[] = {0, 5.7, 4.5, 2.8, 4.1, 2, 4, 4, 0};

void initList();
void printList();
void expand(struct node cnode);
void moveToFirst();
void removeFirst();
int ccheck(struct node cnode, int id, int v);
int ocheck(struct node cnode, int id, int v);
void printRoute(int id);
void sortOpenList();
int cmp(const void *a, const void *b);

int main()
{
    struct node current;

    initList();
    printList();

    while (TRUE) {
        if (openList == 0) {
            printf("\nCan't find target node.\n");
            break;
        }

        if (openList[0].child == GOAL) {
            printf("\nFound the target node!.\n");
            printf("%d[%d]", openList[0].child, openList[0].parent);
            printRoute(openList[0].parent);
            break;
        }

        current = openList[0];
        removeFirst();

        expand(current);

        closedList[closedListep++] = current;
        sortOpenList();
        printList();
    }

    return FALSE;
}

void sortOpenList()
{
    qsort(openList, openListep, sizeof(struct node), cmp);
}

int cmp(const void *a, const void *b)
{
    struct node *x, *y;
    x = (struct node *)a;
    y = (struct node *)b;

    if ((x->value) < (y->value)) return -1;
    else if ((x->value) > (y->value)) return 1;
    else return 0;
}

void printRoute(int id)
{
    int i;

    for (i=0; i<closedListep; ++i)
        if (closedList[i].child == id) {
            printf(" <- %d[%d]", closedList[i].child
                                ,closedList[i].parent);
            break;
        }

    if (closedList[i].parent != 0)
        printRoute(closedList[i].parent);
    printf("\n");

}

int ccheck(struct node cnode, int id, int v)
{
    int i, j;

    for (i=0; i<closedListep; ++i)
        if (closedList[i].child == id) {
            if (closedList[i].value < cnode.value + v) {
                return TRUE;
            } else {
                for (j=i; j<closedListep; ++i) {
                    closedList[j] = closedList[j+1];
                }
                --closedListep;
            }
        }
    return 0;
}

int ocheck(struct node cnode, int id, int v)
{
    int i, j;

    for (i=0; i<openListep; ++i)
        if (openList[i].child == id) {
            if (openList[i].value < cnode.value + v) {
                return TRUE;
            } else {
                for (j=i; j<openListep; ++i) {
                    openList[j] = openList[j+1];
                }
                --openListep;
            }
        }
    return 0;
}

void removeFirst()
{
    int i;
    for (i=0; i<openListep; ++i)
        openList[i] = openList[i+1];
    --openListep;
}

void moveToFirst()
{
    closedList[closedListep++] = openList[0];
}

void expand(struct node cnode)
{
    double tree[][10] = {
        {1, 2, 2, 4, 3},
        {2, 3, 2, 6, 2},
        {3, 2, 2, 5, 2, 999, 2.8},
        {4, 3, 2.8},
        {5, 7, 2, 999, 2},
        {0}
    };

    int i = 0;
    int j;

    while (tree[i][0] != 0) {
        if (tree[i][0] == cnode.child) {
            for (j=1; tree[i][j] != 0; j+=2) {
                if (ocheck(cnode, tree[i][j], 
                    tree[i][j+1] + h[(int)tree[i][j]]) != TRUE 
                    &&
                    (ccheck(cnode, tree[i][j], 
                    tree[i][j+1] + h[(int)tree[i][j]]) != TRUE)) {
                        openList[openListep].child = tree[i][j];
                        openList[openListep].parent = cnode.child;
                        openList[openListep++].value
                         = cnode.value + tree[i][j+1] + h[(int)tree[i][j]];
                }
            }
            break;
        }
        ++i;
    }
}

void initList()
{
    openList[0].child = START;
    openList[0].parent = 0;
    ++openListep;
}

void printList()
{
    int i;
    
    printf("\nOpenList ");
    for (i=0; i<openListep; ++i)
        printf("%d[%d, %.1lf],", openList[i].child
                                , openList[i].parent
                                , openList[i].value);

    printf("\n");

    printf("ClosedList ");
    for (i=0; i<closedListep; ++i)
        printf("%d[%d],", closedList[i].child, closedList[i].parent);

    printf("\n");
}