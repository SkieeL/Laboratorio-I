#include "ArrayList.h"

struct {
    int turno;
    int dni;
} typedef eCliente;

/**
 * Agregar un cliente con caracter Urgente.
 * @param Puntero al ArrayList.
 */
void agregarCliente(ArrayList* pList, int caracter);

/**
 * Solicita el DNI del cliente y lo carga en el elemento del ArrayList.
 * @param Puntero al elemento.
 * @return Retorna el puntero al elemento.
 */
eCliente* pedirDNI(eCliente* pElement);

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
 * @return Si est� dentro del rango retorna 1, sino 0.
 */
int validarRangoEntero(int numero, int min, int max);

/**
 * Muestra el pr�ximo cliente y lo atiende.
 * @param Puntaro al ArrayList de clientes no atendidos.
 * @param Puntaro al ArrayList de clientes atendidos.
 * @param Caracter del cliente, 1 urgente, 0 regular.
 */
void proximoCliente(ArrayList* noAtendidos, ArrayList* atendidos, int caracter);

/**
 * Lista los clientes con caracter urgente.
 * @param Puntero al ArrayList de clientes.
 * @param Caracter del cliente, 1 urgente, 0 regular.
 */
void mostrarClientes(ArrayList* clientes, int caracter);

/**
 * Compara los clientes por DNI.
 * @param Puntero al primer cliente.
 * @param Puntero al segundo cliente.
 * @return 1 si A es mayor a B, -1 si B es mayor a A, 0 si son iguales.
 */
int comparaClienteDNI(eCliente* pClienteA, eCliente* pClienteB);
