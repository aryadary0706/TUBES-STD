#include "MLL_parent.h"

/*
FUNGSI DAN PROSEDUR YANG DIPAKAI DALAM MLL_DATAPENULIS.h (SINGLE-linked List)
void createListPenulis(ListPenulis &P);
AdrPenulis AllocatePenulis(ListBuku &B);
void HapusPenulis(ListPenulis &P, int IDPenulis);
void AddPenulis(ListPenulis &P);
AdrPenulis FindPenulisByName(ListPenulis P, string Nama);
void TampilkanPenulisSelectionSortAscending(ListPenulis &P);
void TampilkanPenulisInsertionSortDescending(ListPenulis &P);
void updateNamaPenulis(ListPenulis &P, int IDPenulis);
void updateAsalPenulis(ListPenulis &P, int IDPenulis);
void updateNamaPenaPenulis(ListPenulis &P, int IDPenulis);
*/

void createListPenulis(ListPenulis &P){
    /*
    (I.S -
    F.S : Terdefinisikan ListPenulis P dengan First = NULL)
    */
    P.First = NULL;
}

AdrPenulis AllocatePenulis(ListPenulis P){
    /*
    (I.S : Terdefinisi ListBuku P yang bisa saja kosong
    proses : Mengalokasikan AdrPenulis Pen. Memasukan elemen dari Pen dengan input dari user. Setelahnya, dilanjutkan proses InsertPenulis untuk memasukkan AdrPenulis book ke dalam ListPenulis P
    F.S : alamat Pen masuk ke dalam ListPenulis P)
    */
    string Nama, NamaPena, Asal;
    int ID;
    AdrPenulis Pen = new ElmPenulis;


    //Proses Input Informasi Buku
    cout<<"Masukkan ID Penulis: ";
    cin>>ID;
    cout<<"Masukkan Nama Penulis: ";
    cin>>Nama;
    cout<<"Masukkan Nama Pena Penulis ('-' jika tak ada): ";
    cin>>NamaPena;
    cout<<"Masukkan Asal Penulis: ";
    cin>>Asal;

    AdrPenulis checkNama = FindPenulisByName(P, Nama);
    AdrPenulis checkId = FindPenulisByID(P, ID);

    if (checkNama == NULL && checkId == NULL){
    Pen->InfoPen.IDPenulis = ID;
    Pen->InfoPen.nama = Nama;
    Pen->InfoPen.namaPena = NamaPena;
    Pen->InfoPen.asal = Asal;
    Pen->next = NULL;
    }else{
        cout<<"ID buku atau Judul Buku sudah terdaftar"<<endl;
        AllocatePenulis(P);
    }
    return Pen;
}

AdrPenulis FindPenulisByName(ListPenulis P, string Nama){
    /*
    Mengembalikan nilai AdrPenulis di dalam ListPenulis P dengan (infoPen.Nama == Nama) atau (infoPen.NamaPena == Nama). NULL jika Buku tidak ada daam ListBuku B
    */
    AdrPenulis search = P.First;
    AdrPenulis found = NULL;
    while (search != NULL && found == NULL){
        if (search->InfoPen.nama == Nama || search->InfoPen.namaPena == Nama){
            found = search;
        }
        search = search->next;
    }
    return found;
}

AdrPenulis FindPenulisByID(ListPenulis P, int ID){
    /*
    Mengembalikan nilai AdrPenulis di dalam ListPenulis P dengan (infoPen.Nama == Nama) atau (infoPen.NamaPena == Nama). NULL jika Buku tidak ada daam ListBuku B
    */
    AdrPenulis search = P.First;
    AdrPenulis found = NULL;
    while (search != NULL && found == NULL){
        if (search->InfoPen.IDPenulis == ID){
            found = search;
        }
        search = search->next;
    }
    return found;
}

void InsertFirstPen(ListPenulis &P, AdrPenulis Pen) {
    if (P.First == NULL) {
        P.First = Pen;
    } else {
        Pen->next = P.First;
        P.First = Pen;
    }
}

void InsertLastPen(ListPenulis &P, AdrPenulis Pen) {
    if (P.First == NULL) {
        P.First = Pen;
    } else {
        AdrPenulis temp = P.First;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = Pen;
    }
}

void InsertAfterPen(ListPenulis &P, AdrPenulis prec, AdrPenulis Pen) {
    if (prec == NULL) {
        cout << "Elemen sebelumnya tidak boleh NULL." << endl;
        return;
    }
    Pen->next = prec->next;
    prec->next = Pen;
}

void InputPenuliskeList(ListPenulis &P, AdrPenulis Pen){
    InsertFirstPen(P, Pen);
}

