#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "funciones.h"

int main() {
    int opcion;
    char flagContinue = 's';
    int *pMenosDe3;
    int *pFallos4;
    int *pEntre5y8;
    int *pMasDe8;
    int menosDe3 = 0, fallos4 = 0, entre5y8 = 0, masDe8 = 0;
    pMenosDe3 = &menosDe3;
    pFallos4 = &fallos4;
    pEntre5y8 = &entre5y8;
    pMasDe8 = &masDe8;

    ArrayList* LogsEntry = al_newArrayList();
    ArrayList* Services = al_newArrayList();
    ArrayList* Errores = al_newArrayList();

    if (LogsEntry == NULL || Services == NULL) {
        printf("ERROR: No se pudo asignar espacio en memoria");
        exit(0);
    }

    printf("Bienvenido/a!\n\n");

    while (flagContinue == 's') {

        printf("1. Leer log\n");
        printf("2. Procesar informacion\n");
        printf("3. Mostrar estadisticas\n");
        printf("4. Salir\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch (opcion)
        {
            case 1:
                cargaLogs(LogsEntry, Errores, pMenosDe3, pFallos4, pEntre5y8, pMasDe8);
                cargaServicios(Services);
                break;
            case 2:
                evaluarGravedad(LogsEntry, Services);
                break;
            case 3:
                mostrarEstadisticas(menosDe3, fallos4, entre5y8, masDe8);
                break;
            case 4:
                printf("Hasta pronto!\n");
                flagContinue = 'n';
                break;
            default:
                printf("ERROR: Opcion invalida\n\n");
                break;
        }
    }

    return 0;
}
