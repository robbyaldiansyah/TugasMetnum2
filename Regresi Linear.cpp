#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
#define ar 100

main(){
	
	float n;
	float x[ar];
	float y[ar];
	float kuadratX[ar],kuadratY[ar], kaliXY[ar];
	float m,c;
	float aksen[ar];
	float eror[ar];
	float SigmaX =0, SigmaY =0, SigmaXkuad =0, SigmaXkuadrat =0, SigmaYkuadrat =0, SigmaXkaliY =0, SigmaYaksen = 0, SigmaEror = 0, rata =0;
	printf("\n\t\t\tPROGRAM MENGHITUNG REGRESI LINEAR");
	printf("\n");
	printf("\nMasukan Jumlah data : ");
	scanf("%f",&n);
	
	// input data x
	for(int i=0; i<n; i++){
		printf("\nMasukan Nilai X : ");
			scanf("%f",&x[i]);					
	}
	//input data y
	for(int k=0; k<n; k++){
		printf("\nMasukan Nilai Y : ");
			scanf("%f",&y[k]);		
	}
	printf("\n===============================");
	//Tampil data x
	for(int j=0; j<n; j++){
		printf("\nData X ke-%d: %.0f ",j+1, x[j]);
	}
	//Tampil data x
		for(int j=0; j<n; j++){
		printf("\nData Y ke-%d: %.0f ",j+1, y[j]);
	}
	printf("\n===============================");
	
	//hitung jumlah x dan y
	for(int i=0; i<n; i++){
		SigmaX = SigmaX + x[i];
		SigmaY = SigmaY + y[i];
	}
	// hasil tambah x dan sigma dari x
	SigmaXkuad = pow(SigmaX,2);
	printf("\nSigma X adalah  : %.0f",SigmaX);
	printf("\nSigma X di kuadratkan adalah : %.0f",SigmaXkuad);
	
	// hasil tambah y
	printf("\nSigma Y adalah : %.0f",SigmaY);
	printf("\n===============================");
	
	//menghitung kuadrat
	for(int i=0; i<n; i++){
		kuadratX[i] = x[i] * x[i];
		kuadratY[i] = y[i] * y[i];
	}
	for(int i=0; i<n; i++){
		SigmaXkuadrat = SigmaXkuadrat + kuadratX[i];
		SigmaYkuadrat = SigmaYkuadrat + kuadratY[i];
	}
	printf("\nHasil Nilai Kuadrat X :");
	for(int k=0; k<n; k++){
		printf(" %.0f", kuadratX[k]);
	}
	printf("\nHasil Nilai Kuadrat Y :");
	for(int k=0; k<n; k++){
		printf(" %.0f", kuadratY[k]);
	}
	printf("\nNilai Sigma X Kuadrat adalah  : %.0f",SigmaXkuadrat);
	printf("\nNilai Sigma Y Kuadrat adalah  : %.0f",SigmaYkuadrat);
	
	printf("\n===============================");
	
	//menampilkan hasil x kali y
	for(int i=0; i<n; i++){
		kaliXY[i] = x[i] * y[i];
	}
	printf("\nHasil Kali XY :");
	for(int k=0; k<n; k++){
		printf(" %.0f", kaliXY[k]);
	}
	for(int i=0; i<n; i++){
		SigmaXkaliY = SigmaXkaliY + kaliXY[i];
	}
	printf("\nNilai Sigma dari XY adalah  : %.0f",SigmaXkaliY);
	printf("\n===============================");
	// mencari m
	m= ((n*SigmaXkaliY)-(SigmaX*SigmaY)) / ((n*SigmaXkuadrat)-(SigmaX*SigmaX));
	c = ((SigmaY*SigmaXkuadrat)-(SigmaX*SigmaXkaliY))/((n*SigmaXkuadrat)-(SigmaXkuad));
	printf("\nm = %.3f", m);
	printf("\nc = %.3f", c);
	
    // hasill
 	for(int i=0;i<n;i++){
		aksen[i]=m*x[i]+c;
	}
	printf("\nHasil Y aksen adalah  :");
	for(int k=0; k<n; k++){
		printf(" %.3f", aksen[k]);
	}
	for(int i=0; i<n; i++){
		SigmaYaksen = SigmaYaksen + aksen[i];
	}
	printf("\nHasil Sigma dari y aksen adalah  : %.3f",SigmaYaksen);
	printf("\n===============================");
	
	//mencari eror dan di absolute kan
	for(int i=0; i<n; i++){
		eror[i] = y[i] - aksen[i];
	}
	
	for(int i=0; i<n; i++){
		if(eror[i] < 0 ){
			eror[i] = eror[i] * -1;	
		}
	}
	
	printf("\nHasil error :");
	for(int k=0; k<n; k++){
		printf(" %.3f", eror[k]);
	}
	
	for(int k=0; k<n; k++){
		SigmaEror = SigmaEror + eror[k];
	}
	printf("\nHasil Sigma dari Error adalah  : %.3f",SigmaEror);
	printf("\n===============================");
	
	rata = SigmaEror / n;
	printf("\nNilai rata-rata error adalah  : %.3f",rata);
	printf("\n===============================");
	printf("\nMelakukan Prediksi");
	//Melakukan Prediksi
	int jarak;
	float waktu,waktu1,waktu2;
	printf("\nInput jarak yang anda inginkan : ");
	scanf("%d",&jarak);
	waktu=m*jarak+c;
	waktu1=waktu-rata;
	waktu2=waktu+rata;
	printf("\nJumlah Waktu prediksi sebelum tambah error  : %.3f",waktu);
	printf("\n%.3f%",waktu1);
	printf(" < waktu < ");
	printf("%.3f%",waktu2);
	
}
