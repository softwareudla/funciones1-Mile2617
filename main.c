#include <stdio.h>
#include "funciones.h"


int main() {
    char nombproducto[10][20];
    float precios[10];

    inventario(nombproducto, precios);
    calculos(nombproducto, precios);
    buscarProducto(nombproducto, precios);


    return 0;
}