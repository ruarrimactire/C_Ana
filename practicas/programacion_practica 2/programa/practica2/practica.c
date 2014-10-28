/*Practica 2*/
#include <stdio.h>
main()
{
	char opcion1, opcion2;

	do{
		printf("Menu Gestion de Practicas\nEste es el menu principal");
		printf("1 - Ejercicios de Punteros\n");
		printf("2 - Ejercicios de Estructuras\n");
		printf("3 - Salir del programa\n");
		printf("Selecciona una opcion: ");
		scanf("%c", &opcion1);
	
	if(opcion1 =='1'){
		do{
			printf("\n1.1 - Ejercicios de clase\n");
			printf("1.2 - Ejercicios resueltos\n");
			printf("1.3 - Ejercicios propuestos\n");
			printf("1.4 - Otros\n");
			printf("1.5 - Volver\n");
			printf("1.6 - Salir\n");
			scanf("%d", &opcion2);
		}
		while(opcion2!=5);
	
	}
	}
		while(opcion1 != 3); 
exit(0);
}