void TampilkanPenulisSelectionSortAscending(ListPenulis &P){
    /*
    Menampilkan data Penulis secara ascending
    */
   if (P.First == NULL) {
        cout << "List penulis kosong." << endl;
        return;
    }

    AdrPenulis i = P.First;
    while (i != NULL) {
        AdrPenulis minNode = i;
        AdrPenulis j = i->next;
        while (j != NULL) {
            if (j->InfoPen.nama < minNode->InfoPen.nama) {
                minNode = j;
            }
            j = j->next;
        }

        if (minNode != i) {
            Penulis temp = i->InfoPen;
            i->InfoPen = minNode->InfoPen;
            minNode->InfoPen = temp;
        }

        i = i->next;
    }

    cout << "Daftar penulis dalam urutan ascending:" << endl;
    AdrPenulis curr = P.First;
    while (curr != NULL) {
        cout<<"ID penulis: "<<curr->InfoPen.IDPenulis<<endl;
        cout<<"Nama Penulis: "<<curr->InfoPen.nama<<endl;
        cout<<"Nama Pena: "<<curr->InfoPen.namaPena<<endl;
        cout<<"Asal penulis:"<<curr->InfoPen.asal<<endl;
        cout<<"==============================================="<<endl;
        curr = curr->next;
    }
}

void TampilkanPenulisInsertionSortDescending(ListPenulis &P){
    /*
    Menampilkan data Penulis secara descending
    */
   if (P.First == NULL) {
        cout << "List penulis kosong." << endl;
        return;
    }

    AdrPenulis sorted = NULL;
    AdrPenulis curr = P.First;

    while (curr != NULL) {
        AdrPenulis next = curr->next;

        if (sorted == NULL || curr->InfoPen.nama > sorted->InfoPen.nama) {
            curr->next = sorted;
            sorted = curr;
        } else {
            AdrPenulis temp = sorted;
            while (temp->next != NULL && temp->next->InfoPen.nama > curr->InfoPen.nama) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }

        curr = next;
    }

    P.First = sorted;

    cout << "Daftar penulis dalam urutan descending:" << endl;
    AdrPenulis temp = P.First;
    while (temp != NULL) {
        cout<<"ID penulis: "<<temp->InfoPen.IDPenulis<<endl;
        cout<<"Nama Penulis: "<<temp->InfoPen.nama<<endl;
        cout<<"Nama Pena: "<<temp->InfoPen.namaPena<<endl;
        cout<<"Asal penulis:"<<temp->InfoPen.asal<<endl;
        cout<<"==============================================="<<endl;
        temp = temp->next;
    }
}

void updateNamaPenulis(ListPenulis &P, int IDPenulis) {
    AdrPenulis writer = P.First;
    while (writer != NULL && writer->InfoPen.IDPenulis != IDPenulis) {
        writer = writer->next;
    }
    if (writer == NULL) {
        cout << "Penulis dengan ID " << IDPenulis << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan nama baru: ";
    cin >> writer->InfoPen.nama;
    cout << "Nama berhasil diperbarui." << endl;
}

void updateAsalPenulis(ListPenulis &P, int IDPenulis) {
    AdrPenulis writer = P.First;
    while (writer != NULL && writer->InfoPen.IDPenulis != IDPenulis) {
        writer = writer->next;
    }
    if (writer == NULL) {
        cout << "Penulis dengan ID " << IDPenulis << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan asal baru: ";
    cin >> writer->InfoPen.asal;
    cout << "Asal berhasil diperbarui." << endl;
}

void updateNamaPenaPenulis(ListPenulis &P, int IDPenulis) {
    AdrPenulis writer = P.First;
    while (writer != NULL && writer->InfoPen.IDPenulis != IDPenulis) {
        writer = writer->next;
    }
    if (writer == NULL) {
        cout << "Penulis dengan ID " << IDPenulis << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan nama pena baru: ";
    cin >> writer->InfoPen.namaPena;
    cout << "Nama pena berhasil diperbarui." << endl;
}

void PrintListPenulis(ListPenulis &P){
    AdrPenulis Pr = P.First;
        if (Pr == NULL) {
        cout<<"==============================================="<<endl;
        cout << "Tidak ada data penulis!" << endl;
        cout<<"==============================================="<<endl;
    }
    while (Pr != NULL){
        cout<<"ID Penulis: "<<Pr->InfoPen.IDPenulis<<endl;
        cout<<"Nama Penulis: "<<Pr->InfoPen.nama<<endl;
        cout<<"Nama Pena Penulis: "<<Pr->InfoPen.namaPena<<endl;
        cout<<"Asal Penulis: "<<Pr->InfoPen.asal<<endl;
        cout<<"==============================================="<<endl;
        Pr = Pr->next;
    }
}
