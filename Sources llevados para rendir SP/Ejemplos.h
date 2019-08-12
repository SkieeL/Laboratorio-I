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
 * Lee la información del archivo y en caso de que no exista, lo crea.
 * @param Puntero de punteros que apunta al puntero del contenedor de películas.
 * @param Puntero que apunta al tamaño actual del array.
 * @param Puntero de punteros que apunta al puntero del archivo binario a leer o crear.
 * @return Retorna 1 o 0 dependiendo si pudo leer y/o crear el archivo o no.
 */
int lecturaCreacionArchivo(eMovie** peliculas, int* pMaxRegistros, FILE** archivo);

/**
 * Agrega una película al archivo binario.
 * @param Puntero de punteros que apunta al puntero del contenedor de películas.
 * @param Puntero que apunta al tamaño actual del array.
 * @param Puntero de punteros que apunta al puntero del archivo binario a escribir.
 * @return Retorna 1 o 0 dependiendo si pudo agregar o no la pelicula.
 */
int agregarPelicula(eMovie** pelicula, int* pMaxRegistros, FILE** archivo);

/**
 * Solicita el ingreso del título de la pelicula.
 * @param Puntero de punteros que apunta al puntero del contenedor de películas.
 * @param Índice donde se guarda el título ingresado.
 * @param Si el valor no es 0 agrega la palabra "nuevo" a la solicitud del ingreso de datos.
 */
void pedirTitulo(eMovie** pelicula, int indexLibre, int modificar);

/**
 * Solicita el ingreso de la duración de la pelicula.
 * @param Puntero de punteros que apunta al puntero del contenedor de películas.
 * @param Índice donde se guarda la duración ingresada.
 * @param Si el valor no es 0 agrega la palabra "nueva" a la solicitud del ingreso de datos.
 */
void pedirDuracion(eMovie** pelicula, int indexLibre, int modificar);

/**
 * Elimina una pelicula del archivo binario.
 * @param Puntero de punteros que apunta al puntero del contenedor de películas.
 * @param Tamaño actual del array.
 * @param Puntero de punteros que apunta al puntero del archivo binario a escribir.
 * @return Retorna 1 o 0 dependiendo si pudo eliminar o no la pelicula.
 */
int eliminarPelicula(eMovie** pelicula, int maxRegistros, FILE** archivo);

/**
 * Modifica una pelicula del archivo binario.
 * @param Puntero de punteros que apunta al puntero del contenedor de películas.
 * @param Tamaño actual del array.
 * @param Puntero de punteros que apunta al puntero del archivo binario a escribir.
 * @return Retorna 1 o 0 dependiendo si pudo modificar o no la pelicula.
 */
int modificarPelicula(eMovie** pelicula, int maxRegistros, FILE** archivo);
