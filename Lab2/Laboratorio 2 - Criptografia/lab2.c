/*
	Introduccion a la Criptografia Moderna
	Laboratorio 2
	Autor: Gustavo Rojas
	Problema: AES: Advanced Encryption Standard
	Fecha: 23/05/2018 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	
	//----------------------------------------DEF DE VARIABLES------------------------------------//
	//-----1-----//
	int op;
	int bitrand;
	int array[256];
	int i, j;
	int hora = time(NULL);  
	int n;
	srand(hora); // semilla de rand();

	//-----2-----//
	unsigned char SBox[16][16] = { // Tabla SBox
		{0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76},
		{0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0},
		{0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15},
		{0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75},
		{0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84},
		{0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF},
		{0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8},
		{0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2},
		{0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73},
		{0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB},
		{0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79},
		{0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08},
		{0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A},
		{0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E},
		{0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF},
		{0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16}
	};
	int row[16], column[16]; // posiciones del numero en la tabla
	unsigned char hex[16];

	//-----3-----//	
	int pb;
	unsigned char bloques[16][8];

	//-----4-----//
	unsigned char bloqueSR[16]; // Bloque Shift Rows

	//-----5-----//
	unsigned char B[16] = {
		0x02,0x03,0x01,0x01,
		0x01,0x02,0x03,0x01,
		0x01,0x01,0x02,0x03,
		0x03,0x01,0x01,0x02
	};
	unsigned char C[4];
	unsigned char irrev = {0x1B}; // x⁸+x⁴+x³+x+1 = 00011011 = 1 11 = 1B
	
	//-----Para calcular tiempo de ejecucion-----//
	clock_t start, end, start2;
    double sec1; // para calcular el tiempo de ejecucion
    
    start = clock(); // comienza a calcular el tiempo

	//--------------------------------------------------------------------------------------------//

	printf("Tamaño de la clave: \n  1. 128 bits\n  2. 192 bits\n  3. 256 bits\n");
	do{
		scanf("%d", &op);
	}while(op>3 || op<1);
	
	system("clear");
	
	//----------------------------------------INGRESO DE CLAVE Y CREACION DE ARREGLO------------------------------------1//
	if(op==1){ // opcion 1 - 128 bits
		n=128;
		printf("1. 128 bits\n\n");
		printf("Plaintext:\n ");
		for(i=0; i<n; i=i+1){
			bitrand = rand() % 2;
			printf("%d", bitrand); // mostrar los 128 bits generados de forma Random
			array[i] = bitrand;
		}
	} //array[] guarda los bits
	if(op==2){ // opcion 2 - 196 bits
		n=192;
		printf("2. 192 bits\n\n");
		printf("Plaintext:\n ");
		for(i=0; i<n; i=i+1){
			bitrand = rand() % 2;
			printf("%d", bitrand); // mostrar los 196 bits generados de forma Random
			array[i] = bitrand;
		}
	} //array[] guarda los bits
	if(op==3){ // opcion 3 - 256 bits
		n=256;
		printf("3. 256 bits\n\n");
		printf("Plaintext:\n ");
		for(i=0; i<n; i=i+1){
			bitrand = rand() % 2;
			printf("%d", bitrand); // mostrar los 256 bits generados de forma Random
			array[i] = bitrand;
		}
	} //array[] guarda los bits
	printf("\n\n");
	
	//------------------------------------------------------------------------------------------------------------------1//
	j=0;
	// Obtener fila y columna de cada bloque de 8 bits
	for(i=0;i<n;i=i+8){
		row[j] = array[i]*8 + array[i+1]*4 + array[i+2]*2 + array[i+3]*1;
		column[j] = array[i+4]*8 + array[i+5]*4 + array[i+6]*2 + array[i+7]*1;
		j++;
	}

	//------------------------CONVERTIR BINARIOS A HEXADECIMAL--------------------2//
	for(i=0;i<16;i=i+1){
		hex[i] = SBox[row[i]][column[i]];
	}
	printf("Binarios convertidos a hexadecimal:\n "); // Esto respecto a la SBOX
	for(i=0; i<16;i++){ // PRINT
		printf("%.2X|", hex[i]);
	}
	printf("\n\n");
	//----------------------------------------------------------------------------2//
	
	//------------------------CONVERTIR HEXADECIMAL A BINARIOS--------------------3//
	printf("Representacion binaria de los hexadecimales:\n ");
	for(i=0;i<16;i=i+1){ // PRINT
		for(pb=7; pb>=0; pb=pb-1){
			if(hex[i] & (1<<pb))
				printf("1");
			else
				printf("0");
		}
		printf("|");
	}
	printf("\n\n");
	//----------------------------------------------------------------------------3//

	//---------------------------------------SHIFTROWS---------------------------------------4//
	// Otra alternativa es trabajarlo a nivel de bits con el << para correr las posiciones
	// Se hizo asi por temas de tiempo
	bloqueSR[0]=hex[0];
	bloqueSR[1]=hex[5];
	bloqueSR[2]=hex[10];
	bloqueSR[3]=hex[15];
	bloqueSR[4]=hex[4];
	bloqueSR[5]=hex[9];
	bloqueSR[6]=hex[14];
	bloqueSR[7]=hex[3];
	bloqueSR[8]=hex[8];
	bloqueSR[9]=hex[13];
	bloqueSR[10]=hex[2];
	bloqueSR[11]=hex[7];
	bloqueSR[12]=hex[12];
	bloqueSR[13]=hex[1];
	bloqueSR[14]=hex[6];
	bloqueSR[15]=hex[11];
	//---------------------------------------------------------------------------------------4//

	//-----------------------------------------COLUMN SUBLAYER Y MIXCOLUMN-----------------------------------------5//
	// multiplicacion matriz 4x4 y 4x1
	// Como se trabajó a nivel de bits el XOR e sta interpretado como ^ 
	int k=0;
	for(j=0;j<16;j=j+4){
		for(i=0;i<16;i=i+4){
			if(B[i] > 0X1B){ // si el B[i] es mayor a X⁷ entonces hay que reducirlo con el polinomio irreducible
				C[k] = ((B[i]<<bloqueSR[j])^0x1B) ^ ((B[i+1]<<bloqueSR[j+1])^0x1B) ^ ((B[i+2]<<bloqueSR[j+2])^0x1B) 
				^ ((B[i+3]<<bloqueSR[j+3])^0x1B);
			}
			else{ // si no simplemente se realizan los XOR respectivos
				C[k] = B[i]<<bloqueSR[j] ^ B[i+1]<<bloqueSR[j+1] ^ B[i+2]<<bloqueSR[j+2] ^ B[i+3]<<bloqueSR[j+3];
			}
			k++;
		}
	}
	printf("Primera Ronda del AES:\n ");
	for(i=0;i<16;i=i+1){ // PRINT FINAL
		for(pb=7; pb>=0; pb=pb-1){
			if(C[i] & (1<<pb))
				printf("1");
			else
				printf("0");
		}
	}
	printf("\n\n");
	
	end=clock();
	sec1=(double)(end-start)/CLOCKS_PER_SEC;
	//printf("Tiempo: %f\n", sec1); // tiempo final de  la ejecucion

	return 0;
	//-------------------------------------------------------------------------------------------------------------5//
}
