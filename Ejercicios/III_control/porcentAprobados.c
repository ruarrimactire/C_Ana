/* Errato
 * Author: 
 *
 * Created on November 26, 2014, 5:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
	char nombre[50];
	float nota.teorica;
	float nota.practica;       
}tficha;

int main() {
	tficha var[100];
	int n = 0, i = 0;
	char *fin = NULL;
	int aprobados, suspendidos;

	fin = gets(var[n].nombre);
	fflush(stdin);

	while{
		scanf("%f", &var[n].nota.teoria);
		scanf("%f", &var[n].nota.pract);
		n++;
		fflush(stdin);
	}

	typedef struct{
		char nombre[50];
		float nota.teoria;
		float nota.practica;
	}tficha;

	if(n==100)
		break;
	fin = gets(var[n].nombre);
	for(i=0; i<n; i++) {
		if(var[i].nota.teoria>=5)
		aprobados++;
		else
		suspensos++;
	}
	printf("%d", suspensos "%d",(float)aprobados ((float)suspensos/n)*100);

	return 0;  
}
