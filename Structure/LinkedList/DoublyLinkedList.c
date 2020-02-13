/*
 * DoublyLinkedList.c
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
//void beforeCnode(cnode**, cnode*, cnode*);
void afterCnode(cnode*, cnode*);
void removeCnode(cnode**, cnode*);
//void clearCnode(cnode**);
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
	}
	else
	{
		cnode* tail = *head;

		while (tail->next != NULL) {

			tail = tail->next;
		
        }

		tail->next = node;
        node->prev = tail;
	}
}

void afterCnode(cnode* curr, cnode* node)
{
	node->next = curr->next;
    node->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = node;

    curr->next = node;
}

void removeCnode(cnode** head, cnode* node)
{
	if ( *head == node )
	{
        *head = node->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        node->prev = NULL;
        node->next = NULL;
	}
	else
	{
		cnode* temp = node;

        if (node->prev != NULL)
            node->prev->next = temp->next;

        if (node->next != NULL)
            node->next->prev = temp->prev;

        node->prev = NULL;
        node->next = NULL;
	}
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
