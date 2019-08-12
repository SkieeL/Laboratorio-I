struct {
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];
} typedef S_LogEntry;

struct {
    int id;
    char name[33];
    char email[65];
} typedef S_Service;

struct {
    int idServicio;
    int cantErrores;
} typedef S_Errores;

/**
 * Carga el archivo de logs en memoria.
 * @param ArrayList de logs.
 * @param Puntero al contador de fallos de gravedad menor a 3.
 * @param Puntero al contador de fallos de gravedad igual a 4.
 * @param Puntero al contador de fallos de gravedad entre 5 y 8.
 * @param Puntero al contador de fallos de gravedad mayor a 8.
 */
void cargaLogs(ArrayList* pListLog, ArrayList* pListErr, int* pMenosDe3, int* pFallos4, int* pEntre5y8, int* pMasDe8);

/**
 * Carga el archivo de servicios en memoria.
 * @param ArrayList de servicios.
 */
void cargaServicios(ArrayList* pList);

/**
 * Evalua la gravedad de los errores y los guarda en los archivos correspondientes, los muestra en pantalla o los ignora.
 * @param ArrayList de logs.
 * @param ArrayList de servicios.
 */
void evaluarGravedad(ArrayList* pListLog, ArrayList* pListSer);

/**
 * Escribe el archivo de warnings.
 * @param Puntero al elemento de servicios.
 * @param Puntero al elemento de logs.
 */
void escribirWarnings(S_Service* pElementSer, S_LogEntry* pElementLog);

/**
 * Escribe el archivo de errores.
 * @param Puntero al elemento de servicios.
 * @param Puntero al elemento de logs.
 */
void escribirErrores(S_Service* pElementSer, S_LogEntry* pElementLog);

/**
 * Muestra la cantidad de errores según la gravedad.
 * @param Contador de fallos de gravedad menor a 3.
 * @param Contador de fallos de gravedad igual a 4.
 * @param Contador de fallos de gravedad entre 5 y 8.
 * @param Contador de fallos de gravedad mayor a 8.
 */
void mostrarEstadisticas(int menosDe3, int fallos4, int entre5y8, int masDe8);
