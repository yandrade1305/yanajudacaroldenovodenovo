#include <stdio.h>
#include <string.h>

int romanValue(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToDecimal(char *str) {
    int result = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        int currentVal = romanValue(str[i]);

        if (i < length - 1) {
            int nextVal = romanValue(str[i + 1]);

            if (currentVal < nextVal) {
                result -= currentVal;
            } else {
                result += currentVal;
            }
        } else {
            result += currentVal;
        }
    }

    return result;
}

int main() {
    char romanNumber[13];
    scanf("%s", romanNumber);

    int decimal = romanToDecimal(romanNumber);
    int decimalToBinary = decimal;
    int array[10], i;    

    printf("%s na base 2: ", romanNumber);

    for(i=0;decimalToBinary>0;i++){    
        array[i]=decimalToBinary%2;    
        decimalToBinary=decimalToBinary/2;    
    }    
     
    for(i=i-1;i>=0;i--){    
        printf("%d",array[i]);    
    }    

    printf("\n");

    printf("%s na base 10: %d\n", romanNumber, decimal);

    printf("%s na base 16: %x\n", romanNumber, decimal);

    return 0;
}
