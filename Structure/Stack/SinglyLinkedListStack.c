/*
 *  SinglyLinkedListStack.c
 *
 *  Created on: Aug 4, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "..//Node/SingleNode.c"

#define TRUE 1
#define FALSE 0


typedef struct char_stack
{
    cnode* top;
    cnode* list;
} cstack;

typedef struct int_stack
{
    inode* top;
    inode* list;
} istack;

typedef struct float_stack
{
    fnode* top;
    fnode* list;
} fstack;

typedef struct double_stack
{
    dnode* top;
    dnode* list;
} dstack;

typedef struct string_stack
{
    snode* top;
    snode* list;
} sstack;


void screate(sstack**);
void sdelete(sstack*);

snode* swrite(char*);
void serase(snode*);

void spush(sstack*, snode*);
snode* spop(sstack*);

snode* stop(sstack*);
int ssize(sstack*);
int sempty(sstack*);


void screate(sstack** stack)
{
    (*stack) = (sstack*)malloc(sizeof(sstack));
    
    (*stack)->top = NULL;
    
    (*stack)->list = NULL;
}

void sdelete(sstack* stack)
{
    while (!sempty(stack))
    {
        snode* old = spop(stack);
        
        serase(old);
    }

    free(stack);
}

snode* swrite(char* data)
{
    snode* node = (snode*)malloc(sizeof(snode));

    node->data = (char*)malloc(sizeof(data)+1);

    strcpy(node->data, data);

    node->next = NULL;

    return node;
}

void serase(snode* node)
{
    free(node->data);
    free(node);
}

void spush(sstack* stack, snode* node)
{
    if (stack->list == NULL)
    {
        stack->list = node;
    }
    else
    {
        snode* old = stack->list;

        while (old->next != NULL)
        {
            old = old->next;
        }
        old->next = node;
    }

    stack->top = node;
}

snode* spop(sstack* stack)
{
    snode* node = stack->top;

    if (stack->list == stack->top)
    {
        stack->top = NULL;
        stack->list = NULL;
    }
    else
    {
        snode* curr = stack->list;
        while (curr != NULL && curr->next != stack->top)
        {
            curr = curr->next;
        }
        stack->top = curr;
        curr->next = NULL;
    }

    return node;
}

snode* stop(sstack* stack)
{
    return stack->top;
}

int ssize(sstack* stack)
{
    int count = 0;
    snode* curr = stack->list;

    while (curr != NULL)
    {
        curr = curr->next;
        count++;
    }

    return count;
}

int sempty(sstack* stack)
{
    return (stack->list == NULL) ? TRUE : FALSE;
}
