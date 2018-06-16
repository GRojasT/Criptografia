// Obtiene B, luego de convertir el hexadecimal a binario

int obtenerB( int B[128], char *binario1, char *binario2, char *hexadecimal){
    int count_i, count_j;
    for (count_i = 0; count_i < 128; count_i += 8){
        for (size_t count_j = 0; count_j < 4; count_j++){
            binario1 = hexadecimalABinario( hexadecimal[ 0 ] );
            binario2 = hexadecimalABinario( hexadecimal[ 1 ] );
            B[ count_i ] = binario1[ count_j ] - '0';
            B[ count_i + 4] = binario2[ count_j ] - '0';
        }
    }

    return B[128];
}