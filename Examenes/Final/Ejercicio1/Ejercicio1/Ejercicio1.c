#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alumno {
	char nombre [60] ;
	float nota;
} talumno;

typedef struct datos {
	talumno alumno;
	struct datos *siguiente;
} telemento;

void anadir(telemento **, talumno);
void borrar(telemento **, talumno);
telemento *buscar(telemento *, talumno);
void visualizar (telemento *);
int menu (void);
void borrar_lista (telemento *);

main() {
	telemento *lista = NULL, *temp = NULL;
	talumno alumno;
	int funcion;

	while(1){
		alumno.nombre[0] = '\0';
		alumno.nota = 0;
		funcion = menu();

		switch (funcion) {
				case 1:
					printf("Introducir nombre\n");
					scanf("%s", alumno.nombre);
					printf("Introducir nota\n");
					scanf("%f", &alumno.nota);
					anadir(&lista, alumno);
					// visualizar(lista);
					break;
				case 2:
					printf("Introducir nombre\n");
					scanf("%s", alumno.nombre);
					printf("Introducir nota\n");
					scanf("%f", &alumno.nota);
					borrar(&lista, alumno);
					visualizar(lista);
					break;
				case 3:
					printf("Introducir nombre\n");
					scanf("%s", alumno.nombre);
					printf("Introducir nota\n");
					scanf("%f", &alumno.nota);
					temp = buscar(lista, alumno);
					printf("Nombre: %s\t Nota: %1.1f\n", temp->alumno.nombre, temp->alumno.nota);
					break;
				case 4:
					visualizar (lista);
					break;
				case 5:
					borrar_lista (lista);
					visualizar (lista);
					break;
			}
	}

}



// La función añadir recibirá como parámetros la dirección del primer elemento de la lista, 
// parámetro que será pasado por referencia puesto que puede variar, cuando se inserte un 
// elemento al principio, y los datos del alumno a insertar.
void anadir(telemento **lista, talumno datos) {
	telemento *temp=*lista;
	telemento *nuevo = (telemento *)malloc(sizeof(telemento));
	
	if (!nuevo){
		printf("memoria insuficiente. \n");
		exit(1);
	}

	nuevo->alumno = datos;
	nuevo->siguiente = temp;
	*lista = nuevo;
}


/* b)	Borrar un elemento de la lista. Esta función comprenderá dos casos: 
borrar el elemento del principio de  la lista o borrar otro elemento cualquiera.

La función borrar recibirá como parámetros la dirección del primer elemento de la lista, 
parámetro que será pasado por referencia puesto que puede variar cuando se pone el primer elemento, 
y los datos del alumno a borrar.
*/
void borrar(telemento **lista, talumno datos) {
	telemento *temp, *temp0;

	temp = buscar(*lista, datos);
	if(temp == NULL){
		printf("Alumno no encontrado.\n");
		return;
	}

	temp0 = *lista;
	while(temp0 != NULL) {
		if(temp0->siguiente == temp){
			break;
		}
		else{
			temp0 = temp0->siguiente;
		}
	}
	if(temp0 == NULL) { // si no se encuentra el elemento anterior, quiere decir que tenemos que borrar el primer elemento de la lista
		temp0 = *lista;
		*lista = temp->siguiente;
		free(temp0);
	}
	else { //si temp0 contiene una direccion valida quere decir que tenemos que borrar un otro elemento
		temp0->siguiente = temp->siguiente;
		free(temp);
	}
}


/* c)	Buscar un elemento en la lista.
La función buscar recibirá como parámetros la dirección del primer elemento de la lista 
y los datos del alumno a buscar y devolverá como resultado la dirección del elemento si se encuentra, 
o un valor NULL si no se encuentra.
*/
telemento *buscar(telemento *lista, talumno datos) {
	telemento *temp = lista;

	while(temp != NULL) {
		if( (temp->alumno.nombre == datos.nombre) && (temp->alumno.nota == datos.nota) ) {
			return temp;
		}
		else {
			temp = temp->siguiente;
		}
	}

	return NULL;
}



/* d)	Visualizar el contenido de la lista.
La función visualizar recibirá como parámetros la dirección del primer elemento de la lista.
*/
void visualizar (telemento *lista) {
	while(lista != NULL ){
		printf("Nombre: %s\t Nota: %1.1f\n", lista->alumno.nombre, lista->alumno.nota);
		lista = lista->siguiente;
	}
	printf("fin de la lista\n\n");
}

/* e)	Presentar un menú con cada una de las operaciones anteriores.
La función menú presentará un menú con las opciones: añadir, borrar, buscar, 
visualizar y salir y devolverá como resultado un entero correspondiente a la opción elegida.
*/
int menu (void) {
	int i = 6;

	while(i == 6){
		printf("1. Anyadir alumno\n");
		printf("2. Borrar alumno\n");
		printf("3. Buscar alumno\n");
		printf("4. Visualizar todo\n");
		printf("5. Borrar todo\n");
		printf("0. para salir\n\n");

		scanf("%d", &i);
		fflush(stdin);
		if( ferror(stdin) )
			i = 6;

		if ( i == 0 )
			exit(0);

		if( i<1 || i>5 )
			i = 6;	
	}

	return i;
}

/* e)	Borrar la lista.
La función borrar_lista liberará la memoria ocupada por todos los elementos de la lista.
*/
void borrar_lista (telemento *lista) {
	telemento **temp = &lista;

	while( *temp != NULL ){
		borrar(temp, lista->alumno);
	}
}
