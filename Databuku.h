#ifndef DATABUKU_H_INCLUDED
#define DATABUKU_H_INCLUDED

#include <iostream>
using namespace std;

//List child
struct Buku{
    int IDBuku; //ID yang dimiliki Buku yang terdaftar
    string Judul; //Judul yang dimiliki Buku
    string Penerbit;
    int Tahunterbit;
    int Cetakan;
    string Editor;
};

//list Parent
struct Penulis{
    int IDPenulis; // ID yang dimiliki Penulis yang ada dalam list
    string nama;
    string asal;
    string namaPena; //opsional. Jika penulis tidak ada nama pena. Maka ditulis '-'
};

typedef struct ElmBuku *AdrBuku;
typedef struct ElmPenulis *AdrPenulis;
typedef struct ElmRelasi *AdrRelasi;

//ElmBuku bersifat double linked list
struct ElmBuku {
    Buku InfoBuku; //Informasi Buku
    AdrBuku next;
    AdrBuku prev;
};

//ElmPenulis bersifat single linked list
struct ElmPenulis {
    Penulis InfoPen; //Informasi Penulis
    AdrPenulis next;
};

struct ElmRelasi {
    AdrBuku BR; //BookRelation: Address untuk AdrBuku, menyimpan alamat Buku dalam ListBuku
    AdrPenulis PR; //PenulisRelation: Address untuk adrPenulis, menyimpan alamat Buku dalam ListPenulis
    AdrRelasi next;
};

//List bersifat double linked list
struct ListBuku {
    AdrBuku First;
    AdrBuku Last;
};
//List bersifat single linked list
struct ListPenulis {
    AdrPenulis First;
};
//List bersifat single linked list
struct ListRelasi {
    AdrRelasi First;
};
#endif // DATABUKU_H_INCLUDED
