/*
 *  ArrayStack.c
 *
 *  Created on: Aug 4, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct cNode
{
	char data;
} cnode;

typedef struct iNode
{
	int data;
} inode;

typedef struct fNode
{
	float data;
} fnode;

typedef struct dNode
{
	double data;
} dnode;

typedef struct sNode
{
	char* data;
} snode;


typedef struct cStack
{
    int top;
    int size;
    cnode* node;
} cstack;

typedef struct iStack
{
    int top;
    int size;
    inode* node;
} istack;

typedef struct fStack
{
    int top;
    int size;
    fnode* node;
} fstack;

typedef struct dStack
{
    int top;
    int size;
    dnode* node;
} dstack;

typedef struct sStack
{
    int top;
    int size;
    snode* node;
} sstack;


void createCstack(cstack**, int);
void destroyCstack(cstack*);
void pushCstack(cstack*, char);
char popCstack(cstack*);
char topCstack(cstack*);
int getSizeCstack(cstack*);
int isEmptyCstack(cstack*);
int isFullCstack(cstack*);


void createCstack(cstack** stack, int capacity)
{
    (*stack) = (cstack*)malloc(sizeof(cstack));

    (*stack)->top = 0;
    (*stack)->size = capacity;
    (*stack)->node = (cnode*)malloc(sizeof(cnode) * capacity);
}

void destoryCstack(cstack* stack)
{
    free(stack->node);
    free(stack);
}

void pushCstack(cstack* stack, char data)
{
    stack->node[stack->top].data = data;
    stack->top++;
}

char popCstack(cstack* stack)
{
    return stack->node[--(stack->top)].data;
}

char topCstack(cstack* stack)
{
    return stack->node[(stack->top - 1)].data;
}

int getSizeCstack(cstack* stack)
{
    return stack->top;
}

int isEmptyCstack(cstack* stack)
{
    return (stack->top == 0) ? 1 : 0;
}