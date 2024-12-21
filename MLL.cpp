# include "MLL.h"

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

AdrBuku AllocateBuku(){
    /*
    (I.S : Terdefinisi ListBuku B yang bisa saja kosong
    proses : Mengalokasikan AdrBuku book. Memasukan elemen dari book dengan input dari user. Setelahnya, dilanjutkan proses InsertBuku untuk memasukkan ADrBuku book ke dalam ListBuku B
    F.S : alamat buku masuk ke dalam ListBuku B)
    */
    string judul, penerbit, Editor;
    int tahunTerbit, cetakan, ID;
    AdrBuku book = new ElmBuku;

    //Proses Input Informasi Buku
    cout<<"Masukkan ID Buku:";
    cin>>ID;
    cout<<endl;
    cout<<"Masukkan Judul Buku:";
    cin>>judul;
    cout<<endl;
    cout<<"Masukkan nama penerbit:";
    cin>>penerbit;
    cout<<endl;
    cout<<"Masukkan Tahun Terbit Buku:";
    cin>>tahunTerbit;
    cout<<endl;
    cout<<"Masukkan versi cetakan buku:";
    cin>>cetakan;
    cout<<endl;
    cout<<"Masukkan Nama Editor:";
    cin>>Editor;
    cout<<endl;

    book->InfoBuku.IDBuku = ID;
    book->InfoBuku.Judul = judul;
    book->InfoBuku.Penerbit = penerbit;
    book->InfoBuku.Tahunterbit = tahunTerbit;
    book->InfoBuku.Cetakan = cetakan;
    book->InfoBuku.Editor = Editor;
    book->next = NULL;
    book->prev = NULL;

    return book;
}

void insertFirstBuku(ListBuku &B, AdrBuku book){
    if (B.First == NULL) {
        B.First = book;
        B.Last = book;
    } else {
        book->next = B.First;
        B.First->prev = book;
        B.First = book;
    }
}

void InsertLastBuku(ListBuku &B, AdrBuku book){
    if (B.Last == NULL) {
        B.First = book;
        B.Last = book;
    } else {
        book->prev = B.Last;
        B.Last->next = book;
        B.Last = book;
    }
}

