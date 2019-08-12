

int cargarElemento(ArrayList* pList, eAgente* pElementAux, FILE* archivo, char ruta[]) { // Cambiar "eAgente".
    eAgente* pElement = (eAgente*) malloc(sizeof(eAgente)); // Cambiar "eAgente".

    if (pElement == NULL) {
        printf("ERROR: No se pudo generar espacio en memoria");
        return 0;
    }

    pElement = pedirString(pElement, 0); // Cambiar "pedirString".
    pElement->dni = pedirDNI(); // Cambiar "dni" y "pedirDNI".
    pElement->estado = 0; // Ver si es necesario cargar un estado.

    pList->add(pList, pElement);

    if (cargaArchivo(pList, pElementAux, archivo, ruta) == 0) {
        return 0;
    }

    printf("Elemento %s cargado exitosamente!\n\n", pElement->nombre); // Cambiar leyenda y atributo "nombre".

    return 1;
}

int modificarElemento(ArrayList* pList, eAgente* pElementAux, FILE* archivo, char ruta[]) { // Cambiar "eAgente".
    if (pList->isEmpty(pList) == 0) {
        listarArrayList(pList, pElementAux);
        printf("\n");

        int ID, i, flagFallo = 1;
        ID = pedirDNI(); // Cambiar nombre de la función "pedirDNI".

        for (i = 0; i < pList->len(pList); i++) {
            pElementAux = (eAgente*) pList->get(pList, i); // Cambiar "eAgente".

            if (ID == pElementAux->dni) { // Cambiar atributo "dni".
                char auxNombre[50]; // Cambiar "auxNombre".

                flagFallo = 0;

                strcpy(auxNombre, pElementAux->nombre); // Cambiar "auxNombre" y atributo "nombre".

                pElementAux = pedirNombre(pElementAux, 1); // Cambiar "pedirNombre".

                pList->set(pList, i, pElementAux);

                if (cargaArchivo(pList, pElementAux, archivo, ruta) == 0)
                    return 0;

                printf("Elemento %d modificado!\n", pElementAux->dni); // Cambiar leyenda y "dni".
                printf("Nombre: %s -> %s\n\n", auxNombre, pElementAux->nombre); // Cambiar leyenda, "auxNombre" y "nombre".
            }
        }

        if (flagFallo) {
            system("cls");
            printf("El elemento indicado no se encuentra cargado en el sistema\n\n"); // Cambiar leyenda.
        }
    }
    else {
        system("cls");
        printf("No hay elementos cargados en el sistema\n\n"); // Cambiar leyenda.
    }

    return 1;
}

int eliminarElemento(ArrayList* pList, eAgente* pElementAux, FILE* archivo, char ruta[]) { // Cambiar nombre de la función "eliminarAgente" y "eAgente".
    if (pList->isEmpty(pList) == 0) {
        listarArrayList(pList, pElementAux);
        printf("\n");

        int ID, i, flagFallo = 1;
        ID = pedirDNI(); // Cambiar nombre de la función "pedirDNI".

        for (i = 0; i < pList->len(pList); i++) {
            pElementAux = (eAgente*) pList->get(pList, i); // Cambiar "eAgente".

            if (ID == pElementAux->dni) { // Cambiar atributo "dni".
                flagFallo = 0;

                pElementAux = pList->pop(pList, i);

                if (cargaArchivo(pList, pElementAux, archivo, ruta) == 0)
                    return 0;

                printf("Elemento %s eliminado!\n\n", pElementAux->nombre);// Cambiar leyenda y "nombre".
            }
        }

        if (flagFallo) {
            system("cls");
            printf("El elemento indicado no se encuentra cargado en el sistema\n\n"); // Cambiar leyenda.
        }
    }
    else {
        system("cls");
        printf("No hay elementos cargados en el sistema\n\n"); // Cambiar leyenda.
    }

    return 1;
}

int listarArrayList(ArrayList* pList, eAgente* pElementAux) { // Cambiar "eAgente".
    int i;

    for (i = 0; i < pList->len(pList); i++) {
        pElementAux = (eAgente*) pList->get(pList, i); // Cambiar "eAgente".
        printf("%d. %d\t%s\n", i+1, pElementAux->dni, pElementAux->nombre); // Cambiar toda la línea según datos a mostrar.
    }

    if (pList->len(pList) > 0)
        return 1;

    return 0;
}

eAgente* pedirNombre(eAgente* pElement, int nuevo) { // Cambiar nombre de la función "pedirNombre" y "eAgente".
    char buffer[1024];

    printf("Ingrese el %snombre del agente: ", nuevo ? "nuevo " : ""); // Cambiar leyenda.
    fflush(stdin);
    gets(buffer);

    while (!validarString(buffer)) {
        system("cls");
        printf("Nombre invalido, reingrese: "); // Cambiar leyenda.
        fflush(stdin);
        gets(buffer);
    }

    strcpy(pElement->nombre, buffer); // Cambiar atributo "nombre".

    system("cls");

    return pElement;
}

int validarString(char string[]) {
    if (strcmp(string, "") == 0)
        return 0;

    int len, i;
    len = strlen(string);

    for (i = 0; i < len; i++) {
        if (string[i] != ' ')
            return 1;
    }

    return 0;
}

int pedirDNI() { // Cambiar nombre de la función "pedirDNI".
    char buffer[1024];
    int num;

    printf("Ingrese el DNI del agente: "); // Cambiar leyenda.
    fflush(stdin);
    gets(buffer);
    num = atoi(buffer);

    while (!validarRangoEntero(num, 1000000, 100000000) || !validarInt(buffer)) { // Cambiar rango de validación.
        system("cls");
        printf("DNI invalido, reingrese: "); // Cambiar leyenda.
        fflush(stdin);
        gets(buffer);
        num = atoi(buffer);
    }

    system("cls");

    return num;
}

int validarRangoEntero(int num, int min, int max) {
    if (num < min || num > max)
        return 0;

    return 1;
}

int validarInt(char numero[]) {
    int len, i;
    len = strlen(numero);

    for (i = 0; i < len; i++) {
        if (!isdigit(numero[i]))
            return 0;
    }

    return 1;
}
