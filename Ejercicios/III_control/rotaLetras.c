#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main() //Porque no int main()??
{
    int n.car=0, n_caracteres=0;
    char car, frase[50], stemp[50]; //No va
    
    printf("Introduce una frase: \n");
    gets(frase);
    
    strcpy(stemp, frase); /*Copia frase en stemp*/
    n.caracteres=strlen(frase); /*Da la longitud de la cadena*/
    printf("%s", frase);
    
    do{  /*Repite el buche mientras la cadena no vuelve a sesr original*/
                 car=frase[n.cadenas-1];
                 for(n.car=n.caracteres-2;n.car>=0; n.car--) 
                 {
                      frase[n-car+1]=frase[n-car];                              
                 }
                 frase[0]=car;
                 printf("-%s", frase); //"-%s"??
                 
    }  while(strcmp(frase,strcmp));
      printf("\n");
}
