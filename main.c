#include <stdio.h>
#include "funciones.h"

int main() {
    char productos[10][40];
    float precios[10];
    int cantidad[10];
    char productoBuscar[40]; 
    int repetir;
    

    inventario(productos, precios, cantidad);
    for (int i = 0; i < 10; i++) {
        imprimirProductos(productos, precios, cantidad, i);
    }  
    calculos(productos, precios, cantidad); 


  do
{
    buscarProducto(productos, precios, cantidad, productoBuscar); 
    do
    {
        printf("\n ");
        printf("Si quiere buscar un nuevo producto escriba 1, si quiere salir del programa escriba 0: ");
        scanf("%d", &repetir);
        if (repetir != 0 && repetir != 1) {
            printf("El dato ingresado es incorrecto, ingrese 1 o 0.\n");
        }
    } while (repetir != 0 && repetir != 1); 
} while (repetir == 1); 
        
     

    return 0;
}