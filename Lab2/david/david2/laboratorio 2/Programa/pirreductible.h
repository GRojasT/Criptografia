// polinomio irreductible del aes

int pirreductible(int aux2[144]){
    int PI[9]= {8,0,0,0,4,3,0,1,1};
    int count_i, count_j; 
    for ( size_t count_i = 0; count_i < 144; count_i+=9)
        if ( aux2[ count_i ] == 8)
            for (size_t count_j = 0; count_j < 9; count_j++)
                aux2[ count_i + count_j] = aux2[ count_i + count_j ]^PI[ count_j ];
    
    return aux2[144];
}
