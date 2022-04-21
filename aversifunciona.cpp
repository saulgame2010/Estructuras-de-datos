#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct nodo{
      char dato;
      struct nodo *sgte;
};

typedef struct nodo *TPila;

/*                      Crear Nodo
------------------------------------------------------------------*/

TPila crearNodo(char x)
{
      TPila newNodo = new(struct nodo);
      newNodo->dato = x;
      return newNodo;
}
/*                      Apilar
------------------------------------------------------------------*/
void push(TPila &top, char x)
{
     TPila aux = crearNodo(x);
     aux->sgte = top;
     top = aux;
}
/*                      Desapilar
------------------------------------------------------------------*/
char pop(TPila &top)
{
     int c;
     TPila aux;
     
     aux = top ;
     c = aux->dato;   // asignamos el primer vamor de la pila
     top = aux->sgte ;
     delete(aux);
     return c;
}

/*                      Invertir cadena
------------------------------------------------------------------*/
void invertirCadena( TPila &p, string &cad )
{
     /* Copiando caracteres a la pila */
     for(int i=0; i<cad.size(); i++)
          push(p, cad[i]);  
    
     /* Desapilando y remplanzando en la cadena */
     for(int i=0; i<cad.size(); i++)
          cad[i] = pop( p );   
           
}



/*                   FUNCION PRNCIPAL
------------------------------------------------------------------*/

int main()
{
	system("color 0d");
    TPila pila = NULL;    // creando Pila
    string cad, cad1;
    
    cout<<"\n\t\tINVERTIR CADENA USANDO PILA (STACK) \n\n";
    
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
