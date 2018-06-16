
// convertir a función

// de a a S
//byte Substitution. Transforma cada 8 bits del array en números decimal, los pasa por la sbox guardando el resultado en hex y al final pasa todo a un arreglo b





// transforma de a 8 bits del arreglo a entero

  for(int i=0; i<NUM ;i+=8){
    row = a[i]*8 +a[i+1]*4 +a[i+2]*2 +a[i+3]*1;			//convierte el hexadecimal a binario
    col = a[i+4]*8 +a[i+5]*4 +a[i+6]*2 +a[i+7]*1;
// fin función


  // convierte el entero a hexadecimal desde la sbox
  // obtiene el hexadecimal desde la sbox
    hex=aes_sbox[row][col];													//Captura desde la sbox el hexadecimal al que se convierte Ai

    k=i; 	
    
    // de S a B																					//Para que guarde los bits transformados en la posición original que estaban en a
    for (size_t j = 0; j < 4; j++) {
      bin = hextobin(hex[0]);												//Guarda el binario del hexadecimal capturado desde la sbox
      bin2 = hextobin(hex[1]);
      b[k] = bin[j] - '0';
      b[k+4] = bin2[j] - '0';
      k++;
    }
  }