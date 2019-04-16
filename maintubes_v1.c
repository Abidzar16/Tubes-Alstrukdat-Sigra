#include <tubes.h>

int main(){
	//KAMUS LOKAL
	List Listmain;
	Score skor;
	int move = 0;
	int Index1,Index2;
	int selisih = 0;
	char Arah;
	int meletus = 0;
	int meletus_x = 0;
	int meletus_y = 0;

	//ALGORITMA MAIN

	Alokasi(Listmain);
	//pengisian List dengan huruf tertentu yang random (pakai fungsi Rand)

	while(!IsSelesai(skor,move)){

		PrintTabel(Listmain);
		printf("Masukkan nomor kotak: ");
		scanf("%d",&Index1);
		printf("Arah perpindahan: ");
		scanf("%c",&Arah);
		//Asumsi input Index1 dan Arah sudah benar

		TukarPosisi(&Listmain,&Index1,&Index12,arah);
		//Index1 akan bertukar posisi dengan Index12 (berdasarkan input arah)

		Meletus(Listmain,Index1,Index12,&skor,&ElemenHapus);
		//sub-tipe dari skor yang berubah : row3, row4 ,dan row5

		UpdateSkor(&skor,&selisih_nilai);
		//sub-tipe dari skor yang berubah hanya Total

		if (selisih_nilai <= 0) {
			//jika Index1 dan Index12 sudah ditukar 
			//tapi tidak ada candy yang meletus
			//maka posisinya diubah ke awal dan nilai move bertambah satu
			move++;
			tukarposisi(&Listmain,&Index2,&Index1,arah);
			
		}
		else {
			move++;
			Timpa_Isi(&Listmain,ElemenHapus);
			Dealokasi(ElemenHapus);
			
			PrintTabel(Listmain); //setelah operasi Hapus_Turun
			printf("Skor: %d",score.Total);
			//sudah diupdate
		}
	}

	if (IsMenang(Skor,Move)){
		printf("Anda Berhasil\n");
	} else {
		printf("Anda Gagal\n");
	}
}