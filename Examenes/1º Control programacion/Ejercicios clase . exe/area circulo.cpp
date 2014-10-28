/*Área del círculo*/
#include <stdio.h>

int main ()
{
    float area, radio, pi;
    
    pi = 3.14159;
    printf("Escribe el radio: ");
    scanf("%f", &radio);
    
    area = pi*radio*radio;
    
    printf("El area del circulo es: %f", area);
    
    getchar();
    getchar();
    return 0;
    
}
