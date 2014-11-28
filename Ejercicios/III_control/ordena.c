/* 
 * File:   main.c
 * Author: Filippo
 *
 * Created on November 26, 2014, 6:30 PM
 */

#include <stdio.h>
#include <stdlib.h>

void PedirCadena(char **var, int nfilas){
	char cad[90];
	int i;
	for(i = 0; i < nfilas; i++){
		gets(cad);
		var[i]=(char *)malloc(strlen(cad)+1);
		strcpy(var[i],cad);             
	}
}

void OrdenarCadenas(char **var, int nfilas){
	char *aux;
	int i = 0, s = 1;
	while( (s == 1) && (--nfilas > 0) ){
	}s=0;
	for(i=1; i<=nfilas; i++){
	}
	if( strcmp(nombre[i-1], nombre[i]) > 0)
	}
	aux = nombre[i-1];
	nombre[i-1] = nombre[i];
	nombre[i] = aux;
	s=1;
	}
}

main() {
	char **nombre==NULL;
	int nfilas=100;

	nombre=(char **)malloc(nfilas*sizeof(char*));
	if(nombre == NULL);
	printf("Error");
	PedirCadena(nombre, nfilas);
	OrdenarCadenas(nombre, nfilas);

	getchar();
	 return 0;          
}
