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
  nodo *sugarDaddy;
};

//Prototipos
void menu();
nodo *crearNodo(int, nodo*);
void insertar(nodo *&, int, nodo*);
void mostrarArbol(nodo*, int);
bool buscarNodo(nodo *, int);
int alturaArbol(nodo*);
void verArbol(nodo*, int);
int contarHojas(nodo*);
void eliminar(nodo*, int);
void eliminarNodo(nodo*);
nodo *zurdo(nodo*);
void cambio(nodo*, nodo*);
void matarNodo(nodo*);
void preOrden(nodo*);
void enOrden(nodo*);
void posOrden(nodo*);

nodo *arbol = NULL;
int numNodos = 0;
//Funcion para crear el arbol (la raiz)
nodo *crearNodo(int n, nodo *sugarDaddy) {
  nodo *nuevo_nodo = new nodo();

  nuevo_nodo -> dato = n;
  nuevo_nodo -> izq = NULL;
  nuevo_nodo -> der = NULL;
  nuevo_nodo -> sugarDaddy = sugarDaddy;

  return nuevo_nodo;
}

//Inserta nodos al arbol
void insertar(nodo *&arbol, int n, nodo *sugarDaddy) {
	//verifica si el arbol esta vacio, en caso de ser así, crea el arbol 
  if(arbol == NULL) {
    nodo *nuevo_nodo = crearNodo(n, sugarDaddy);
    arbol = nuevo_nodo;
  } 
  else {
  	//si el arbol ya esta creado, verifica el valor del nodo existente para poner el nuevo nodo del lado izquierdo si es menor que el nodo existente o del lado derecho en caso contrario
    int valorR = arbol -> dato;
    if(n < valorR) {
      insertar(arbol -> izq, n, arbol);
  }
    else {
      insertar(arbol -> der, n, arbol);
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
		//aqui imprime espacios para que se aprecie la estructura del arbol 
		mostrarArbol(arbol -> der, contador + 1);
		for(i = 0; i < contador; i++) {
			cout<<"   ";
		}
		cout<<arbol -> dato<<endl;
		mostrarArbol(arbol -> izq, contador +1);
	}
}

//Busca el nodo deseado por el usuario
bool buscarNodo(nodo *arbol, int n) {
	//Si el arbol esta vacio no tiene datos que buscar
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

//Calcula la altura del arbol
int alturaArbol(nodo *arbol){
	 int AltIzq, AltDer;

    if(arbol == NULL)
        return -1;
    else
    {
        AltIzq = alturaArbol(arbol->izq);
        AltDer = alturaArbol(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
	}
}

//Muestra el arbol y cuenta los nodos del arbol
void verArbol(nodo *arbol, int n){
     if(arbol == NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     numNodos++;
     cout<< arbol->dato <<endl;

     verArbol(arbol->izq, n+1);
}

//Cuenta las hojas del arbol
int contarHojas(nodo *arbol){
        if (arbol == NULL)
        {
                return 0;
        }
        if ((arbol->der == NULL)&&(arbol->izq == NULL))        {
                return 1;
        }
        else{
                return contarHojas(arbol->izq) + contarHojas(arbol->der);
        }
}

//Verifica para luego eliminar
void eliminar(nodo *arbol, int n){ 
	if(arbol == NULL){
		return;
	}
	else if(n < arbol->dato){
		eliminar(arbol->izq, n);
	}
	else if(n > arbol->dato) {
		eliminar(arbol->der, n);
	}
	else {
		eliminarNodo(arbol);
	}
}
//Esta funcion ve el nodo mas izquierdo, el mas pequeño xD
nodo *zurdo(nodo *arbol) {
	if(arbol == NULL) {
		return NULL;
	}
	if(arbol->izq) {
		return zurdo(arbol->izq);		
	}
	else {
		return arbol;
	}
}
//Reemplaza al nodo hijo
void cambio(nodo *arbol, nodo *nuevo) {
	if(arbol->sugarDaddy){
		//Aqui le vamos a dar a su nuevo hijo
		if(arbol->dato == arbol->sugarDaddy->izq->dato){
			arbol->sugarDaddy->izq = nuevo;
		}
		else if(arbol->dato == arbol->sugarDaddy->der->dato){
			arbol->sugarDaddy->der = nuevo;
		}
	}
	if(nuevo){
		//aqui se le da su nuevo padre
		nuevo->sugarDaddy = arbol->sugarDaddy;
	}
}
//Vamos a matar al nodo
void matarNodo(nodo *nodo) {
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}
//Eliminar el perro nodo
void eliminarNodo(nodo *deleteThis){
	//aqui verifica si el nodo a eliminar tiene dos hjos
	if(deleteThis -> izq && deleteThis -> der){
		nodo *menor = zurdo(deleteThis->der);
		deleteThis->dato = menor->dato;
		eliminarNodo(menor);
	}
	//verifica que el nodo a eliminar solo tenga hijo izquierdo
	else if(deleteThis->izq) {
		cambio(deleteThis, deleteThis->izq);
		matarNodo(deleteThis);
	}
	//verifica que el nodo a eliminar solo tenga hijo derecho
	else if(deleteThis->der) {
		cambio(deleteThis, deleteThis->der);
		matarNodo(deleteThis);
	}
	//si el nodo a eliminar no tiene hijos, lo elimina directamente alv
	else {
		cambio(deleteThis, NULL);
		matarNodo(deleteThis);
	}
}

//Imprime en preOrden los nodos
void preOrden(nodo *arbol) {
     if(arbol!=NULL) {
          cout << arbol->dato <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

//Imprime en enOrden los nodos
void enOrden(nodo *arbol){
	if(arbol!=NULL) {
          enOrden(arbol->izq);
          cout << arbol->dato << " ";
          enOrden(arbol->der);
	}
}

//Imprime en posOrden los nodos
void posOrden(nodo *arbol) {
	if(arbol!=NULL) {
          enOrden(arbol->izq);
          enOrden(arbol->der);
          cout << arbol->dato << " ";
	}
}

//Menu de opciones para el usuario
void menu() {
  int dato, op, contador = 0;
  do{
  	cout<<"------MENU------"<<endl;
  	cout<<"Elige una opcion"<<endl;
  	cout<<"1. Insertar valor"<<endl;
  	cout<<"2. Mostrar arbol"<<endl;
  	cout<<"3. Buscar nodo"<<endl;
  	cout<<"4. Altura del arbol"<<endl;
  	cout<<"5. Numero de nodos"<<endl;
  	cout<<"6. Numero de hojas"<<endl;
  	cout<<"7. Eliminar un nodo"<<endl;
  	cout<<"8. Recorrido preorden"<<endl;
  	cout<<"9. Recorrido enorden"<<endl;
  	cout<<"10. Recorrido en posorden"<<endl;
  	cout<<"11. Salir"<<endl;
  	cin>>op;
  	switch (op) {
    	case 1:
    		cout<<"Ingresa un numero"<<endl;
    		cin>>dato;
    		insertar(arbol, dato, NULL);
    		cout<<"\n";
    		system("pause");
    		break;
		case 2:
			cout<<"Mostrando el arbol de forma HORIZONTAL\n\n";
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
		case 4: 
			int h;
            h = alturaArbol(arbol);
            cout << " La altura es : "<< h << endl;
			system("pause");
			break;
  		case 5:
  			verArbol(arbol, 0);
            cout << "\n\n El numero de nodos es:\n ";
            cout << numNodos;
            system("pause");
			break;
		case 6:
			int g; 
			g = contarHojas(arbol);
			cout<<"El numero de hojas es: "<<g<<endl;
			system("pause");
			break;
		case 7:
			cout<<"\nDigite el valor del nodo que quiere eliminar: ";
			cin>>dato;
			eliminar(arbol, dato);
			cout<<"\n";
			system("pause");
			break;
		case 8:
			preOrden(arbol);
			system("pause");
			break;
		case 9:
			enOrden(arbol);
			system("pause");
			break;
		case 10:
			posOrden(arbol);
			system("pause");
			break;		
		}
  		system("cls");
  	}while(op != 11);  	
}
/*dios, mátame*/
int main(int argc, char const *argv[]) {
	system("color 0d");
  	menu();
  	return 0;
}
