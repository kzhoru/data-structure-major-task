#include <iostream>
#include "graph.h"

using namespace std;

void createVertex(char newVertexID, adrVertex &v) {
    v = new vertex;
    idVertex(v) = newVertexID;
    position(v) = false;
    visitCount(v) = 0;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

bool checkVertices(graph G) {
    // Mengecek apakah graf sudah memiliki simpul
    int vertexCount = 0;
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        vertexCount++;
        v = nextVertex(v);
    }
    return (vertexCount <= 0) ? false : true;
}

void initGraph(graph &G) {
    firstVertex(G) = NULL;
}

void addVertex(graph &G, char newVertexID) {
    adrVertex newV;
    createVertex(newVertexID, newV);

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

void buildGraph(graph &G) {
    char inputVertexID;

    while (true) {
        cout << "Masukkan ID Simpul antara A-Z (Masukkan lainnya untuk batal) : ";
        cin >> inputVertexID;

        if(!(inputVertexID >= 'A' && inputVertexID <= 'Z')) {
            cout << "ID Simpul yang anda masukkan bukan A-Z." << endl;
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
            addVertex(G, inputVertexID);
            cout << "Simpul " << inputVertexID << " berhasil ditambahkan.\n" << endl;
        } else {
            cout << "ID Simpul " << inputVertexID << " yang anda masukkan sudah ada.\n" << endl;
        }
    }
}

void showVertex(graph G) {
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        adrEdge e = firstEdge(v);
        cout << idVertex(v) << " | Posisi saat ini: " << (position(v) ? "True" : "False") << (position(v) ? "  | Jumlah Kunjungan: " : " | Jumlah Kunjungan: ") << visitCount(v) << endl;
        if(e != NULL) {
            while(e != NULL) {
                cout << "  -> " << destVertexID(e) << " (Bobot: " << weight(e) << ")" << endl;
                e = nextEdge(e);
            }
        }
        cout << endl;
        v = nextVertex(v);
    }
}

bool haveVisited(graph G) {
    bool haveVisitedPlace = false;
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        if(position(v) == true) {
            haveVisitedPlace = true;
            break;
        }
        v = nextVertex(v);
    }
    return haveVisitedPlace;
}

adrVertex searchVertex(graph G, char vertexID){
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        if (vertexID == idVertex(v)) {
            return v;
        }
        v = nextVertex(v);
    }
    return NULL;
}

void createEdge(graph &G, char vertexId, char destvertexid, int weight) {
    adrVertex v = searchVertex(G,vertexId);
    adrVertex destV = searchVertex(G, destvertexid);

    if (v == NULL || destV == NULL) {
        cout << "ID Simpul tidak ditemukan.\n"<<endl;
    } else {
        adrEdge e = firstEdge(v);
        while(e != NULL) {
            if(destVertexID(e) == destvertexid) {
                cout << "Simpul " << vertexId << " sudah terhubung dengan " << destvertexid << ".\n" << endl;
                return;
            }
            e = nextEdge(e);
        }

        adrEdge newEdge = new edge;
        destVertexID(newEdge) = destvertexid;
        weight(newEdge) = weight;
        nextEdge(newEdge) = NULL;
        if (firstEdge(v) == NULL) {
            firstEdge(v) = newEdge;
        } else {
            adrEdge e = firstEdge(v);
            while (nextEdge(e) != NULL) {
                e = nextEdge(e);
            }
            nextEdge(e) = newEdge;
        }
        cout << "Simpul " << vertexId << " berhasil terhubung dengan simpul " << destvertexid << endl;

        adrEdge reverseEdge = new edge;
        destVertexID(reverseEdge) = vertexId;
        weight(reverseEdge) = weight;
        nextEdge(reverseEdge) = NULL;
        if(firstEdge(destV) == NULL) {
            firstEdge(destV) = reverseEdge;
        } else {
            adrEdge e = firstEdge(destV);
            while(nextEdge(e) != NULL) {
                e = nextEdge(e);
            }
            nextEdge(e) = reverseEdge;
        }
        cout << "Simpul " << destvertexid << " berhasil terhubung dengan simpul " << vertexId << endl << endl;
    }
}

void connectVertex(graph G) {
    while(true) {
        char v, vDestination, answer;
        int weight;

        cout << "Pilih vertex asal : ";
        cin >> v;
        if(searchVertex(G, v) == NULL) {
            cout << "Vertex asal tidak ditemukan. Ulangi ? (y/n) : ";
            cin >> answer;

            if(answer == 'y') {
                continue;
            } else {
                break;
            }
        }

        cout << "Pilih vertex tujuan : ";
        cin >> vDestination;
        if(searchVertex(G, vDestination) == NULL) {
            cout << "Vertex tujuan tidak ditemukan. Ulangi ? (y/n) : ";
            cin >> answer;

            if(answer == 'y') {
                continue;
            } else {
                break;
            }
        }

        cout << "Masukkan bobot : ";
        cin >> weight;
        if (weight < 1) {
            cout << "Bobot tidak boleh <= 0. Ulangi ? (y/n) : ";
            cin >> answer;

            if(answer == 'y') {
                continue;
            } else {
                break;
            }
        }

        createEdge(G, v, vDestination, weight);
    }
}

adrVertex findLocation(graph G) {
    adrVertex v = firstVertex(G);
    while(v != NULL) {
        if(position(v) == true || position(v) == 1) {
            return v;
        }
        v = nextVertex(v);
    }
    return NULL;
}

void showLocation(graph G) {
    adrVertex v = findLocation(G);
    cout << "Posisi anda saat ini berada di simpul : " << idVertex(v) << endl;
}

