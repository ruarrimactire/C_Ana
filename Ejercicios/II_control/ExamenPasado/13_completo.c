#include <stdio.h> 

struct contacto{ 
       char nombre[30]; 
       char apellidos[50];
       char telefono[16];
       char direccion[150];
       char codigo_postal[5];
       float descuento;
       int pedidos[200];
       int numero_pedidos=0;
}; 

// parte 2
void PedirContacto(struct contacto[]);
void NuevoPedido( struct contacto[] , int pedido );

int posicion = 0;  // primera posición libre dentro del array de estructuras 

int main(int argc, char** argv) {

	int Pedido=1040;
    struct contacto agenda[1000]; 
    
    PedirContacto(agenda);
	NuevoPedido( agenda, Pedido ); // Pedido por decir numero cualquira
	
	printf("\n Nombre:        %s " , agenda[0].nombre        );
	printf("\n Apellidos:     %s " , agenda[0].apellidos     );
	printf("\n Telefono:      %s " , agenda[0].telefono      );
	printf("\n Direccion:     %s " , agenda[0].direccion     );
	printf("\n Codigo Postal: %s " , agenda[0].codigo_postal );
	printf("\n Descuento:     %f " , agenda[0].descuento     );
	for(int i=0; i < agenda[posicion-1].numero_pedidos; i++){
			printf("\n\t Pedido:     %f " , agenda[posicion-1].pedidos[i]     );
	}
	
	printf("\n Introduce envio: \n");

   	getchar();
getchar();
    	return 0; 
}

void PedirContacto(struct contacto age[]) {
     
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

void NuevoPedido( struct contacto age[] , int pedido ){
	age[posicion-1].pedidos[numero_pedidos] = pedido;
	numero_pedidos++;
}
