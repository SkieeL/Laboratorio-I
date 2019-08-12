/**
 * Valida un char entre dos tipos de valores char.
 * @param Char a validar.
 * @param Primer tipo de dato char posible.
 * @param Segundo tipo de dato char posible.
 * @return Char validado y pasado a mayúscula.
 */
char validarChar(char datoChar, char necesario1, char necesario2);

/**
 * Valida si el string está vacío o si contiene sólo espacios.
 * @param String a validar.
 * @return Si no está vacío ni contiene sólo espacios retorna 1, de lo contrario 0.
 */
int validarString(char cadena[]);

/**
 * Valida si es un número entero.
 * @param Número a validar.
 * @return Si es un número devuelve 1, sino 0.
 */
int validarInt(char numero[]);

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
 * Calcula el número más alto entre los números ingresados.
 * @param Primer número a comparar.
 * @param Segundo número a comparar.
 * @param Tercer número a comparar.
 * @return Número mayor.
 */
int calcularMayor(int num1, int num2, int num3);
