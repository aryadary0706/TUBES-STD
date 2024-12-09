#include "MLL.h"
using namespace std;

int main() {
    ListBuku B;
    ListPenulis P;
    ListRelasi R;

    createListBuku(B);
    createListPenulis(P);
    createListRelasi(R);

    int pilihan = 0; // Inisialisasi pilihan
    do {
        cout << "---------------------------------------------"<<endl;
        cout<<"                MENU PROGRAM"<<endl;
        cout << "---------------------------------------------"<<endl;
        cout << "1. Masukkan Data ( BUKU / PENULIS )\n";
        cout << "2. Hapus Data ( BUKU / PENULIS )\n";
        cout << "3. Ubah/Rekayasa Data ( BUKU / PENULIS )\n";
        cout << "4. Tampilkan Data ( BUKU / PENULIS )\n";
        cout << "5. KELUAR\n";
        cout << "Masukkan pilihan: "; // Tambahkan prompt untuk input
        cin >> pilihan; // Ambil input dari pengguna

        switch (pilihan) {
            case 1: {
                int P1;
                cout << "---------------------------------------------"<<endl;
                cout << "                INPUT DATA"<<endl;
                cout << "---------------------------------------------"<<endl;
                cout << "Data apa yang ingin dimasukkan?\n";
                cout << "1. Buku\n";
                cout << "2. Penulis\n";
                cout << "3. Keluar\n";
                cout << "Masukkan pilihan: ";
                cin >> P1;

                if (P1 == 1) {
                    AdrBuku book;
                    book = AllocateBuku();
                    InputBukukeList(B, book, R);
                    cout<<"Apakah kamu ingin menambah data penulis dari buku? [Y untuk menjawab]\n"; //Untuk nambah data relasi secara langsung
                    char A1;
                    cin>>A1;
                    if (A1 == 'Y'){
                        string Nama_Pen;
                        cout<<"Masukkan nama penulis buku yang menulis "<<book->InfoBuku.Judul<<": ";
                        cin>>Nama_Pen;
                        AdrPenulis AP = FindPenulisByName(P, Nama_Pen);
                        if (AP != NULL){
                            AddRelasi(R, book->InfoBuku.Judul, B, P, Nama_Pen);
                        }else{
                            cout<<"Penulis tidak ditemukan. Isi Data Penulis tersebut untuk menyelesaikan proses\n";
                            AdrPenulis NewPenulis = AllocatePenulis();
                            InputPenuliskeList(P, NewPenulis, R);
                            AddRelasi(R, book->InfoBuku.Judul, B, P, NewPenulis->InfoPen.nama);
                        }
                    }else{
                        break;
                    }
                } else if (P1 == 2) {
                    AdrPenulis Pen;
                    Pen = AllocatePenulis();
                    InputPenuliskeList(P, Pen, R);
                    cout<<"Apakah kamu ingin menambah data Buku dari Penulis?\n"; //Untuk nambah data relasi secara langsung
                    char A2;
                    cin>>A2;
                    if (A2 == 'Y'){
                        string judul_buku;
                        cout<<"Masukkan nama judul buku yang ditulis "<<Pen->InfoPen.nama<<": ";
                        cin>>judul_buku;
                        AdrBuku AB = FindBukuByJudul(B, judul_buku);
                        if (AB != NULL){
                            AddRelasi(R, judul_buku, B, P, Pen->InfoPen.nama);
                        }else{
                            cout<<"Buku tidak ditemukan. Isi Data Buku tersebut untuk menyelesaikan proses\n";
                            AdrBuku NewBuku = AllocateBuku();
                            InputBukukeList(B, NewBuku, R);
                            AddRelasi(R, NewBuku->InfoBuku.Judul, B, P, Pen->InfoPen.nama);
                        }
                    }else{
                        break;
                    }
                } else {
                    break; // Keluar dari sub-menu
                }
                break; // Tambahkan break untuk case 1
            }
            case 2: {
                // Implementasi untuk menghapus data (BUKU / PENULIS) harus ditambahkan di sini
                int P2;
                cout << "---------------------------------------------"<<endl;
                cout << "                  DELETE DATA"<<endl;
                cout << "---------------------------------------------"<<endl;
                cout<<"Data apa yang ingin dihapus:\n";
                cout<<"1. BUKU\n";
                cout<<"2. PENULIS\n";
                cin>>P2;
                if (P2 == 1){
                    int IDbuku;
                    cout<<"Masukkan ID Buku yang ingin dihapus: ";
                    cin>>IDbuku;
                    HapusBukuPadaRelasi(B, R, IDbuku);
                    HapusBuku(B, IDbuku);
                }else if (P2 == 2){
                    int IDPen;
                    cout<<"Masukkan ID Penulis yang ingin dihapus: ";
                    cin>>IDPen;
                    HapusPenulisPadaRelasi(P, R, IDPen);
                    HapusPenulis(P, IDPen);
                }else {
                    break;
                }
            }
            case 3: {
                // Implementasi untuk mengubah data (BUKU / PENULIS) harus ditambahkan di sini
                cout << "---------------------------------------------"<<endl;
                cout << "                  EDIT DATA"<<endl;
                cout << "---------------------------------------------"<<endl;
                cout<<"TISEE KERJAIN PLIS";
                break; // Tambahkan break untuk case 3
            }
            case 4: {
                int A4;
                // Implementasi untuk menampilkan data (BUKU / PENULIS) harus ditambahkan di sini
                cout << "---------------------------------------------"<<endl;
                cout << "                  SHOW DATA"<<endl;
                cout << "---------------------------------------------"<<endl;
                cout<<"1. Cari Penulis Berdasarkan Judul Buku"<<endl;
                cout<<"2. Cari Buku Berdasarkan Nama Penulis"<<endl;
                cout<<"3. Tampilkan Buku dan Penulis (Tanpa Urutan)"<<endl;
                cout<<"4. Tampilkan Nama Penulis secara Ascending"<<endl;
                cout<<"5. Tampilkanm Nama Penulis secara Descending"<<endl;
                cout<<"6. Tampilkan Penulis yang paling aktif dan paling malas"<<endl;
                cout<<"7. Keluar\n";
                cout<<"Masukkan Pilihan Anda: \n";
                cin>>A4;
                if (A4 == 1){
                    string JudulDicari;
                    cout<<"Masukkan Nama Judul Buku yang dicari: "<<endl;
                    cin>>JudulDicari;
                    PrintPenulisOnBuku(R, JudulDicari);
                    break;
                }else if (A4 == 2){
                    string NamaDicari;
                    cout<<"Masukkan Nama Penulis yang dicari: "<<endl;
                    cin>>NamaDicari;
                    PrintBukuBasedPenulis(R, NamaDicari);
                    break;
                }else if (A4 == 3){
                    PrintBukuDanPenulis(R);
                    break;
                }else if (A4 == 4){
                    TampilkanPenulisSelectionSortAscending(P);
                    break;
                }else if (A4 == 5){
                    TampilkanPenulisInsertionSortDescending(P);
                    break;
                }else if (A4 == 6){
                    EvaluasiPenulis(P, R);
                    break;
                }else if (A4 == 7){
                    break;
                }
            }
            case 5: {
                cout << "Keluar dari program.\n";
                break; // Tambahkan break untuk case 5
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break; // Tambahkan break untuk default case
            }
        }

    } while (pilihan != 5);

    return 0; // Tambahkan return statement
}
