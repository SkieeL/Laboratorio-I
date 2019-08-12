char validarChar(char datoChar, char necesario1, char necesario2) {
    datoChar = toupper(datoChar);
    necesario = toupper(necesario1);
    necesario2 = toupper(necesario2);

    while (datoChar != necesario1 && datoChar != necesario2) {
        printf("Dato invalido. Reingrese: ");
        datoChar = getch();
        datoChar = toupper(datoChar);
    }

    return datoChar;
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

int obtenerEspacioLibre(ePersona listaPersonas[], int len) {
    int i, indexLibre = -1;

    for (i = 0; i < len; i++) {
        if (listaPersonas[i].estadoPer == 0) {
            indexLibre = i;
            break;
        }
    }

    return indexLibre;
}

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

int calcularMayor(int num1, int num2, int num3) {

    if (num1 >= num2 && num1 >= num3) {
        return num1;
    }
    else if (num2 >= num3 && num2 >= num1) {
        return num2;
    }

    return num3;
}
