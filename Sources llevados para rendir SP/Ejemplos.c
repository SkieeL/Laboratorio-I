
int buscarPorDNI(ePersona listaPersonas[], int len, int DNI) {
    int i, indexDNI = -1;

    for (i = 0; i < len; i++) {
        if (listaPersonas[i].dniPer == DNI) {
            indexDNI = i;
            break;
        }
    }

    return indexDNI;
}

void agregarPersona(ePersona listaPersonas[], int len) {
    int indexLibre;

    indexLibre = obtenerEspacioLibre(listaPersonas, len);

    if (indexLibre == -1) {
        printf("ERROR: No se pueden cargar mas personas\n\n");
    }
    else {
        pedirNombre(listaPersonas, indexLibre);
        listaPersonas[indexLibre].edadPer = pedirEdad();
        listaPersonas[indexLibre].dniPer = pedirDNI(listaPersonas, len, 1);
        listaPersonas[indexLibre].estadoPer = 1;
        printf("Persona agregada exitosamente!\n\n");
    }
}

void pedirNombre(ePersona listaPersonas[], int index) {
    char buffer[1024];

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(buffer);

    strcpy(listaPersonas[index].nombrePer, buffer);

    system("cls");
}

int pedirEdad() {
    int edad;

    printf("Ingrese la edad: ");
    scanf("%d", &edad);

    while(!validarEdad(edad)) {
        system("cls");
        printf("Edad invalida, reingrese: ");
        scanf("%d", &edad);
    }

    system("cls");

    return edad;
}

int pedirDNI(ePersona listaPersonas[], int len, int flagAlta) {
    int DNI;

    printf("Ingrese el DNI: ");
    scanf("%d", &DNI);

    while (!validarDNI(DNI)) {
        system("cls");
        printf("DNI invalido, reingrese: ");
        scanf("%d", &DNI);
    }

    while (DNIIngresado(listaPersonas, len, DNI) && flagAlta) {
        system("cls");
        printf("El DNI ingresado ya se encuentra en nuestras bases de datos, reingrese: ");
        scanf("%d", &DNI);
    }

    system("cls");

    return DNI;
}

void eliminarPersona(ePersona listaPersonas[], int len) {
    int DNI, index;

    DNI = pedirDNI(listaPersonas, len, 0);
    index = buscarPorDNI(listaPersonas, len, DNI);

    if (index == -1 || listaPersonas[index].estadoPer == 0) {
        printf("ERROR: No se encontro ninguna persona asociada al DNI ingresado\n\n");
    }
    else {
        printf("La persona fue dada de baja exitosamente!\n\n");
        listaPersonas[index].estadoPer = 0;
    }
}

int DNIYaIngresado(ePersona listaPersonas[], int len, int DNI) {
    int i;

    for (i = 0; i < len; i++)
    {
        if (DNI == listaPersonas[i].dniPer && listaPersonas[i].estadoPer)
            return 1;
    }

    return 0;
}

void ordenarPersonas(ePersona listaPersonas[], int len) {
    int i, j, cantPersonas = 0;
    ePersona auxPersona;

    // Ordena las personas alfabéticamente.
    for (i = 0; i < len-1; i++)
    {
        for (j = i+1; j < len; j++)
        {
            if (strcmp(listaPersonas[i].nombrePer, listaPersonas[j].nombrePer) > 0) {
                auxPersona = listaPersonas[i];
                listaPersonas[i] = listaPersonas[j];
                listaPersonas[j] = auxPersona;
            }
            else if (strcmp(listaPersonas[i].nombrePer, listaPersonas[j].nombrePer) == 0) {
                auxPersona = listaPersonas[i];
                listaPersonas[i] = listaPersonas[j];
                listaPersonas[j] = auxPersona;
            }
        }
    }

    // Muestra las personas.
    printf("-----------------\n");
    printf("Personas cargadas\n");
    printf("-----------------\n\n");

    for (i = 0; i < len; i++)
    {
        if (listaPersonas[i].estadoPer == 1) {
            cantPersonas++;

            if (cantPersonas == 1) {
                printf("ID\tNombre\tEdad\tDNI\n");
            }

            printf("%d\t%s\t%d\t%d\n", cantPersonas, listaPersonas[i].nombrePer, listaPersonas[i].edadPer, listaPersonas[i].dniPer);
        }
    }

    if (!cantPersonas) {
        printf("No hay personas cargadas\n");
    }

    printf("\n");
}

