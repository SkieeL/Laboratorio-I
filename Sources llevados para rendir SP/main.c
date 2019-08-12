#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "Employee.h"
#include "SkieL.h"
#include "funciones.h"

int main()
{
    int opcion, i;
    char flagContinuar = 's';
    ArrayList* listaEmpleados = al_newArrayList();

    printf("Bienvenido/a!\n\n");

    while (flagContinuar == 's') {

        printf("1. Agregar\n");
        printf("2. Eliminar\n");
        printf("3. Modificar\n");
        printf("4. Ordenar\n");
        printf("5. Salir\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch (opcion)
        {
            case 1:
                agregarEmpleado(listaEmpleados);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                listaEmpleados->sort(listaEmpleados, comparaSalarioEmployee, 0);
                for (i = 0; i < listaEmpleados->len(listaEmpleados); i++) {
                    eEmployee* empleado = listaEmpleados->pElements[i];
                    printf("Nombre: %s - Edad: %d\n", empleado->name, empleado->sector);
                }

                break;
            case 5:
                printf("Hasta pronto!\n");
                flagContinuar = 'n';
                break;
            default:
                printf("ERROR: Opcion invalida");
                break;

        }
    }

    return 0;
}
