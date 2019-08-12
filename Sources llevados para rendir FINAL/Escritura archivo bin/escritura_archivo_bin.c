/**
 * Carga información en un archivo binario.
 * @param ArrayList de donde se va a extraer la información a guardar.
 * @param Puntero auxiliar a estructura.
 * @param Archivo a cargar información.
 * @param Ruta del archivo donde se va a cargar la información.
 * @return Retorna 1 en caso de exito, 0 en caso de error.
 */
int cargaArchivo(ArrayList* pList, eAgente* pElement, FILE* archivo, char ruta[]); // Cambiar "eAgente".

// Esto debe ser llamado desde la función donde se actualizan los datos.
eAgente* pElementAux = (eAgente*) malloc(sizeof(eAgente)); // Cambiar "eAgente".
if (cargaArchivo(agentesCargados, pElementAux, archivo, ruta) == 0) { // Cambiar "agentesCargados" por el ArrayList, "archivo" por el archivo a cargar y ruta por la ruta del archivo.
    printf("ERROR: No se pudieron guardar los datos");
    exit(0);
}

int cargaArchivo(ArrayList* pList, eAgente* pElement, FILE* archivo, char ruta[]) {
    FILE* auxArchivo = fopen(ruta, "wb");

    if (auxArchivo == NULL) {
        printf("ERROR: No se pudo abrir el archivo binario\n");
        return 0;
    }

    archivo = auxArchivo;
    int i;

    for (i = 0; i < pList->len(pList); i++) {
        pElement = (eAgente*) pList->get(pList, i); // Cambiar "eAgente".
        fwrite(pElement, sizeof(eAgente), 1, archivo); // Cambiar "eAgente".
    }

    fclose(archivo);

    return 1;
}
