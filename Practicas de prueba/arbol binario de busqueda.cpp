#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "iostream"
using namespace std;

struct nodo {
  int dato;
  nodo *izq;
  nodo *der;
};

//Prototipos
void menu();
nodo *crearNodo(int);
void insertar(nodo *&, int);
void mostrarArbol(nodo *, int);
bool buscarNodo(nodo *, int);

nodo *arbol = NULL;

nodo *crearNodo(int n) {
  nodo *nuevo_nodo = new nodo();

  nuevo_nodo -> dato = n;
  nuevo_nodo -> izq = NULL;
  nuevo_nodo -> der = NULL;

  return nuevo_nodo;
}

void insertar(nodo *&arbol, int n) {
  if(arbol == NULL) {
    nodo *nuevo_nodo = crearNodo(n);
    arbol = nuevo_nodo;
  } 
  else {
    int valorR = arbol -> dato;
    if(n < valorR) {
      insertar(arbol -> izq, n);
  }
    else {
      insertar(arbol -> der, n);
    }
  }
}
//Muestra el arbol completo
void mostrarArbol(nodo *arbol, int contador) {
	int i;
	if(arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol -> der, contador + 1);
		for(i = 0; i < contador; i++) {
			cout<<"   ";
		}
		cout<<arbol -> dato<<endl;
		mostrarArbol(arbol -> izq, contador +1);
	}
}

bool buscarNodo(nodo *arbol, int n) {
	if(arbol == NULL) {
		return false;
	}
	else if(arbol -> dato == n) {
		return true;
	}
	else if(n < arbol -> dato) {
		return buscarNodo(arbol -> izq, n);		
	}
	else if (n > arbol -> dato) {
		return buscarNodo(arbol -> der, n);
	}
}

void menu() {
  int dato, op, contador = 0;
  do{
  	cout<<"------MENU------"<<endl;
  	cout<<"Elige una opcion"<<endl;
  	cout<<"1. Insertar valor"<<endl;
  	cout<<"2. Mostrar arbol"<<endl;
  	cout<<"3. Buscar nodo"<<endl;
  	cout<<"4. Salir"<<endl;
  	cin>>op;
  	switch (op) {
    	case 1:
    		cout<<"Ingresa un numero"<<endl;
    		cin>>dato;
    		insertar(arbol, dato);
    		cout<<"\n";
    		system("pause");
    		break;
		case 2:
			cout<<"Mostrando el arbol\n\n";
			mostrarArbol(arbol, contador);
			cout<<"\n";
			system("pause");
			break;
		case 3:
			cout<<"\nDigite el elemento a buscar"<<endl;    		
			cin>>dato;
			if(buscarNodo(arbol, dato) == true) {
				cout<<"\nEl elemento "<<dato<<" ha sido encontrado en el arbol\n";
			}
			else {
				cout<<"\nElemento no encontrado\n";
			}
			cout<<"\n";
			system("pause");
			break;
  		}
  		system("cls");
  	}while(op != 4);  	
}

int main(int argc, char const *argv[]) {
	system("color 0d");
  	menu();
  	return 0;
}
