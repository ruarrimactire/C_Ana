#include <stdio.h>
#include <stdlib.h>

int menu (void)
{
	int opc;
	do 
	{ 
		system("cls");
		printf("menu gestion de practicas:\n");
		printf("1 - ejercicios tema1\n");
		printf("2 - ejercicios tema2\n");
		printf("3 - salir\n");
		printf("selecciona una opcion:");
		scanf("%d",&opc);
	}while (opc<1 || opc>3);
		
	return opc;

main(){
	int op;
	op=menu();

int menutema1 (&opc,&opc1)
{

	if (opc == '1' || '2');
	{ 
		int opc1;
		do{
			system("cls");
			printf("menu gestion de practicas:\n");
			printf(">>ejercicios tema 2>\n");
			printf("%d.1 - ejercicios de clase\n");
			printf("%d.2 - ejercicios resueltos\n");
			printf("%d.3 - ejercicios propuestos\n");
			printf("%d.4 - otros\n");
			printf("%d.5 - volver a menu anterior\n");
			printf("%d.6 - salir\n");
			printf("selecciona una opcion:");
			scanf("%d",&opc1);
		}while (opc1<1 || opc1>6);
			return opc1;
	}
}

main(){
	int=op1;
		op1=menutema1();
				



	system("PAUSE");
}