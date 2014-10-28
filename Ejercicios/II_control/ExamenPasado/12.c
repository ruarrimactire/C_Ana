// Control II Programación

// 12)

#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

int main() {

    char texto[160];
    char textoNuevo[160];
    int i = 0; 
    printf("Introduce una palabra: \n");
    gets(texto); 
    	
	for(i = 0; i<strlen(texto); i++){
		textoNuevo[i] = texto[strlen(texto)-i-1];
	}
	textoNuevo[i] = '\0';

	puts(texto);      // sirven solo para visualizar el resultado
	puts(textoNuevo); // sirven solo para visualizar el resultado
	
	if ( !strcmp(texto, textoNuevo) ) {
		printf("\nLa palabra es un palindromo.\n");
	}
	else{
		printf("\nLa palabra NO es un palindromo.\n");
	}
	
	printf("\n Introduce envio: \n");
    getchar();

	return 0; 
}
