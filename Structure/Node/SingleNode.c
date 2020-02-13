/*
 *  SingleNode.c
 *
 *  Created on: Aug 5, 2019
 *      Author: arti
 */

typedef struct char_node
{
	char data;
	struct char_node* next;
} cnode;

typedef struct int_node
{
	int data;
	struct int_node* next;
} inode;

typedef struct float_node
{
	float data;
	struct float_node* next;
} fnode;

typedef struct double_node
{
	double data;
	struct double_node* next;
} dnode;

typedef struct string_node
{
	char* data;
	struct string_node* next;
} snode;
