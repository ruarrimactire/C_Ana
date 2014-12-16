// 2.  Realizar un programa que permita utilizar el terminal, como un diccionario
    // Ingles-Espa�ol, esto es, al introducir una palabra en Ingl�s, se escribir� la 
    // correspondiente palabra en Espa�ol. El numero de parejas de palabras es variable, 
	// pero limitado a un m�ximo de 100. La longitud m�xima de cada palabra
    // ser� de 40 caracteres. Por ejemplo, introducimos las siguientes parejas de letras:
	
	// book 	libro
	// green	verde
	// mouse	rat�n

	// Una vez finalizada la introducci�n de la lista. pasamos al modo traducci�n, de
	// forma que si tecleamos green, la respuesta ha de ser verde. Si la palabra no se
	// encuentra se emitir� un mensaje que lo indique.

	// El programa constar� al menos de dos funciones

	// a) CrearDicconario(). Esta funci�n crear� el diccionario.
	// b)  Traducir(). Esta funci�n realizar� la labor de traducci�n

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

	do {
		char *c, *d, string2[MAXFRASE], identificadores[] = {" \t.,-;"};

		if ( gets(string) == NULL || strlen(string)<1 )
			continue; 
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
		printf("%s\n", &string2[d-string]);
	} while( !feof(stdin) );
	
	printf("\nn%cmero de palabras traducidas: %d\n", -93, count  );
	
	return 1;
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
			c = getchar();
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
