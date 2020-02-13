/*
 *  BinaryTree.c
 *
 *  Created on: Aug 12, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode 
{
    struct tagBSTNode* Left;
    struct tagBSTNode* Right;

    ElementType Data;
} BSTNode;

BSTNode*  BST_CreateNode( ElementType NewData );
void      BST_DestroyNode( BSTNode* Node );
void      BST_DestroyTree( BSTNode* Tree );

BSTNode*  BST_SearchNode( BSTNode* Tree, ElementType Target );
BSTNode*  BST_SearchMinNode( BSTNode* Tree );
void      BST_InsertNode( BSTNode* Tree, BSTNode *Child );
BSTNode*  BST_RemoveNode( BSTNode* Tree,BSTNode* Parent, ElementType Target );
void      BST_InorderPrintTree( BSTNode* Node );


BSTNode* BST_CreateNode( ElementType NewData )
{
    BSTNode* NewNode = (BSTNode*)malloc( sizeof(BSTNode) );
    NewNode->Left    = NULL;
    NewNode->Right   = NULL;
    NewNode->Data    = NewData;

    return NewNode;
}

void BST_DestroyNode( BSTNode* Node )
{
    free(Node);
}

void BST_DestroyTree( BSTNode* Tree )
{
    if ( Tree->Right != NULL )
        BST_DestroyTree( Tree->Right );

    if ( Tree->Left != NULL )
        BST_DestroyTree( Tree->Left );

    Tree->Left = NULL;
    Tree->Right = NULL;

    BST_DestroyNode( Tree );
}

BSTNode*  BST_SearchNode( BSTNode* Tree, ElementType Target )
{
    if ( Tree == NULL )
        return NULL;
   
    if ( Tree->Data == Target )
        return Tree;
    else if ( Tree->Data > Target )
        return BST_SearchNode ( Tree->Left, Target );
    else
        return BST_SearchNode ( Tree->Right,  Target );
}


BSTNode*  BST_SearchMinNode( BSTNode* Tree )
{
    if ( Tree == NULL )
        return NULL;

    if ( Tree->Left == NULL ) 
        return Tree;
    else
        return BST_SearchMinNode( Tree->Left );
}

void BST_InsertNode( BSTNode* Tree, BSTNode *Child)
{
    if ( Tree->Data < Child->Data ) 
    {
        if ( Tree->Right == NULL )
            Tree->Right = Child;
        else
            BST_InsertNode( Tree->Right, Child );

    } 
    else if ( Tree->Data > Child->Data ) 
    {
        if ( Tree->Left == NULL )
            Tree->Left = Child;
        else
            BST_InsertNode( Tree->Left, Child );
    }
}

BSTNode* BST_RemoveNode( BSTNode* Tree,BSTNode* Parent, ElementType Target )
{
    BSTNode* Removed = NULL;

    if ( Tree == NULL )
        return NULL;

    if ( Tree->Data > Target )
        Removed = BST_RemoveNode( Tree->Left, Tree, Target );
    else if ( Tree->Data < Target )
        Removed = BST_RemoveNode( Tree->Right, Tree, Target );
    else
    {
        Removed = Tree;

        if ( Tree->Left == NULL && Tree->Right == NULL )
        {
            if ( Parent->Left == Tree )
                Parent->Left = NULL;
            else 
                Parent->Right = NULL;
        }
        else
        {
            if ( Tree->Left != NULL && Tree->Right != NULL ) 
            {
                BSTNode* MinNode = BST_SearchMinNode( Tree->Right );
                MinNode = BST_RemoveNode( Tree, NULL, MinNode->Data );
                Tree->Data = MinNode->Data;
            }
            else
            {
                BSTNode* Temp = NULL;
                if ( Tree->Left != NULL )
                    Temp = Tree->Left;
                else 
                    Temp = Tree->Right;

                if ( Parent->Left == Tree )
                    Parent->Left  = Temp;
                else 
                    Parent->Right = Temp;
            }
        }
    }

    return Removed;
}

void BST_InorderPrintTree( BSTNode* Node )
{
    if ( Node == NULL )
        return;

    BST_InorderPrintTree( Node->Left );

    printf( "%d ", Node->Data );

    BST_InorderPrintTree( Node->Right );
}


int main( void )
{
    BSTNode* Tree = BST_CreateNode(123);
    BSTNode* Node = NULL;

    BST_InsertNode( Tree, BST_CreateNode(22) );
    BST_InsertNode( Tree, BST_CreateNode(9918) );
    BST_InsertNode( Tree, BST_CreateNode(424) );
    BST_InsertNode( Tree, BST_CreateNode(17) );
    BST_InsertNode( Tree, BST_CreateNode(3) );

    BST_InsertNode( Tree, BST_CreateNode(98) );
    BST_InsertNode( Tree, BST_CreateNode(34) );

    BST_InsertNode( Tree, BST_CreateNode(760) );
    BST_InsertNode( Tree, BST_CreateNode(317) );
    BST_InsertNode( Tree, BST_CreateNode(1) );
    
	Node =  BST_SearchNode(Tree, 17 );
    if(Node != NULL)
        printf("%d \n", Node->Data);
    else
        puts("�׷� ��� �����");

    BST_InorderPrintTree( Tree );
    printf( "\n");

    printf( "Removing 98...\n");

    Node = BST_RemoveNode( Tree, NULL, 98 );
    BST_DestroyNode( Node );

    BST_InorderPrintTree( Tree );
    printf( "\n");

    printf( "Inserting 111...\n");

    BST_InsertNode( Tree, BST_CreateNode(111) );
    BST_InorderPrintTree( Tree );
    printf( "\n");

    BST_DestroyTree( Tree );

    return 0;
}