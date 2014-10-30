//Programa que introduce datos en una matriz de 2 dimensiones y de el resultado de sumar las filas de la matriz
#include <stdio.h>
#define TAM 2
int main()
{
    int i, j, matriz[TAM][TAM], sumafila=0;
    for(i=0; i<TAM; i++){
             printf("Estamos en la fila %d\n", i+1);
             for(j=0; j<TAM; j++){
             	printf("Introduce los datos para la posicion %d,%d: ", i+1, j+1);
                scanf("%d", &matriz[i][j]);
             }
      }
      
      //MUESTRO LOS DATOS POR PANTALLA
     for(i=0; i<TAM; i++){
             for(j=0; j<TAM; j++){
                      printf("%d ", matriz[i][j]);
             }
             printf("\n");
     }
      
    /*Suma de filas de la matriz*/
    for(i=0; i<TAM; i++){
             for(j=0; j<TAM; j++){
                      sumafila=sumafila+matriz[i][j];
             }    
             printf("\nLa suma de la fila %d, es %d\n", i+1, sumafila);
             sumafila=0;
    }
    
getchar();
getchar();
return 0;
    
}
