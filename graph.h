#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>

#define firstVertex(G) G.firstVertex
#define idVertex(V) V->idVertex
#define nextVertex(V) V->next
#define position(V) V->position
#define visitCount(V) V->visitCount
#define firstEdge(V) V->firstEdge
#define destVertexID(E) E->destVertexID
#define weight(E) E->weight
#define nextEdge(E) E->nextEdge
using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    char idVertex;
    adrVertex next;
    bool position;
    int visitCount;
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

void createVertex(char newVertexID, adrVertex &v);

bool checkVertices(graph G);

void initGraph(graph &G);

void addVertex(graph &G, char newVertexID);

void buildGraph(graph &G);

void showVertex(graph G);

bool haveVisited(graph G);

adrVertex searchVertex(graph G, char vertexID);

void createEdge(graph &G,char vertexId,char destVertexId, int weight);

void connectVertex(graph G);

void findShortestPath(graph G, char startVertex, char targetVertex);
#endif // GRAPH_H_INCLUDED
