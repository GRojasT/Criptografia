// obtiene B

#include "Sbox.h"
#include "HexadecimalABinario.h"

int obtenerb(int A[128], int B[128]){
    int count_i, count_j, count_k, fila, columna;
    char *hexadecimal;
    char *binario1, *binario2;
    
    for ( int count_i = 0; count_i < 128; count_i += 8 ){
        fila = A[ count_i ] * 8 + A[ count_i + 1 ] * 4 + A[ count_i + 2 ] * 2 + A[ count_i + 3 ] * 1;		
        columna = A[ count_i + 4 ] * 8 + A[ count_i + 5 ] * 4 + A[ count_i + 6 ] * 2 + A[ count_i + 7 ] * 1;

        hexadecimal = aes_sbox[ fila ][ columna ];

        count_k = count_i;
        for (size_t count_j = 0; count_j < 4; count_j++){
            binario1 = hexadecimalABinario( hexadecimal[ 0 ] );
            binario2 = hexadecimalABinario( hexadecimal[ 1 ] );
            B[ count_k ] = binario1[ count_j ] - '0';
            B[ count_k + 4] = binario2[ count_j ] - '0';
            count_k++;
        }
    }

    return B[128];
}