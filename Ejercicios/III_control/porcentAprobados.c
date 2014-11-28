/* 
 * File:   main.c
 * Author: Filippo
 *
 * Created on November 26, 2014, 5:00 PM
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    char nombre[50];
    float nota_teorica;
    float nota_practica;       
}tficha;

int main() {
    tficha var[MAX];
    int n = 0, i = 0;
    int aprobados = 0, suspensos = 0;

    while( 1 ) {
        printf("Nombre?\n");
        gets(var[n].nombre);
        if( !strcmp(var[n].nombre, "") )
            break;
        printf("Nota Teorica? Y Practica?\n");
        scanf("%f", &var[n].nota_teorica);
        scanf("%f", &var[n].nota_practica);
        n++;
        if(n == 100)
            break;
		while (getchar() != '\n'){}
        fflush(stdin);
    }

	printf("Aprobados\nnombre\tnota teorica\tnota practica\n");
    for(i = 0; i < n; i++) {
		if( (var[i].nota_teorica + var[i].nota_practica)/2 >= 5) {
			printf("%s\t%1.2f\t%1.2f\n",var[i].nombre, var[i].nota_teorica, var[i].nota_practica );
            aprobados++;
		}
        else
            suspensos++;
    }
    printf("%d suspensos, %d aprobados: %1.2f%% de suspensos sobre el totál \n", suspensos, aprobados, ((float)suspensos/n)*100);

    return 0;  
}