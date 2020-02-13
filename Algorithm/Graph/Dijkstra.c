/*
 *  Dijkstra.c
 *
 *  Created on: Aug 17, 2019
 *      Author: arti
 */

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_WEIGHT 36267

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

typedef int       PriorityType;

typedef struct tagePQNode 
{
    PriorityType Priority;
    void*        Data;
} PQNode;

typedef struct tagPriorityQueue 
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create( int InitialSize );
void           PQ_Destroy( PriorityQueue* PQ );
void           PQ_Enqueue( PriorityQueue* PQ, PQNode NewData );
void           PQ_Dequeue( PriorityQueue* PQ, PQNode* Root );
int            PQ_GetParent( int Index );
int            PQ_GetLeftChild( int Index );
void           PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 );
int            PQ_IsEmpty( PriorityQueue* PQ );

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* MST );

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

PriorityQueue* PQ_Create( int IntitialSize )
{
    PriorityQueue* NewPQ = (PriorityQueue*) malloc( sizeof( PriorityQueue ) );
    NewPQ->Capacity = IntitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode*) malloc( sizeof ( PQNode ) * NewPQ->Capacity );

    return NewPQ;
}

void  PQ_Destroy( PriorityQueue* PQ )
{
    free( PQ->Nodes );
    free( PQ );
}

void  PQ_Enqueue( PriorityQueue* PQ, PQNode NewNode )
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition  = PQ_GetParent( CurrentPosition );

    if ( PQ->UsedSize == PQ->Capacity ) 
    {
        if ( PQ->Capacity == 0 )
            PQ->Capacity = 1;
            
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*) realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    /*  �ļ� ó��. */
    while ( CurrentPosition > 0 
        && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority )
    {
        PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );
        
        CurrentPosition = ParentPosition;
        ParentPosition  = PQ_GetParent( CurrentPosition );
    }

    PQ->UsedSize++;
}

void      PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 )
{ 
    int CopySize = sizeof( PQNode );
    PQNode* Temp = (PQNode*)malloc(CopySize);
        
    memcpy( Temp,               &PQ->Nodes[Index1], CopySize);
    memcpy( &PQ->Nodes[Index1] , &PQ->Nodes[Index2], CopySize);
    memcpy( &PQ->Nodes[Index2] , Temp,              CopySize);

    free(Temp);
}

