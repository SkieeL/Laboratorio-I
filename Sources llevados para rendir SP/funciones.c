#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "Employee.h"
#include "SkieL.h"
#include "funciones.h"

void agregarEmpleado(ArrayList* pList) { // Modificar nombre de la función
    eEmployee* pElement = (eEmployee*) malloc(sizeof(eEmployee)); // MODIFICAR TIPO DE DATO "eEmployee"

    if (pElement != NULL) {
        pElement = pedirNombre(pElement, 0);
        pElement = pedirEdad(pElement, 0);

        pList->add(pList, pElement);

        printf("Cargado exitosamente!\n\n");
    }
    else
        printf("ERROR: No se pudo reservar espacio en memoria");

}

eEmployee* pedirNombre(eEmployee* pElement, int modificar) { // Modificar nombre de funcion y el dato "eEmployee"

    char buffer[1024];

    printf("Ingrese el%s nombre: ", modificar ? " nuevo" : ""); // Modificar "nombre".
    fflush(stdin);
    gets(buffer);

    while (!validarString(buffer)) {
        printf("Nombre invalido, reingrese: "); // Modificar "Nombre".
        fflush(stdin);
        gets(buffer);
    }

    strcpy(pElement->name, buffer); // Modificar campo "name".

    system("cls");

    return pElement;
}

eEmployee* pedirEdad(eEmployee* pElement, int modificar) { // Modificar nombre de funcion y el dato "eEmployee"

    char buffer[1024];
    int num;

    printf("Ingrese la%s edad: ", modificar ? " nueva" : ""); // Modificar "edad".
    fflush(stdin);
    gets(buffer);
    num = atoi(buffer);

    while (!validarRangoEntero(num, 1, 100) || !validarInt(buffer)) { // Modificar rango de validación.
        system("cls");
        printf("Edad invalida, reingrese: "); // Modificar "Edad".
        fflush(stdin);
        gets(buffer);
        num = atoi(buffer);
    }

    pElement->sector = num; // Modificar campo "sector" (vendría a guardar la edad).

    system("cls");

    return pElement;
}
