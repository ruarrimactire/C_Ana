#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
int main() 
{ 
    char texto[80];
    char textoNuevo[80];
    int i, j = 0; 
    
    printf("Introduce una frase: ");
    gets(texto); 
    
    for(i=0; texto[i] != '\0'; i++)
    {
        if(ispunct(texto[i]) == 0){  //no es un signo de puntuacion   
            if(isdigit(texto[i]) == 0){ //no es un numero
                 textoNuevo[j] = toupper(texto[i]); 
                 j++;
            }    
        }
    }
    textoNuevo[j] = '\0';
    
    puts(textoNuevo);
    
    getchar(); getchar();
    return 0; 
}