void findShortestPath(graph G, char startVertex, char targetVertex) {
    const int INF = INT_MAX;
    int vertexCount = 0;

    // Hitung jumlah simpul
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        vertexCount++;
        v = nextVertex(v);
    }

    // Array untuk menyimpan data graf
    char vertexIDs[vertexCount];
    int distances[vertexCount];
    bool visited[vertexCount];
    int predecessors[vertexCount];

    // Inisialisasi data
    v = firstVertex(G);
    for (int i = 0; i < vertexCount; ++i) {
        vertexIDs[i] = idVertex(v);
        distances[i] = INF;
        visited[i] = false;
        predecessors[i] = -1;
        v = nextVertex(v);
    }

    // Temukan indeks simpul awal dan tujuan
    int startIndex = -1, targetIndex = -1;
    for (int i = 0; i < vertexCount; ++i) {
        if (vertexIDs[i] == startVertex) startIndex = i;
        if (vertexIDs[i] == targetVertex) targetIndex = i;
    }

    if (startIndex == -1 || targetIndex == -1) {
        cout << "Simpul awal atau tujuan tidak ditemukan!" << endl;
        return;
    }

    // Set jarak simpul awal ke 0
    distances[startIndex] = 0;

    // Algoritma Dijkstra
    for (int i = 0; i < vertexCount; ++i) {
        // Cari simpul dengan jarak minimum yang belum dikunjungi
        int currentIndex = -1;
        int minDistance = INF;
        for (int j = 0; j < vertexCount; ++j) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                currentIndex = j;
            }
        }

        // Jika tidak ada simpul yang dapat dikunjungi, keluar dari loop
        if (currentIndex == -1) break;

        // Tandai simpul sebagai dikunjungi
        visited[currentIndex] = true;

        // Perbarui jarak ke tetangga
        adrVertex currentVertex = firstVertex(G);
        for (int k = 0; k < currentIndex; ++k) {
            currentVertex = nextVertex(currentVertex);
        }

        adrEdge edge = firstEdge(currentVertex);
        while (edge != NULL) {
            char neighborID = destVertexID(edge);
            int weightEdge = weight(edge);

            // Cari indeks tetangga
            int neighborIndex = -1;
            for (int j = 0; j < vertexCount; ++j) {
                if (vertexIDs[j] == neighborID) {
                    neighborIndex = j;
                    break;
                }
            }

            // Perbarui jarak jika ditemukan jalur yang lebih pendek
            if (neighborIndex != -1 && distances[currentIndex] + weightEdge < distances[neighborIndex]) {
                distances[neighborIndex] = distances[currentIndex] + weightEdge;
                predecessors[neighborIndex] = currentIndex;
            }

            edge = nextEdge(edge);
        }
    }

    // Output hasil
    if (distances[targetIndex] == INF) {
        cout << "Tidak ada jalur dari " << startVertex << " ke " << targetVertex << endl;
    } else {
        cout << "Jarak terpendek dari " << startVertex << " ke " << targetVertex << " adalah: " << distances[targetIndex] << endl;
        cout << "Jalur: ";

        // Rekonstruksi jalur
        int step = targetIndex;
        while (step != -1) {
            cout << vertexIDs[step];
            step = predecessors[step];
            if (step != -1) cout << " <- ";
        }
        cout << endl;
    }
}

void showMostVisitedPlaces(graph G) {
    adrVertex v = firstVertex(G), mostVisitedPlace1 = NULL, mostVisitedPlace2 = NULL, mostVisitedPlace3 = NULL;
    int mostVisitedCount1 = 0, mostVisitedCount2 = 0, mostVisitedCount3 = 0;

    while (v != NULL) {
        int currentVisitCount = visitCount(v);

        if (currentVisitCount > mostVisitedCount1) {
            mostVisitedPlace3 = mostVisitedPlace2;
            mostVisitedCount3 = mostVisitedCount2;

            mostVisitedPlace2 = mostVisitedPlace1;
            mostVisitedCount2 = mostVisitedCount1;

            mostVisitedPlace1 = v;
            mostVisitedCount1 = currentVisitCount;
        } else if (currentVisitCount > mostVisitedCount2) {
            mostVisitedPlace3 = mostVisitedPlace2;
            mostVisitedCount3 = mostVisitedCount2;

            mostVisitedPlace2 = v;
            mostVisitedCount2 = currentVisitCount;
        } else if (currentVisitCount > mostVisitedCount3) {
            mostVisitedPlace3 = v;
            mostVisitedCount3 = currentVisitCount;
        }

        v = nextVertex(v);
    }

    cout << "Urutan tempat paling sering dikunjungi adalah : " << endl;
    if(mostVisitedPlace1 != NULL) {
        cout << "1. " << idVertex(mostVisitedPlace1) << " (sebanyak " << mostVisitedCount1 << " kali)" << endl;
    }
    if(mostVisitedPlace2 != NULL) {
        cout << "2. " << idVertex(mostVisitedPlace2) << " (sebanyak " << mostVisitedCount2 << " kali)" << endl;
    }
    if(mostVisitedPlace3 != NULL) {
        cout << "3. " << idVertex(mostVisitedPlace3) << " (sebanyak " << mostVisitedCount3 << " kali)" << endl;
    }
}

void visitVertex(graph G, char targetVertex) {
    adrVertex startVertex, endVertex;
    startVertex = findLocation(G);
    endVertex = searchVertex(G, targetVertex);

    position(startVertex) = false;
    position(endVertex) = true;
    visitCount(endVertex)++;

    cout << "Anda telah berpindah dari simpul " << idVertex(startVertex) << " ke simpul " << idVertex(endVertex) << endl;
}
