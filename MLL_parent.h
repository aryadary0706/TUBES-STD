#ifndef MLL_PARENT_H_INCLUDED
#define MLL_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

struct Penulis{
    int IDPenulis; // ID yang dimiliki Penulis yang ada dalam list
    string nama;
    string asal;
    string namaPena; //opsional. Jika penulis tidak ada nama pena. Maka ditulis '-'
};

typedef struct ElmPenulis *AdrPenulis;

//ElmPenulis bersifat single linked list
struct ElmPenulis {
    Penulis InfoPen; //Informasi Penulis
    AdrPenulis next;
};


//List bersifat single linked list
struct ListPenulis {
    AdrPenulis First;
};

void createListPenulis(ListPenulis &P);
AdrPenulis AllocatePenulis();
void HapusPenulis(ListPenulis &P, int IDPenulis);
void AddPenulis(ListPenulis &P);
AdrPenulis FindPenulisByName(ListPenulis P, string Nama);
void TampilkanPenulisSelectionSortAscending(ListPenulis &P);
void TampilkanPenulisInsertionSortDescending(ListPenulis &P);

#endif // MLL_PARENT_H_INCLUDED
