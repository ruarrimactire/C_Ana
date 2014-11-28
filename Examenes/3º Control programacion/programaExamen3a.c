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
int AnyadirAFicheros(FichaLibro *ficha, char nombreFichero);

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

int AnyadirAFicheros(FichaLibro *ficha, char nombreFichero) {
	FILE *pf = NULL;
	int i = 0;

	pf = fopen(nombreFichero, "w");

	fwrite(ficha, sizeof(FichaLibro), 1, pf);

	fclose(pf);

	return 1;
}
