#if !defined(_INTERFAZ_LLSE_H)
#define _INTERFAZ_LLSE_H

#include "elemento.h"

void error(); 

Elemento *nuevoElemento();

void anyadirAlPrincipio(void *e, Elemento **lista);

void *obtener(int i, Elemento *q);

void borrarTodos(Elemento **lista);

#endif
