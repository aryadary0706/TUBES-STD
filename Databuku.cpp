#include "DataBuku.h"

void createListPenulis(ListPenulis &P){
    P.First = NULL;
}

void createListBuku(ListBuku &B){
    B.First = NULL;
    B.Last = NULL;
}

void createListRelasi(ListRelasi &R){
    R.First = NULL;
}

void InsertBuku(ListBuku &B, AdrBuku Newbook){
    if (B.First == NULL && B.Last == NULL){
        B.First = Newbook;
        B.Last = Newbook;
    }else{
        Newbook->prev = B.Last;
        B.Last->next = Newbook;
        B.Last = Newbook;
    }
}

void InsertPenulis(ListPenulis &P, AdrPenulis Writer){
    if (P.First = NULL){
        P.First = Writer;
    }else{
        AdrPenulis temp = P.First;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = Writer;
    }
}

void AddBuku(ListBuku &B){
    string judul, penerbit, Editor;
    int tahunTerbit, cetakan, ID;
    AdrBuku book = new ElmBuku;
    cout<<"Masukkan ID Buku:";
    cin>>ID;
    cout<<endl;
    cout<<"Masukkan Judul Buku:";
    cin>>judul;
    cout<<endl;
    cout<<"Masukkan nama penerbit";
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

    InsertBuku(B, book);
}

void AddPenulis(ListPenulis &P){
    string nama, asal, namapena;
    int ID;

    AdrPenulis Pen = new ElmPenulis;
    cout<<"Masukkan ID Penulis:";
    cin>>ID;
    cout<<endl;
    cout<<"Masukkan Nama asli Penulis:";
    cin>>nama;
    cout<<endl;
    cout<<"Masukkan Asal penulis";
    cin>>asal;
    cout<<endl;
    cout<<"Masukkan Nama pena penulis:";
    cin>>namapena;
    cout<<endl;

    Pen->InfoPen.IDPenulis = ID;
    Pen->InfoPen.nama = nama;
    Pen->InfoPen.asal = asal;
    Pen->InfoPen.namaPena = namapena;

    InsertPenulis(P, Pen);
}

AdrBuku FindBukuByJudul(ListBuku B, string judul){
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

AdrPenulis FindPenulisByName(ListPenulis P, string Nama){
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

void InsertRelasi(ListRelasi &R, AdrRelasi NewRelasi){
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

void AddRelasi(ListRelasi &R, string JudulBuku, ListBuku B, ListPenulis P, string NamaPenulis){
    AdrBuku P_Buku = FindBukuByJudul(B, JudulBuku);
    AdrPenulis P_Writer = FindPenulisByName(P, NamaPenulis);
    if (P_Buku != NULL && P_Writer != NULL){
        AdrRelasi Rel = new ElmRelasi;
        Rel->BR = P_Buku;
        Rel->PR = P_Writer;
        Rel->next = NULL;
        InsertRelasi(R, Rel);
    }else{
        cout<<endl<<"Judul Buku atau Nama Penulis tidak ditemukan."<<endl;
    }
}

void HapusPenulis(ListPenulis &P, ListRelasi &R, int IDPenulis) {
    AdrPenulis curr = P.First, prev = NULL;
    while (curr != NULL && curr->InfoPen.IDPenulis != IDPenulis) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        AdrRelasi relCurr = R.First;
        while (relCurr != NULL) {
            if (relCurr->PR == curr) {
                relCurr->PR = NULL;
            }
            relCurr = relCurr->next;
        }

        if (prev == NULL) {
            P.First = curr->next;
        } else {
            prev->next = curr->next;
        }
        curr->next = NULL;
        cout << "Penulis berhasil dihapus dari list.\n";
    } else {
        cout << "Penulis tidak ditemukan.\n";
    }
}

void HapusBuku(ListBuku &B, ListRelasi &R, int IDBuku) {
    AdrBuku curr = B.First, prev = NULL;
    while (curr != NULL && curr->InfoBuku.IDBuku != IDBuku) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        AdrRelasi relCurr = R.First;
        while (relCurr != NULL) {
            if (relCurr->BR == curr) {
                relCurr->BR = NULL;
            }
            relCurr = relCurr->next;
        }

        if (curr == B.First && curr == B.Last) {
            B.First = B.Last = NULL;
        } else if (curr == B.First) {
            B.First = curr->next;
            B.First->prev = NULL;
        } else if (curr == B.Last) {
            B.Last = curr->prev;
            B.Last->next = NULL;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        curr->next = curr->prev = NULL; 
        cout << "Buku berhasil dihapus dari list.\n";
    } else {
        cout << "Buku tidak ditemukan.\n";
    }
}

void TampilkanSemuaBuku(ListBuku B, ListRelasi R) {
    AdrBuku curr = B.First;
    while (curr != NULL) {
        cout << "Judul Buku: " << curr->InfoBuku.Judul << endl;
        AdrRelasi relCurr = R.First;
        while (relCurr != NULL) {
            if (relCurr->BR == curr) {
                cout << "  Penulis: " << relCurr->PR->InfoPen.nama << endl;
            }
            relCurr = relCurr->next;
        }
        curr = curr->next;
    }
}

void TampilkanBukuByPenulis(ListRelasi R, string NamaPenulis) {
    AdrRelasi curr = R.First;
    while (curr != NULL) {
        if (curr->PR->InfoPen.nama == NamaPenulis || curr->PR->InfoPen.namaPena == NamaPenulis) {
            cout << "Judul Buku: " << curr->BR->InfoBuku.Judul << endl;
        }
        curr = curr->next;
    }
}

void TampilkanPenulisByBuku(ListRelasi R, string JudulBuku) {
    AdrRelasi curr = R.First;
    while (curr != NULL) {
        if (curr->BR->InfoBuku.Judul == JudulBuku) {
            cout << "Penulis: " << curr->PR->InfoPen.nama << endl;
        }
        curr = curr->next;
    }
}

void TampilkanPenulisPalingAktifDanPasif(ListPenulis P, ListRelasi R) {
    AdrPenulis curr = P.First;
    int maxBooks = 0, minBooks = INT_MAX;
    AdrPenulis aktif = NULL, pasif = NULL;

    while (curr != NULL) {
        int count = 0;
        AdrRelasi relCurr = R.First;
        while (relCurr != NULL) {
            if (relCurr->PR == curr) {
                count++;
            }
            relCurr = relCurr->next;
        }
        if (count > maxBooks) {
            maxBooks = count;
            aktif = curr;
        }
        if (count < minBooks) {
            minBooks = count;
            pasif = curr;
        }
        curr = curr->next;
    }

    cout << "Penulis paling aktif: " << aktif->InfoPen.nama << " dengan " << maxBooks << " buku.\n";
    cout << "Penulis paling pasif: " << pasif->InfoPen.nama << " dengan " << minBooks << " buku.\n";
}

void TampilkanPenulisAscending(ListPenulis &P) {
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

    cout << "Daftar penulis dalam urutan ascending (Selection Sort):" << endl;
    AdrPenulis curr = P.First;
    while (curr != NULL) {
        cout << "Nama Penulis: " << curr->InfoPen.nama << endl;
        curr = curr->next;
    }
}

void TampilkanPenulisDescending(ListPenulis &P) {
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

    cout << "Daftar penulis dalam urutan descending (Insertion Sort):" << endl;
    AdrPenulis temp = P.First;
    while (temp != NULL) {
        cout << "Nama Penulis: " << temp->InfoPen.nama << endl;
        temp = temp->next;
    }
}
