// 2.  Realizar un programa que permita utilizar el terminal, como un diccionario
    // Ingles-Español, esto es, al introducir una palabra en Inglés, se escribirá la 
    // correspondiente palabra en Español. El numero de parejas de palabras es variable, 
	// pero limitado a un máximo de 100. La longitud máxima de cada palabra
    // será de 40 caracteres. Por ejemplo, introducimos las siguientes parejas de letras:
	
	// book 	libro
	// green	verde
	// mouse	ratón

	// Una vez finalizada la introducción de la lista. pasamos al modo traducción, de
	// forma que si tecleamos green, la respuesta ha de ser verde. Si la palabra no se
	// encuentra se emitirá un mensaje que lo indique.

	// El programa constará al menos de dos funciones

	// a) CrearDicconario(). Esta función creará el diccionario.
	// b)  Traducir(). Esta función realizará la labor de traducción

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPAREJAS 100
#define MAXFRASE 100
#define LONGPALABRA 40

typedef struct {
	char parejas[MAXPAREJAS][2][LONGPALABRA];
	int num;
} diccionario;

int crearDiccionario(diccionario *diccio);
int traducir(char *texto, diccionario *diccio);

int main(void) {
	diccionario EngEsp;
	char string[MAXFRASE];
	int count = 0;
		
	EngEsp.num = 0;
	crearDiccionario(&EngEsp);

	while( gets(string)[0] != '\0' ) {
		char *c, *d, string2[MAXFRASE], identificadores[] = {" \t.,-;"};
		strcpy(string2, string);
		c = strtok (string, identificadores);
		while (c != NULL) {
			int i = 0;
			count += traducir(c, &EngEsp);
			d = c + strlen(c);
			c = strtok(NULL, identificadores);
			for(i = d-string ; i < c-string; i++)
				putchar( string2[i] );
		}
		printf("\n");
	}
	
	printf("\nn%cmero de palabras traducidas: %d\n", -93, count );
	
	return 1;
	// while(c) {
		// printf("1. Añadir palabras al diccionario;");
		// printf("2. Modo traducción;");
		// printf("0. Salir del programa");
		// c = getchar();
		
		// switch(c){
			// case 1:
				// break;
			// case 2:
				// break;
			// case 0:
				// break;
			// default: 
		// }
		
		// printf("teclear invio...");
		// getchar();
		// fflush(stdin);
		// system("cls");
	// }

		// http://stackoverflow.com/questions/2347770/how-do-you-clear-console-screen-in-c
			// #include <conio.h>	// and use	// clrscr()
			// // printf("\e[1;1H\e[2J");

			// // This function will work on ANSI terminals, demands POSIX. I assume there is a version that might also work on window's console, since it also supports ANSI escape sequences.

			// // #include <unistd.h>
			// // void
			// // clearScreen()
			// // {
			  // // const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
			  // // write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
			// // }

}

int crearDiccionario(diccionario *diccio) {
	int num = 0;
	
	while( diccio->num < MAXPAREJAS ) {
		int flag = 1;
		char c;

		printf("Introducir palabra en Ingl%cs\n", -126);
		scanf("%s", diccio->parejas[diccio->num][0]);
		fflush(stdin);

		printf("Introducir palabra correspondiente en Espa%col\n", -92);
		scanf("%s", diccio->parejas[diccio->num][1]);
		fflush(stdin);
		
		num++;
		diccio->num++;
		while( flag ) {
			printf("Introducir otras palabras? (s/n)\n");
			c = getch();
			if ( c == 's' )
				flag = 0;
			else if( c == 'n')
				return num;
			else
				{}
		}
	}
}

int traducir(char *texto, diccionario *diccio) {
	int i = 0, flag = 0;

	for(i = 0; i < diccio->num; i++) {
		if( !strcmp(texto, diccio->parejas[i][0]) ) {
			printf("%s", diccio->parejas[i][1]);
			flag = 1;
		}
	}
	if (!flag)
		printf("%s", texto);

	return flag;
}
