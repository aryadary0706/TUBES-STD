#ifndef MLL_RELATION_H_INCLUDED
#define MLL_RELATION_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct ElmRelasi *AdrRelasi;

struct ElmRelasi {
    AdrBuku BR; //BookRelation: Address untuk AdrBuku, menyimpan alamat Buku dalam ListBuku
    AdrPenulis PR; //PenulisRelation: Address untuk adrPenulis, menyimpan alamat Buku dalam ListPenulis
    AdrRelasi next;
};


//List bersifat single linked list
struct ListRelasi {
    AdrRelasi First;
};
void createListRelasi(ListRelasi &R);
void InsertRelasi(ListRelasi &R, AdrRelasi NewRelasi);
void PrintBukuDanPenulis(ListRelasi R);
void PrintBukuBasedPenulis(ListRelasi R, string NamaPenulis);
void PrintPenulisOnBuku(ListRelasi R, string judulBuku);

#endif // MLL_RELATION_H_INCLUDED
