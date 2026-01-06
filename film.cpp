//Kelompok 7

#include "film.h"
#include <iostream>
using namespace std;

//BST
Node* buatNode(Film film) {
    Node* baru = new Node;
    baru->data = film;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insertBST(Node* root, Film film) {
    if (root == NULL)
        return buatNode(film);

    if (film.judul < root->data.judul)
        root->left = insertBST(root->left, film);
    else if (film.judul > root->data.judul)
        root->right = insertBST(root->right, film);
    else
        cout << "Judul film sudah terdaftar!\n";

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

//TRAVERSAL
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
