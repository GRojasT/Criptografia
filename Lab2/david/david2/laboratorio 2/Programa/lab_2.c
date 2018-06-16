/****************************************************
 @author David Sanhueza Andréus
 @file main.c
 @date miércoles 23 de mayo de 2018

****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
Se incluyen los módulos con cada una de la funciones utilizadas en este programa

@file: hexadecimalABinario.h
hextobin: convierte el hexadecimal a binario

@file: ShiftRows.h
shiftrows: aplica shiftrows a B

@file: Mixcolumn.h
mixcolumn: aplica mixcolumn a s

@file: multiplicacion.h
multiplicacion: multiplicación por matriz

@file: pirreductible.h
pirreductible: polinomio irreductible de aes

@file: pgrado7.h
pgrado7: se crea un nuevo arreglo de largo 128 con polinomios de grado 7

*/


#include "ObtenerB.h"
#include "ShiftRows.h"
#include "Mixcolumn.h"
#include "multiplicacion.h"
#include "pirreductible.h"
#include "pgrado7.h"


/**
Variables

count_i: se utilizan como contadores
A[128]: arreglo que contiene la clave original
B[128]: arreglo que contiene la nueva clave luego de aplicar S a A
s[128]: guarda los desplazamientos de shiftrows
aux[128]: arreglo auxiliar para mixcolumn
aux2[144]: arreglo auxiliar para la multiplicación en mixcolumn
*/


int main(){

    int count_i;
    int A[128];
    int B[128];
    int s[128];
    int aux[128];
    int aux2[144];

    clock_t start;
    clock_t end;
    start = clock();
    
    // genera la clave A de 128 bits
    for ( count_i = 0; count_i < 128; count_i++ ){
        A[ count_i ] = rand () % 2;
    }

    printf("Arreglo a codificar\n\n");
    for ( count_i = 0; count_i < 128; count_i++ ){
        printf("%d", A[count_i]);
    }

    // Obtiene B
    obtenerb(A, B);

    // aplica shiftrows a B
    shiftrows(B, s);

    // aplica mixcolumns a s
    mixcolumn(s, aux);

    // multiplicación por matriz
    multiplicacion(aux2, aux);

    // polinomio irreductible del aes
    pirreductible(aux2);

    printf("\n\nEl arreglo codificado es:\n\n" );

    // polinomio de grado 7
    pgrado7(s, aux2);

    end = clock();

    printf("\n time: %f", (double)(end - start));
    
    return 0;
}