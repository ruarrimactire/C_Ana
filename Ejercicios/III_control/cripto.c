// 1.	Realizar un programa que solicite una frase y a continuación6n la escriba modificada 
	// de forma que a la A le corresponda la K, a la B la L, ... , a la O la Y, a
	// la P la Z, a la Q la A, ... y a la Z la J.

/*
	 65      A +10 =      K
	 66      B       L
	 67      C       M
	 68      D       N
	 69      E       O
	 70      F       P
	 71      G       Q
	 72      H       R
	 73      I       S
	 74      J       T
	 75      K       U
	 76      L       V
	 77      M       W
	 78      N       X
	 79      O       Y
	 80      P       Z
	 81      Q       A
	 82      R       B
	 83      S       C
	 84      T       D
	 85      U       E
	 86      V       F
	 87      W       G
	 88      X       H
	 89      Y       I
	 90      Z       J

-10

*/

#include <stdio.h>
#include <string.h>
#define SUBSTITUTEA 'K'

main( ) {
	char c;
	char f = SUBSTITUTEA;

	while( (c = getchar() ) != EOF ) {
		c = toupper(c);
		if ( c >= 'A' && c <= 'Z' )
			putchar( (c -'A'+(f-'A')) % ('Z'-'A'+1) + 'A' );
		else
			putchar(c);
	}
}
