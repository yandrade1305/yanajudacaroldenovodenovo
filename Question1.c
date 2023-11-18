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

    printf("%s in base 2: ", romanNumber);

    for (int i = 11; i >= 0; i--) {
        printf("%d", (decimal >> i) & 1);
    }
    printf("\n");

    printf("%s in base 10: %d\n", romanNumber, decimal);

    printf("%s in base 16: %X\n", romanNumber, decimal);

    return 0;
}
