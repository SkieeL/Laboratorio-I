/**
 * Valida un char entre dos tipos de valores char.
 * @param Char a validar.
 * @param Primer tipo de dato char posible.
 * @param Segundo tipo de dato char posible.
 * @return Char validado y pasado a may�scula.
 */
char validarChar(char datoChar, char necesario1, char necesario2);

/**
 * Valida si el string est� vac�o o si contiene s�lo espacios.
 * @param String a validar.
 * @return Si no est� vac�o ni contiene s�lo espacios retorna 1, de lo contrario 0.
 */
int validarString(char cadena[]);

/**
 * Valida si es un n�mero entero.
 * @param N�mero a validar.
 * @return Si es un n�mero devuelve 1, sino 0.
 */
int validarInt(char numero[]);

/**
 * Valida un n�mero entero entre un rango de n�meros.
 * @param Entero a validar.
 * @param N�mero m�nimo.
 * @param N�mero m�ximo.
 * @return Entero validado.
 */
int validarRangoEntero(int numero, int min, int max);

/**
 * Valida un n�mero float entre un rango de n�meros.
 * @param Float a validar.
 * @param N�mero m�nimo.
 * @param N�mero M�ximo.
 * @return Float validado.
 */
float validarRangoFloat(float numero, float min, float max);

/**
 * Calcula el n�mero m�s alto entre los n�meros ingresados.
 * @param Primer n�mero a comparar.
 * @param Segundo n�mero a comparar.
 * @param Tercer n�mero a comparar.
 * @return N�mero mayor.
 */
int calcularMayor(int num1, int num2, int num3);
