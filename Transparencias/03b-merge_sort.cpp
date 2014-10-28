#include <stdio.h>

int comparaciones=0;

void Mezclar(int ent1[], int ent2[], int n1, int n2, int sal[]);
void Ordenar(int ent [ ], int a, int b, int sal [ ]);

void Ordenar(int ent [ ], int a, int b, int sal [ ]){
  int m;
  int sal1[20], sal2[20];
  if(a==b) //solo un elemento
    sal[0]=ent[a];
  else
    if(1==(b-a)) //dos elementos
    {
      if(ent[a]<=ent[b]){
        sal[0]=ent[a];
        sal[1]=ent[b];
      }
      else{
        sal[0]=ent[b];
        sal[1]=ent[a];
      }
      comparaciones++;
    }
    else{
       /*Dividir vectores de 3 o mas*/
       m = a + (b-a)/2; 
       /*Ordena Primera Mitad*/
       Ordenar(ent,a,m,sal1);
       /*Ordena segunda Mitad*/
       Ordenar(ent,m+1,b,sal2);
       /* Mezclar */
       Mezclar(sal1, sal2, (1+m-a), (b-m), sal);     
    }
}


void Mezclar(int ent1[], int ent2[], int n1, int n2, int sal[]){

  int i=0,j=0,k=0;
  while((i<n1) && (j<n2)){
  		/* comprobar si primer elemento es el mas pequeño */
  		if(ent1[i]<=ent2[j]){
  	     sal[k]=ent1[i];
  	     i++;
  		}else{
  		   sal[k]=ent2[j];
  		   j++;
  		}
  		k++;
  		comparaciones++;
  }
      /*comprobar si hay elementos a la izda en el primer vector */
      if(i!=n1){
        do{
          sal[k]=ent1[i];
          i++;
          k++;
        }while(i<n1);
      }else{
        do{
          sal[k]=ent2[j];
          j++;
          k++;
        }while(j<n2);
      }
  
}

/*programa principal*/

int main(){
  int vec_ent[20]={6,7,5,8,4,9,3,0,2};
  int n=9;
  int vec_sal[20]; 
	Ordenar(vec_ent,0,n-1,vec_sal);
}