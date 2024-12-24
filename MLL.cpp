#include "MLL.h"

/*
FUNGSI DAN PROSEDUR YANG DIPAKAI DALAM MLL.h
void EvaluasiPenulis(ListPenulis P, ListRelasi R);
void AddRelasi(ListRelasi &R, string JudulBuku, ListBuku B, ListPenulis P, string NamaPenulis);
void HapusPenulisPadaRelasi(ListPenulis &P, ListRelasi &R, int IDPenulis);
void HapusBukuPadaRelasi(ListBuku &B, ListRelasi &R, int IDBuku);
void InputBukukeList(ListBuku &B, AdrBuku book, ListRelasi &R);
void InputPenuliskeList(ListPenulis &P, AdrPenulis Pen, ListRelasi &R);
*/

void EvaluasiPenulis(ListPenulis P, ListRelasi R){
    /*
    Menampilkan data penulis yang paling aktif dan tidak dalam menulis buku
    */
    AdrPenulis q = P.First;
    int maxBooks = 0, minBooks = 10;
    AdrPenulis aktif = NULL, pasif = NULL;

    while (q != NULL) {
        int count = 0;
        AdrRelasi r = R.First;
        while (r != NULL) {
            if (r->PR == q) {
                count++;
            }
            r = r->next;
        }
        if (count > maxBooks) {
            maxBooks = count;
            aktif = q;
        }
        if (count < minBooks) {
            minBooks = count;
            pasif = q;
        }
        q = q->next;
    }

    cout << "Penulis paling aktif: " << aktif->InfoPen.nama << " dengan " << maxBooks << " buku.\n";
    cout << "Penulis paling pasif: " << pasif->InfoPen.nama << " dengan " << minBooks << " buku.\n";
}

void AddRelasi(ListRelasi &R, string JudulBuku, ListBuku B, ListPenulis P, string NamaPenulis){
    /*
    (I.S : Terdefinisi ListBuku P yang kosong, judulBuku dan NamaPenulis yang akan direlasikan, ListBuku B dan ListPenulis P
    proses : Mengalokasikan AdrPenulis Rel. Memasukan elemen dari Rel dengan fungsi FindBukuByJudul() dan FindPenulisByName(). Setelahnya, dilanjutkan proses Relasi() untuk memasukkan Rel ke dalam ListRelasi R
    F.S : alamat Rel masuk ke dalam ListRelasi R)
    */
    AdrBuku P_Buku = FindBukuByJudul(B, JudulBuku);
    AdrPenulis P_Writer = FindPenulisByName(P, NamaPenulis);
    if (P_Buku != NULL && P_Writer != NULL){
        AdrRelasi Rel = new ElmRelasi;
        Rel->BR = P_Buku;
        Rel->PR = P_Writer;
        Rel->next = NULL;
        InsertRelasi(R, Rel);
        cout<<"Relasi antara Buku-Penulis Sudah Ditambahkan.\n";
    }else{
        cout<<endl<<"Judul Buku atau Nama Penulis tidak ditemukan.\n"<<endl;
    }
}

void HapusBukuPadaRelasi(ListBuku &B, ListRelasi &R, int IDBuku) {
    AdrRelasi RAB = R.First;
    AdrRelasi p = NULL;
    AdrRelasi del = NULL;
    while (RAB != NULL) {
        if (RAB->BR->InfoBuku.IDBuku == IDBuku) {
            if (RAB == R.First) {
                R.First = RAB->next;
                del = RAB;
                RAB = R.First;
            } else {
                p->next = RAB->next;
                del = RAB;
                RAB = p->next;
            }
        } else {
            p = RAB;
            RAB = RAB->next;
        }
    }
}


void HapusPenulisPadaRelasi(ListPenulis &P, ListRelasi &R, int IDPenulis) {
    AdrRelasi RAP = R.First;
    AdrRelasi p = NULL;
    AdrRelasi del = NULL;
    while (RAP != NULL) {
        if (RAP->PR->InfoPen.IDPenulis == IDPenulis) {
            if (RAP == R.First) {
                R.First = RAP->next;
                del = RAP;
                RAP = R.First;
            } else {
                p->next = RAP->next;
                del = RAP;
                RAP = p->next;
            }
        } else {
            p = RAP;
            RAP = RAP->next;
        }
    }
}

void InputBukukeList(ListBuku &B, AdrBuku book, ListRelasi &R){
    int Idbook = book->InfoBuku.IDBuku;
    if (B.First == NULL && B.Last == NULL) {
        B.First = book;
        B.Last = book;
    }else if (B.First->InfoBuku.IDBuku < Idbook){
        insertFirstBuku(B, book);
    }else if (B.Last->InfoBuku.IDBuku > Idbook){
        InsertLastBuku(B, book);
    }else{
        AdrBuku pointer = B.First;
        AdrBuku pointerNext = pointer->next;
        while (pointer != NULL){
            if (pointer->InfoBuku.IDBuku >= Idbook && pointerNext->InfoBuku.IDBuku <= Idbook){
                InsertAfterBuku(B, pointer, book);
                return;
            }
            pointer = pointer->next;
        }
    }
}

void InputPenuliskeList(ListPenulis &P, AdrPenulis Pen, ListRelasi &R){
    int Idpen = Pen->InfoPen.IDPenulis;
    if (P.First == NULL) {
        P.First = Pen;
    } else if (P.First->InfoPen.IDPenulis > Idpen) {
        InsertFirstPen(P, Pen);
    } else {
        AdrPenulis pointer = P.First;
        AdrPenulis previous = NULL;
        while (pointer != NULL && pointer->InfoPen.IDPenulis < Idpen) {
            previous = pointer;
            pointer = pointer->next;
        }
        if (previous == NULL) {
            InsertFirstPen(P, Pen);
        } else if (pointer == NULL) {
            InsertLastPen(P, Pen);
        } else {
            InsertAfterPen(P, previous, Pen);
        }
    }
}

void TambahRelasiPenulis(ListRelasi &R, ListBuku B, ListPenulis P){
    string JudulBuku, NamaPen;
    cout<< "Nama Penulis yang ingin di-update: ";
    cin>> NamaPen;
    cout<<endl;
    cout<< "Judul Buku yang ingin ditambahkan: ";
    cin>> JudulBuku;
    AddRelasi(R, JudulBuku, B, P, NamaPen);
}

void TambahRelasiBuku(ListRelasi &R,ListBuku B,ListPenulis P){
    string JudulBuku, NamaPen;
    cout<< "Judul buku yang ingin di-update: ";
    cin>> JudulBuku;
    cout<<endl;
    cout<< "Nama Penulis yang ingin ditambahkan: ";
    cin>> NamaPen;
   AddRelasi(R, JudulBuku, B, P, NamaPen);
}
