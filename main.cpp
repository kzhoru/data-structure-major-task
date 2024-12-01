#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    graph G;
    initGraph_103022330008(G);

    buildGraph_103022330008(G);

    cout << "\nDaftar isi simpul pada graf : " << endl;
    showVertex(G);

    //Misalkan posisi orang start pada simpul pertama
    //Inisialisasi posisi berada pada simpul pertama
    adrVertex firstV = firstVertex(G);
    posisi(firstV) = true;

    return 0;
}
