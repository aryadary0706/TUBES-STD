#include "DataBuku.h"

void createListPenulis(ListPenulis &P){
    /*
    (I.S -
    F.S : Terdefinisikan ListPenulis P dengan First = NULL)
    */
    P.First = NULL;
}

void createListBuku(ListBuku &B){
    /*
    (I.S -
    F.S : Terdefinisikan ListBuku B dengan First = NULL)
    */
    B.First = NULL;
    B.Last = NULL;
}

void createListRelasi(ListRelasi &R){
    /*
    (I.S -
    F.S : Terdefinisikan ListRelasi R dengan First = NULL)
    */
    R.First = NULL;
}

void InsertBuku(ListBuku &B, AdrBuku Newbook){
       /*
    (I.S : Terdefinisi ListBuku B yang bisa saja kosong dan AdrBuku NewBuku yang akan dimasukkan ke dalam list
    F.S : NewBuku masuk ke dalam B)
    */
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
       /*
    (I.S : Terdefinisi ListBuku B dan AdrPenulis Writer yang akan dimasukkan ke dalam list
    F.S : Writer masuk ke dalam P)
    */
    if (P.First == NULL){
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
       /*
    (I.S : Terdefinisi ListBuku B yang bisa saja kosong
    proses : Mengalokasikan AdrBuku book. Memasukan elemen dari book dengan input dari user. Setelahnya, dilanjutkan proses InsertBuku untuk memasukkan ADrBuku book ke dalam ListBuku B
    F.S : alamat buku masuk ke dalam ListBuku B)
    */
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
    book->next = NULL;
    book->prev = NULL;

    InsertBuku(B, book);
}

void AddPenulis(ListPenulis &P){
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
    cout<<"Masukkan Asal penulis";
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

    InsertPenulis(P, Pen);
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
    }else{
        cout<<endl<<"Judul Buku atau Nama Penulis tidak ditemukan."<<endl;
    }
}

void DeleteBuku(ListBuku &B, string BukuDihapus){
    /*
    I.S: Terdefinisi ListBuku B yang bisa saja kosong dan string BukuDihapus adalah judul buku yang akan dihapus pada ListBuku
    F.S: alamat dengan judul buku = BukuDihapus telah terhapus dari ListBuku
    */
    AdrBuku P;
    AdrBuku temp1;
    AdrBuku temp2;
    P = FindBukuByJudul(B, BukuDihapus);
    if (P != NULL){
        if (P->next != NULL && P != B.First) {
            temp1 = P->next;
            temp2 = P->prev;
            temp1->next = temp2;
            temp2->prev = temp1;
            P->next = NULL;
            P->prev = NULL;
            cout<<"Buku "<<P->InfoBuku.Judul<<" sudah dihapus dari data"<<endl;
        }else if (P != NULL){
            temp1 = P->prev;
            P->prev = NULL;
            temp1->next = NULL;
            cout<<"Buku "<<P->InfoBuku.Judul<<" sudah dihapus dari data"<<endl;
        }else{
            cout<<"Buku "<<BukuDihapus<<" Tidak ditemukan"<<endl;
        }
    }
}

void DeletePenulis(ListPenulis &G, string PenulisDihapus){
    /*
    I.S: Terdefinisi ListPenulius P yang bisa saja kosong dan string PenulisDihapus yang merupakan nama penulis yang akan dihapus pada ListPenulis
    F.S: alamat dengan nama penulis = PenulisDihapus atau nama pena = PenulisDihapus telah terhapus dari ListBuku
    */
    AdrPenulis P = G.First;
    AdrPenulis temp1;
    AdrPenulis temp2;

    while (P != NULL &&
           P->next->InfoPen.nama == PenulisDihapus &&
           P->next->InfoPen.namaPena == PenulisDihapus){
                P= P->next;
           }
    if (P != NULL){
        if (P->next != NULL){
            temp1 = P->next;
            temp2 = temp1->next;
            P->next = temp2;
            temp1->next = NULL;
            cout<<"Data Penulis sudah dihapus"<<endl;
        }else{
            P->next = NULL;
        }
    }
}

void PrintBukuDanPenulis(ListRelasi R){
    /*
    I.S Terdefinisi ListRelasi R
    F.S Ditampilkan Data dari Buku dan data penulis buku tersebut
    */
    AdrRelasi P = R.First;
    string BukuDicari;
    cout<<"Masukkan buku yang ingin dicari: "<<endl;
    cin>>BukuDicari;
    while (P->BR->InfoBuku.Judul != BukuDicari && P != NULL){
        P = P->next;
    }
    AdrPenulis P_Penulis;
    AdrBuku P_Buku;
    if (P != NULL) {
        P_Buku = P->BR;
        P_Penulis = P->PR;
        cout<<"==============================================="<<endl;
        cout<<"ID BUKU: "<<P_Buku->InfoBuku.IDBuku<<endl;
        cout<<"Judul Buku: "<<P_Buku->InfoBuku.Judul<<endl;
        cout<<"Nama Penulis: "<<P_Penulis->InfoPen.nama<<endl;
        cout<<"Nama Pena: "<<P_Penulis->InfoPen.namaPena<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"                   Tentang Buku"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Penerbit: "<<P_Buku->InfoBuku.Penerbit<<endl;
        cout<<"Tahun terbit: "<<P_Buku->InfoBuku.Tahunterbit<<endl;
        cout<<"Cetakan: "<<P_Buku->InfoBuku.Cetakan<<endl;
        cout<<"Editor: "<<P_Buku->InfoBuku.Editor<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"                   Tentang Penulis"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"ID penulis: "<<P_Penulis->InfoPen.IDPenulis<<endl;
        cout<<"Asal penulis:"<<P_Penulis->InfoPen.asal<<endl;
        cout<<"==============================================="<<endl;
    }else{
        cout<<"JUDUL BUKU TIDAK DITEMUKAN.";
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

void EvaluasiPenulis(){
    /*
    Menampilkan data penulis yang paling aktif dan tidak dalam menulis buku
    */
}

void sortingBuku(){
    /*
    Menampilkan list parent secara terurut ascending/descending berdasarkan atribut tertentu.
    */
}
