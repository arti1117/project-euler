/*
 *  Graph.c
 *
 *  Created on: Aug 17, 2019
 *      Author: arti
 */

#include "Graph.h"

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

int main( void )
{
    Graph* G = CreateGraph();
    
    Vertex* V1 = CreateVertex( '1' );
    Vertex* V2 = CreateVertex( '2' );
    Vertex* V3 = CreateVertex( '3' );
    Vertex* V4 = CreateVertex( '4' );
    Vertex* V5 = CreateVertex( '5' );

    AddVertex( G, V1 );
    AddVertex( G, V2 );
    AddVertex( G, V3 );
    AddVertex( G, V4 );
    AddVertex( G, V5 );

    AddEdge( V1, CreateEdge(V1, V2, 0) );
    AddEdge( V1, CreateEdge(V1, V3, 0) );
    AddEdge( V1, CreateEdge(V1, V4, 0) );
    AddEdge( V1, CreateEdge(V1, V5, 0) );

    AddEdge( V2, CreateEdge(V2, V1, 0) );
    AddEdge( V2, CreateEdge(V2, V3, 0) );
    AddEdge( V2, CreateEdge(V2, V5, 0) );

    AddEdge( V3, CreateEdge(V3, V1, 0) );
    AddEdge( V3, CreateEdge(V3, V2, 0) );

    AddEdge( V4, CreateEdge(V4, V1, 0) );
    AddEdge( V4, CreateEdge(V4, V5, 0) );

    AddEdge( V5, CreateEdge(V5, V1, 0) );
    AddEdge( V5, CreateEdge(V5, V2, 0) );
    AddEdge( V5, CreateEdge(V5, V4, 0) );

    PrintGraph( G );

    DestroyGraph( G );

    return 0;
}

