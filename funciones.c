#include <stdio.h>
#include <string.h>
#include "funciones.h"


void inventario(char productos[][20], float precios[]) {
    for (int i = 0; i < 10; i++) {
        printf("Nombre del producto %d: ", i + 1);
        fflush(stdin);
        fgets(productos[i], 20, stdin);
       

        int resultado;
        do {
            printf("Ingrese el precio del producto %s: ", productos[i]);
            resultado = scanf("%f", &precios[i]);
            if (resultado != 1) {
                printf("Dato Invalido. Ingrese un número.\n");
                while (getchar() != '\n');
            }
        } while (resultado != 1);
    }

    printf("\nProductos y sus precios:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s : %.2f\n", productos[i], precios[i]);
    }
}

void calculos(char productos[][20], float precios[]) {
    float suma = 0, maxprecio = precios[0], minprecio = precios[0];
    int productoMax = 0, productoMin = 0;

    for (int i = 0; i < 10; i++) {
        suma += precios[i];
        if (precios[i] > maxprecio) {
            maxprecio = precios[i];
            productoMax = i;
        }
        if (precios[i] < minprecio) {
            minprecio = precios[i];
            productoMin = i;
        }
    }

    printf("\nPrecio Máximo del Inventario es: %.2f que le corresponde al producto: %s\n", maxprecio, productos[productoMax]);
    printf("Precio Mínimo del Inventario es: %.2f que le corresponde al producto: %s\n", minprecio, productos[productoMin]);
   printf("El valor del Inventario es: %.2f\n", suma );
    printf("El promedio del Inventario es: %.2f\n", suma / 10);
}

void buscarproducto(char productos[][20], float precios[]) {
    char nombreBuscado[20];
    int encontrado = 0;

    printf("\nIngrese el nombre del producto que busca: ");
    fflush(stdin);
    fgets(nombreBuscado, 20, stdin);
    

    for (int i = 0; i < 10; i++) {
        if (strcmp(productos[i], nombreBuscado) == 0) {
            printf("El precio del producto '%s' es: %.2f\n", productos[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}
