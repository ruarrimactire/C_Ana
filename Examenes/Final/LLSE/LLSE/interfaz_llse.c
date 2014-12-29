#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

void error()
{
	printf("Insuficiente memoria\n");
	exit(1);
}

Elemento *nuevoElemento() {
	Elemento *q = (Elemento *)malloc(sizeof(Elemento));
	if(!q)
		error();
	return q;
}

void anyadirAlPrincipio(void *e, Elemento **lista) {
	Elemento *p = *lista;
	Elemento *q = nuevoElemento();
	q->dato = e;
	q->siguiente = p;
	p = q;
	*lista = p;
}

void *obtener(int i, Elemento *q) {
	int n = 0;
	if(q == NULL) {
		printf("lista vacia\n");
		return NULL;
	}
	if(i >= 0) {
		for(n=0; q != NULL && n<i; n++)
			q = q->siguiente;
		if(q != NULL)
			return q->dato;
	}
	return NULL;
}

void borrarTodos(Elemento **lista) {
	Elemento *p=*lista, *q=NULL;

	while(p != NULL)
	{
		q=p;
		p=p->siguiente;
		free(q);
	}
	*lista=NULL;
}

