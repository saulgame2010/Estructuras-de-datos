#include <stdio.h>
#include <stdlib.h>

int vocales(char *);

int main() {
	
	char nombre[20];
	printf("Ingresa tu perro nombre, bastardo\n");
	gets(nombre);
	
	printf("El numero de vocales en tu nombre es: %i", vocales(nombre));
	
	return 0;
}

int vocales(char *ap){
	
	int cont = 0;
	
	while(*ap){
		switch(*ap) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': cont ++;	
		}
		ap++;
	}
	
	return cont;
}
