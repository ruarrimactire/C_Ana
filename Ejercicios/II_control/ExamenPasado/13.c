// 13)

#include <stdio.h> 
#include <string.h>
#define SIZE 10

typedef struct { 
       char nombre[30]; 
       char apellidos[50];
       char telefono[16];
       char direccion[150];
       char codigo_postal[5];
       float descuento;
       int pedidos[200];
       int numero_pedidos;
} contacto; 

// parte 2
void PedirContacto(contacto*);

int main(int argc, char** argv) {

	int posicion = 0;

	contacto agenda[SIZE]; 
	for(int i = 0; i < sizeof(agenda)/sizeof(agenda[0]); i++){
		int size = sizeof(agenda[i].pedidos)/sizeof(agenda[i].pedidos[0]);
		strcpy(agenda[i].nombre, "");
		strcpy(agenda[i].apellidos, "");
		strcpy(agenda[i].telefono, "");
		strcpy(agenda[i].direccion, "");
		strcpy(agenda[i].codigo_postal, "");
		agenda[i].descuento = 0;
		for(int j = 0; j < size ; j++){
			agenda[i].pedidos[j] = 0;
		}
		agenda[i].numero_pedidos = 0;
	}

	PedirContacto(&agenda[posicion]);
	posicion++;

	printf("\n Nombre:        %s " , agenda[posicion-1].nombre        );
	printf("\n Apellidos:     %s " , agenda[posicion-1].apellidos     );
	printf("\n Telefono:      %s " , agenda[posicion-1].telefono      );
	printf("\n Direccion:     %s " , agenda[posicion-1].direccion     );
	printf("\n Codigo Postal: %s " , agenda[posicion-1].codigo_postal );
	printf("\n Descuento:     %f " , agenda[posicion-1].descuento     );

	printf("\n Introduce envio: \n");
    getchar();
	
    return 0; 
}

void PedirContacto(contacto *age) {
     
	printf("Por favor rellene los datos");
	printf("\n Nombre: ");
	gets(age->nombre);

	printf("\n Apellidos: ");
	gets(age->apellidos); //gets(age[posicion].apellidos);

	printf("\n Telefono: ");
	gets(age->telefono);

	printf("\n Direccion: ");
	gets(age->direccion);

	printf("\n Codigo Postal: ");
	gets(age->codigo_postal);

	printf("\n Descuento: ");
	scanf("%f", &age->descuento);

}
