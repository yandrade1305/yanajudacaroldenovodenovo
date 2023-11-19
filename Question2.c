#include <stdio.h>
#include <math.h>

int main(){
    int months;
    double monthlyAport, monthlyReturnTax, calculatedAmount;

    scanf("%d %lf %lf", &months, &monthlyAport, &monthlyReturnTax);
    for (int i = 1; i < months + 1; i++){
        calculatedAmount = monthlyAport * (1+monthlyReturnTax) * ((pow((1 + monthlyReturnTax), i) - 1 )/monthlyReturnTax);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, calculatedAmount);
    }

    return 0;
}