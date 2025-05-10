#include "MLL_relation.h"

/*
FUNGSI DAN PROSEDUR YANG DIPAKAI DALAM MLL_Relasi.h (SINGLE-linked List)
void InsertRelasi(ListRelasi &R, AdrRelasi NewRelasi);
void PrintBukuDanPenulis(ListRelasi R);
void PrintBukuBasedPenulis(ListRelasi R, string NamaPenulis);
void PrintPenulisOnBuku(ListRelasi R, string judulBuku);
void
*/

void createListRelasi(ListRelasi &R){
    R.First = NULL;
}

void InsertRelasi(ListRelasi &R, AdrRelasi NewRelasi){
    /*
    (I.S : Terdefinisi ListRelasi R yang bisa saja kosong dan NewRelasi adalah alamat relasi yang akan dimasukkan
    F.S : alamat Pen masuk ke dalam ListPenulis P)
    */
    if (R.First == NULL){
        R.First = NewRelasi;
    }else{
        AdrRelasi Q = R.First;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = NewRelasi;
    }
}



void PrintBukuBasedPenulis(ListRelasi R, string NamaPenulis){
    /*
    I.S Terdifinisi ListRelasi R dan string NamaPenulis yang merupakan kata kunci untuk mencari nama buku-buku yang telah ditulis NamaPenulis
    F.S Ditampilkan Data Buku-buku yang ditulis oleh Penulis tersebut
    */
    AdrRelasi R_pointer = R.First;
    AdrBuku BfromR;
    int count = 1;
    cout<<"Judul-judul Buku yang sudah ditulis "<<NamaPenulis<<endl;
    while (R_pointer != NULL){
            if (R_pointer->PR->InfoPen.nama == NamaPenulis || R_pointer->PR->InfoPen.namaPena == NamaPenulis){
               BfromR = R_pointer->BR;
               cout<< count;
               cout<<"ID BUKU: "<<BfromR->InfoBuku.IDBuku<<endl;
               cout<<"Judul Buku: "<<BfromR->InfoBuku.Judul<<endl;
               cout<<"Penerbit: "<<BfromR->InfoBuku.Penerbit<<endl;
               cout<<"Tahun terbit: "<<BfromR->InfoBuku.Tahunterbit<<endl;
               cout<<"Cetakan: "<<BfromR->InfoBuku.Cetakan<<endl;
               cout<<"Editor: "<<BfromR->InfoBuku.Editor<<endl;
               cout<<"==============================================="<<endl;
            }
            R_pointer = R_pointer->next;
            count++;
           }
        if (count == 1){
            cout<<"Penulis belum menerbitkan buku!"<<endl;
        }
}

void PrintPenulisOnBuku(ListRelasi R, string judulBuku){
    /*
    I.S Terdefinisi ListRelasi R dan string judulBuku yang merupakan judul Buku yang ingin ditampilkan data penulisnya
    F.S Ditampilkan dat penulis yang menulis Buku berjudul judulBuku
    */
    AdrRelasi RP = R.First;
    AdrPenulis PfromR;
    int count =1;
    while (RP != NULL){
        if (RP->BR->InfoBuku.Judul == judulBuku ){
            PfromR = RP->PR;
            cout<<"==============================================="<<endl;
            cout<<"ID Penulis: "<<PfromR->InfoPen.IDPenulis<<endl;
            cout<<"Nama Penulis: "<<PfromR->InfoPen.nama<<endl;
            cout<<"Nama Pena Penulis: "<<PfromR->InfoPen.namaPena<<endl;
            cout<<"Asal Penulis: "<<PfromR->InfoPen.asal<<endl;
             cout<<"==============================================="<<endl;
        }
        RP = RP->next;
        count++;
    }
    if (count == 1){
        cout<<"Tidak ada informasi Penulis terkait Buku tersebut"<<endl;
    }
}
