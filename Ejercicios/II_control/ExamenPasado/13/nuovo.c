#include <stdio.h> 
#include <string.h>

struct contacto{ 
 char nombre[30]; 
 char apellidos[50]; //long?
 char telefono[16];
 char direccion[150];
 char codigo_postal[5]; //int?
 float descuento;
 int pedidos[200];
 int numero_pedidos;
}; 

int posicion = 0;

void PedirContacto(contacto age[1000]){
	printf("Por favor rellene los datos");

	printf("\n Nombre: ");
	gets(age[posicion].nombre);

	printf("\n Apellidos: ");
	gets(age[posicion].apellidos); 

	printf("\n Telefono: ");
	gets(age[posicion].telefono);

	printf("\n Direccion: ");
	gets(age[posicion].direccion);

	printf("\n Codigo Postal: ");
	gets(age[posicion].codigo_postal);

	printf("\n Descuento: ");
	scanf("%f", &age[posicion].descuento); 

	posicion++;
}

void NuevoPedido(int (contacto age[1000]), int pedido) {
	agenda[posicion].pedidos[agenda[contacto age[1000]].numero_pedidos++]=pedido;
}

int main() { 
	int num_pedido=0
	struct contacto agenda[1000]; 

	PedirContacto(agenda);
	NuevoPedido(1000,pedido);
	Printf("\nNumero de pedidos: %d\n", num_pedido);

	getchar();
	getchar();

	return 0;
}