// 11.cpp : Defines the entry point for the console application.
//


// 11

#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <locale.h> 
#include "utf8.h" 

int main(int argc, char** argv) 
{ 
	char *locale;
	locale = setlocale(LC_ALL, "");

	char cad[]="Hola agente 007, soy Max! ¿Dónde está el jefe?\n";
	char oMinAcute = '\363';
	char aMinAcute = '\341';
	char intInvert = '\277';

    char texto[80];
    char textoNuevo[80];
    int j = 0; 
    
    printf("Introduce una frase: \n");
    gets(texto); 
    strcpy(texto, cad);
    
    for(int i = 0; texto[i] != '\0'; i++) 
    {
		if( !ispunct(texto[i]) && !isdigit(texto[i]) && texto[i] != intInvert) {  //no es un signo de puntuacion   //no es un numero
			textoNuevo[j] = toupper(texto[i]); 
			j++;
        }
		else if (texto[i] == oMinAcute) {
			textoNuevo[j] = 'O'; 
			j++;
		}
		else if (texto[i] == oMinAcute) {
			textoNuevo[j] = 'A'; 
			j++;
		}
    }
    textoNuevo[j] = '\0';
    
	// printf("%ls", textoNuevo);
	puts(textoNuevo);
    
	getchar(); 
    
	return 0; 
}
