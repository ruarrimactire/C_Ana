#include <stdio.h> 
#include <string.h>
#define PEDIDO 1040

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

struct contacto agenda[1000]; 
int posicion = 0;

void PedirContacto(struct contacto age[1000]);
void NuevoPedido(int id, int pedido);

void PedirContacto(struct contacto age[1000]){
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

	age[posicion].numero_pedidos = 0;
	posicion++;
}

void NuevoPedido(int id, int pedido) {
	agenda[id].pedidos[agenda[id].numero_pedidos++] = pedido;
}


int main() { 
	int num_pedido = 0;

	PedirContacto(agenda);
	NuevoPedido(1000, PEDIDO);
	printf("\nNumero de pedidos: %d\n", num_pedido);

	getchar(); 
	getchar();

	return 0;
}