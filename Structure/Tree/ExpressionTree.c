/*
 *  ExpressionTree.c
 *
 *  Created on: Aug 11, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

typedef struct tagETNode 
{
    struct tagETNode* Left;
    struct tagETNode* Right;

    ElementType Data;
} ETNode;

ETNode*   ET_CreateNode( ElementType NewData );
void      ET_DestroyNode( ETNode* Node );
void      ET_DestroyTree( ETNode* Root );

void      ET_PreorderPrintTree( ETNode* Node );
void      ET_InorderPrintTree( ETNode* Node );
void      ET_PostorderPrintTree( ETNode* Node );
void      ET_BuildExpressionTree( char* PostfixExpression, ETNode** Node );
double    ET_Evaluate( ETNode* Tree );


ETNode* ET_CreateNode( ElementType NewData )
{
    ETNode* NewNode = (ETNode*)malloc( sizeof(ETNode) );
    NewNode->Left    = NULL;
    NewNode->Right   = NULL;
    NewNode->Data    = NewData;

    return NewNode;
}

void ET_DestroyNode( ETNode* Node )
{
    free(Node);
}

void ET_DestroyTree( ETNode* Root )
{
    if ( Root == NULL )
        return;

    ET_DestroyTree( Root->Left );
    ET_DestroyTree( Root->Right );
    ET_DestroyNode( Root );
}

void ET_PreorderPrintTree( ETNode* Node )
{
    if ( Node == NULL )
        return;

    printf( " %c", Node->Data );

    ET_PreorderPrintTree( Node->Left );
    ET_PreorderPrintTree( Node->Right );
}

void ET_InorderPrintTree( ETNode* Node )
{
    if ( Node == NULL )
        return;
    
    printf( "(" );
    ET_InorderPrintTree( Node->Left );

    printf( "%c", Node->Data );

    ET_InorderPrintTree( Node->Right );
    printf( ")" );
}

void ET_PostorderPrintTree( ETNode* Node )
{
    if ( Node == NULL )
        return;
    
    ET_PostorderPrintTree( Node->Left );
    ET_PostorderPrintTree( Node->Right );
    printf( " %c", Node->Data );
}

void ET_BuildExpressionTree( char* PostfixExpression, ETNode** Node )
{
    ETNode* NewNode = NULL;
    int  len        = strlen( PostfixExpression );
    char Token      = PostfixExpression[ len -1 ];
    PostfixExpression[ len-1 ] = '\0';

    switch ( Token ) 
    {
        case '+': case '-': case '*': case '/':
            (*Node) = ET_CreateNode( Token );
            ET_BuildExpressionTree( PostfixExpression, &(*Node)->Right );
            ET_BuildExpressionTree( PostfixExpression, &(*Node)->Left  );
            break;

        default :
            (*Node) = ET_CreateNode( Token);
            break;
    }
}

double ET_Evaluate( ETNode* Tree )
{
    char Temp[2];
    
    double Left   = 0;
    double Right  = 0;
    double Result = 0;

    if ( Tree == NULL )
        return 0;

    switch ( Tree->Data ) 
    {
        case '+': case '-': case '*': case '/':
            Left  = ET_Evaluate( Tree->Left );
            Right = ET_Evaluate( Tree->Right );

                 if ( Tree->Data == '+' ) Result = Left + Right;
            else if ( Tree->Data == '-' ) Result = Left - Right;
            else if ( Tree->Data == '*' ) Result = Left * Right;
            else if ( Tree->Data == '/' ) Result = Left / Right;            

            break;

        default :
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp);  
            break;
    }

    return Result;
}


int main( void )
{
    ETNode* Root = NULL;

    char PostfixExpression[20] = "71*52-/";
    ET_BuildExpressionTree( PostfixExpression, &Root);

    printf("Preorder ...\n");
    ET_PreorderPrintTree( Root );
    printf("\n\n");

    printf("Inorder ... \n");
    ET_InorderPrintTree( Root );
    printf("\n\n");

    printf("Postorder ... \n");
    ET_PostorderPrintTree( Root );
    printf("\n");

    printf("Evaulation Result : %f \n", ET_Evaluate( Root ) );

    ET_DestroyTree( Root );

    return 0;
}