//se crea un nuevo arreglo de largo 128 con polinomios de grado 7

int pgrado7(int s[128], int aux2[144]){
    int count_t = 0, count_i, count_j;
    for (size_t count_i = 0; count_i < 144; count_i+=9)
        for (size_t count_j = count_i + 1; count_j < count_i + 9; count_j++) {
            s[ count_t ] = aux2[ count_j ] == 0 ? 0 : 1;
            count_t++;
            printf("%d", s[count_j]);
        }
    return s[128];
}
  