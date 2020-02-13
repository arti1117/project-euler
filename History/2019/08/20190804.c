/*
 *  20190804.c
 *  
 *  Created on: Aug 4, 2019
 *      Author: arti
 */

#include "Architects.h"

#define TRUE 1
#define FALSE 0

typedef enum
{
     LEFT = '('
    ,RIGHT = ')'
    ,PLUS = '+'
    ,MINUS ='-'
    ,MULTIPLY = '*'
    ,DIVIDE = '/'
    ,SPACE = ' '
    ,OPERAND
} SYMBOL;

int IsNumber(char);
unsigned int GetNextToken(char*, char*, int*);
int GetPriority(char, int);
int IsPrior(char, char);
void GetPostfix(char*, char*);
double Calculate(char*);

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int IsNumber(char Cipher)
{
    int i;
    int ArrayLength = sizeof(NUMBER);

    for (i=0; i<ArrayLength; i++)
    {
        if (Cipher == NUMBER[i])
            return TRUE;
    }

    return FALSE;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
    unsigned int i = 0;
    
    for (i=0 ; 0 != Expression[i]; i++)
    {
        Token[i] = Expression[i];

        if (IsNumber(Expression[i]) == TRUE)
        {            
            *TYPE = OPERAND;

            if (IsNumber(Expression[i+1]) != TRUE)
                break;
        }
        else
        {
            *TYPE = Expression[i];
            break;            
        }
    }

    Token[++i] = '\0';
    return i;
}

int GetPriority(char Operator, int InStack)
{
    int Priority = -1;

    switch (Operator)
    {
    case LEFT:
        if (InStack)
            Priority = 3;
        else
            Priority = 0;
        break;

    case MULTIPLY:
    case DIVIDE:
        Priority = 1;
        break;

    case PLUS:
    case MINUS:
        Priority = 2;
        break;
    }

    return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
    return (GetPriority(OperatorInStack, TRUE) > GetPriority(OperatorInToken, FALSE));
}

void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
    sstack* Stack;

    char Token[32];
    int  Type = -1;
    unsigned int Position = 0;
    unsigned int Length = strlen(InfixExpression);

    screate(&Stack);

    while (Position < Length)
    {
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        if (Type == OPERAND) 
        {
            strcat(PostfixExpression, Token);
            strcat(PostfixExpression, " ");
        }
        else if (Type == RIGHT) 
        {               
            while (!sempty(Stack))
            {
                snode* Popped = spop(Stack);

                if (Popped->data[0] == LEFT)
                {
                    serase(Popped);
                    break;
                }
                else
                {
                    strcat(PostfixExpression, Popped->data);
                    serase(Popped);
                }
            }
        }
        else
        {
            while (!sempty(Stack) && 
                    !IsPrior(stop(Stack)->data[0], Token[0] ) )
            {
                snode* Popped = spop(Stack);

                if (Popped->data[0] != LEFT)
                    strcat(PostfixExpression, Popped->data);
                
                serase(Popped);
            }
            
            spush(Stack, swrite(Token));
        }
    }

    while (!sempty(Stack))
    {
        snode* Popped = spop(Stack);

        if ( Popped->data[0] != LEFT )
            strcat(PostfixExpression, Popped->data);
        
        serase(Popped);
    }

    sdelete(Stack);
}

double Calculate(char* PostfixExpression)
{
    sstack* Stack;
    snode*  ResultNode;

    double Result;
    char Token[32];
    int  Type = -1;
    unsigned int Read = 0; 
    unsigned int Length = strlen(PostfixExpression);

    screate(&Stack);
   
    while (Read < Length)
    {
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

        if (Type == SPACE)  
            continue;
        
        if (Type == OPERAND) 
        {
            snode* NewNode = swrite( Token );
            spush(Stack, NewNode);
        }
        else
        {
            char   ResultString[32];            
            double Operator1, Operator2, TempResult;
            snode* OperatorNode;

            OperatorNode = spop( Stack );
            Operator2 = atof( OperatorNode->data );
            serase( OperatorNode );

            OperatorNode = spop( Stack );
            Operator1 = atof( OperatorNode->data );
            serase( OperatorNode );
            
            switch (Type)
            {
                case PLUS:     TempResult = Operator1 + Operator2; break;
                case MINUS:    TempResult = Operator1 - Operator2; break;
                case MULTIPLY: TempResult = Operator1 * Operator2; break;
                case DIVIDE:   TempResult = Operator1 / Operator2; break;
            }

            gcvt( TempResult, 10, ResultString );            
            spush( Stack, swrite( ResultString ) );
        }
    }

    ResultNode = spop( Stack );            
    Result = atof( ResultNode->data );
    serase( ResultNode );

    sdelete( Stack );

    return Result;
}

void test()
{
    char InfixExpression[100];
    char PostfixExpression[100];

	double Result = 0.0;

    memset( InfixExpression,   0, sizeof(InfixExpression) );
    memset( PostfixExpression, 0, sizeof(PostfixExpression) );
    
    printf( "Enter Infix Expression:" );
    scanf( "%s", InfixExpression );
    
    GetPostfix( InfixExpression, PostfixExpression );
    
    printf( "Infix:%s\nPostfix:%s\n",
             InfixExpression,
             PostfixExpression );

	Result = Calculate( PostfixExpression );

    printf( "Calculation Result : %f\n", Result );

}