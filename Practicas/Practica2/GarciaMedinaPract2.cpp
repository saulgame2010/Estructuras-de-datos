#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct nodo {
      char dato;
      struct nodo *sgte;
};

typedef struct nodo *TPila;


TPila crearNodo(char x) {
      TPila newNodo = new(struct nodo);
      newNodo->dato = x;
      return newNodo;
}

void push(TPila &top, char x) {
     TPila aux = crearNodo(x);
     aux->sgte = top;
     top = aux;
}

char pop(TPila &top) {
     char c;
     TPila aux;
     
     aux = top ;
     c = aux->dato;   
     top = aux->sgte ;
     delete(aux);
     return c;
}

void invertirCadena( TPila &p, string &cad ) {
   
     for(int i=0; i<cad.size(); i++)
          push(p, cad[i]);  
    
     
     for(int i=0; i<cad.size(); i++)
          cad[i] = pop( p );   
           
}

int main() {
	system("color 0d");
    TPila pila = NULL;   
    string cad, cad1;
    
    cout << " Ingrese palabra: ";
    getline(cin, cad);
    
    cad1 = cad;
    
    invertirCadena(pila, cad);
    
    cout << "\n\n Cadena invertida: " << cad <<endl;
    
    if(cad.compare(cad1) == 0) {
    	cout << "\nLa palabra es un palindromo";
	} else {
		cout << "\nLa palabra no es un palindromo";
	}
    cout<<"\n\n ";
    system("pause");
    return 0;
}
