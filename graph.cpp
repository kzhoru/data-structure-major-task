#include <iostream>
#include "graph.h"
using namespace std;

void createVertex_103022330008(char newVertexID, adrVertex &v) {
    v = new vertex;
    idVertex(v) = newVertexID;
    posisi(v) = false;
    jmlKunjungan(v) = 0;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

void initGraph_103022330008(graph &G) {
    firstVertex(G) = NULL;
}

void addVertex_103022330008(graph &G, char newVertexID) {
    adrVertex newV;
    createVertex_103022330008(newVertexID, newV);

    if(firstVertex(G) == NULL) {
        firstVertex(G) = newV;
    } else {
        adrVertex v = firstVertex(G);
        while (nextVertex(v) != NULL) {
            v = nextVertex(v);
        }
        nextVertex(v) = newV;
    }
}

void buildGraph_103022330008(graph &G) {
    char inputVertexID;

    while (true) {
        cout << "Masukkan ID Simpul (A-Z) : ";
        cin >> inputVertexID;

        if(!(inputVertexID >= 'A' && inputVertexID <= 'Z')) {
            cout << "ID Simpul yang anda masukkan bukan (A-Z)." << endl;
            break;
        }

        bool isUnique = true;
        adrVertex v = firstVertex(G);

        while (v != NULL) {
            if(idVertex(v) == inputVertexID) {
                isUnique = false;
                break;
            }
            v = nextVertex(v);
        }

        if(isUnique) {
            addVertex_103022330008(G, inputVertexID);
            cout << "Simpul " << inputVertexID << " berhasil ditambahkan." << endl;
        } else {
            cout << "ID Simpul " << inputVertexID << " yang anda masukkan sudah ada." << endl;
        }
    }
}

void showVertex(graph G) {
    adrVertex v = firstVertex(G);

    while (v != NULL) {
        cout << idVertex(v) << " ";
        v = nextVertex(v);
    }
}
