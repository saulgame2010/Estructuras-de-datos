#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

//Prototipo de las funciones
void insertarLista(Nodo *&, int);
void insertarNuevoLista(Nodo *&, int);
void buscar();
void recuperar();
void eliminar();
void vaciar();
void imprimir(Nodo *);

int main() {
	
	Nodo *lista = NULL;
	int dato = 10;
	while(dato >= 1){
		insertarLista(lista, dato);
		dato--;	
	}
	system("cls");
	int op;
	do{
	cout<<"Que quieres hacer\n";
	cout<<"1. Insertar salon\n2. Buscar salon\n3. Recuperar salon\n4. Eliminar salon\n5. Vaciar lista\n6. Imprimir lista\n7. Salir\n";
	cin>>op;
	switch(op) {
		case 1:
			int dat;
			cout<<"\nDigite un salon ";
			cin>>dat;
			insertarNuevoLista(lista, dat);
			system("pause");
			break;
		case 2:
			buscar();
			system("pause");
			break;
		case 3:
			recuperar();
			system("pause");
			break;
		case 4:
			eliminar();
			system("pause");
			break;
		case 5:
			vaciar();
			system("pause");
			break;
		case 6:
			imprimir(lista);
			system("pause");
			break;
		default:
		cout<<"Sale pues, bye";
		break;					
	}	
	system("cls");
} while(op != 7);
	
	getch();
	return 0;
}

void buscar() {
	cout<<"Que buscas ewe";
}

void recuperar() {
	cout<<"Que vas a recuperar ewe";
}

void eliminar() {
	cout<<"Que vas a eliminar ewe";
}

void vaciar() {
	cout<<"Vacio";
}

void imprimir(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL) {
		cout<<"Salon No. "<<actual->dato<<"\n";
		actual = actual->siguiente;
	}
}

void insertarLista(Nodo *&lista, int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1) {
		lista = nuevo_nodo;
	}else{
		aux2->siguiente = aux1;
	}
	nuevo_nodo->siguiente = aux1;
	cout<<"Se inserto el salon "<<n<<" en la lista\n";
}

void insertarNuevoLista(Nodo *&lista, int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1) {
		lista = nuevo_nodo;
	}else{
		aux2->siguiente = aux1;
	}
	nuevo_nodo->siguiente = aux1;
	
	cout<<"El elemento "<<n<<" se inserto correctamente en la lista\n";
}
/*
void eliminaRepetidos(Tlista &lista, int valor)
{
    Tlista q, ant;
    q = lista;
    ant = lista;
 
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }
 
    }// fin del while
   
    cout<<"\n\n Se elimino el elemento repetido"<<endl;
}
*/
