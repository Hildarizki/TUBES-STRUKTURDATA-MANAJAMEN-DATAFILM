//Kelompok 7

#ifndef FILM_H
#define FILM_H

#include <string>
using namespace std;

const int MAX_AKTOR = 10;

// ===== STRUKTUR DATA =====

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
    Node* left;
    Node* right;
};

// ===== DEKLARASI OPERASI BST =====

Node* buatNode(Film film);
Node* insertBST(Node* root, Film film);
Node* cariFilm(Node* root, string judul);

// ===== OPERASI AKTOR =====

void tambahAktor(Node* film, string namaAktor);
void hapusAktor(Node* film, string namaAktor);

// ===== TRAVERSAL =====

void inorder(Node* root);

// ===== PENGOLAHAN DATA =====

int hitungFilm(Node* root);
void cariDurasi(Node* root, Node*& minFilm, Node*& maxFilm);

#endif
