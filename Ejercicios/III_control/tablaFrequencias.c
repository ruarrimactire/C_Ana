#include <stdio.h>
#include <stdlib.h>
#define N_ELEMENTOS ('z'-'a'+1) // Porque pongo +1???

main() // Porque no pongo int main()???
{
int c[N_ELEMENTOS]; //Matriz?
char car; /*Indice*/

/*Poner los elementos de la matriz a 0*/

for(car='a'; car<='z'; car++)	
c[car-'a']=0; //??

/*Entrada datos y calculo de la tabla frecuencias*/

printf("Introducir texto.\n");
while((car=getchar())!=EOF)
{   /*Si el caracter leido es de 'a' a 'z' incrementa el contador correspondiente*/
            if(car>='a'&&car<='z')
            c[car-'a']++;     
                           }      
                            
/*Escribir tabla de frecuencias*/  
     
for(car='a'; car<='z'; car++)
printf("%c", car);
printf("\n.......\n");
for(car='a';car<='z'; car++) 
printf("%3d", c[car-'a']);
putchar('\n');      
}
