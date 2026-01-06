//Kelompok 7

#include <iostream>
#include "film.h"
using namespace std;

int main() {
    Node* root = NULL;
    int pilihan;

    do {
        cout << "\n===== MENU MANAJEMEN DATA FILM =====\n";
        cout << "1. Tambah Film\n";
        cout << "2. Tampilkan Semua Film\n";
        cout << "3. Cari Film\n";
        cout << "4. Tambah Aktor ke Film\n";
        cout << "5. Hapus Aktor dari Film\n";
        cout << "6. Hitung Jumlah Film\n";
        cout << "7. Film Terlama & Tercepat\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                Film film;
                film.jumlahAktor = 0;

                cout << "Judul Film : ";
                getline(cin, film.judul);
                cout << "Durasi     : ";
                cin >> film.durasi;
                cin.ignore();
                cout << "Genre      : ";
                getline(cin, film.genre);
                cout << "Tahun      : ";
                cin >> film.tahun;
                cin.ignore();

                root = insertBST(root, film);
                break;
            }

            case 2: {
                if (root == NULL) {
                    cout << "Data film kosong!\n";
                } else {
                    inorder(root);
                }
                break;
            }

            case 3: {
                if (root == NULL) {
                    cout << "Data film kosong!\n";
                    break;
                }
                string judul;
                cout << "Masukkan judul film: ";
                getline(cin, judul);

                Node* film = cariFilm(root, judul);
                if (film != NULL)
                    cout << "Film ditemukan!\n";
                else
                    cout << "Film tidak ditemukan.\n";
                break;
            }

            case 4: {
                if (root == NULL) {
                    cout << "Data film kosong!\n";
                    break;
                }
                string judul, aktor;
                cout << "Judul Film: ";
                getline(cin, judul);

                Node* film = cariFilm(root, judul);
                if (film != NULL) {
                    cout << "Nama Aktor: ";
                    getline(cin, aktor);
                    tambahAktor(film, aktor);
                } else {
                    cout << "Film tidak ditemukan!\n";
                }
                break;
            }

            case 5: {
                if (root == NULL) {
                    cout << "Data film kosong!\n";
                    break;
                }
                string judul, aktor;
                cout << "Judul Film: ";
                getline(cin, judul);

                Node* film = cariFilm(root, judul);
                if (film != NULL) {
                    cout << "Nama Aktor: ";
                    getline(cin, aktor);
                    hapusAktor(film, aktor);
                } else {
                    cout << "Film tidak ditemukan!\n";
                }
                break;
            }

            case 6: {
                int total = hitungFilm(root);
                if (total == 0)
                    cout << "Data film kosong!\n";
                else
                    cout << "Total film: " << total << endl;
                break;
            }

            case 7: {
                if (root == NULL) {
                    cout << "Data film kosong!\n";
                    break;
                }
                Node* minFilm = NULL;
                Node* maxFilm = NULL;
                cariDurasi(root, minFilm, maxFilm);

                if (minFilm && maxFilm) {
                    cout << "Film Tercepat : " << minFilm->data.judul << endl;
                    cout << "Film Terlama  : " << maxFilm->data.judul << endl;
                } else {
                    cout << "Data film kosong!\n";
                }
                break;
            }

            case 0:
                cout << "Keluar dari program...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}