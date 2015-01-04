#include <stdio.h>
#include <stdlib.h>
#include "interfaz_llse.h"

main() {		
	int i = 0;
	Elemento *llse = NULL;
	double *n = NULL, d = 0;

	printf("Introducir datos. Finalizar con eof.\n");
	printf("Valor double: ");
	
	while(scanf("%lf", &d)!= EOF) {	
		n = (double *)malloc(sizeof(double));
		if(!n)
			error();
		*n=d;
		anyadirAlPrincipio(n, &llse);
		printf("Valor double: ");
	}
	printf("\n");
	
	i = 0;
	n = (double *)obtener(i, llse);
	while(n != NULL){
		printf("%g \n", *n); // printf("%g \n", *n); por un formato variable de impresion de los numeros %lf por el double
		i++;
		n = (double *)obtener(i, llse);
	}
	printf("\n%d valores.\n", i);
	
	i=0;
	n=(double *)obtener(i, llse);
	while(n != NULL){
		free(n);
		i++;
		n = (double *)obtener(i, llse);
	}

	borrarTodos(&llse);
}
