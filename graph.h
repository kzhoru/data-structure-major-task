#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define firstVertex(G) G.firstVertex
#define idVertex(V) V->idVertex
#define nextVertex(V) V->next
#define firstEdge(V) V->firstEdge
using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    char idVertex;
    adrVertex next;
    adrEdge firstEdge;
};

struct edge {
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex_103022330008(char newVertexID, adrVertex &v);

void initGraph_103022330008(graph &G);

void addVertex_103022330008(graph &G, char newVertexID);

void buildGraph_103022330008(graph &G);

void showVertex(graph G);


#endif // GRAPH_H_INCLUDED