void      PQ_Dequeue( PriorityQueue* PQ, PQNode* Root )
{
    int ParentPosition = 0;
    int LeftPosition   = 0;    
    int RightPosition  = 0;    
    
    memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
    memset(&PQ->Nodes[0], 0, sizeof(PQNode));

    PQ->UsedSize--;
    PQ_SwapNodes( PQ, 0, PQ->UsedSize );

    LeftPosition  = PQ_GetLeftChild( 0 );
    RightPosition = LeftPosition + 1;

    while ( 1 )
    {
        int SelectedChild = 0;

        if ( LeftPosition >= PQ->UsedSize )
            break;

        if ( RightPosition >= PQ->UsedSize )
        {
            SelectedChild = LeftPosition;
        }
        else {
            if ( PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;                
        }

        if ( PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority)
        {
            PQ_SwapNodes(PQ, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition  = PQ_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if ( PQ->UsedSize < ( PQ->Capacity / 2 ) ) 
    {
        PQ->Capacity /= 2;
        PQ->Nodes = 
            (PQNode*) realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }
}

int PQ_GetParent( int Index )
{
    return (int) ((Index - 1) / 2);
}

int PQ_GetLeftChild( int Index )
{
    return (2 * Index) + 1;
}

int PQ_IsEmpty( PriorityQueue* PQ )
{
    return ( PQ->UsedSize == 0 );
}

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* ShortestPath )
{
    int i = 0;

    PQNode         StartNode = { 0, StartVertex };
    PriorityQueue* PQ        = PQ_Create(10);

    Vertex*  CurrentVertex = NULL;
    Edge*    CurrentEdge   = NULL; 

    int*     Weights       = (int*) malloc( sizeof(int) * G->VertexCount );
    Vertex** ShortestPathVertices = 
                             (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
    Vertex** Fringes       = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );
    Vertex** Precedences   = (Vertex**) malloc( sizeof(Vertex*) * G->VertexCount );

    CurrentVertex = G->Vertices;
    while ( CurrentVertex != NULL )
    {
        Vertex* NewVertex = CreateVertex( CurrentVertex->Data );
        AddVertex( ShortestPath, NewVertex);

        Fringes[i]     = NULL;
        Precedences[i] = NULL;
        ShortestPathVertices[i] = NewVertex;        
        Weights[i]     = MAX_WEIGHT;        
        CurrentVertex  = CurrentVertex->Next;
        i++;
    }

    PQ_Enqueue ( PQ, StartNode );

    Weights[StartVertex->Index] = 0;
    
    while( ! PQ_IsEmpty( PQ ) )
    {
        PQNode  Popped;
        
        PQ_Dequeue(PQ, &Popped);
        CurrentVertex = (Vertex*)Popped.Data;
        
        Fringes[CurrentVertex->Index] = CurrentVertex;

        CurrentEdge = CurrentVertex->AdjacencyList;
        while ( CurrentEdge != NULL )
        {            
            Vertex* TargetVertex = CurrentEdge->Target;

            if ( Fringes[TargetVertex->Index] == NULL &&
                 Weights[CurrentVertex->Index] + CurrentEdge->Weight < 
                               Weights[TargetVertex->Index] )
            {
                PQNode NewNode =  { CurrentEdge->Weight, TargetVertex };
                PQ_Enqueue ( PQ, NewNode );

                Precedences[TargetVertex->Index] =  CurrentEdge->From;
                Weights[TargetVertex->Index]     =  
                               Weights[CurrentVertex->Index] + CurrentEdge->Weight; 
            }
            
            CurrentEdge = CurrentEdge->Next;
        }
    }

    for ( i=0; i<G->VertexCount; i++ )
    {
        int FromIndex, ToIndex;

        if ( Precedences[i] == NULL )
            continue;

        FromIndex = Precedences[i]->Index;
        ToIndex   = i;

        AddEdge( ShortestPathVertices[FromIndex], 
            CreateEdge( 
                ShortestPathVertices[FromIndex], 
                ShortestPathVertices[ToIndex],   
                Weights[i] ) );
    }

    free( Fringes );
    free( Precedences );
    free( ShortestPathVertices );
    free( Weights );

    PQ_Destroy( PQ );
}

int main( void )
{
    
    Graph* graph      = CreateGraph();
    Graph* PrimMST    = CreateGraph();
    Graph* KruskalMST = CreateGraph();
   
    Vertex* A = CreateVertex( 'A' );
    Vertex* B = CreateVertex( 'B' );
    Vertex* C = CreateVertex( 'C' );
    Vertex* D = CreateVertex( 'D' );
    Vertex* E = CreateVertex( 'E' );
    Vertex* F = CreateVertex( 'F' );
    Vertex* G = CreateVertex( 'G' );
    Vertex* H = CreateVertex( 'H' );
    Vertex* I = CreateVertex( 'I' );

    AddVertex( graph, A );
    AddVertex( graph, B );
    AddVertex( graph, C );
    AddVertex( graph, D );
    AddVertex( graph, E );
    AddVertex( graph, F );
    AddVertex( graph, G );
    AddVertex( graph, H );
    AddVertex( graph, I );

    AddEdge( A, CreateEdge(A, E, 247) );

    AddEdge( B, CreateEdge(B, A, 35  ) );
    AddEdge( B, CreateEdge(B, C, 126 ) );
    AddEdge( B, CreateEdge(B, F, 150 ) );
    
    AddEdge( C, CreateEdge(C, D, 117 ) );
    AddEdge( C, CreateEdge(C, F, 162 ) );
    AddEdge( C, CreateEdge(C, G, 220 ) );
    
    AddEdge( E, CreateEdge(E, H, 98 ) );

    AddEdge( F, CreateEdge(F, E, 82  ) );
    AddEdge( F, CreateEdge(F, G, 154 ) );
    AddEdge( F, CreateEdge(F, H, 120 ) );

    AddEdge( G, CreateEdge(G, I, 106 ) );

    Dijkstra(graph, B, PrimMST);
    PrintGraph ( PrimMST );
    
    DestroyGraph( PrimMST );
    DestroyGraph( KruskalMST );
    DestroyGraph( graph );

    return 0;
}
