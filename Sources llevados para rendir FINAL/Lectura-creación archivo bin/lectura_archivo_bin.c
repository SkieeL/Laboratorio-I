#define RUTA_ARCHIVO "archivito.dat" // Poner nombre acorde al archivo.

/**
 * Lee la información de un archivo binario, en caso de que dicho archivo no exista, lo crea.
 * @param ArrayList donde se va a guardar la información leída.
 * @param Archivo a leer.
 * @param Ruta del archivo a leer.
 * @return Retorna 1 en caso de exito, 0 en caso de error.
 */
int lecturaCreacionArchivoBin(ArrayList* pList, FILE* archivo, char ruta[]);

int main() {
    ArrayList* registroEgresos = al_newArrayList(); // Cambiar "registroEgresos".

    FILE* archivoEgresos = fopen(RUTA_ARCHIVO, "rb"); // Cambiar "archivoEgresos".

    if (registroEgresos == NULL) { // Cambiar "registroEgresos".
        printf("ERROR: No se pudo asignar espacio en memoria");
        exit(0);
    }
    else if (lecturaCreacionArchivoBin(registroEgresos, archivoEgresos, RUTA_ARCHIVO_EGRESOS) == 0) {
        exit(0);
    }
}

int lecturaCreacionArchivoBin(ArrayList* pList, FILE* archivo, char ruta[]) {
    if (archivo == NULL) {
        archivo = fopen(ruta, "wb");

        if (archivo == NULL) {
            printf("ERROR: No se pudo crear el archivo binario\n");
            return 0;
        }
    }
    else {
        rewind(archivo);

        while (!feof(archivo)) {
            eAgente* pElement = (eAgente*) malloc(sizeof(eAgente)); // Cambiar "eAgente".

            if (pElement == NULL) {
                printf("ERROR: No se pudo asignar espacio en memoria\n");
                return 0;
            }

            if (fread(pElement, sizeof(eAgente), 1, archivo) == 1) { // Cambiar "eAgente".
                pList->add(pList, pElement);
            }
        }
    }

    fclose(archivo);

    return 1;
}
