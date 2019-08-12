
/* Cantidad de registros que puede almacenar la estructura */
#define MAX_REGISTROS 20

/* Ejemplo de estructura */
typedef struct {
    char nombrePer[50];
    int edadPer;
    int dniPer;
    int estadoPer;

} ePersona;

/* Ejemplo de contenedor de estructura */
ePersona contenedorPersonas[MAX_REGISTROS];

/**
 * Valida un char entre dos tipos de valores char.
 * @param Char a validar.
 * @param Primer tipo de dato char posible.
 * @param Segundo tipo de dato char posible.
 * @return Char validado y pasado a mayúscula.
 */
char validarChar(char datoChar, char necesario1, char necesario2);

/**
 * Valida un número entero entre un rango de números.
 * @param Entero a validar.
 * @param Número mínimo.
 * @param Número máximo.
 * @return Entero validado.
 */
int validarRangoEntero(int numero, int min, int max);

/**
 * Valida un número float entre un rango de números.
 * @param Float a validar.
 * @param Número mínimo.
 * @param Número Máximo.
 * @return Float validado.
 */
float validarRangoFloat(float numero, float min, float max);

/**
 * Obtiene el primer índice libre del array.
 * @param Array a buscar espacio libre.
 * @param Tamaño del array.
 * @return El primer indice disponible, si no encuentra retorna -1.
 */
int obtenerEspacioLibre(ePersona[] listaPersonas, int len);

/**
 * Obtiene el índice que coincide con el DNI pasado por parametro.
 * @param Array en donde busca el DNI.
 * @param Tamaño del array.
 * @param DNI a ser buscado en el array.
 * @return El indice en donde se encuentra el elemento que coincide con el parametro DNI, si no lo encuentra retorna -1.
 */
int buscarPorDNI(ePersona[] listaPersonas, int len, int DNI);

/**
 * Agrega una persona a la lista.
 * @param Array de personas.
 * @param Tamaño del array.
 */
void agregarPersona(ePersona[] listaPersonas, int len);

/**
 * Solicita el ingreso del nombre de la persona.
 * @param Array de personas.
 * @param Índice donde se guarda el nombre ingresado.
 */
void pedirNombre(ePersona[] listaPersonas, int index);

/**
 * Solicita el ingreso de la edad de la persona.
 * @return Devuelve la edad ingresada.
 */
int pedirEdad();

/**
 * Solicita el ingreso del DNI de la persona.
 * @param Array de personas.
 * @param Tamaño del array.
 * @param Flag, si se solicita el DNI para hacer un alta setear en 1, para búsqueda por DNI setear en 0.
 * @return Devuelve el DNI ingresado.
 */
int pedirDNI(ePersona[] listaPersonas, int len, int flagAlta);

/**
 * Elimina una persona de la lista
 * @param Array de personas.
 * @param Tamaño del array.
 */
void eliminarPersona(ePersona[] listaPersonas, int len);

/**
 * Verifica si el DNI ingresado ya se encuentra cargado.
 * @param Array de personas.
 * @param Tamaño del array.
 * @param DNI a verificar.
 * @return DNI no ingresado = 0, DNI ya ingresado = 1.
 */
int DNIYaIngresado(ePersona[] listaPersonas, int len, int DNI);

/**
 * Muestra la lista de personas ordenadas alfabéticamente.
 * @param Array de personas.
 * @param Tamaño del array.
 */
void ordenarPersonas(ePersona[] listaPersonas, int len);

/**
 * Muestra un gráfico de cantidad de personas separado por rangos de edad.
 * @param Array de personas.
 * @param Tamaño del array.
 */
void mostrarGrafico(ePersona[] listaPersonas, int len);

/**
 * Calcula el número más alto entre los números ingresados.
 * @param Primer número a comparar.
 * @param Segundo número a comparar.
 * @param Tercer número a comparar.
 * @return Número mayor.
 */
int calcularMayor(int num1, int num2, int num3);
