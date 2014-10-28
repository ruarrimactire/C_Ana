#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
int main() 
{ 
    char texto[80];
    char textoNuevo[80];
    int i, j = 0; 
    
    printf("Introduce una frase: \n");
    gets(texto); 
    
    for(i=0; texto[i] != '\0'; i++)
    {
        if( !ispunct(texto[i]) && !isdigit(texto[i]) && texto[i] != '¿') {  //no es un signo de puntuacion   //no es un numero
			textoNuevo[j] = toupper(texto[i]); 
			j++;
        }
		else if (texto[i] == 'ó') {
			textoNuevo[j] = 'O'; 
			j++;
		}
		else if (texto[i] == 'á') {
			textoNuevo[j] = 'A'; 
			j++;
		}
    }
    textoNuevo[j] = '\0';
    
    puts(textoNuevo);
    
	getchar(); 
	getchar(); 
	getchar();
    
	return 0; 
}
