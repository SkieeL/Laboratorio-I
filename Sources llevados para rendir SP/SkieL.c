#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

char validarChar(char datoChar, char necesario1, char necesario2) {
    datoChar = toupper(datoChar);
    necesario1 = toupper(necesario1);
    necesario2 = toupper(necesario2);

    while (datoChar != necesario1 && datoChar != necesario2) {
        printf("Dato invalido. Reingrese: ");
        datoChar = getch();
        datoChar = toupper(datoChar);
    }

    return datoChar;
}

int validarString(char cadena[]) {
    if (strcmp(cadena, "") == 0) {
        system("cls");
        printf("ERROR: Debe ingresar algun caracter\n");
        return 0;
    }

    int len, i;
    len = strlen(cadena);

    for (i = 0; i < len; i++) {
        if (cadena[i] != ' ') {
            return 1;
        }
    }

    system("cls");
    printf("ERROR: No puede ingresar solo espacios\n");

    return 0;
}

int validarInt(char numero[]) {
    int len, i;
    len = strlen(numero);

    for (i = 0; i < len; i++) {
        if (!isdigit(numero[i])) {
            return 0;
        }
    }

    return 1;
}

int validarRangoEntero(int numero, int min, int max) {
    while (numero < min || numero > max) {
        printf("Dato invalido. Reingrese: ");
        scanf("%d", &numero);
    }

    return numero;
}

float validarRangoFloat(float numero, float min, float max) {
    while (numero < min || numero > max) {
        printf("Dato invalido. Reingrese: ");
        scanf("%f", &numero);
    }

    return numero;
}

int calcularMayor(int num1, int num2, int num3) {

    if (num1 >= num2 && num1 >= num3) {
        return num1;
    }
    else if (num2 >= num3 && num2 >= num1) {
        return num2;
    }

    return num3;
}
