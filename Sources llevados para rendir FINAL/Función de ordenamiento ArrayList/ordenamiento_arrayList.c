/**
 * Compara el nombre de dos agentes, en caso de ser iguales, compara los apellidos.
 * @param Puntero a la estructura del primer agente a comparar.
 * @param Puntero a la estructura del segundo agente a comparar.
 * @return Retorna 1 en caso de que el primer agente tenga un nombre mayor que el segundo, -1 si es menor y 0 si poseen el mismo nombre y apellido.
 */
int comparaAgenteNoAp(eAgente* Agente1, eAgente* Agente2);

// Llamada a la función.
pList->sort(pList, comparaAgenteNoAp, 1); // El 1 quiere decir ascendente.

// Ordena de forma ascendente por nombre, en caso de igualdad, por apellido.
int comparaAgenteNoAp(eAgente* Agente1, eAgente* Agente2) {
    if (strcmp(Agente1->nombre, Agente2->nombre) > 0)
        return 1;
    else if (strcmp(Agente1->nombre, Agente2->nombre) < 0)
        return -1;
    else {
        if (strcmp(Agente1->apellido, Agente2->apellido) > 0)
            return 1;
        else if (strcmp(Agente1->apellido, Agente2->apellido) < 0)
            return -1;
    }

    return 0;
}
