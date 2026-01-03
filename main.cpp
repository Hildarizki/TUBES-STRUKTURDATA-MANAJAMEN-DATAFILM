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

        if (pilihan == 1) {
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

            root = insertBST(root, film);
        }
        else if (pilihan == 2) {
            inorder(root);
        }
        else if (pilihan == 3) {
            string judul;
            cout << "Masukkan judul film: ";
            getline(cin, judul);

            Node* film = cariFilm(root, judul);
            if (film != NULL)
                cout << "Film ditemukan!\n";
            else
                cout << "Film tidak ditemukan.\n";
        }
        else if (pilihan == 4) {
            string judul, aktor;
            cout << "Judul Film: ";
            getline(cin, judul);

            Node* film = cariFilm(root, judul);
            if (film != NULL) {
                cout << "Nama Aktor: ";
                getline(cin, aktor);
                tambahAktor(film, aktor);
            }
        }
        else if (pilihan == 5) {
            string judul, aktor;
            cout << "Judul Film: ";
            getline(cin, judul);

            Node* film = cariFilm(root, judul);
            if (film != NULL) {
                cout << "Nama Aktor: ";
                getline(cin, aktor);
                hapusAktor(film, aktor);
            }
        }
        else if (pilihan == 6) {
            cout << "Total film: " << hitungFilm(root) << endl;
        }
        else if (pilihan == 7) {
            Node* minFilm = NULL;
            Node* maxFilm = NULL;
            cariDurasi(root, minFilm, maxFilm);

            if (minFilm && maxFilm) {
                cout << "Film Tercepat : " << minFilm->data.judul << endl;
                cout << "Film Terlama  : " << maxFilm->data.judul << endl;
            }
        }

    } while (pilihan != 0);

    return 0;
}
