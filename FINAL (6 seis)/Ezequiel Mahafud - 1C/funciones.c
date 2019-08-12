#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "funciones.h"

void cargaLogs(ArrayList* pListLog, ArrayList* pListErr, int* pMenosDe3, int* pFallos4, int* pEntre5y8, int* pMasDe8) {
    char date[500], time[500], serviceId[500], gravedad[500], msg[500];

    FILE* pFile;
    pFile = fopen("log.txt", "r");

    if (pFile == NULL) {
        printf("ERROR: No se pudo abrir el archivo");
        exit(0);
    }

    while(!feof(pFile)) {
        S_LogEntry* pElement = (S_LogEntry*) malloc(sizeof(S_LogEntry));
        S_Errores* pElementErr = (S_Errores*) malloc(sizeof(S_Errores));

        if (pElement == NULL || pElementErr == NULL) {
            printf("ERROR: No se pudo asignar espacio en memoria");
            exit(0);
        }

        fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", date, time, serviceId, gravedad, msg);
        strcpy(pElement->date, date);
        strcpy(pElement->time, time);
        pElement->serviceId = atoi(serviceId);
        pElement->gravedad = atoi(gravedad);
        strcpy(pElement->msg, msg);
        pListLog->add(pListLog, pElement);

        int i, flag = 1;

        for (i = 0; i < pListErr->len(pListErr); i++) {
            pElementErr = pListErr->get(pListErr, i);

            if (pElementErr->idServicio == pElement->serviceId) {
                pElementErr->cantErrores++;
                flag = 0;
            }
        }

        if (flag) {
            pElementErr->idServicio = pElement->serviceId;
            pElementErr->cantErrores = 1;
            pListErr->add(pListErr, pElementErr);
        }

        if (pElement->gravedad <= 3)
            *pMenosDe3 += 1;
        else if (pElement->gravedad == 4)
            *pFallos4 += 1;
        else if (pElement->gravedad >= 5 && pElement->gravedad <= 8)
            *pEntre5y8 += 1;
        else if (pElement->gravedad > 8)
            *pMasDe8 += 1;
   }

   printf("Archivo de logs cargado exitosamente!\n");

   fclose(pFile);
}

void cargaServicios(ArrayList* pList) {
    char id[500], name[500], email[500];

    FILE *pFile;
    pFile = fopen("services.txt", "r");

    if (pFile == NULL) {
        printf("ERROR: No se pudo abrir el archivo");
        exit(0);
    }

    while(!feof(pFile)) {
        S_Service* pElement = (S_Service*) malloc(sizeof(S_Service));

        if (pElement == NULL) {
            printf("ERROR: No se pudo asignar espacio en memoria");
            exit(0);
        }

        fscanf(pFile, "%[^;]; %[^;]; %[^\n]\n", id, name, email);
        pElement->id = atoi(id);
        strcpy(pElement->name, name);
        strcpy(pElement->email, email);
        pList->add(pList, pElement);
   }

   printf("Archivo de servicios cargado exitosamente!\n\n");

   fclose(pFile);
}

void evaluarGravedad(ArrayList* pListLog, ArrayList* pListSer) {
    int i, j;
    FILE* pFile;
    pFile = fopen("log.txt", "r");

    if (pFile == NULL) {
        printf("ERROR: No se pudo abrir el archivo de warnings");
        exit(0);
    }

    S_LogEntry* pElementLog = (S_LogEntry*) malloc(sizeof(S_LogEntry));
    S_Service* pElementSer = (S_Service*) malloc(sizeof(S_Service));

    if (pElementLog == NULL || pElementSer == NULL) {
        printf("ERROR: No se pudo generar espacio en memoria");
        exit(0);
    }

    for (i = 0; i < pListLog->len(pListLog); i++) {
        pElementLog = (S_LogEntry*) pListLog->get(pListLog, i);

        for (j = 0; j < pListSer->len(pListSer); j++) {
            pElementSer = (S_Service*) pListSer->get(pListSer, j);

            if (pElementLog->serviceId == pElementSer->id) {
                break;
            }
        }

        if(pElementLog->gravedad < 3) {
            continue;
        }
        else if (pElementLog->gravedad == 4 && pElementLog->serviceId != 45) {
            escribirWarnings(pElementSer, pElementLog);
        }
        else if (pElementLog->gravedad >= 5 && pElementLog->gravedad <= 8) {
            escribirErrores(pElementSer, pElementLog);
        }
        else if (pElementLog->gravedad > 8) {
            printf("%s\t%s\t%s\t%s\t%s\n", pElementLog->date, pElementLog->time, pElementSer->name, pElementLog->msg, pElementSer->email);
        }
    }

    printf("Informacion procesada correctamente!\n\n");
}

void escribirWarnings(S_Service* pElementSer, S_LogEntry* pElementLog) {
    FILE *pFile;

    pFile = fopen("warnings.txt", "a");

    if (pFile == NULL) {
        printf("ERROR: No se pudo abrir el archivo de warnings");
        exit(0);
    }

    fprintf(pFile, "%s;%s;%s;%s\n", pElementLog->date, pElementLog->time, pElementSer->name, pElementLog->msg);

    fclose(pFile);
}

void escribirErrores(S_Service* pElementSer, S_LogEntry* pElementLog) {
    FILE *pFile;

    pFile = fopen("errores.txt", "a");

    if (pFile == NULL) {
        printf("ERROR: No se pudo abrir el archivo de errores");
        exit(0);
    }

    fprintf(pFile, "%s;%s;%s;%s\n", pElementLog->date, pElementLog->time, pElementSer->name, pElementLog->msg);

    fclose(pFile);
}

void mostrarEstadisticas(int menosDe3, int fallos4, int entre5y8, int masDe8) {
    /*int i, name[50];
    S_Errores* auxErrores;

    for (i = 0; i < pList->len(pList); i++) {
        auxErrores = pList->get(pList, i);

        if
    }*/

    printf("Cantidad de fallos de gravedad menor a 3: %d\n", menosDe3);
    printf("Cantidad de fallos de gravedad igual a 4: %d\n", fallos4);
    printf("Cantidad de fallos de gravedad entre 5 y 8: %d\n", entre5y8);
    printf("Cantidad de fallos de gravedad mayor a 8: %d\n\n", masDe8);
}
