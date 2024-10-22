#include <stdio.h>
#include "funciones.h"

int main() {
    char productos[10][40];
    float precios[10];
    int cantidad[10];
    char productoBuscar[40]; 

    inventario(productos, precios, cantidad);  
    calculos(productos, precios, cantidad); 

    for (int i = 0; i < 10; i++) {
        imprimirProductos(productos, precios, cantidad, i);
    }


    buscarProducto(productos, precios, cantidad, productoBuscar);  

    return 0;
}