/* 
 * File:   13.c
 * Author: Filippo
 *
 * Created on November 8, 2014, 1:30 PM
 * 
 * 
 * int main(int argc, char** argv) {
 * 
 *     return (EXIT_SUCCESS);
 * }
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#define N 1000
#include <string.h>
#include<ctype.h>

typedef struct
{
	char nombre[30];
	char apellidos[50];
	long telefono [16];
	char direccion [150];
	int codigo_postal[5];
	float descuento;
	int pedidos[200];/*array con el numero de pedidos realizados*/
	int numero_pedidos; /*nos dice el numero de pedidos que hay ya en el array*/
}contacto;

contacto agenda[N];

void PedirContacto(int indice);
void NuevoPedido(int indice,int Pedido); /*num hace referencia a num_pedidos*/

main() {
	int Pedido=0;
	PedirContacto(N);
	NuevoPedido(N,Pedido);
	printf("\nNumero de pedidos: %d\n",Pedido);
	system("pause");
}

void PedirContacto(int indice) {
	char res='s';
	while(tolower(res)=='s' || indice<N) {
		printf("Introduce los datos del contacto:\n");
		
		printf("Nombre: ");
		gets(agenda[indice].nombre);
		
		printf("Apellidos: ");
		gets(agenda[indice].apellidos);
		
		printf("Telefono: ");
		scanf("%d",&agenda[indice].telefono);
		fflush(stdin);
		
		printf("Direccion: ");
		gets(agenda[indice].direccion);
		
		printf("Codigo Postal: ");
		scanf("%d",&agenda[indice].codigo_postal);
		fflush(stdin);
		
		printf("Descuento: ");
		scanf("%f",&agenda[indice].descuento);
		
		agenda[indice].numero_pedidos=0;
		indice++;
		fflush(stdin);
		
		do{
			printf("Mas datos a introducir?[s/n]: ");
			res=getchar();
			fflush(stdin);
		} while(tolower(res)!='s' && tolower(res)!='n');
	}
}

void NuevoPedido(int indice,int Pedido) {
	agenda[indice].pedidos[agenda[indice].numero_pedidos++]=Pedido;
}
