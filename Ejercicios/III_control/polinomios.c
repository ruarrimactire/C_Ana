/**************Polinomios*************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int grado;
	float *coef;      
} tpolinomio;

tpolinomio leerPol(void);
void visualizarPol(tpolinomio pol);
tpolinomio sumarPol(tpolinomio A, tpolinomio B);


tpolinomio leerPol(void) {
	tpolinomio pol;
	int i = 0;

	printf("Grado del polinomio: \n");
	scanf("%d", &pol.grado);

	/*Asignar memoria para el array de coeficientes */
	pol.coef = (float *)malloc( (pol.grado +1)*sizeof(float) );

	////////Esto lo puedo quitar??///////////
	if(pol.coef == NULL) {
		printf("Insuficiente memoria\n");
		exit(-1);                  
	}

	/////////////////////////////////////////
	/*Leer los coeficientes de mayor a menor grado*/
	printf("Coeficientes de mayor a menor grado: \n");
	for(i = pol.grado; i >= 0; i--)
		scanf("%g", &pol.coef[i]);

	return(pol);       
}

void visualizarPol(tpolinomio pol) {
	int i=0;
	
	/*Escribir los terminos de mayor a menor grado*/
	for(i = pol.grado; i > 0; i--)
		if(pol.coef[i]) //Imprime el termino solo si el coeficiente es diferente de 0
			printf("%+gx^%d ", pol.coef[i], i); ////%g elige la represencación mas corta entre %f y %e
	
	/*Escribir el termino independiente*/
	if(pol.coef[i])//Imprime el termino solo si el coeficiente es diferente de 0
		printf("%+g \n", pol.coef[i]);
}

tpolinomio sumarPol(tpolinomio polA, tpolinomio polB) {
	int i = 0;
	tpolinomio polresu, polaux;

	/*Hacer que polA sea el de mayor grado*/
	if(polA.grado<polB.grado) { // Si el grado de A es menor que el de B, se invierte el orden de los 2 polinomios
		//Hace esto solo para encontrar con mas rapidez el polinomio de grado mayor
		polaux=polA;
		polA=polB;
		polB=polaux;               
	}           
	/*El polinomio resultante tendra como grado, el mayor*/
	polresu.grado=polA.grado;

	/*Asignar memoria para el array de coeficientes de polresu*/
	polresu.coef = (float *)malloc((polresu.grado +1)*sizeof(float));
	if(polresu.coef==NULL) {
	   printf("Insuficiente memoria\n");
	   exit(-1);
	}
	
	/*Sumar polB con los coeficientes correspondientes de polA*/
	for(i=0; i<=polB.grado; i++)
		polresu.coef[i]=polB.coef[i]+polA.coef[i];
		
	/*A partir del valor actual de i, copiar los coeficientes restantes de polA*/
	for(i ; i<=polA.grado; i++) // deja que en la variable i se quede el valor con que se terminó el bucle precedente
		polresu.coef[i]=polA.coef[i];
		
	return polresu;                      
}

main() {
    tpolinomio polA, polB, polR;
    
    printf("Introduce poliomio A\n");
	polA=leerPol();
    printf("Introduce poliomio B\n");
    polB=leerPol();
    polR=sumarPol(polA, polB);

    visualizarPol(polA);
	visualizarPol(polB);
	visualizarPol(polR);

    /*Liberar la memoria asignada*/
    free(polA.coef);
    free(polB.coef);
    free(polR.coef);    
}
