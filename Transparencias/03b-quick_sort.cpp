#include <stdio.h>

int comparaciones=0;


void Quick(int ent [ ], int a, int b, int sal [ ]);

void Quick(int ent [ ], int a, int b, int sal [ ]){
  int pivote,i=0,j=0,k=0,z=0;
  int ent1[20], ent2[20];
  int sal1[20], sal2[20];
  if(b!=-1) /*solo un elemento*/
	  if(a==b)
		  sal[0]=ent[a];
	  else /*dos elementos*/
		  if(1==(b-a)){
			  if(ent[a]<=ent[b]){
				  sal[0]=ent[a];
				  sal[1]=ent[b];
			  }else{
				  sal[0]=ent[b];
				  sal[1]=ent[a];
			  }
			  comparaciones++;
		  }else{ /*tres o mas elementos*/
			  pivote=ent[0];
			  while(k<=b){
				  if(pivote > ent[k]){
					  ent1[i]=ent[k];
					  i++;
				  }else{ /* pivote es mas pequeño */
					  ent2[j]=ent[k];
					  j++;
				  }
				  k++;
				  comparaciones++;
			  }
			  /* Ordenar particion mas pequeña */
			  Quick(ent1,0,i-1,sal1);
			  /* Ordenar particion mas grande */
			  Quick(ent2,0,j-1,sal2);
			  /* Escribir en salida el vector mas pequeño*/
			  for(k=0;k<i;k++){
				  sal[z]=sal1[k];
				  z++;
			  }
			  /*Escribir pivote*/
			  sal[z]=pivote;
			  z++;
			  /* escribir vector mas grande en salida */
			  for(k=0;k<j;k++){
				  sal[z]=sal2[k];
				  z++;
			  }
}


/*programa principal*/

int main(){
  int vec_ent[20]={6,7,5,8,4,9,3,0,2};
  int n=9;
  int vec_sal[20]; 
	Quick(vec_ent,0,n-1,vec_sal);
}