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

#include <stdio.h> 
#define PEDIDO 1040 // dato que se ha de escribir en la primera posicion de la lista de pedidos del cliente

struct contacto{ 
       char nombre[30];       //
       char apellidos[50];    //
       char telefono[16];     //
       char direccion[150];   //
       char codigo_postal[5]; //
       float descuento;       // descuento de cliente
       int pedidos[200];      // lista de pedidos del cliente
       int numero_pedidos;    // indice de la lista
}; 

struct contacto agenda[1000]; // array de estructuras -> lista de clientes
int posicion = 0;  // primera posición libre dentro de la lista de clientes
    
// parte 2
void PedirContacto(int idCliente);
void NuevoPedido( int idCliente , int numPedido );

void Imprimir(int idCliente); // función facultativa


int main(int argc, char** argv) {
    PedirContacto(posicion);
    posicion++;
    Imprimir(posicion-1); // función facultativa
    
    NuevoPedido( posicion-1, PEDIDO ); // Pedido por decir numero cualquiera
    Imprimir(posicion-1); // función facultativa

    return 0; 
}

void PedirContacto(int idCliente) {
	printf("Por favor rellene los datos");
	printf("\n Nombre: ");
	gets(agenda[idCliente].nombre);

	printf("\n Apellidos: ");
	gets(agenda[idCliente].apellidos); 

	printf("\n Telefono: ");
	gets(agenda[idCliente].telefono);

	printf("\n Direccion: ");
	gets(agenda[idCliente].direccion);

	printf("\n Codigo Postal: ");
	gets(agenda[idCliente].codigo_postal);

	printf("\n Descuento: ");
	scanf("%f", &agenda[idCliente].descuento);
        
        agenda[idCliente].numero_pedidos = 0;	
}

void NuevoPedido( int idCliente , int numPedido ) {
    agenda[idCliente].pedidos[agenda[idCliente].numero_pedidos] = numPedido;
    agenda[idCliente].numero_pedidos++;

// equivalente:
// agenda[idCliente].pedidos[agenda[idCliente].numero_pedidos++] = numPedido;
}

////////////////////////////// ///función facultativa///////////////////////////
void Imprimir(int idCliente) {
    
    printf("\n Nombre:        %s " , agenda[idCliente].nombre        );
    printf("\n Apellidos:     %s " , agenda[idCliente].apellidos     );
    printf("\n Telefono:      %s " , agenda[idCliente].telefono      );
    printf("\n Direccion:     %s " , agenda[idCliente].direccion     );
    printf("\n Codigo Postal: %s " , agenda[idCliente].codigo_postal );
    printf("\n Descuento:     %1.2f %%" , agenda[idCliente].descuento     );
    for(int i=0; i < agenda[posicion-1].numero_pedidos; i++){
                    printf("\n\t Pedido:  %d " , agenda[idCliente].pedidos[i] );
    }
    printf("\n Introduce envio: \n");
    getchar();

}
////////////////////////////// ///función facultativa///////////////////////////
