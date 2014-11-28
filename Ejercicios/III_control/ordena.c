/*
 * File:   main.c
 * Author: Filippo
 *
 * Created on November 26, 2014, 3:50 PM
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 100
#define MAXCHAR 90

int PedirCadena(char **var, int lineas) {
    char cad[MAXCHAR];
    int i = 0;

	for(i = 0; i < lineas; i++){
		gets(cad);
		var[i] = (char *) malloc( strlen(cad)+1 ); //pongo +1 para reservar espacio por el \0
        strcpy(var[i], cad);        
	}
    
    return i;
}

void OrdenarCadenas(char **var, int nfilas){
    char *aux;
    int i = 0, s = 1;
    
    while( (s == 1) && (--nfilas > 0) ){
        s = 0;
        for(i=1; i <= nfilas; i++){
            if( strcmp(var[i-1], var[i]) > 0 ){
                aux = var[i-1];
                var[i-1] = var[i];
                var[i] = aux;
                s = 1; //S se convierte en 1 cuando if se cumple
            }
        } 
    }
}

int main() {
    char **lista;
    int nfilas = MAXLINES;
    int i = 0;

    printf("Cuantas filas hay que leer?\n\n");
    scanf("%d", &nfilas);
    fflush(stdin);
    
    lista = (char **) malloc( nfilas*sizeof(char *) );
    if(lista == NULL){
        printf("Error");
        return 1;
    }

    nfilas = PedirCadena(lista, nfilas);
    OrdenarCadenas(lista, nfilas);

    printf("\nLista ordenada de %d filas\n\n", nfilas);
    for(i = 0; i < nfilas; i++){
        printf("%s\n", lista[i]);
    }

    return 0;          
}
