struct {
    char nombre[50];
    int dni;
    int estado;
} typedef eAgente;

/**
 * Carga un elemento en la lista.
 * @param ArrayList de elementos cargados.
 * @param Puntero auxiliar a estructura.
 * @param Archivo contenedor de estructuras.
 * @param Ruta del archivo contenedor de estructuras.
 * @return Retorna 1 en caso de exito, 0 en caso de error.
 */
int cargarElemento(ArrayList* pList, eAgente* pElementAux, FILE* archivo, char ruta[]);

/**
 * Modifica un elemento de la lista.
 * @param ArrayList de elementos cargados.
 * @param Puntero auxiliar a estructura.
 * @param Archivo contenedor de estructuras.
 * @param Ruta del archivo contenedor de estructuras.
 * @return Retorna 1 en caso de exito, 0 en caso de error.
 */
int modificarElemento(ArrayList* pList, eAgente* pElementAux, FILE* archivo, char ruta[]);

/**
 * Elimina un elemento de la lista.
 * @param ArrayList de elementos cargados.
 * @param Puntero auxiliar a estructura.
 * @param Archivo contenedor de estructuras.
 * @param Ruta del archivo contenedor de estructuras.
 * @return Retorna 1 en caso de exito, 0 en caso de error.
 */
int eliminarElemento(ArrayList* pList, eAgente* pElementAux, FILE* archivo, char ruta[]);

/**
 * Muestra el contenido de un ArrayList.
 * @param ArrayList a mostrar.
 * @param Puntero auxiliar a estructura.
 * @return Retorna 1 en caso de exito, 0 en caso de que el ArrayList se encuentre vac�o.
 */
int listarArrayList(ArrayList* pList, eAgente* pElement);

/**
 * Solicita el ingreso del nombre del agente.
 * @param Puntero al elemento donde se cargar� el nombre.
 * @param Flag: Si llega en 1 agrega la palabra "nuevo" a la leyenda que solicita el ingreso del nombre.
 * @return Retorna el puntero del agente con el nombre cargado.
 */
eAgente* pedirNombre(eAgente* pElement, int nuevo);

/**
 * Valida si un string llega vac�o o s�lo contiene espacios.
 * @param String a validar.
 * @return Retorna 1 en caso de �xito, 0 en caso de error.
 */
int validarString(char string[]);

/**
 * Solicita el ingreso de un DNI y valida que se ingresen s�lo n�meros en un rango de entre 1.000.000 y 100.000.000.
 * @return Retorna el DNI validado.
 */
int pedirDNI();

/**
 * Valida que un n�mero Int se encuentre entre determinado rango de n�meros.
 * @param N�mero a validar.
 * @param N�mero m�nimo.
 * @param N�mero m�ximo.
 * @return Retorna el n�mero validado.
 */
int validarRangoEntero(int num, int min, int max);

/**
 * Valida que una cadena contenga s�lo n�meros.
 * @param Cadena a validar.
 * @return Retorna 1 en caso de �xito, 0 en caso de error.
 */
int validarInt(char numero[]);
