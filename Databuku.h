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

void createListPenulis(ListPenulis &P);
void createListBuku(ListBuku &B);
void createListRelasi(ListRelasi &R);
void InsertBuku(ListBuku &B, AdrBuku Newbook);
void InsertPenulis(ListPenulis &P, AdrPenulis Writer);
void AddBuku(ListBuku &B);
void AddPenulis(ListPenulis &P);
AdrBuku FindBukuByJudul(ListBuku B, string judul);
AdrPenulis FindPenulisByName(ListPenulis P, string Nama);
void InsertRelasi(ListRelasi &R, AdrRelasi NewRelasi);
void AddRelasi(ListRelasi &R, string JudulBuku, ListBuku B, ListPenulis P, string NamaPenulis);
void HapusPenulis(ListPenulis &P, ListRelasi &R, int IDPenulis);
void HapusBuku(ListBuku &B, ListRelasi &R, int IDBuku);
void TampilkanSemuaBuku(ListBuku B, ListRelasi R);
void TampilkanBukuByPenulis(ListRelasi R, string NamaPenulis);
void TampilkanPenulisByBuku(ListRelasi R, string JudulBuku);
void TampilkanPenulisPalingAktifDanPasif(ListPenulis P, ListRelasi R);
void TampilkanPenulisAscending(ListPenulis &P);
void TampilkanPenulisDescending(ListPenulis &P);


#endif // DATABUKU_H_INCLUDED
