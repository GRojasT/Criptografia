// multiplicación por matriz

#include "check.h"
#include "matrix.h"

int multiplicacion( int aux2[144], int aux[128]){
    int row = 0, col = 0, piv = 0, count_i, count_j, count_k;
    for ( count_i = 0; count_i < 128; count_i+=32){
        count_k = count_i;
        for ( count_j = count_i; count_j < count_k + 32; count_j+=8){
            if( matrix[ row ][ col ] == 01){                 
                aux2[ piv ] = 0;                            
                aux2[ piv + 1 ] = aux[ count_j ];
                aux2[ piv + 2 ] = aux[count_j + 1 ];
                aux2[ piv + 3 ] = aux[count_j + 2 ];
                aux2[ piv + 4 ] = aux[count_j + 3 ];
                aux2[ piv + 5 ] = aux[count_j + 4 ];
                aux2[ piv + 6 ] = aux[count_j + 5 ];
                aux2[ piv + 7 ] = aux[count_j + 6 ];
                aux2[ piv + 8 ] = aux[count_j + 7]^1;
            }else if ( matrix[ row ][ col ] == 02){           
                aux2[ piv ] = check( aux[ count_j ] );
                aux2[ piv + 1 ] = check( aux[ count_j + 1 ]);
                aux2[ piv + 2 ] = check( aux[ count_j + 2]);
                aux2[ piv + 3 ] = check( aux[ count_j + 3]);
                aux2[ piv + 4 ] = check( aux[ count_j + 4]);
                aux2[ piv + 5 ] = check( aux[ count_j + 5]);
                aux2[ piv + 6 ] = check( aux[ count_j + 6]);
                aux2[ piv + 7 ] = aux[ count_j + 7 ];                   
                aux2[ piv + 8 ] = 0;                          
            }else{
                aux2[ piv ] = check( aux[ count_j ] );                
                aux2[ piv + 1 ] = check( aux[ count_j+ 1])^aux[ count_j ];     
                aux2[ piv + 2 ] = check( aux[ count_j+ 2])^aux[ count_j + 1 ];   
                aux2[ piv + 3 ] = check( aux[ count_j+ 3])^aux[ count_j + 2 ];   
                aux2[ piv + 4 ] = check( aux[ count_j+ 4])^aux[ count_j + 3 ];
                aux2[ piv + 5 ] = check( aux[ count_j+ 5])^aux[ count_j + 4 ];
                aux2[ piv + 6 ] = check( aux[ count_j+ 6])^aux[ count_j + 5 ];
                aux2[ piv + 7 ] = aux[ count_j + 7 ]^aux[count_j + 6 ];
                aux2[ piv + 8 ] = aux[ count_j + 7 ];
            }
            piv+=9;
            col++;
        }
        row++;
        col = 0;
    }
    return aux2[144];
}