void InsertAfterBuku(ListBuku &B, AdrBuku prec, AdrBuku book){
    string JudulDicari;
    cout<<"Masukkan buku yang ingin diinput setelahnya:"<<endl;
    cin>>JudulDicari;
    prec = FindBukuByJudul(B, JudulDicari);
    if (prec == NULL) {
        cout << "Elemen sebelumnya (prec) tidak boleh NULL." << endl;
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

void HapusBuku(ListBuku &B, int IDBuku) {
    AdrBuku current = B.First; // Pointer to traverse the list

    while (current != NULL) {
        if (current->InfoBuku.IDBuku == IDBuku) {
            if (current == B.First) { // If it's the first node
                B.First = current->next; // Update the head of the list
                if (B.First != NULL) {
                    B.First->prev = NULL; // Update the previous pointer of the new head
                }
            } else if (current->next == NULL) { // If it's the last node
                current->prev->next = NULL; // Update the next pointer of the previous node
            } else { // If it's a middle node
                current->prev->next = current->next; // Bypass the current node
                current->next->prev = current->prev; // Update the previous pointer of the next node
            }
            delete current; // Free memory
            return; // Exit after deletion
        }
        current = current->next; // Move to the next node
    }
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

AdrPenulis AllocatePenulis(){
    /*
    (I.S : Terdefinisi ListBuku P yang bisa saja kosong
    proses : Mengalokasikan AdrPenulis Pen. Memasukan elemen dari Pen dengan input dari user. Setelahnya, dilanjutkan proses InsertPenulis untuk memasukkan AdrPenulis book ke dalam ListPenulis P
    F.S : alamat Pen masuk ke dalam ListPenulis P)
    */
    string nama, asal, namapena;
    int ID;

    AdrPenulis Pen = new ElmPenulis;
    cout<<"Masukkan ID Penulis:";
    cin>>ID;
    cout<<endl;
    cout<<"Masukkan Nama asli Penulis:";
    cin>>nama;
    cout<<endl;
    cout<<"Masukkan Asal penulis:";
    cin>>asal;
    cout<<endl;
    cout<<"Masukkan Nama pena penulis('-' jika tidak ada):";
    cin>>namapena;
    cout<<endl;

    Pen->InfoPen.IDPenulis = ID;
    Pen->InfoPen.nama = nama;
    Pen->InfoPen.asal = asal;
    Pen->InfoPen.namaPena = namapena;
    Pen->next = NULL;

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

void HapusPenulis(ListPenulis &P, int IDPenulis) {
    AdrPenulis current = P.First; // Pointer to traverse the list
    AdrPenulis previous = NULL; // Pointer to keep track of the previous node

    while (current != NULL) {
        if (current->InfoPen.IDPenulis == IDPenulis) {
            if (previous == NULL) { // If it's the first node
                P.First = current->next; // Update the head of the list
            } else { // If it's not the first node
                previous->next = current->next; // Bypass the current node
            }
            delete current; // Free memory
            return; // Exit after deletion
        }
        previous = current; // Move to the next node
        current = current->next; // Move to the next node
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

void PrintBukuDanPenulis(ListRelasi R){
    /*
    I.S Terdefinisi ListRelasi R
    F.S Ditampilkan Seluruh Data dari Buku dan data penulis buku tersebut
    */
    AdrRelasi P = R.First;
    AdrPenulis P_Penulis;
    AdrBuku P_Buku;
    if (P != NULL) {
        while (P != NULL){
        P_Buku = P->BR;
        P_Penulis = P->PR;
        cout<<"==============================================="<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"                   Tentang Buku"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"ID BUKU: "<<P_Buku->InfoBuku.IDBuku<<endl;
        cout<<"Judul Buku: "<<P_Buku->InfoBuku.Judul<<endl;
        cout<<"Penerbit: "<<P_Buku->InfoBuku.Penerbit<<endl;
        cout<<"Tahun terbit: "<<P_Buku->InfoBuku.Tahunterbit<<endl;
        cout<<"Cetakan: "<<P_Buku->InfoBuku.Cetakan<<endl;
        cout<<"Editor: "<<P_Buku->InfoBuku.Editor<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"                   Tentang Penulis"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"ID penulis: "<<P_Penulis->InfoPen.IDPenulis<<endl;
        cout<<"Nama Penulis: "<<P_Penulis->InfoPen.nama<<endl;
        cout<<"Nama Pena: "<<P_Penulis->InfoPen.namaPena<<endl;
        cout<<"Asal penulis:"<<P_Penulis->InfoPen.asal<<endl;
        cout<<"==============================================="<<endl;
        P = P->next;
        }
    }else{
        cout<<"JUDUL BUKU TIDAK DITEMUKAN.\n";
    }
}

void PrintBukuBasedPenulis(ListRelasi R, string NamaPenulis){
    /*
    I.S Terdifinisi ListRelasi R dan string NamaPenulis yang merupakan kata kunci untuk mencari nama buku-buku yang telah ditulis NamaPenulis
    F.S Ditampilkan Data Buku-buku yang ditulis oleh Penulis tersebut
    */
    AdrRelasi R_pointer = R.First;
    AdrBuku BfromR;
    while (R_pointer != NULL){
            cout<<"Judul-judul Buku yang sudah ditulis "<<NamaPenulis<<endl;
            if (R_pointer->PR->InfoPen.nama == NamaPenulis && R_pointer->PR->InfoPen.namaPena == NamaPenulis){
               BfromR = R_pointer->BR;
               cout<<"==============================================="<<endl;
               cout<<"ID BUKU: "<<BfromR->InfoBuku.IDBuku<<endl;
               cout<<"Judul Buku: "<<BfromR->InfoBuku.Judul<<endl;
               cout<<"Penerbit: "<<BfromR->InfoBuku.Penerbit<<endl;
               cout<<"Tahun terbit: "<<BfromR->InfoBuku.Tahunterbit<<endl;
               cout<<"Cetakan: "<<BfromR->InfoBuku.Cetakan<<endl;
               cout<<"Editor: "<<BfromR->InfoBuku.Editor<<endl;
               cout<<"==============================================="<<endl;
            }
            R_pointer = R_pointer->next;
           }
}

void PrintPenulisOnBuku(ListRelasi R, string judulBuku){
    /*
    I.S Terdefinisi ListRelasi R dan string judulBuku yang merupakan judul Buku yang ingin ditampilkan data penulisnya
    F.S Ditampilkan dat penulis yang menulis Buku berjudul judulBuku
    */
    AdrRelasi RP = R.First;
    AdrPenulis PfromR;
    while (RP != NULL){
         cout<<"Informasi Penulis yang menulis buku "<<judulBuku<<endl;
        if (RP->BR->InfoBuku.Judul == judulBuku ){
            PfromR = RP->PR;
            cout<<"==============================================="<<endl;
            cout<<"ID Penulis: "<<PfromR->InfoPen.IDPenulis<<endl;
            cout<<"Nama Penulis: "<<PfromR->InfoPen.nama<<endl;
            cout<<"Nama Pena Penulis: "<<PfromR->InfoPen.namaPena<<endl;
            cout<<"Asal Penulis: "<<PfromR->InfoPen.asal<<endl;
             cout<<"==============================================="<<endl;
        }
    }
}

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
    AdrRelasi RAB = R.First; // RelationAtBuku
    AdrRelasi p = NULL; // Pointer to keep track of the previous node
    AdrRelasi del = NULL;
    while (RAB != NULL) {
        if (RAB->BR->InfoBuku.IDBuku == IDBuku) {
            if (RAB == R.First) { // If it's the first node
                R.First = RAB->next; // Update the head of the list
                del = RAB; // Free memory
                RAB = R.First; // Move to the next node
            } else { // If it's not the first node
                p->next = RAB->next; // Bypass the current node
                del = RAB; // Free memory
                RAB = p->next; // Move to the next node
            }
        } else {
            p = RAB; // Move the previous pointer only if we didn't delete
            RAB = RAB->next; // Move to the next node
        }
    }
}


void HapusPenulisPadaRelasi(ListPenulis &P, ListRelasi &R, int IDPenulis) {
    AdrRelasi RAP = R.First; // RelationAtPenulis
    AdrRelasi p = NULL; // Pointer to keep track of the previous node
    AdrRelasi del = NULL;
    while (RAP != NULL) {
        if (RAP->PR->InfoPen.IDPenulis == IDPenulis) {
            if (RAP == R.First) { // If it's the first node
                R.First = RAP->next; // Update the head of the list
                del = RAP; // Free memory
                RAP = R.First; // Move to the next node
            } else { // If it's not the first node
                p->next = RAP->next; // Bypass the current node
                del = RAP; // Free memory
                RAP = p->next; // Move to the next node
            }
        } else {
            p = RAP; // Move the previous pointer only if we didn't delete
            RAP = RAP->next; // Move to the next node
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
