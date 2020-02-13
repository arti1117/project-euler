/*
 *  LCRS.c
 *
 *  Created on: Aug 11, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode 
{
    struct tagLCRSNode* LeftChild;
    struct tagLCRSNode* RightSibling;

    ElementType Data;
} LCRSNode;


LCRSNode* LCRS_CreateNode( ElementType NewData );
void      LCRS_DestroyNode( LCRSNode* Node );
void      LCRS_DestroyTree( LCRSNode* Root );

void      LCRS_AddChildNode( LCRSNode* ParentNode, LCRSNode *ChildNode);
void      LCRS_PrintTree( LCRSNode* Node, int Depth );

LCRSNode* LCRS_CreateNode( ElementType NewData )
{
    LCRSNode* NewNode = (LCRSNode*)malloc( sizeof(LCRSNode) );
    NewNode->LeftChild    = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void LCRS_DestroyNode( LCRSNode* Node )
{
    free(Node);
}

void LCRS_DestroyTree( LCRSNode* Root )
{
    if ( Root->RightSibling != NULL )
        LCRS_DestroyTree( Root->RightSibling );

    if ( Root->LeftChild != NULL )
        LCRS_DestroyTree( Root->LeftChild );

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    LCRS_DestroyNode( Root );
}

void LCRS_AddChildNode( LCRSNode* Parent, LCRSNode *Child)
{
    if ( Parent->LeftChild == NULL )
    {
        Parent->LeftChild = Child;
    }
    else 
    {
        LCRSNode* TempNode = Parent->LeftChild;
        while ( TempNode->RightSibling != NULL )
            TempNode = TempNode->RightSibling;

        TempNode->RightSibling = Child;        
    }
}

void LCRS_PrintTree( LCRSNode* Node, int Depth )
{
    int i=0; 
    for ( i=0; i<Depth; i++ )
        printf("--");

    printf("%c\n", Node->Data);

    if ( Node->LeftChild != NULL )
        LCRS_PrintTree(Node->LeftChild, Depth+1);

    if ( Node->RightSibling != NULL )
        LCRS_PrintTree(Node->RightSibling, Depth);
}

int main( void )
{
    /*  ��� ���� */
    LCRSNode* Root = LCRS_CreateNode('A');
    
    LCRSNode* B = LCRS_CreateNode('B');
    LCRSNode* C = LCRS_CreateNode('C');
    LCRSNode* D = LCRS_CreateNode('D');
    LCRSNode* E = LCRS_CreateNode('E');
    LCRSNode* F = LCRS_CreateNode('F');
    LCRSNode* G = LCRS_CreateNode('G');
    LCRSNode* H = LCRS_CreateNode('H');
    LCRSNode* I = LCRS_CreateNode('I');
    LCRSNode* J = LCRS_CreateNode('J');
    LCRSNode* K = LCRS_CreateNode('K');

    /*  Ʈ���� ��� �߰� */
    LCRS_AddChildNode( Root, B );
        LCRS_AddChildNode( B, C );
        LCRS_AddChildNode( B, D );
            LCRS_AddChildNode( D, E );
            LCRS_AddChildNode( D, F );

    LCRS_AddChildNode( Root, G );
        LCRS_AddChildNode( G, H );

    LCRS_AddChildNode( Root, I );
        LCRS_AddChildNode( I, J );
            LCRS_AddChildNode( J, K );
    
    /*  Ʈ�� ��� */
    LCRS_PrintTree( Root, 0 );

    /*  Ʈ�� �Ҹ��Ű�� */
    LCRS_DestroyTree( Root );

    return 0;
}