/*
	Introduccion a la Criptografia Moderna
	Laboratorio 1
	Autor: Gustavo Rojas
	Problema: Key Shedule de DES
	Fecha: 18/04/2018 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
		
	clock_t start, end, start2;
    double sec1; // para calcular el tiempo de ejecucion
    
	int op, i, j; // opcion y contadores
	int array[64], array2[56];
	int bitrand;
	int hora = time(NULL);  
	srand(hora); // semilla de rand();  
	
	int adef[64];
	for(i=0;i<64;i++){
		adef[i]=i;
	}
	
	start = clock(); // comienza a calcular el tiempo
	
	printf("Ingresar clave de 64 bits: \n 1. Manualmente\n 2. Random\n\n");
	do{
		scanf("%d", &op);
	}while(op>2 || op<1);
	
	system("clear");
	
	if(op == 1){ // Ingreso Manualmente
		printf("1. Manualmente\n\n");
		for(i=0; i<64; i=i+1){ 
			do{
				scanf("%d", &array[i]);
				if(array[i]>1 || array[i]<0)
					printf("No es un bit\n");
			}while(array[i]>1 || array[i]<0);	
		}
		printf("Clave de 64 bits:\n ");
		for(i=0; i<64; i=i+1){ 
			printf("%d", array[i]);	
		}
	}
	else{ // opcion 2 - Ingreso Random
		printf("2. Random\n\n");
		printf("Clave de 64 bits:\n ");
		for(i=0; i<64; i=i+1){
			bitrand = rand() % 2;
			printf("%d", bitrand); // mostrar los 64 bits generados de forma Random
			array[i] = bitrand;
		}
	} //array[] guarda los bits
	
	//-------------------------------|PC-1|-------------------------------
	
	int arrayn[56];
	int v, init;
	int cont=0;
	
	init=56;
	i=init;
	// se realiza el proceso PC-1
	for(j=0; j<28; j=j+1){
		arrayn[j]=array[i];
		if(j==7 || j==15 || j==23){ // tambien puede tomarse como j%7==0 pero si fuese asi tambien incluiria el 0
			array[init]=array[57];
			i=i+init;
		}
		else
			i=i-8;
		cont++;
	}
	i=62, v=0;
	for(j=28; j<56; j=j+1){
		arrayn[j]=array[i];
		if(j==35 || j==43 || j==50){
			if(v == 2){
				i=i+23;
			}
			else{
				i=i+(init-2);
				v++;
			}
		}
		else
			i=i-8;
	}

	arrayn[51]=array[4];
	printf("\n\n");
	
	int CD[56];
	
	// divide el arreglo en dos mitades
	for(i=0; i<56; i=i+1){
		CD[i]=arrayn[i];
	}

	int inic, inid, inic2, inid2;
	
	//---------------------------------16 Rondas-------------------------------//
	for(int r=0; r<16; r=r+1){
		if((r == 0) || (r == 1) || (r == 8) || (r == 15)){ // rotacion 1 espacio hacia la izquierda
			inic=CD[0];
			for(i=0;i<28;i=i+1){
				CD[i]=CD[i+1];
			}
			CD[27]=inic;
			inid=CD[28];
			for(i=28;i<56;i=i+1){
				CD[i]=CD[i+1];
			}
			CD[55]=inid;
		}
		else{ // rotacion 2 espacios a la izquierda
			inic=CD[0];
			inic2=CD[1];
			inid=CD[28];
			inid2=CD[29];
			for(i=0;i<27;i=i+1){
				CD[i]=CD[i+2];
			}
			CD[26]=inic;
			CD[27]=inic2;
			for(i=28;i<56;i=i+1){
				CD[i]=CD[i+2];
			}
			CD[54]=inid;
			CD[55]=inid2;
		}
		
	//-------------------------------|PC-2|-------------------------------
	
		int PC2[48];
		// se hizo de esta forma dado que no se encontro un patron especifico para ordenarlo
		PC2[0] = CD[13];
		PC2[1] = CD[16];
		PC2[2] = CD[10];
		PC2[3] = CD[23];
		PC2[4] = CD[0];
		PC2[5] = CD[4];
		PC2[6] = CD[2];
		PC2[7] = CD[27];
		PC2[8] = CD[14];
		PC2[9] = CD[5];
		PC2[10] = CD[20];
		PC2[11] = CD[9];
		PC2[12] = CD[22];
		PC2[13] = CD[18];
		PC2[14] = CD[11];
		PC2[15] = CD[3];
		PC2[16] = CD[25];
		PC2[17] = CD[7];
		PC2[18] = CD[15];
		PC2[19] = CD[6];
		PC2[20] = CD[26];
		PC2[21] = CD[19];
		PC2[22] = CD[12];
		PC2[23] = CD[1];
		PC2[24] = CD[40];
		PC2[25] = CD[51];
		PC2[26] = CD[30];
		PC2[27] = CD[36];
		PC2[28] = CD[46];
		PC2[29] = CD[54];
		PC2[30] = CD[29];
		PC2[31] = CD[39];
		PC2[32] = CD[50];
		PC2[33] = CD[44];
		PC2[34] = CD[32];
		PC2[35] = CD[47];
		PC2[36] = CD[43];
		PC2[37] = CD[48];
		PC2[38] = CD[38];
		PC2[39] = CD[55];
		PC2[40] = CD[33];
		PC2[41] = CD[52];
		PC2[42] = CD[45];
		PC2[43] = CD[41];
		PC2[44] = CD[49];
		PC2[45] = CD[35];
		PC2[46] = CD[28];
		PC2[47] = CD[31];

		printf("Clave %d:\n ", r+1); // se imprime en pantalla la clave de su respectiva ronda

		for(i=0; i<48; i=i+1){
			printf("%d", PC2[i]);
		}
		printf("\n");
	}
	printf("\n");
	
	end=clock();
	sec1=(double)(end-start)/CLOCKS_PER_SEC;
	//printf("Tiempo: %f\n", sec1); // tiempo final de  la ejecucion
	
	return 0;
}
