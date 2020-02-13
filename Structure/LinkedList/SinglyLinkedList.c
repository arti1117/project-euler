/*
 * SinglyLinkedList.c
 *
 *  Created on: Aug 3, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct cNode
{
	char data;
	struct cNode* next;
} cnode;

typedef struct iNode
{
	int data;
	struct iNode* next;
} inode;

typedef struct fNode
{
	float data;
	struct fNode* next;
} fnode;

typedef struct dNode
{
	double data;
	struct dNode* next;
} dnode;

typedef struct sNode
{
	char* data;
	struct sNode* next;
} snode;


cnode* createCnode(char);
void destroyCnode(cnode*);
void appendCnode(cnode**, cnode*);
void beforeCnode(cnode**, cnode*, cnode*);
void afterCnode(cnode*, cnode*);
void insertCnode(cnode**, cnode*);
void removeCnode(cnode**, cnode*);
//void clearCnode(cnode**);
cnode* getCnode(cnode*, int);
int countCnode(cnode*);


cnode* createCnode(char new)
{
	cnode* node = (cnode*)malloc(sizeof(cnode));

	node->data = new;
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
		cnode* tail = (*head);

		while (tail->next != NULL) {
			tail = tail->next;
		}

		tail->next = node;
	}
}

void beforeCnode(cnode** head, cnode* curr, cnode* node)
{
	if ((*head) == NULL)
	{
		*head = node;
	}
	else
	{
		cnode* tail = (*head);

		while (tail->next != NULL && tail->next != curr)
		{
			if (tail->next == curr)
			{
				node->next = curr;
				tail->next = node;
				break;
			} 
			tail = tail->next;
		}

	}
}

void afterCnode(cnode* curr, cnode* node)
{
	node->next = curr->next;
	curr->next = node;
}

void insertCnode(cnode** head, cnode* node)
{
	if (*head == NULL)
	{
		(*head) = node;
	} 
	else
	{
		node->next = (*head);
		(*head) = node;
	}
}

void removeCnode(cnode** head, cnode* node)
{
	if ( (*head) == node)
	{
		*head = node->next;
	}
	else
	{
		cnode* curr = *head;
		
		while ( curr != NULL && curr->next != node )
		{
			curr = curr->next;
		}

		if ( curr != NULL )
		{
			curr->next = node->next;
		}
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
	int cnt = 0;
	cnode* curr = head;

	while ( curr != NULL )
	{
		curr = curr->next;
		cnt++;
	}

	return cnt;	
}
