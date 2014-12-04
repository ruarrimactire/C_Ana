#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main() //Porque no int main()??
{
    int n_car = 0, n_caracteres = 0;
    char car, frase[50], stemp[50]; //No va
    
    printf("Introduce una frase: \n");
    gets(frase);
    
    strcpy(stemp, frase); /*Copia frase en stemp*/
    n_caracteres = strlen(frase); /*Da la longitud de la cadena*/
    printf("\t %s\n\n", frase);
    
    do{  /*Repite el buche mientras la cadena no vuelve a ser la original*/
                 car = frase[n_caracteres-1]; //Para tener la posicion exacta. Quita \0 al final de la frase
                 for(n_car = n_caracteres-2; n_car >= 0; n_car--) 
                 {
                      frase[n_car+1] = frase[n_car];                              
                 }
                 frase[0] = car;
                 printf("\t %s\n", frase);
                 
    } while(strcmp(frase, stemp)); //Sigue hasta que haya dado una vuelta completa. Hasta que sean iguales. Sigue mientras que sean diferentes.
      printf("\n");
}
