
// 13)

#include <stdio.h> 

struct contacto{ 
       char nombre[30]; 
       char apellidos[50];
       char telefono[16];
       char direccion[150];
       char codigo_postal[5];
       float descuento;
       int pedidos[200];
       int numero_pedidos;
}; 

// parte 2
void PedirContacto(struct contacto[]);

int posicion = 0;

int main(int argc, char** argv) {

    struct contacto agenda[1000]; 
    
    PedirContacto(agenda);
	

	printf("\n Nombre:        %s " , agenda[0].nombre        );
	printf("\n Apellidos:     %s " , agenda[0].apellidos     );
	printf("\n Telefono:      %s " , agenda[0].telefono      );
	printf("\n Direccion:     %s " , agenda[0].direccion     );
	printf("\n Codigo Postal: %s " , agenda[0].codigo_postal );
	printf("\n Descuento:     %f " , agenda[0].descuento     );

	printf("\n Introduce envio: \n");
    getchar();
	
    return 0; 
}




void PedirContacto(struct contacto age[]) {
     
	printf("Por favor rellene los datos");
	printf("\n Nombre: ");
	gets(age[posicion].nombre);

	printf("\n Apellidos: ");
	gets(age[posicion].apellidos); //gets(age[posicion].apellidos);

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
