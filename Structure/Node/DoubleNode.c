/*
 *  DoubleNode.c
 *
 *  Created on: Aug 4, 2019
 *      Author: arti
 */

typedef struct char_node
{
	char data;
    struct char_node* prev;
    struct char_node* next;
} cnode;

typedef struct int_node
{
	int data;
    struct int_node* prev;
    struct int_node* next;
} inode;

typedef struct float_node
{
	float data;
    struct float_node* prev;
    struct float_node* next;
} fnode;

typedef struct double_node
{
	double data;
    struct double_node* prev;
    struct double_node* next;
} dnode;

typedef struct string_node
{
	char* data;
    struct string_node* prev;
    struct string_node* next;
} snode;
