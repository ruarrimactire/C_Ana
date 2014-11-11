//Programa que introduce datos en una matriz de 2 dimensiones y de el resultado de sumar las filas de la matriz
#include <stdio.h>
#define FILASMAX 50
#define COLUMNASMAX 50

int main()
{
	int filas, columnas;
	int matriz[FILASMAX][COLUMNASMAX];
	int matrizTranspuesta[COLUMNASMAX][FILASMAX];

	printf("Introduce el tamaño de la matriz (antes numero filas luego columnas): ");
	scanf("%d", &filas);
	scanf("%d", &columnas);

	{ int i, j;
		for(i = 0; i < filas; i++) {
				printf("Estamos en la fila %d\n", i+1);
				for(j = 0; j < columnas; j++) {
     				printf("Introduce los datos para la posicion %d,%d: ", i+1, j+1);
					scanf("%d", &matriz[i][j]);
				}
		}
		  
		// MUESTRO LOS DATOS POR PANTALLA
		for(i = 0; i < filas; i++) {
				 for(j = 0; j < columnas; j++) {
						  printf("%d \t", matriz[i][j]);
				 }
				 printf("\n");
		}
		  
		int sumafila = 0;
		/*Suma de filas de la matriz*/
		for(i = 0; i < filas; i++) {
				 for(j = 0; j < columnas; j++) {
						  sumafila = sumafila + matriz[i][j];
				 }    
				 printf("\nLa suma de la fila %d, es %d\n", i+1, sumafila);
				 sumafila = 0;
		}

		// Traspongo la matriz
		for(i = 0; i < filas; i++) {
				for(j = 0; j < columnas; j++) {
					  matrizTranspuesta[j][i] = matriz[i][j];
				}
				printf("\n");
		}

		// MUESTRO LOS DATOS POR PANTALLA
		for(i = 0; i < columnas; i++) {
				for(j = 0; j < filas; j++) {
					  printf("%d \t", matrizTranspuesta[i][j]);
				}
				printf("\n");
		}
	}

	getchar();

	return 0;
}
