#include <stdio.h>
#include <iostream>
#include <stdlib.h>

use namespace std;

struct jajaPila {
	char dato;
	jajaPila *sig;
};

void agregarPila(jajaPila *&pila, char dato) {
	jajaPila *nuevaPila = new jajaPila();
	nuevaPila->dato = 'a';
	nuevaPila->sig = pila;
	pila = nuevaPila;
}
