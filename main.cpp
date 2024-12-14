#include <iostream>
#include "graph.h"
using namespace std;

int selectMenu() {
    int userInput;
    cout << "===================== Menu =====================" << endl;
    cout << "1. Buat Simpul-simpul Tempat Wisata" << endl;
    cout << "2. Menampilkan Semua Simpul" << endl;
    cout << "3. Hubungkan Simpul-simpul Tempat Wisata" << endl;
    cout << "4. Mencari Posisi Saat Ini" << endl;
    cout << "5. Mencari Rute Tercepat" << endl;
    cout << "6. Kunjungi Tempat Wisata" << endl;
    cout << "7. Urutan Kunjungan Tempat Wisata" << endl;
    cout << "0. Keluar" << endl;
    cout << "================================================" << endl;
    cout << "Pilih Menu : ";
    cin >> userInput;
    return userInput;
}

int main()
{
    int selectedMenu;
    graph G;
    initGraph(G);

    selectedMenu = selectMenu();
    while (selectedMenu != 0) {
        switch(selectedMenu) {
            case 1:
                // Buat Simpul-simpul Tempat Wisata
                buildGraph(G);
                break;

            case 2:
                // Menampilkan Semua Simpul
                if(!checkVertices(G)) {
                    cout << "Buat simpul tempat wisata terlebih dahulu." << endl;
                    break;
                }
                cout << "\nDaftar isi simpul pada graf : " << endl;
                showVertex(G);
                break;

            case 3:
                // Hubungkan Simpul-simpul Tempat Wisata
                if(!checkVertices(G)) {
                    cout << "Buat simpul tempat wisata terlebih dahulu." << endl;
                    break;
                }
                cout << "\nMenghubungkan vertex (Inputkan selain ID Simpul untuk membatalkan) : " << endl;
                connectVertex(G);
                break;

            case 4:
                // Mencari Posisi Saat Ini
                if(!checkVertices(G)) {
                    cout << "Buat simpul tempat wisata terlebih dahulu." << endl;
                    break;
                }
                break;

            case 5:
                // Mencari Rute Tercepat
                if(!checkVertices(G)) {
                    cout << "Buat simpul tempat wisata terlebih dahulu." << endl;
                    break;
                }
                break;

            case 6:
                // Kunjungi Tempat Wisata
                if(!checkVertices(G)) {
                    cout << "Buat simpul tempat wisata terlebih dahulu." << endl;
                    break;
                }

                if (!haveVisited(G)) {
                    //jika belum mengujungi salah satu tempat (semua position vertex bernilai false)
                    char visitPlace;
                    cout << "Belum ada lokasi yang dikunjungi. ";
                    while (true) {
                        cout << "Pilih sembarang satu lokasi untuk dikunjungi: ";
                        cin >> visitPlace;
                        adrVertex v = searchVertex(G, visitPlace);
                        if(v != NULL) {
                            position(v) = true;
                            visitCount(v) = visitCount(v) + 1;
                            cout << "Mengunjungi " << visitPlace << ", jumlah kunjungan +1." << endl;
                            break;
                        } else {
                            cout << "Lokasi tidak ditemukan. ";
                            continue;
                        }
                    }
                } else {
                    //jika sudah ada tempat yang dikunjungi (ada 1 vertex yang position bernilai true)
                    // algoritma dijkstra...
                }

                break;

            case 7:
                // Urutan Kunjungan Tempat Wisata
                if(!checkVertices(G)) {
                    cout << "Buat simpul tempat wisata terlebih dahulu." << endl;
                    break;
                }
                break;

            default:
                cout << "Input menu diluar opsi yang disediakan." << endl;
                break;
        }
        cout << endl;
        selectedMenu = selectMenu();
    }

    cout << "\nProgram Selesai" << endl;
    return 0;
}