void mostrarGrafico(ePersona listaPersonas[], int len) {
    int i, cantMenor18 = 0, cant19a35 = 0, cantMayor35 = 0, numeroMayor;

    for (i = 0; i < len; i++)
    {
        if (listaPersonas[i].estadoPer) {
            if (listaPersonas[i].edadPer < 18) {
                cantMenor18++;
            }
            else if (listaPersonas[i].edadPer > 18 && listaPersonas[i].edadPer < 36) {
                cant19a35++;
            }
            else if (listaPersonas[i].edadPer > 35) {
                cantMayor35++;
            }
        }
    }

    numeroMayor = calcularMayor(cantMenor18, cant19a35, cantMayor35);

    if (numeroMayor == 0) {
        printf("ERROR: No hay personas cargadas.\n\n");
    }
    else {
        for (i = 0; i < numeroMayor; i++)
        {
            printf("%d\t\t%s\t\t%s\t\t%s\n", numeroMayor-i, cantMenor18 >= (numeroMayor-i) ? "*" : "", cant19a35 >= (numeroMayor-i) ? "*" : "", cantMayor35 >= (numeroMayor-i) ? "*" : "");
        }

        printf("Cantidad\tMenor a 18\tEntre 19 y 35\tMayor a 35\n\n");
    }
}

int lecturaCreacionArchivo(eMovie** pelicula, int* pMaxRegistros, FILE** archivo) {

    if (*archivo == NULL) {
        *archivo = fopen(RUTA_ARCHIVO_BIN, "wb");

        if (*archivo == NULL) {
            printf("ERROR: No se pudo crear el archivo binario\n\n");
            return 0;
        }

        fwrite(*pelicula, sizeof(eMovie), *pMaxRegistros, *archivo);
    }
    else {
        int indexLibre, cantPeliculas = 0;

        rewind(*archivo);

        while (!feof(*archivo)) {
            indexLibre = obtenerEspacioLibre(pelicula, pMaxRegistros);

            if (indexLibre == -1) {
                return 0;
            }

            fread(*pelicula+indexLibre, sizeof(eMovie), 1, *archivo);

            cantPeliculas++;
        }

    }

    fclose(*archivo);

    return 1;
}

int agregarPelicula(eMovie** pelicula, int* pMaxRegistros, FILE** archivo) {

    int indexLibre;
    FILE* auxArchivo;

    indexLibre = obtenerEspacioLibre(pelicula, pMaxRegistros);

    if (indexLibre == -1) {
        return 0;
    }

    (*pelicula+indexLibre)->estado = 1;

    pedirTitulo(pelicula, indexLibre, 0);
    pedirGenero(pelicula, indexLibre, 0);
    pedirDuracion(pelicula, indexLibre, 0);
    pedirDescripcion(pelicula, indexLibre, 0);
    pedirPuntaje(pelicula, indexLibre, 0);
    pedirLink(pelicula, indexLibre, 0);

    auxArchivo = fopen(RUTA_ARCHIVO_BIN, "wb");

    if (auxArchivo == NULL) {
        printf("ERROR: No se pudo abrir el archivo binario\n\n");
        (*pelicula+indexLibre)->estado = 0;
        return 0;
    }

    *archivo = auxArchivo;

    fwrite(*pelicula, sizeof(eMovie), *pMaxRegistros, *archivo);

    fclose(*archivo);

    printf("Pelicula agredada exitosamente!\n\n");

    return 1;
}

void pedirTitulo(eMovie** pelicula, int indexLibre, int modificar) {

    char buffer[1024];

    printf("Ingrese el%s titulo: ", modificar ? " nuevo" : "");
    fflush(stdin);
    gets(buffer);

    while (!validarString(buffer)) {
        printf("Titulo invalido, reingrese: ");
        fflush(stdin);
        gets(buffer);
    }

    strcpy((*pelicula+indexLibre)->titulo, buffer);

    system("cls");
}

