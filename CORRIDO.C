#include <stdio.h>
#include <string.h>

int main() {
    int valorpro = 0;
    char nombres[10][20];
    char buscapro[20];
    float precio[10];
    float preciototal = 0;
    float promeprecio;
    int proMayor = 0;
    int proMenor = 0;
    int busvalor = -1;

    printf("Ingrese la cantidad de productos (maximo 10): ");
    scanf("%d", &valorpro);

    if (valorpro > 10) {
        valorpro = 10;
    }

    if (valorpro < 1) {
        printf("Cantidad de productos no valida.\n");
        return 0;
    }

    for (int i = 0; i < valorpro; i++) {
        printf("Ingrese el nombre del producto: ");
        scanf("%19s", nombres[i]);

        printf("Ingrese el precio del producto: ");
        scanf("%f", &precio[i]);

        while (precio[i] < 0) {
            printf("Precio no valido. Ingrese nuevamente: ");
            scanf("%f", &precio[i]);
        }

        preciototal = preciototal + precio[i];
    }

    printf("\nEl precio total es: %.2f$\n", preciototal);

    for (int i = 1; i < valorpro; i++) {
        if (precio[i] > precio[proMayor]) {
            proMayor = i;
        }

        if (precio[i] < precio[proMenor]) {
            proMenor = i;
        }
    }

    printf("Producto mas caro: %s: %.2f$\n",
           nombres[proMayor], precio[proMayor]);

    printf("Producto mas barato: %s: %.2f$\n",
           nombres[proMenor], precio[proMenor]);

    promeprecio = preciototal / valorpro;

    printf("Precio promedio: %.2f$\n", promeprecio);

    printf("Ingrese el producto que desea buscar: ");
    scanf("%19s", buscapro);

    for (int i = 0; i < valorpro; i++) {
        if (strcmp(buscapro, nombres[i]) == 0) {
            busvalor = i;
        }
    }

    if (busvalor != -1) {
        printf("Producto encontrado: %s: %.2f$\n",
               nombres[busvalor], precio[busvalor]);
    } else {
        printf("Producto no encontrado.\n");
    }

    return 0;
}