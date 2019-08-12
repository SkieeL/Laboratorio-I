#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo, categoria;
    char descripcion[20];
    float precio;
} eProducto;

int main()
{
    char codigo[500], descripcion[500], categoria[500], precio[500];
    eProducto producto;

    FILE *pFile;
    pFile = fopen("productos.csv", "r");

    // Hace una lectura falsa, sirve para evitar almacenar la información de las cabeceras (títulos)
    fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", codigo, descripcion, categoria, precio);

    while(!feof(pFile)) {
       fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", codigo, descripcion, categoria, precio);
       producto.codigo = atoi(codigo);
       producto.categoria = atoi(categoria);
       strcpy(producto.descripcion, descripcion);
       producto.precio = atof(precio);
       printf("%d - %s - %d - %.2f\n", producto.codigo, producto.descripcion, producto.categoria, producto.precio);
   }

   fclose(pFile);

   return 0;
}
