//Programa que introduce datos en una matriz de 2 dimensiones y de el resultado de sumar las filas de la matriz
#include <stdio.h>

int main()
{
    int filas, columnas;
    printf("Introduce el tamaño de la matriz (antes numero filas luego columnas): ");
    scanf("%d", &filas);
    scanf("%d", &columnas);
    
    int matriz[filas][columnas];
    
	int i, j;
    for(i=0; i<filas; i++){
             printf("Estamos en la fila %d\n", i+1);
             for(j=0; j<columnas; j++){
             	printf("Introduce los datos para la posicion %d,%d: ", i+1, j+1);
                scanf("%d", &matriz[i][j]);
             }
      }
      
      //MUESTRO LOS DATOS POR PANTALLA
     for(i=0; i<filas; i++){
             for(j=0; j<columnas; j++){
                      printf("%d \t", matriz[i][j]);
             }
             printf("\n");
     }
      
    int sumafila = 0;
    /*Suma de filas de la matriz*/
    for(i=0; i<filas; i++){
             for(j=0; j<columnas; j++){
                      sumafila = sumafila + matriz[i][j];
             }    
             printf("\nLa suma de la fila %d, es %d\n", i+1, sumafila);
             sumafila = 0;
    }
    
getchar();
getchar();
return 0;
}
