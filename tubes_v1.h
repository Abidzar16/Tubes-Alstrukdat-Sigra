#ifndef Tubes_H
#define Tubes_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char ElemenKe[64]; //untuk memudahkan, kita mengabaikan array ke nol
} List; //nantinya akan diubah ke tabel dengan fungsi printtabel

typedef struct {
	int IdxTimpa[64];// -> berisi Index berapa saja yang perlu ditimpa            
	int IdxIsi[8]; // -> berisi Index berapa saja yang yang perlu diisi
} ArrayIdx; //perlu didealokasikan lagi agar bisa dipakai
	// -> misalnya : A.IdxTimpa[0] = 45 -> maka Index yang perlu ditimpa adalah L.ElemenKe[45]
	// 				 A.Idxisi[0] = 4 -> maka Index yang perlu diisi adalah L.ElemenKe[4]
	     			  
typedef struct{
	int row3; //jumlah 3-permen sejenis yang meletus
	int row4; //		4-permen
	int row5; //		5-permen
	int Total
} Score;

void Alokasi(List *L);
//mengisi List dengan huruf tertentu secara random,

void Dealokasi(ArrayIdx *A);
//mengosongkan subtipe : array IdxHapus
//agar bisa dipakai ulang

void PrintTabel(List L); 
//untuk print List dalam bentuk tabel
//lengkap dengan garis pembatas

bool IsSelesai(int Skor,int Move);
//jika outputnya true maka fungsi IsMenang akan dijalankan
//jika false, permainan akan terus berlanjut

bool IsMenang(int Skor,int Move);
//true jika skor >= 5000 dan move <= 18
//false jika skor <= 5000 dan move >= 18

void TukarPosisi(List *L,int *Index1, int *Index2, char Arah);
//input : List l, integer Index1, dan arah
//Proses : Index2 ditentukan berdasarkan arah tukar
//         posisi elemen Index1 ditukar dengan Index2

void Meletus(List L,int Index1,int Index2,score *skor,ArrayIdx *A);
//syarat agar candy meletus (acuan Index1 dan Index2) :
// -> candynya sama kekanan 1 - 2 blok dan/atau kekiri 1 - 2 blok
// -> candynya sama keatas 1 - 2 blok dan/atau kebawah 1 - 2 blok
//
//output (yang berubah) : 
//	sub-Tipe dari ArrayIdx yang berubah : IdxTimpa, IdxIsi (boleh kosong)
//  sub-tipe dari score yang berubah : row3, row4 ,dan row5 (kalau kosong, isi dengan nilai nol)

void Timpa_Isi(List *L,ArrayIdx *A);
//terdiri dari dua subproses :
//1) timpa : sebagian elemen akan (berdasarkan input A) 
//   	     ditimpa oleh elemen diatasnya, dan 
//           seterusnya hingga elemen kedua teratas (antara Index 9 - 16)
//2) isi : khusus untuk elemen teratas (antara Index 1 - 8) akan 
//		   diassign char baru secara random
//	       tergantung Index1 elemen yang terlibat dalam proses timpa

void UpdateSkor(Score *skor,int *selisih_nilai);
//update score terbaru (bisa saja skor-nya tidak berubah)
//selisih nilai = skor baru - skor lama
//aturan skor cek di tubes
//sub-tipe dari score yang berubah hanya Total

#endif