#ifndef DATABUKU_H_INCLUDED
#define DATABUKU_H_INCLUDED

#include <iostream>
using namespace std;
struct Buku{
    int IDBuku;
    string Judul;
    string Penerbit;
    int Tahunterbit;
    int Cetakan;
    string Editor;
};

struct Penulis{
    int IDPenulis;
    string nama;
    string asal;
    string namaPena;
};

typedef struct ElmBuku *AdrBuku;
typedef struct ElmPenulis *AdrPenulis;
typedef struct ElmRelasi *AdrRelasi;

struct ElmBuku {
    Buku InfoBuku;
    AdrBuku next;
    AdrBuku prev;
};

struct ElmPenulis {
    Penulis InfoPen;
    AdrPenulis next;
};

struct ElmRelasi {
    AdrBuku BR;
    AdrPenulis PR;
    AdrRelasi next;
};

struct ListBuku {
    AdrBuku First;
    AdrBuku Last;
};

struct ListPenulis {
    AdrPenulis First;
};

struct ListRelasi {
    AdrRelasi First;
};
#endif // DATABUKU_H_INCLUDED
