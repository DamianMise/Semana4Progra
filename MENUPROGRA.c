/** Programa hecho por los integrantes:
    Nicolas Chisaguano, Damian Mise, John Quintuna, Juan Silva
**/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int menu;
    int valorpro = 0;
    char nombres[10][20];
    char buscapro[20];
    float precio[10];
    float preciototal = 0;
    float promeprecio = 0;
    int busvalor;
    int proMayor;
    int proMenor;

    do {
        printf("\n");
        printf("========================================\n");
        printf("  GESTION DE PRODUCTOS\n");
        printf("========================================\n");
        printf("1. Agregar un producto.\n");
        printf("2. Calcular el precio total del inventario.\n");
        printf("3. Encontrar el producto mas caro y el mas barato.\n");
        printf("4. Calcular el precio promedio.\n");
        printf("5. Buscar un producto.\n");
        printf("6. Finalizar programa.\n");
        printf("Ingrese una opcion: ");

        do {
            scanf("%d", &menu);

            if (menu < 1 || menu > 6) {
                printf("Opcion invalida, intente de nuevo: ");
            }

        } while (menu < 1 || menu > 6);

        switch (menu) {

            case 1:

                if (valorpro < 10) {

                    printf("\nIngrese los datos del producto %d:\n",
                           valorpro + 1);

                    printf("Nombre (maximo 19 caracteres): ");
                    scanf("%19s", nombres[valorpro]);

                    do {
                        printf("Ingrese el precio del producto: ");
                        scanf("%f", &precio[valorpro]);

                        if (precio[valorpro] < 0) {
                            printf("Error: valor no permitido.\n");
                        }

                    } while (precio[valorpro] < 0);

                    printf("Producto agregado exitosamente.\n");

                    valorpro++;

                } else {

                    printf("Se ha alcanzado el maximo de productos.\n");

                }

                break;

            case 2:

                if (valorpro > 0) {

                    preciototal = 0;

                    printf("\n");
                    printf("----------------------------------------------------------\n");
                    printf("%-15s %-25s %-10s\n",
                           "Producto", "Nombre", "Precio");
                    printf("----------------------------------------------------------\n");

                    for (int i = 0; i < valorpro; i++) {

                        preciototal = preciototal + precio[i];

                        printf("%-15d %-25s %.2f $\n",
                               i + 1, nombres[i], precio[i]);

                    }

                    printf("----------------------------------------------------------\n");
                    printf("Precio total del inventario: %.2f $\n",
                           preciototal);

                } else {

                    printf("Falta informacion sobre los productos.\n");

                }

                break;

            case 3:

                if (valorpro > 0) {

                    proMayor = 0;
                    proMenor = 0;

                    for (int i = 0; i < valorpro; i++) {

                        if (precio[i] > precio[proMayor]) {
                            proMayor = i;
                        }

                        if (precio[i] < precio[proMenor]) {
                            proMenor = i;
                        }

                    }

                    printf("\n");
                    printf("========================================\n");
                    printf("  PRODUCTO MAS CARO Y MAS BARATO\n");
                    printf("========================================\n");

                    printf("\nProducto mas caro:\n");
                    printf("Nombre: %s\n", nombres[proMayor]);
                    printf("Precio: %.2f $\n", precio[proMayor]);

                    printf("\nProducto mas barato:\n");
                    printf("Nombre: %s\n", nombres[proMenor]);
                    printf("Precio: %.2f $\n", precio[proMenor]);

                } else {

                    printf("Falta informacion sobre los productos.\n");

                }

                break;

            case 4:

                if (valorpro > 0) {

                    preciototal = 0;

                    printf("\n");
                    printf("========================================\n");
                    printf("       PROMEDIO DE PRECIOS\n");
                    printf("========================================\n");

                    printf("%-12s %-20s %10s\n",
                           "Producto", "Nombre", "Precio");
                    printf("----------------------------------------\n");

                    for (int i = 0; i < valorpro; i++) {

                        preciototal = preciototal + precio[i];

                        printf("%-12d %-20s %9.2f $\n",
                               i + 1, nombres[i], precio[i]);

                    }

                    promeprecio = preciototal / valorpro;

                    printf("----------------------------------------\n");
                    printf("Precio total: %.2f $\n", preciototal);
                    printf("Precio promedio: %.2f $\n", promeprecio);
                    printf("========================================\n");

                } else {

                    printf("Falta informacion sobre los productos.\n");

                }

                break;

            case 5:

                if (valorpro > 0) {

                    printf("\n");
                    printf("========================================\n");
                    printf("           BUSCAR PRODUCTO\n");
                    printf("========================================\n");

                    printf("Ingrese el nombre del producto: ");
                    scanf("%19s", buscapro);

                    busvalor = -1;

                    for (int i = 0;
                         i < valorpro && busvalor == -1;
                         i++) {

                        if (strcmp(buscapro, nombres[i]) == 0) {
                            busvalor = i;
                        }

                    }

                    if (busvalor != -1) {

                        printf("\n");
                        printf("========================================\n");
                        printf("        PRODUCTO ENCONTRADO\n");
                        printf("========================================\n");

                        printf("Nombre: %s\n", nombres[busvalor]);
                        printf("Precio: %.2f $\n", precio[busvalor]);

                        printf("========================================\n");

                    } else {

                        printf("\n");
                        printf("========================================\n");
                        printf("       PRODUCTO NO ENCONTRADO\n");
                        printf("========================================\n");

                    }

                } else {

                    printf("Falta informacion sobre los productos.\n");

                }

                break;

            case 6:

                printf("Muchas gracias por utilizar el programa.\n");

                return 0;

            default:

                printf("Opcion no valida.\n");

                break;

        }

    } while (menu != 6);

    return 0;
}