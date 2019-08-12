#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "funciones.h"

void agregarCliente(ArrayList* pList, int caracter) {
    eCliente* pElement = (eCliente*) malloc(sizeof(eCliente));

    if (pElement != NULL) {
        pElement->turno = pList->len(pList)+1;
        pElement = pedirDNI(pElement);

        pList->add(pList, pElement);

        printf("Turno %s expedido exitosamente! Numero de turno: %d\n\n", caracter ? "urgente" : "regular", pList->len(pList));
    }
    else
        printf("ERROR: No se pudo reservar espacio en memoria");
}

eCliente* pedirDNI(eCliente* pElement) {

    char buffer[1024];
    int num;

    printf("Ingrese su DNI: ");
    fflush(stdin);
    gets(buffer);
    num = atoi(buffer);

    while (!validarRangoEntero(num, 1000000, 100000000) || !validarInt(buffer)) {
        system("cls");
        printf("DNI invalido, reingrese: ");
        fflush(stdin);
        gets(buffer);
        num = atoi(buffer);
    }

    pElement->dni = num;

    system("cls");

    return pElement;
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
    if (numero < min || numero > max)
        return 0;

    return 1;
}

void proximoCliente(ArrayList* noAtendidos, ArrayList* atendidos, int caracter) {
    eCliente* proximoCliente = (eCliente*) malloc(sizeof(eCliente));

    if (noAtendidos != NULL && atendidos != NULL && proximoCliente != NULL) {
        proximoCliente = noAtendidos->pop(noAtendidos, 0);
        atendidos->add(atendidos, proximoCliente);
        printf("Proximo cliente\n\n");
        printf("DNI: %d\n", proximoCliente->dni);
        printf("Turno: %d\n", proximoCliente->turno);
        printf("Caracter: %s\n\n", caracter ? "Urgente" : "Regular");
    }
    else {
        printf("ERROR: No se pudo asignar espacio en memoria o alguno de los punteros es nulo");
    }
}

void mostrarClientes(ArrayList* clientes, int caracter) {
    eCliente* cliente = (eCliente*) malloc(sizeof(eCliente));

    if (cliente != NULL) {
        int i;

        for (i = 0; i < clientes->len(clientes); i++) {
            cliente = (eCliente*) clientes->get(clientes, i);
            printf("Turno: %d | DNI: %d | Caracter: %s\n", cliente->turno, cliente->dni, caracter ? "Urgente" : "Regular");
        }
    }
    else {
        printf("ERROR: No se pudo asignar espacio en memoria");
    }
}

int comparaClienteDNI(eCliente* clienteA, eCliente* clienteB) {

    if (clienteA->dni > clienteB->dni)
        return 1;

    if (clienteA->dni < clienteB->dni)
        return -1;

    return 0;
}
