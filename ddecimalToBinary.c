#define SUCCESS 100

int decimalToBinary(int decimal);

int main(void) {
    decimalToBinary(60);
    return 0;
}

/*
int decimal -> receives a decimal number eg) 30
and converts it to binary
*/
int decimalToBinary(int decimal) {
    // initial array
    int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 
    // length is 8 bits 
    int bit = 8; 

    // while the bit index is in this range
    while (bit <= 8 && bit >= 0) {
        // gives a 0 or a 1
        int modulus = decimal % 2;
        // half the decimal value each time 
        int quotient = decimal / 2;
        // set the decimal to the quotient value 
        decimal = quotient; 
        // add the modulus to the array
        binary[bit - 1] = modulus; 
        bit--;
    }

    /*
    TEST 

    for (int i = 0; i < sizeof(binary) / sizeof(binary[0]); i++) {
         printf(" %d ", binary[i]);
    }  
    */
    

    return SUCCESS;
}
