void pedirDuracion(eMovie** pelicula, int indexLibre, int modificar) {

    char buffer[1024];
    int num;

    printf("Ingrese la%s duracion (en minutos): ", modificar ? " nueva" : "");
    fflush(stdin);
    gets(buffer);
    num = atoi(buffer);

    while (!validarDuracion(num) || !validarInt(buffer)) {
        system("cls");
        printf("Duracion invalida, reingrese: ");
        fflush(stdin);
        gets(buffer);
        num = atoi(buffer);
    }

    (*pelicula+indexLibre)->duracion = num;

    system("cls");
}

int eliminarPelicula(eMovie** pelicula, int maxRegistros, FILE** archivo) {

    char buffer[1024];
    FILE* auxArchivo;
    int i, cantPeliculas = 0;

    printf("------------------\n");
    printf("Peliculas cargadas\n");
    printf("------------------\n\n");

    printf("Numero\tTitulo\n");

    for (i = 0; i < maxRegistros; i++) {
        if ((*pelicula+i)->estado == 1) {

            cantPeliculas++;
            printf("%d\t%s\n", cantPeliculas, (*pelicula+i)->titulo);
        }
    }

    if (!cantPeliculas) {
        system("cls");

        printf("No hay peliculas cargadas\n\n");
        return 0;
    }

    printf("\n");

    printf("Ingrese el titulo de la pelicula a eliminar: ");
    fflush(stdin);
    gets(buffer);

    for (i = 0; i < maxRegistros; i++) {
        if (strcmp((*pelicula+i)->titulo, buffer) == 0 && (*pelicula+i)->estado == 1) {
            (*pelicula+i)->estado = 0;

            auxArchivo = fopen(RUTA_ARCHIVO_BIN, "wb");

            if (auxArchivo == NULL) {
                printf("ERROR: No se pudo abrir el archivo");
                return 0;
            }

            *archivo = auxArchivo;

            fwrite(*pelicula, sizeof(eMovie), maxRegistros, *archivo);
            fclose(*archivo);

            system("cls");
            printf("Pelicula borrada exitosamente!\n\n");
            return 1;
        }
    }

    system("cls");
    printf("No se pudo encontrar la pelicula a eliminar\n\n");

    return 0;
}

int modificarPelicula(eMovie** pelicula, int maxRegistros, FILE** archivo) {

    char buffer[1024];
    FILE* auxArchivo;
    int i, cantPeliculas = 0;

    printf("------------------\n");
    printf("Peliculas cargadas\n");
    printf("------------------\n\n");

    printf("Numero\tTitulo\n");

    for (i = 0; i < maxRegistros; i++) {
        if ((*pelicula+i)->estado == 1) {

            cantPeliculas++;
            printf("%d\t%s\n", cantPeliculas, (*pelicula+i)->titulo);
        }
    }

    if (!cantPeliculas) {
        system("cls");

        printf("No hay peliculas cargadas\n\n");
        return 0;
    }

    printf("\n");

    printf("Ingrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(buffer);

    for (i = 0; i < maxRegistros; i++) {
        if (strcmp((*pelicula+i)->titulo, buffer) == 0 && (*pelicula+i)->estado == 1) {
            system("cls");
            pedirTitulo(pelicula, i, 1);
            pedirGenero(pelicula, i, 1);
            pedirDuracion(pelicula, i, 1);
            pedirDescripcion(pelicula, i, 1);
            pedirPuntaje(pelicula, i, 1);
            pedirLink(pelicula, i, 1);

            auxArchivo = fopen(RUTA_ARCHIVO_BIN, "wb");

            if (auxArchivo == NULL) {
                printf("ERROR: No se pudo abrir el archivo");
                return 0;
            }

            *archivo = auxArchivo;

            fwrite(*pelicula, sizeof(eMovie), maxRegistros, *archivo);
            fclose(*archivo);

            system("cls");
            printf("Pelicula modificada exitosamente!\n\n");
            return 1;
        }
    }

    system("cls");
    printf("No se pudo encontrar la pelicula a modificar\n\n");

    return 0;
}

