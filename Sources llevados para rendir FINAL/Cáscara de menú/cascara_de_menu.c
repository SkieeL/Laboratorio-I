#include "ArrayList.h"
#include "funciones.h"

int main() {
    int opcion;
    char flagContinue = 's';

    printf("Bienvenido/a!\n\n");

    while (flagContinue == 's') {

        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificacion\n");
        printf("4. Registro X\n");
        printf("5. Registro Y\n\n");
        printf("6. Salir\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch (opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
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
