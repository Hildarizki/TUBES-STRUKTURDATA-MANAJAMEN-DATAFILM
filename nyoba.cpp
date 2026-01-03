#include <iostream>
#include <string>
using namespace std;

const int MAX_AKTOR = 10;

//STRUKTUR DATA  

struct Film {
    string judul;
    int durasi;
    string genre;
    int tahun;
    string aktor[MAX_AKTOR];   
    int jumlahAktor;
};

struct Node {
    Film data;
    Node *left;
    Node *right;
};

//FUNGSI BST

Node* buatNode(Film film) {
    Node* baru = new Node;
    baru->data = film;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insertBST(Node* root, Film film) {
    if (root == NULL) {
        return buatNode(film);
    }

    if (film.judul < root->data.judul) {
        root->left = insertBST(root->left, film);
    } else if (film.judul > root->data.judul) {
        root->right = insertBST(root->right, film);
    } else {
        cout << "Judul film sudah terdaftar!\n";
    }
    return root;
}

Node* cariFilm(Node* root, string judul) {
    if (root == NULL || root->data.judul == judul)
        return root;

    if (judul < root->data.judul)
        return cariFilm(root->left, judul);
    else
        return cariFilm(root->right, judul);
}

//OPERASI AKTOR

void tambahAktor(Node* film, string namaAktor) {
    if (film->data.jumlahAktor < MAX_AKTOR) {
        film->data.aktor[film->data.jumlahAktor++] = namaAktor;
        cout << "Aktor berhasil ditambahkan.\n";
    } else {
        cout << "Kapasitas aktor penuh!\n";
    }
}

void hapusAktor(Node* film, string namaAktor) {
    for (int i = 0; i < film->data.jumlahAktor; i++) {
        if (film->data.aktor[i] == namaAktor) {
            for (int j = i; j < film->data.jumlahAktor - 1; j++) {
                film->data.aktor[j] = film->data.aktor[j + 1];
            }
            film->data.jumlahAktor--;
            cout << "Aktor berhasil dihapus.\n";
            return;
        }
    }
    cout << "Aktor tidak ditemukan.\n";
}

//TRAVERSAL BST

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);

        cout << "Judul  : " << root->data.judul << endl;
        cout << "Durasi : " << root->data.durasi << " menit\n";
        cout << "Genre  : " << root->data.genre << endl;
        cout << "Tahun  : " << root->data.tahun << endl;
        cout << "Aktor  : ";
        for (int i = 0; i < root->data.jumlahAktor; i++)
            cout << root->data.aktor[i] << ", ";
        cout << "\n--------------------------\n";

        inorder(root->right);
    }
}

//PENGOLAHAN DATA

int hitungFilm(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + hitungFilm(root->left) + hitungFilm(root->right);
}

void cariDurasi(Node* root, Node*& minFilm, Node*& maxFilm) {
    if (root == NULL) return;

    if (minFilm == NULL || root->data.durasi < minFilm->data.durasi)
        minFilm = root;

    if (maxFilm == NULL || root->data.durasi > maxFilm->data.durasi)
        maxFilm = root;

    cariDurasi(root->left, minFilm, maxFilm);
    cariDurasi(root->right, minFilm, maxFilm);
}

//PROGRAM UTAMA

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
            } else {
                cout << "Film tidak ditemukan.\n";
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
            } else {
                cout << "Film tidak ditemukan.\n";
            }
        }

        else if (pilihan == 6) {
            cout << "Total film: " << hitungFilm(root) << endl;
        }

        else if (pilihan == 7) {
            Node* minFilm = NULL;
            Node* maxFilm = NULL;
            cariDurasi(root, minFilm, maxFilm);

            if (minFilm != NULL && maxFilm != NULL) {
                cout << "Film Tercepat : " << minFilm->data.judul << endl;
                cout << "Film Terlama  : " << maxFilm->data.judul << endl;
            }
        }

    } while (pilihan != 0);

    return 0;
}
