/*
 * File:   main.c
 * Author: Filippo
 *
 * Created on November 27, 2014, 1:30 PM
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 100

int PedirCadena(char **var) {
    char cad[90];
    int i = 0;

    while( gets(cad)[0] != '\0' && i < MAXLINES ) {
        var[i] = (char *)malloc(strlen(cad) + 1);
        strcpy(var[i], cad);
        i++;
    }
    return i;
}

void OrdenarCadenas(char **var, int nfilas){
    char *aux;
    int i = 0, s = 1;
    
    while( (s == 1) && (--nfilas > 0) ){
        s=0;
        for(i=1; i <= nfilas; i++){
            if( strcmp(var[i-1], var[i]) > 0 ){
                aux = var[i-1];
                var[i-1] = var[i];
                var[i] = aux;
                s=1;
            }
        } 
    }
}

int main() {
    char *lista[MAXLINES];
    int nfilas = 0;
    int i = 0;

	printf("Introducir Lineas:\n");
    nfilas = PedirCadena(lista);
    
    if(lista == NULL){
        printf("Error");
        return 1;
    }

    OrdenarCadenas(lista, nfilas);

    printf("\nLista ordenada de %d filas\n\n", nfilas);
    for(i = 0; i < nfilas; i++){
        printf("%s\n", lista[i]);
    }
    
    return 0;          
}
