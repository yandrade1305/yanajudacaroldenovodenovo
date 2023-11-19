#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPlacaAntiga(char *placa) {
    if (strlen(placa) != 8) {
        return 0;
    }
    
    for (int i = 0; i < 3; i++) {
        if (!isalpha(placa[i])) {
            return 0;
        }
    }

    if (placa[3] != '-' || !isdigit(placa[4]) || !isdigit(placa[5]) || !isdigit(placa[6]) || !isdigit(placa[7])) {
        return 0;
    }

    return 1;
}

int isPlacaMercosul(char *placa) {
    if (strlen(placa) != 7) {
        return 0;
    }
    
    for (int i = 0; i < 3; i++) {
        if (!isalpha(placa[i])) {
            return 0;
        }
    }

    if (isalpha(placa[3]) || !isalpha(placa[4]) || isalpha(placa[5]) || !isdigit(placa[6]) || isdigit(placa[7])) {
        return 0;
    }

    return 1;
}

int main() {
    char placa[9];
    char diaSemana[20];

    fgets(placa, sizeof(placa), stdin);
    placa[strcspn(placa, "\n")] = '\0';

    fgets(diaSemana, sizeof(diaSemana), stdin);
    diaSemana[strcspn(diaSemana, "\n")] = '\0';

    for (int i = 0; diaSemana[i]; i++) {
        diaSemana[i] = toupper(diaSemana[i]);
    }

    int placaAntigaValida = isPlacaAntiga(placa);
    int placaMercosulValida = isPlacaMercosul(placa);

    if (!placaAntigaValida && !placaMercosulValida) {
        printf("Placa invalida\n");
    } 

    char ultimoDigito = placa[strlen(placa) - 1];

    if (strcmp(diaSemana, "SEGUNDA-FEIRA") == 0) {
        if (ultimoDigito != '0' && ultimoDigito != '1') {
            printf("%s pode circular segunda-feira\n", placa);
        } else {
            printf("%s nao pode circular segunda-feira\n", placa);
        }
    } else if (strcmp(diaSemana, "TERCA-FEIRA") == 0) {
        if (ultimoDigito != '2' && ultimoDigito != '3') {
            printf("%s pode circular terca-feira\n", placa);
        } else {
            printf("%s nao pode circular terca-feira\n", placa);
        }
    } else if (strcmp(diaSemana, "QUARTA-FEIRA") == 0) {
        if (ultimoDigito != '4' && ultimoDigito != '5') {
            printf("%s pode circular quarta-feira\n", placa);
        } else {
            printf("%s nao pode circular quarta-feira\n", placa);
        }
    } else if (strcmp(diaSemana, "QUINTA-FEIRA") == 0) {
        if (ultimoDigito != '6' && ultimoDigito != '7') {
            printf("%s pode circular quinta-feira\n", placa);
        } else {
            printf("%s nao pode circular quinta-feira\n", placa);
        }
    } else if (strcmp(diaSemana, "SEXTA-FEIRA") == 0) {
        if (ultimoDigito != '8' && ultimoDigito != '9') {
            printf("%s pode circular sexta-feira\n", placa);
        } else {
            printf("%s nao pode circular sexta-feira\n", placa);
        }
    } else if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        printf("Dia da semana invalido\n");
    }

    return 0;
}
