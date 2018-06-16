int mixcolumn(int s[128], int aux[128]){
    
    int elevado = 7, count_i;
    int piv = 7;
    
    for ( count_i = 0 ; count_i < 128 ; count_i++){
        if ( count_i % 8 == 0){
            elevado = 7;
        }else if ( count_i == piv){                         
            aux[ count_i ] = s[ count_i ];
            piv+=8;
            elevado--;
            continue;
        }
        aux[ count_i ] = s[ count_i ] * elevado;
        elevado--;
    }
    return aux[128];
} 
 
 
 