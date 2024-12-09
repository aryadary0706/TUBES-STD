#ifndef MLL_CHILD_H_INCLUDED
#define MLL_CHILD_H_INCLUDED

# include <iostream>
using namespace std;

// Elemen Buku
struct Buku{
    int IDBuku; //ID yang dimiliki Buku yang terdaftar
    string Judul; //Judul yang dimiliki Buku
    string Penerbit;
    int Tahunterbit;
    int Cetakan;
    string Editor;
};

//Adress Buku
typedef struct ElmBuku *AdrBuku;

//ElmBuku bersifat double linked list
struct ElmBuku {
    Buku InfoBuku; //Informasi Buku
    AdrBuku next;
    AdrBuku prev;
};

//List bersifat double linked list
struct ListBuku {
    AdrBuku First;
    AdrBuku Last;
};

void createListBuku(ListBuku &B);
AdrBuku AllocateBuku();
void insertFirstBuku(ListBuku &B, AdrBuku book);
void InsertLastBuku(ListBuku &B, AdrBuku book);
void InsertAfterBuku(ListBuku &B, AdrBuku prec, AdrBuku book);
void HapusBuku(ListBuku &B, int IDBuku);
AdrBuku FindBukuByJudul(ListBuku B, string judul);

#endif // MLL_CHILD_H_INCLUDED
