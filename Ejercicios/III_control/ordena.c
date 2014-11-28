/*
 * File:   main.c
 * Author: Filippo
 *
 * Created on November 26, 2014, 1:39 PM
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **lista;

char **appendCadena(char **var2, int num, char *cad2){
/*
    //char *list[num];
*/
    char **list = (char **)malloc( num*sizeof(char *) );
    int i;
    
    for(i = 0; i < num-1; i++){
        list[i] = var2[i];
    }
    list[i] = (char *)malloc( strlen(cad2)+1 );
    strcpy(list[i], cad2);
/*
    //free(var2);
*/
    lista = list;
    return list;
}

int PedirCadena(char **var){
    char cad[90];
    int i = 0;

    while( gets(cad)[0] != '\0' ){
        i++;
        appendCadena(var, i, cad);
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

main() {
    int nfilas = 0;
    int i = 0;

    nfilas = PedirCadena(lista);
    
/*
    if(lista == NULL){
        printf("Error");
        return 1;
    }
*/

    printf("\nLista no ordenada de %d filas\n\n", nfilas);
    for(i = 0; i < nfilas; i++){
        printf("%s\n", lista[i]);
    }

    OrdenarCadenas(lista, nfilas);

    printf("\nLista ordenada de %d filas\n\n", nfilas);
    for(i = 0; i < nfilas; i++){
        printf("%s\n", lista[i]);
    }

    free(lista);
    
    return 0;          
}
