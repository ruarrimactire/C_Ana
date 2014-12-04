/**************Polinomios*************/
#include <stdio.h>
#include <stdlib.h>
typef struct
{
int grado;
float *coef;      
}tpolinomio;

tpolinomio LeerPol(void)
void VisualizarPol(tpolinomio pol)
tpolinomio sumarPol(tpolinomio A, tpolinomio B);


tpolinomio LeerPol(void)
{
tpolinomio pol;
int i=0;

printf("Grado del polinomio: ");
scanf("%d", &pol.grado);
/*Asignar memoria para el array de coeficientes */
pol.coef=(float *)malloc((pol.grado +1)*sizeof(tpolinomio));
////////Esto lo puedo quitar??///////////
if(pol.coef==NULL)  
{
printf("Insuficiente memoria\n");
exit(-1);                    
}
/////////////////////////////////////////

/*Leer los coeficientes de mayor a menor grado*/
printf("Coeficientes de mayor a menor grado: ");
for(i=pol.grado; i>=0; i--)
scanf("%g", &pol.coef[i]);

return(pol);       
}

void VisualizarPol(tpolinomio pol)
{
int i=0;
/*Escribir los terminos de mayor a menor grado*/
for(i=pol.grado; i>0; i--)
    if(pol.coef[i])printf("%+gx^%d ", pol.coef[i], i); ////?????????   
  /*Escribir el termino independiente*/
  if(pol.coef[i])printf("%+gx^%d ", pol.coef[i])  
}

tpolinomio sumarPol(tpolinomio A, tpolinomio B)
{
int i=0;
tpolinomio polresu, polaux;

/*Hacer que polA sea el de mayor grado*/
if(polA.grado<polB.grado)
{
 polaux=polA;
 polA=polB;
 polB=polaux;               
                         }           
 /*El polinomio resultante tendra como grado, el mayor*/
 polresu.grado=polA.grado;
 
 /*Asignar memoria para el array de coeficientes de polresu*/
 polresu.coef=(float *)malloc((polresu.grado +1)*sizeof(tpolinomio));
 if(polresu.coef==NULL)
 {
       printf("Insuficiente memoria\n");
       exit(-1);
                       
                       }
 /*Sumar polB con los coeficientes correspondientes de polA*/
 for(i=0; i<=polB.grado; i++)
 polresu.coef[i]=polB.coef[i]+polA.coef[i];
 /*A partir del valor actual de i, copiar los coeficientes restantes de polA*/
 for( ; i<=polA.grado; i++)
 polresu.coef[i]=polA.coef[i];
 return (polresu);                      
}

void main(void)
{
    tpolinomio polA, polB, polR;
    
    polA=LeerPol();
    polB=LeerPol();
    polR=SumarPols(polA, polB);
    VisualizarPol(polR);

    
    /*Liberar la memoria asignada*/
    free(polA.coef);
    free(polB.coef);
    free(polR.coef);    
}
