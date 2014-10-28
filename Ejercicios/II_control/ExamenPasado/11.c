// Control II Programación

// 11)

#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

int main(int argc, char** argv) {

    char texto[160];
    char textoNuevo[160];
    int i = 0, j = 0; 
    printf("Introduce una frase: \n");
    gets(texto); 
    	
    for(i=0; i<strlen(texto); i++) // texto[i] != '\0'
    {
		// if ( isalpha(texto[i]) || (texto[i] == ' ') ) { //no es un signo de puntuacion   Y //no es un numero
		if ( (ispunct(texto[i]) == 0) && (isdigit(texto[i]) == 0) ) { //no es un signo de puntuacion   Y //no es un numero
			textoNuevo[j] = toupper(texto[i]); 
			j++;
		}
		// else {
			// textoNuevo[i] = ' ';
		// }
	}
	textoNuevo[j] = '\0';

	puts(textoNuevo);
	
	printf("\n Introduce envio: \n");
    getchar();

	return 0; 
}
