#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct EstructuraFichaLibro{
    char titulo[256];
    char autor[256];
    char ISBN[256];
    char Estante[256];
    int prestado;
    char cliente[256];
}FichaLibro; //definicion de tipo

void obtenerDatos(FichaLibro *ficha);
int AnyadirAFicheros(FichaLibro *ficha, char *nombreFichero);

int main() {
	FichaLibro fichaTemp; //Declaro una sola ficha

	obtenerDatos( &fichaTemp ); //pongo & para pasarle la dirección de la ficha, sino se pasarian los datos

	return AnyadirAFicheros(&fichaTemp, "biblioteca.bin");
}

void obtenerDatos(FichaLibro *ficha) {
	printf("Titulo libro?\n");
    scanf("%s", ficha->titulo);
    fflush(stdin);

	printf("Autor libro?\n");
    scanf("%s", ficha->autor);
    fflush(stdin);

	printf("ISBN libro?\n");
    scanf("%s", ficha->ISBN);
    fflush(stdin);

	printf("Estante libro?\n");
    scanf("%s", ficha->Estante);
    fflush(stdin);

	printf("libro prestado?\n");
    scanf("%d", &ficha->prestado);
    fflush(stdin);

	printf("Cliente?\n");
    scanf("%s", ficha->cliente);
    fflush(stdin);
}

int AnyadirAFicheros(FichaLibro *ficha, char *nombreFichero) {
	FILE *pf = NULL;
	int i = 0;

	pf = fopen(nombreFichero, "a+"); //fseek solo va con a o a+
	if (pf == NULL) //Si hay un error al abrir el fichero devuelve 0
		return 0; //Recomendable poner esto despues de fopen
	fseek(pf, 0, SEEK_END); //En el fichero pf ponte al final. Pf un puntero a fichero. 0 es el desplazamiento. SEE_END es el final
	fwrite(ficha, sizeof(FichaLibro), 1, pf); //Escribe el dato ficha; reservando un tamaño en el disco igual al tamaño de la estructura fichalibro
	//Escribe 1 solo elemento; dentro de pf.

	//Detecta errores de cualquier tipo
	//if( ferror() ) {
	//	clearerr();
	//	return 0;
	//}

	fclose(pf);

	return 1; //Devuelve true 
}