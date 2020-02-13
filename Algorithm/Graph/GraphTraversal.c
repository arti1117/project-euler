/*
 *  GraphTraversal.c
 *
 *  Created on: Aug 17, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited };

typedef int ElementType;

typedef struct tagVertex
{
    ElementType       Data;
    int               Visited;
    int               Index;

    struct tagVertex* Next;
    struct tagEdge*   AdjacencyList;
} Vertex;

typedef struct tagEdge
{
    int    Weight;
    struct tagEdge* Next;
    Vertex* From;
    Vertex* Target;
} Edge;

typedef struct tagGraph
{
    Vertex* Vertices;
    int     VertexCount;
} Graph;

Graph* CreateGraph();
void   DestroyGraph( Graph* G );

Vertex* CreateVertex( ElementType Data );
void    DestroyVertex( Vertex* V );

Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight );
void    DestroyEdge( Edge* E );

void   AddVertex( Graph* G, Vertex* V );
void   AddEdge( Vertex* V, Edge* E );
void   PrintGraph ( Graph* G );

typedef struct tagNode
{
    Vertex*         Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue
{
    Node* Front;
    Node* Rear;
    int   Count;
} LinkedQueue;

LinkedQueue* LQ_CreateQueue();
void         LQ_DestroyQueue(LinkedQueue* Queue);

Node*        LQ_CreateNode(Vertex* V);
void         LQ_DestroyNode(Node* _Node);

void         LQ_Enqueue(LinkedQueue** Queue, Node* NewNode);
Node*        LQ_Dequeue(LinkedQueue** Queue);

int          LQ_IsEmpty(LinkedQueue* Queue);

void DFS( Vertex* V );
void BFS( Vertex* V, LinkedQueue* Queue );

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc( sizeof( Graph ) );
    graph->Vertices = NULL;
    graph->VertexCount = 0;

    return graph;
}

void DestroyGraph( Graph* G )
{
    while ( G->Vertices != NULL )
    {
        Vertex* Vertices = G->Vertices->Next;        
        DestroyVertex( G->Vertices );
        G->Vertices = Vertices;        
    }

    free( G );
}

Vertex* CreateVertex( ElementType Data )
{
    Vertex* V = (Vertex*)malloc( sizeof( Vertex ) );
    
    V->Data = Data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited;
    V->Index = -1;

    return V;
}

void DestroyVertex( Vertex* V )
{
    while ( V->AdjacencyList != NULL )
    {
        Edge* Edge = V->AdjacencyList->Next;

        DestroyEdge ( V->AdjacencyList );

        V->AdjacencyList = Edge;
    }

    free( V );    
}

Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight )
{
    Edge* E   = (Edge*)malloc( sizeof( Edge ) );
    E->From   = From;
    E->Target = Target;
    E->Next   = NULL;
    E->Weight = Weight;

    return E;
}

void    DestroyEdge( Edge* E )
{
    free( E );
}

void AddVertex( Graph* G, Vertex* V )
{
    Vertex* VertexList = G->Vertices;

    if ( VertexList == NULL ) 
    {
        G->Vertices = V;
    } 
    else 
    {
        while ( VertexList->Next != NULL )
            VertexList = VertexList->Next;

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}

void AddEdge( Vertex* V, Edge* E )
{
    if ( V->AdjacencyList == NULL ) 
    {
        V->AdjacencyList = E;
    } 
    else
    {
        Edge* AdjacencyList = V->AdjacencyList;

        while ( AdjacencyList->Next != NULL )
            AdjacencyList = AdjacencyList->Next;

        AdjacencyList->Next = E;
    }
}

void PrintGraph ( Graph* G )
{
    Vertex* V = NULL;
    Edge*   E = NULL;

    if ( ( V = G->Vertices ) == NULL )
        return;

    while ( V != NULL )
    {
        printf( "%c : ", V->Data );        
        
        if ( (E = V->AdjacencyList) == NULL ) {
            V = V->Next;
            printf("\n");
            continue;
        }

        while ( E != NULL )
        {
            printf("%c[%d] ", E->Target->Data, E->Weight );
            E = E->Next;
        }

        printf("\n");

        V = V->Next;    
    }   

    printf("\n");
}

LinkedQueue* LQ_CreateQueue()
{
    LinkedQueue* Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    
    Queue->Front = NULL;
    Queue->Rear  = NULL;
    Queue->Count = 0;

    return Queue;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
    while ( !LQ_IsEmpty(Queue) )
    {
        Node* Popped = LQ_Dequeue(&Queue);
        LQ_DestroyNode(Popped);    
    }

    free(Queue);
}

Node* LQ_CreateNode(Vertex* V)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = V;

    NewNode->NextNode = NULL;

    return NewNode;
}

void  LQ_DestroyNode(Node* _Node)
{
    free(_Node->Data);
    free(_Node);
}

void LQ_Enqueue(LinkedQueue** Queue, Node* NewNode)
{
    if ( (*Queue)->Front == NULL ) 
    {        
        (*Queue)->Front = NewNode;
        (*Queue)->Rear  = NewNode;
        (*Queue)->Count++;
    } 
    else
    {
        (*Queue)->Rear->NextNode = NewNode;
        (*Queue)->Rear = NewNode;
        (*Queue)->Count++;
    }
}

Node* LQ_Dequeue(LinkedQueue** Queue)
{
    Node* Front = (*Queue)->Front;

    if ( (*Queue)->Front->NextNode == NULL )
    {
        (*Queue)->Front = NULL;
        (*Queue)->Rear  = NULL;
    }
    else
    {
        (*Queue)->Front = (*Queue)->Front->NextNode;
    }

    (*Queue)->Count--;

    return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
    return (Queue->Front == NULL);
}

void DFS( Vertex* V )
{
    Edge* E = NULL;

    printf("%d ", V->Data);

    V->Visited = Visited;

    E = V->AdjacencyList;

    while ( E != NULL )
    {
        if ( E->Target != NULL && E->Target->Visited == NotVisited )
            DFS( E->Target );

        E = E->Next;
    }
}

void BFS( Vertex* V, LinkedQueue* Queue )
{
    Edge* E = NULL;

    printf("%d ", V->Data);
    V->Visited = Visited;
    
    LQ_Enqueue( &Queue, LQ_CreateNode( V ) );

    while ( !LQ_IsEmpty( Queue ) )
    {
        Node* Popped = LQ_Dequeue( &Queue );
        V = Popped->Data;
        E = V->AdjacencyList;

        while ( E != NULL )
        {
            V = E->Target;

            if ( V != NULL && V->Visited == NotVisited )
            {
                printf("%d ", V->Data);
                V->Visited = Visited;
                LQ_Enqueue( &Queue, LQ_CreateNode( V ) );
            }

            E = E->Next;
        }
    }
}

int main( void )
{
    int          Mode  = 0;
    Graph* graph = CreateGraph();
    
    Vertex* V1 = CreateVertex( 1 );
    Vertex* V2 = CreateVertex( 2 );
    Vertex* V3 = CreateVertex( 3 );
    Vertex* V4 = CreateVertex( 4 );
    Vertex* V5 = CreateVertex( 5 );
    Vertex* V6 = CreateVertex( 6 );
    Vertex* V7 = CreateVertex( 7 );

    AddVertex( graph, V1 );
    AddVertex( graph, V2 );
    AddVertex( graph, V3 );
    AddVertex( graph, V4 );
    AddVertex( graph, V5 );
    AddVertex( graph, V6 );
    AddVertex( graph, V7 );

    AddEdge( V1, CreateEdge(V1, V2, 0) );
    AddEdge( V1, CreateEdge(V1, V3, 0) );

    AddEdge( V2, CreateEdge(V2, V4, 0) );
    AddEdge( V2, CreateEdge(V2, V5, 0) );

    AddEdge( V3, CreateEdge(V3, V4, 0) );
    AddEdge( V3, CreateEdge(V3, V6, 0) );

    AddEdge( V4, CreateEdge(V4, V5, 0) );
    AddEdge( V4, CreateEdge(V4, V7, 0) );

    AddEdge( V5, CreateEdge(V5, V7, 0) );

    AddEdge( V6, CreateEdge(V6, V7, 0) );

    printf( "Enter Traversal Mode (0:DFS, 1:BFS) : " );
    scanf(  "%d", &Mode );

    if ( Mode == 0  ) 
    {
        DFS( graph->Vertices );
    }
    else
    {
        LinkedQueue* Queue = LQ_CreateQueue();
    
        BFS(V1, Queue);
        
        LQ_DestroyQueue( Queue );
    }

    DestroyGraph( graph );

    return 0;
}
