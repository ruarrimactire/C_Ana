#include <stdio.h>
#include <stdlib.h>
#define N_ELEMENTOS ('z'-'a'+1) // Porque pongo +1??? -> 
// para calcular el númerodeletras del afabeto (ya que son elementos consecutivos de la tabla ASCII) 
// hay que calcular (posición de)'z' - (posición de)'a' + 1.

main() { // Porque no pongo int main()??? -> depende de si quieres que el programa te devuelva un código o no
	int c[N_ELEMENTOS]; //Matriz?
	char car; /*Indice*/

	/*Poner los elementos de la matriz a 0*/
	for(car='a'; car<='z'; car++)	
		c[car-'a']=0; //?? -> 
	// 'a' en la tabla ASCII está en la posición 97 
	// mientras en el array de frequencias que hemos construido quieremos que sea correspondiente ala posición 0.

	/*Entrada datos y calculo de la tabla frecuencias*/
	printf("Introducir texto.\n");
	while( (car = tolower( getchar() ) )!=EOF)
	{   /*Si el caracter leido es de 'a' a 'z' incrementa el contador correspondiente*/
				if(car>='a'&&car<='z')
				c[car-'a']++;     
	}      
	                            
	/*Escribir tabla de frecuencias*/  
	for(car='a'; car<='z'; car++)
		printf("%2d \t %c \t%3d\n", car, car, c[car-'a']);
	printf("\n.......\n");
}
