// convierte de binario a entero

int BinarioAEntero(int A[128], int fila, int columna){
    int count_i;
    for ( int count_i = 0; count_i < 128; count_i += 8 ){
        fila = A[ count_i ] * 8 + A[ count_i + 1 ] * 4 + A[ count_i + 2 ] * 2 + A[ count_i + 3 ] * 1;		
        columna = A[ count_i + 4 ] * 8 + A[ count_i + 5 ] * 4 + A[ count_i + 6 ] * 2 + A[ count_i + 7 ] * 1;
    }

    return A[128];
    return fila;
    return columna;
}