#include "MLL_child.h"

/*
FUNGSI DAN PROSEDUR YANG DIPAKAI DALAM MLL_DATABUKU.h (Double-linked List)
1. void createListBuku(ListBuku &B);
2. AdrBuku AllocateBuku(ListBuku &B);
3. void insertFirstBuku(ListBuku &B, AdrBuku book);
4. void InsertLastBuku(ListBuku &B, AdrBuku book);
5. void InsertAfterBuku(ListBuku &B, AdrBuku prec, AdrBuku book);
6. void HapusBuku(ListBuku &B, int IDBuku);
7. AdrBuku FindBukuByJudul(ListBuku B, string judul);
8. void updateJudulBuku(ListBuku &B, int IDBuku);
9. void updatePenerbitBuku(ListBuku &B, int IDBuku);
10. void updateTahunTerbitBuku(ListBuku &B, int IDBuku);
11. void updateCetakanBuku(ListBuku &B, int IDBuku);
12. void updateEditorBuku(ListBuku &B, int IDBuku);
*/

void createListBuku(ListBuku &B){
    /*
    (I.S -
    F.S : Terdefinisikan ListBuku B dengan First = NULL)
    */
    B.First = NULL;
    B.Last = NULL;
}

AdrBuku AllocateBuku(ListBuku B){
    /*
    (I.S : Terdefinisi ListBuku B yang bisa saja kosong
    proses : Mengalokasikan AdrBuku book. Memasukan elemen dari book dengan input dari user. Setelahnya, dilanjutkan proses InsertBuku untuk memasukkan ADrBuku book ke dalam ListBuku B
    F.S : alamat buku masuk ke dalam ListBuku B)
    */
    string judul, penerbit, Editor;
    int tahunTerbit, cetakan, ID;
    AdrBuku book = new ElmBuku;


    //Proses Input Informasi Buku
    cout<<"Masukkan ID Buku: ";
    cin>>ID;
    cout<<"Masukkan Judul Buku: ";
    cin>>judul;
    cout<<"Masukkan Nama Penerbit: ";
    cin>>penerbit;
    cout<<"Masukkan Tahun Terbit Buku: ";
    cin>>tahunTerbit;
    cout<<"Masukkan Versi Cetakan Buku: ";
    cin>>cetakan;
    cout<<"Masukkan Nama Editor: ";
    cin>>Editor;

    AdrBuku checkJudul = FindBukuByJudul(B, judul);
    AdrBuku checkId = FindBukuByID(B, ID);

    if (checkJudul == NULL && checkId == NULL){
    book->InfoBuku.IDBuku = ID;
    book->InfoBuku.Judul = judul;
    book->InfoBuku.Penerbit = penerbit;
    book->InfoBuku.Tahunterbit = tahunTerbit;
    book->InfoBuku.Cetakan = cetakan;
    book->InfoBuku.Editor = Editor;
    book->next = NULL;
    book->prev = NULL;

    }else{
        cout<<"ID buku atau Judul Buku sudah terdaftar"<<endl;
        AllocateBuku(B);
    }
    return book;
}

void insertFirstBuku(ListBuku &B, AdrBuku book){
    if (B.First == NULL && B.Last == NULL) {
        B.First = book;
        B.Last = book;
    } else {
        book->next = B.First;
        B.First->prev = book;
        B.First = book;
    }
}

void InsertLastBuku(ListBuku &B, AdrBuku book){
    if (B.Last == NULL && B.First == NULL) {
        B.First = book;
        B.Last = book;
    } else {
        B.Last->next = book;
        book->prev = B.Last;
        B.Last = book;
    }
}

void InsertAfterBuku(ListBuku &B, AdrBuku prec, AdrBuku book){
    string JudulDicari;
    cout<<"Masukkan buku yang ingin diinput setelahnya: "<<endl;
    cin>>JudulDicari;
    prec = FindBukuByJudul(B, JudulDicari);
    if (prec == NULL) {
        cout << "Buku tidak ditemukan" << endl;
        return;
    }
    if (prec->next == NULL) { // Jika prec adalah elemen terakhir
        InsertLastBuku(B, book);
    } else {
        book->next = prec->next;
        book->prev = prec;
        prec->next->prev = book;
        prec->next = book;
    }
}

