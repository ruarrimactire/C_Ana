#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

int main() {

    char texto[160];
    char texto2[160];	
    char textoNuevo[160];
    int i = 0; 
    printf("Introduce una palabra: \n");
    gets(texto2); 
	
	for(int i = 0; i < strlen(texto); i++)
	{
		texto[i] = toupper(texto2[i]);
	}
   	
	for(i = 0; i<strlen(texto); i++){
		textoNuevo[i] = texto[ (strlen(texto)-1) -i ];
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
//getchar();
    getchar();

	return 0; 
}

