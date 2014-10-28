/*Calclar el valor acumulado*/
#include <stdio.h>
int main()
{
    int cantidadInvertida, Intereses, valorAcumulado;
    
    printf("Escribe la cantidad invertida: ");
    scanf("%d", &cantidadInvertida);
    
    printf("Escribe los intereses: ");
    scanf("%d", &Intereses);
    
    valorAcumulado = cantidadInvertida * Intereses;
    printf("El valor acumulado es: %d", valorAcumulado);
    
    getchar();
    getchar();
    return 0;
    
}
