#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    int opcion, emptyUrg, emptyReg;
    char flagContinuar = 's';
    ArrayList* atendidosUrg = al_newArrayList();
    ArrayList* noAtendidosUrg = al_newArrayList();
    ArrayList* atendidosReg = al_newArrayList();
    ArrayList* noAtendidosReg = al_newArrayList();

    printf("Bienvenido/a!\n\n");

    while (flagContinuar == 's') {

        printf("1. Tramite urgente\n");
        printf("2. Tramite regular\n");
        printf("3. Proximo cliente\n");
        printf("4. Clientes no atendidos\n");
        printf("5. Clientes atendidos\n");
        printf("6. Salir\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch (opcion)
        {
            case 1:
                agregarCliente(noAtendidosUrg, 1);
                break;
            case 2:
                agregarCliente(noAtendidosReg, 0);
                break;
            case 3:
                emptyUrg = noAtendidosUrg->isEmpty(noAtendidosUrg);
                emptyReg = noAtendidosReg->isEmpty(noAtendidosReg);

                if (!emptyUrg)
                    proximoCliente(noAtendidosUrg, atendidosUrg, 1);
                else if (!emptyReg)
                    proximoCliente(noAtendidosReg, atendidosReg, 0);
                else
                    printf("No quedan clientes por atender\n\n");
                break;
            case 4:
                printf("CLIENTES NO ATENDIDOS\n\n");

                emptyUrg = noAtendidosUrg->isEmpty(noAtendidosUrg);
                emptyReg = noAtendidosReg->isEmpty(noAtendidosReg);

                if (!emptyUrg)
                    mostrarClientes(noAtendidosUrg, 1);

                if (!emptyReg)
                    mostrarClientes(noAtendidosReg, 0);

                if (emptyUrg && emptyReg)
                    printf("No hay clientes sin atender\n\n");
                else
                    printf("\n");

                break;
            case 5:
                printf("CLIENTES ATENDIDOS\n\n");

                emptyUrg = atendidosUrg->isEmpty(atendidosUrg);
                emptyReg = atendidosReg->isEmpty(atendidosReg);

                if (!emptyUrg) {
                    atendidosUrg->sort(atendidosUrg, comparaClienteDNI, 0);
                    mostrarClientes(atendidosUrg, 1);
                }

                if (!emptyReg) {
                    atendidosReg->sort(atendidosReg, comparaClienteDNI, 0);
                    mostrarClientes(atendidosReg, 0);
                }

                if (emptyUrg && emptyReg)
                    printf("No hay clientes atendidos\n\n");
                else
                    printf("\n");

                break;
            case 6:
                printf("Hasta pronto!\n");
                flagContinuar = 'n';
                break;
            default:
                printf("ERROR: Opcion invalida\n\n");
                break;
        }
    }

    return 0;
}
