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
    int maxBooks = 0, minBooks = 100;
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

void AddRelasi(ListRelasi &R, string JudulBuku, ListBuku &B, ListPenulis &P, string NamaPenulis){
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
        cout<<"Judul Buku atau Nama Penulis tidak ditemukan.\n"<<endl;
    }
}

void HapusBuku(ListBuku &B, ListRelasi &R, int IDBuku) {
    AdrBuku buku = B.First;

    while(buku != NULL && buku->InfoBuku.IDBuku != IDBuku){
        buku = buku->next;
    }

    if (buku != NULL){
        AdrRelasi relasi = R.First;
        while (relasi != NULL){
            if (relasi->BR == buku){
                if (relasi == R.First){
                    R.First = relasi->next;
                }else{
                    AdrRelasi q = R.First;
                    while (q->next != relasi){
                        q = q->next;
                    }
                    q->next = relasi->next;
                }
                relasi->BR = NULL;
            }
            relasi = relasi->next;
        }
        if (buku == B.First && buku == B.Last){
            B.First = NULL;
            B.Last = NULL;
        } else if (buku == B.First){
            B.First = buku->next;
            B.First->prev = NULL;
        } else if (buku == B.Last){
            B.Last = buku->prev;
            B.Last->next = NULL;
        }else{
            buku->prev->next = buku->next;
            buku->next->prev = buku->prev;
        }
        buku->next = NULL;
        buku->prev = NULL;

        cout << "Buku dengan ID" << IDBuku << " berhasil dihapus.\n";
    }else{
        cout << "Buku dengan ID" << IDBuku << " tidak ditemukan.\n";
    }
}


void HapusPenulis(ListPenulis &P, ListRelasi &R, int IDPenulis) {
    AdrPenulis q = NULL;
    AdrPenulis p = P.First;

    while (p != NULL && p->InfoPen.IDPenulis != IDPenulis) {
        q = p;
        p = p->next;
    }

    if (p != NULL) {
        AdrRelasi relasi = R.First;
        AdrRelasi rPrec = NULL;

        while (relasi != NULL) {
            if (relasi->PR == p) {
                if (rPrec == NULL) {
                    R.First = relasi->next;
                } else {
                    rPrec->next = relasi->next;
                }
                relasi->PR = NULL;
                relasi = relasi->next;
            } else {
                rPrec = relasi;
                relasi = relasi->next;
            }
        }

        if (q == NULL) {
            P.First = p->next;
        } else {
            q->next = p->next;
        }

        p->next = NULL;
        cout << "Penulis dengan ID " << IDPenulis << " berhasil dihapus.\n";
    } else {
        cout << "Penulis dengan ID " << IDPenulis << " tidak ditemukan.\n";
    }
}


void PrintBukuDanPenulis(ListPenulis P, ListRelasi R){
    /*
    I.S Terdefinisi ListPenulis P dan ListRelasi R
    F.S Ditampilkan Seluruh penulis beserta bukunya
    */

    AdrPenulis penulis = P.First;
    while (penulis != NULL) {
        cout << "ID Penulis: " << penulis->InfoPen.IDPenulis << endl;
        cout << "Nama Penulis: " << penulis->InfoPen.nama << endl;
        cout << "Nama Pena: " << penulis ->InfoPen.namaPena << endl;
        cout << "Asal Kota Penulis: " << penulis->InfoPen.asal << endl;
        cout << "Buku yang Ditulis:\n";

        AdrRelasi relasi = R.First;
        while (relasi != NULL){
            if (relasi->PR == penulis){
                cout << "- " << relasi->BR->InfoBuku.Judul << " terbit tahun " << relasi->BR->InfoBuku.Tahunterbit << endl;
            }
            relasi = relasi->next;
        }
        cout<<"===============================================\n";
        penulis = penulis->next;
    }

}
