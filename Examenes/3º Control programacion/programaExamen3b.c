//Ejercicio 7: (4 puntos) Crear un programa que lea del fichero creado anteriormente (“biblioteca.bin”), de manera que almacene los datos en un array de estructuras creado de forma dinámica.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct EstructuraFichaLibro {
	char titulo[256];
	char autor[256];
	char ISBN[256];
	char Estante[256];
	int prestado;
	char cliente[256];
} FichaLibro;

//a) CalculaElementos. Esta función se encargará e calcular cuántas estructuras hay almacenadas en el fichero, en función del tamaño del fichero.
int CalculaElementos(FILE *pf);
//b) ReservaMemoria será la función encargada de reservar memoria dinámica para el array des estructuras de tipo “FichaLibro”.
void ReservaMemoria(FichaLibro **d, int cuantos);
//c) LeerDatos será la función encargada de leer los datos de las estructuras del fichero y almacenarlas en el array des estructuras creado anteriormente.
void LeerDatos(FichaLibro *datos, int cuantos, FILE *pf);
//d) OrdenarArray será la función encargada de ordenar el array de estructuras en orden alfabético por el campo autor de las estructuras. Se puede utilizar cualquiera de los métodos de ordenación vistos en clase.
void OrdenarArray(FichaLibro *datos, int cuantos);

void imprimir(FichaLibro *datos, int cuantos) {
	int i;
	for(i = 0; i<cuantos; i++){
		printf("titulo   %s\n",   (datos+i)->titulo);
		printf("autor    %s\n",   (datos+i)->autor);
		printf("ISBN     %s\n",   (datos+i)->ISBN);
		printf("Estante  %s\n",   (datos+i)->Estante);
		printf("prestado %d\n",   (datos+i)->prestado);
		printf("cliente  %s\n\n", (datos+i)->cliente);
	}
	printf("__________________________________________\n");
}                           

int main() {
	FILE *pf;
	FichaLibro *datos = NULL; //NULL para iniciar el puntero. *datos=datos[].
	int cuantos = 0;

	pf = fopen("biblioteca.bin", "r");
		if (pf == NULL){printf("Error"); return 0;}
	cuantos = CalculaElementos(pf); //si datos es un puntero simple, escribiendo &datos le estoy pasando a la función un puntero a puntero
	ReservaMemoria(&datos, cuantos);
	LeerDatos(datos, cuantos, pf);
		imprimir(datos, cuantos);
	OrdenarArray(datos, cuantos);
		imprimir(datos, cuantos);
		getchar();
	free(datos);
	fclose(pf); //Cierra el fichero
	return 1;
}

int CalculaElementos(FILE *pf) {
	int n;
	fpos_t pos; //typedef estandar

	fseek(pf, 0, SEEK_END);
	fgetpos(pf, &pos); //Sirve para guardar dentro del dato pos, la posicion actual dentro del fichero pf.
	fseek(pf, 0, SEEK_SET);
	n = (int)pos/sizeof(FichaLibro); //(int)ALGO para convertir a entero ; se llama operador de molde ; conversion explicita al tipo de dato especificado.
	return n;
}

void ReservaMemoria(FichaLibro **d, int cuantos) {
	int i;

	*d = (FichaLibro *)malloc( cuantos*sizeof(FichaLibro) ); //Como es dentro de una función, en malloc, puntero a puntero se pone como *d. Si es dentro del main no hace falta.
	for(i = 0; i<cuantos; i++){ //No es obligatorio pero sirve para inicializar a cadenas vacias y a cero el int
		((*d)+i) ->titulo[0]  = '\0';
		((*d)+i)->autor[0]    = '\0';
		((*d)+i)->ISBN[0]     = '\0';
		((*d)+i)->Estante[0]  = '\0';
		((*d)+i)->prestado    = 0 ;
		((*d)+i)->cliente[0]  = '\0';
	} 
}

void LeerDatos(FichaLibro *datos, int cuantos, FILE *pf) {
	fread(datos, sizeof(FichaLibro), cuantos, pf);
}

void OrdenarArray(FichaLibro *datos, int cuantos) {
    FichaLibro aux;
    int i = 0, s = 1;
    
    while( (s == 1) && (--cuantos > 0) ){
        s = 0;
        for(i=1; i <= cuantos; i++){
            if( strcmp( datos[i-1].autor , datos[i].autor) > 0 ){ //Ordena estructuras
                aux = datos[i-1];
                datos[i-1] = datos[i];
                datos[i] = aux;
                s = 1; //S se convierte en 1 cuando if se cumple
            }
        } 
    }
	
}
