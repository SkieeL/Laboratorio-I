int i, j;
ePersona auxPersona;

// Ordena las personas alfabéticamente.
for (i = 0; i < len-1; i++)
{
    for (j = i+1; j < len; j++)
    {
        if (strcmp(personas[i].nombrePer, personas[j].nombrePer) > 0) {
            auxPersona = personas[i];
            personas[i] = personas[j];
            personas[j] = auxPersona;
        }
        else if (strcmp(personas[i].nombrePer, personas[j].nombrePer) == 0) {
            if (strcmp(personas[i].apellidoPer, personas[j].apellidoPer) > 0) {
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;
            }
        }
    }
}
