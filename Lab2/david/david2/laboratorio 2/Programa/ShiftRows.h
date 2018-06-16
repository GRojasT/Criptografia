// Shift Rows

int shiftrows(int b[128], int s[128]){
    int count_k = 0, count_i, count_j;
    int shift[ 16 ] = { 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11 };

    for ( count_i = 0 ; count_i < 16 ; count_i++){
        for ( count_j = 0; count_j < 8; count_j++) {
            s[ count_k ] = b[ shift[ count_i ] * 8 + count_j]; 								
            count_k++; 																		
        }
    }
    return s[128];
}