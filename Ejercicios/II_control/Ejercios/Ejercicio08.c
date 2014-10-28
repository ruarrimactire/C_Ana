#include <stdio.h>
#define NALUMNOS 5 //Num. Max. de alumnos

int main()
{
    float notas[NALUMNOS];
    int i=0;
    int nalumnos=0;
    float suma=0;
	
    //Ahora pide el número de alumnos
    do{
          printf("Numero de alumnos: ");
          scanf("%d", &nalumnos);                
	} while(nalumnos < 1 || nalumnos > NALUMNOS); //No va, seria: 'Nalumnos'??
    
    for(i=0; i<nalumnos; i++){
             printf("Alumno numero %3d, nota media: ", i+1);
             scanf("%f", &notas[i]);  //No va           
             }
			 
    for(i=0; i<nalumnos; i++) {
		suma=suma+notas[i];
    }
	
    printf("\n\nNota media del curso: %5.2f\n", suma/nalumnos);
    
    getchar();
    getchar();
    return 0;
}
