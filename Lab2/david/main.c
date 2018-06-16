/****************************************************
 @author David Sanhueza Andréus
 @file main.c
 @date miércoles 23 de mayo

****************************************************/
#include <stdio.h>
#include <stdlib.h>


/**
Se incluyen los módulos con cada una de la funciones utilizadas en este programa

@file: sbox.h
aes_sbox: representación de la sbox del AES

@file: hexadecimalABinario.h
hextobin: convierte el hexadecimal a binario

*/


#include "SBox.h"
#include "HexadecimalABinario.h"
#include "BinarioAEntero.h"
#include "ObtenerB.h"

/**
Variables

count_i, count_j: se utilizan como contadores
A[128]: arreglo que contiene la clave original
B[128]: arreglo que contiene la nueva clave luego de aplicar S a A
fila, columna: datos para obtener los valores de la sbox
binario1, binario2: auxiliares donde se guarda el hexadecimal transformado a binario
*/

int main(){

    int count_i, count_j;
    int A[128];
    int B[128];
    char *binario1, *binario2;
    int fila, columna;
    char *hexadecimal;

    // genera la clave A de 128 bits
    for ( count_i = 0; count_i < 128; count_i++ ){
        A[ count_i ] = rand () % 2;
    }

    // convierte la clave A a binario
    BinarioAEntero(A, fila, columna);

    // convierte los binarios de la clave A a hexadecimal
    hexadecimal = aes_sbox[ fila ][ columna ];	

    // convierte los hexadecimales de la clave A a binarios, para luego guardarlos en el nuevo arreglo B
    obtenerB(B, binario1, binario2, hexadecimal);

    


    return 0;
}