void InputBukukeList(ListBuku &B, AdrBuku book){
    InsertLastBuku(B, book);
}

AdrBuku FindBukuByJudul(ListBuku B, string judul){
    /*
    Mengembalikan nilai AdrBuku di dalam ListBuku B dengan infoBuku.judul yang sama dengan judul. NULL jika Buku tidak ada daam ListBuku B
    */
    AdrBuku search = B.First;
    AdrBuku found = NULL;
    while (search != NULL && found == NULL){
        if (search->InfoBuku.Judul == judul){
            found = search;
        }
        search = search->next;
    }
    return found;
}

AdrBuku FindBukuByID(ListBuku B, int ID){
    /*
    Mengembalikan nilai AdrBuku di dalam ListBuku B dengan infoBuku.judul yang sama dengan judul. NULL jika Buku tidak ada daam ListBuku B
    */
    AdrBuku search = B.First;
    AdrBuku found = NULL;
    while (search != NULL && found == NULL){
        if (search->InfoBuku.IDBuku == ID){
            found = search;
        }
        search = search->next;
    }
    return found;
}


void updateJudulBuku(ListBuku &B, int IDBuku) {
    AdrBuku book = B.First;
    while (book != NULL && book->InfoBuku.IDBuku != IDBuku) {
        book = book->next;
    }
    if (book == NULL) {
        cout << "Buku dengan ID " << IDBuku << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan judul baru: ";
    cin >> book->InfoBuku.Judul;
    cout << "Judul berhasil diperbarui." << endl;
}

void updatePenerbitBuku(ListBuku &B, int IDBuku) {
    AdrBuku book = B.First;
    while (book != NULL && book->InfoBuku.IDBuku != IDBuku) {
        book = book->next;
    }
    if (book == NULL) {
        cout << "Buku dengan ID " << IDBuku << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan penerbit baru: ";
    cin >> book->InfoBuku.Penerbit;
    cout << "Penerbit berhasil diperbarui." << endl;
}

void updateTahunTerbitBuku(ListBuku &B, int IDBuku) {
    AdrBuku book = B.First;
    while (book != NULL && book->InfoBuku.IDBuku != IDBuku) {
        book = book->next;
    }
    if (book == NULL) {
        cout << "Buku dengan ID " << IDBuku << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan tahun terbit baru: ";
    cin >> book->InfoBuku.Tahunterbit;
    cout << "Tahun terbit berhasil diperbarui." << endl;
}

void updateCetakanBuku(ListBuku &B, int IDBuku) {
    AdrBuku book = B.First;
    while (book != NULL && book->InfoBuku.IDBuku != IDBuku) {
        book = book->next;
    }
    if (book == NULL) {
        cout << "Buku dengan ID " << IDBuku << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan cetakan baru: ";
    cin >> book->InfoBuku.Cetakan;
    cout << "Cetakan berhasil diperbarui." << endl;
}

void updateEditorBuku(ListBuku &B, int IDBuku) {
    AdrBuku book = B.First;
    while (book != NULL && book->InfoBuku.IDBuku != IDBuku) {
        book = book->next;
    }
    if (book == NULL) {
        cout << "Buku dengan ID " << IDBuku << " tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan editor baru: ";
    cin >> book->InfoBuku.Editor;
    cout << "Editor berhasil diperbarui." << endl;
}

void PrintListBuku(ListBuku B){
    AdrBuku Br;
    Br = B.First;
    if (Br == NULL) {
        cout<<"==============================================="<<endl;
        cout << "Tidak ada data buku!" << endl;
        cout<<"==============================================="<<endl;
    }
    while (Br != NULL){
        cout<<"==============================================="<<endl;
        cout<<"Judul Buku: "<<Br->InfoBuku.Judul<<endl;
        cout<<"==============================================="<<endl;
        cout<<"ID Buku: "<<Br->InfoBuku.IDBuku<<endl;
        cout<<"Nama Penerbit: "<<Br->InfoBuku.Penerbit<<endl;
        cout<<"Tahun Terbit: "<<Br->InfoBuku.Tahunterbit<<endl;
        cout<<"Versi Cetakan: "<<Br->InfoBuku.Cetakan<<endl;
        cout<<"Nama Editor: "<<Br->InfoBuku.Editor<<endl;
        cout<<"==============================================="<<endl;
        Br = Br->next;
    }
}
