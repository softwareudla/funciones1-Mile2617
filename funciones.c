#include <stdio.h>
#include <string.h>
#include "funciones.h"



void inventario(char productos[10][40], float precios[10], int cantidad[10]) {
    for (int i = 0; i < 10; i++) {
       printf("Ingrese el nombre del Producto %d: ", i+1);
        fflush(stdin);
        fgets(productos[i], 40, stdin);
        productos[i][strcspn(productos[i], "\n")] = 0; // se elimina el salto de linea

        
        do {
        printf("Ingrese el precio del Producto %d: ", i+1);
        scanf("%f", &precios[i]);
        if (precios[i] < 0) {
            printf("El precio no puede ser negativo\n");
        }
    } while (precios[i] < 0); 
    do {
        printf("Ingrese la cantidad del Producto %d: ", i+1);
        scanf("%d", &cantidad[i]);
        if (cantidad[i] < 1) {
            printf("La cantidad no puede ser negativa o nula\n");
        }
    } while (cantidad[i] < 1); 
       printf("\n");
    }

   
}

void imprimirProductos(char productos[10][40], float precios[10], int cantidad[10], int i) {
    printf(" %d\t\t Nombre: %s\t\t Precio unitario: %.2f\t\t Cantidad: %d\n", i + 1, productos[i], precios[i], cantidad[i]);
}



void calculos(char productos[10][40], float precios[10], int cantidad[10]) {
    float suma = 0, maxprecio = precios[0], minprecio = precios[0];
    int productoMax = 0, productoMin = 0;

    for (int i = 0; i < 10; i++) {
        float valorTotalProducto = precios[i] * cantidad[i];
      suma += valorTotalProducto;
        if (precios[i] > maxprecio) {
            maxprecio = precios[i];
            productoMax = i;
        }
        if (precios[i] < minprecio) {
            minprecio = precios[i];
            productoMin = i;
        }
    }

    printf("\nPrecio maximo del Inventario es: %.2f que le corresponde al producto: %s, teniendo en cuenta el precio unitario del producto\n", maxprecio, productos[productoMax]);
    printf("Precio minimo del Inventario es: %.2f que le corresponde al producto: %s, teniendo en cuenta el precio unitario del producto\n", minprecio, productos[productoMin]);
    printf("Total del inventario: %.2f\n", suma);
    printf("El promedio del Inventario es: %.2f\n", suma / 10);
}

void buscarProducto(char productos[10][40], float precios[10], int cantidad[10], char productoBuscar[40]) {
    int noencontrado = 0;
    printf("\nIngrese el nombre del producto que busca: ");
    fflush(stdin);
    fgets(productoBuscar, 40, stdin);
     productoBuscar[strcspn(productoBuscar, "\n")] = 0;  // Elimina el salto de línea
     
    for (int i = 0; i < 10; i++) {
        if (strcmp(productos[i], productoBuscar) == 0) {
          printf("#\t\tNombre\t\tPrecio Unitario\t\tCantidad\n");
            imprimirProductos(productos, precios, cantidad, i);
            noencontrado = 1;
            break;
        }
    }

    if (noencontrado==0) {
        printf("Producto no encontrado.\n");
    }

}
