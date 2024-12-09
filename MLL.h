#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include "MLL_child.h"
#include "MLL_parent.h"
#include "MLL_relation.h"

void EvaluasiPenulis(ListPenulis P, ListRelasi R);
void AddRelasi(ListRelasi &R, string JudulBuku, ListBuku B, ListPenulis P, string NamaPenulis);
void HapusPenulisPadaRelasi(ListPenulis &P, ListRelasi &R, int IDPenulis);
void HapusBukuPadaRelasi(ListBuku &B, ListRelasi &R, int IDBuku);
void InputBukukeList(ListBuku &B, AdrBuku book, ListRelasi &R);
void InputPenuliskeList(ListPenulis &P, AdrPenulis Pen, ListRelasi &R);

#endif // MLL_H_INCLUDED
