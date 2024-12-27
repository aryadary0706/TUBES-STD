#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include "MLL_child.h"
#include "MLL_parent.h"
#include "MLL_relation.h"

void EvaluasiPenulis(ListPenulis P, ListRelasi R);
void AddRelasi(ListRelasi &R, string JudulBuku, ListBuku &B, ListPenulis &P, string NamaPenulis);
void HapusPenulis(ListPenulis &P, ListRelasi &R, int IDPenulis);
void HapusBuku(ListBuku &B, ListRelasi &R, int IDBuku);
void PrintBukuDanPenulis(ListPenulis P, ListRelasi R);

#endif // MLL_H_INCLUDED
