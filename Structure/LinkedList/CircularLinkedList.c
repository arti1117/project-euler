/*
 *  CircularLinkedList.c
 *
 *  Created on: Aug 3, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct cNode
{
	char data;
    struct cNode* prev;
	struct cNode* next;
} cnode;

typedef struct iNode
{
	int data;
	struct iNode* prev;
	struct iNode* next;
} inode;

typedef struct fNode
{
	float data;
	struct fNode* prev;
	struct fNode* next;
} fnode;

typedef struct dNode
{
	double data;
	struct dNode* prev;
	struct dNode* next;
} dnode;

typedef struct sNode
{
	char* data;
	struct sNode* prev;
	struct sNode* next;
} snode;


cnode* createCnode(char);
void destroyCnode(cnode*);
void appendCnode(cnode**, cnode*);
void afterCnode(cnode*, cnode*);
void removeCnode(cnode**, cnode*);
cnode* getCnode(cnode*, int);
int countCnode(cnode*);


cnode* createCnode(char new)
{
	cnode* node = (cnode*)malloc(sizeof(cnode));

	node->data = new;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

void destroyCnode(cnode* node)
{
	free(node);
}

void appendCnode(cnode** head, cnode* node)
{
	if ((*head) == NULL)
	{
		*head = node;
        (*head)->next = *head;
        (*head)->prev = *head;
	}
	else
	{
		cnode* tail = (*head)->prev;

        tail->next->prev = node;
        tail->next = node;

        node->next = (*head);
        node->prev = tail;
	}
}

void afterCnode(cnode* curr, cnode* node)
{
	node->next = curr->next;
    node->prev = curr;

    curr->next->prev = node;
    curr->next = node;
}

void removeCnode(cnode** head, cnode* node)
{
	if ( *head == node )
	{
        (*head)->prev->next = node->next;
        (*head)->next->prev = node->prev;

        *head = node->next;
    }
	else
	{
		cnode* temp = node;

        node->prev->next = temp->next;
        node->next->prev = temp->prev;
	}

    node->prev = NULL;
    node->next = NULL;

	destroyCnode(node);
}

cnode* getCnode(cnode* head, int loc)
{
	cnode* curr = head;

	while ( curr != NULL && (--loc) >= 0 )
	{
		curr = curr->next;
	}
 
	return curr;
}

int countCnode(cnode* head)
{
	unsigned int count = 0;
	cnode* curr = head;

	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}

	return count;	
}

void printCnode(cnode* node)
{
    if (node->prev == NULL)
        printf("Previous Node is NULL.");
    else
        printf("Previous Node is %d.", node->prev->data);

    if (node->next == NULL)
        printf("Next Node is NULL.");
    else
        printf("Next Node is %d.", node->next->data);
}
