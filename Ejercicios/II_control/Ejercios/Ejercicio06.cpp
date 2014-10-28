#include <stdio.h>
#include <string.h>

int main()
{
    char nombre1[30];
    char nombre2[30];
 
  printf("Escriba su nombre  ");
  scanf("%s", nombre1);
    
  for (int i = 0; i<strlen(nombre1); i++){
           nombre2[strlen(nombre1)-1 -i] = nombre1[i]; // "(strlen(nombre1)-1) -i" recorre al reves
      }  
      nombre2[ strlen(nombre1) ] = '\0'; //marca el final de la nueva cadena de caracteres
      
      printf("%s  \n%s  \n", nombre1, nombre2);
      
      getchar();
      getchar();
      
      return 0;
      
}
