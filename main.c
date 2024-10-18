#include <stdio.h>
#include <conio.h>
#include "funciones.h"


int main() {
    char nombproducto[10][20];
    float precios[10];

    // Llamar a las funciones para ejecutar el flujo del programa
    inventario(nombproducto, precios);
    calculos(nombproducto, precios);
    buscarproducto(nombproducto, precios);

    getch();
    return 0;
}
