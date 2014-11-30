/*
 * File:   main.c
 * Author: Filippo
 *
 * Created on November 30, 2014, 10:49 AM
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
		var[i] = (char *) malloc( strlen(cad)+1 ); //pongo +1 para reservar espacio por el \0 //porqué pongo var[i]? Cualquer puntero puede convertirse en un array siempre que haya espacio de memoria //porqué no (char **)? //porque es var[i], si fuese solo var si seria con char**.    var[i] == *(var+i) 
        strcpy(var[i], cad);  //Copia en var[i] la cadena 'cad'      
	}
    
    return i; //?? //Devuelve el numero de lineas leidas
}

void OrdenarCadenas(char **var, int nfilas){ 
    char *aux;
    int i = 0, s = 1; //?? //cambia el valor dependiendo de si se cumple while o for (flag)
    
    while( (s == 1) && (--nfilas > 0) ){ //Se definen 2 condiciones que tienen que ser verdaderas a la vez para que se ejecute
        s = 0;
        for(i=1; i <= nfilas; i++){
            if( strcmp(var[i-1], var[i]) > 0 ){ //Compara 2 cadenas
                aux = var[i-1]; //invierte las cadenas
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
    fflush(stdin); //Es necesario o solo para caracteres //Poner fflush despues del ultimo scanf o antes de un gets o getchar. Si tengo mas de 1 scanf poner fflush al final.
	//while(getchar() != '\n'){}   //Se puede sustituir fflush por esto

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
