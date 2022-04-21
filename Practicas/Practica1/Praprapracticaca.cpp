#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int numm;        
       struct nodo *sig;
};
 
typedef struct nodo *lalalista;
 
void insertarInicio(lalalista &lista, int valor)
{
    lalalista q;
    q = new(struct nodo);
    q->numm = valor;
    q->sig = lista;
    lista  = q;
}
 
void insertarFinal(lalalista &lista, int valor)
{
    lalalista t, q = new(struct nodo);
 
    q->numm  = valor;
    q->sig = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sig!=NULL)
        {
            t = t->sig;
        }
        t->sig = q;
    }
 
}
 
int insertarAntesDespues()
{
    int _op, jajanoma;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n"; cin>> _op;
 
    if(_op==1)
        jajanoma = -1;
    else
        jajanoma = 0;
 
    return jajanoma;
}
 
void insertarElemento(lalalista &lista, int valor, int pos)
{
    lalalista q, t;
    int i;
    q = new(struct nodo);
    q->numm = valor;
 
    if(pos==1)
    {
        q->sig = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;
 
        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sig = t->sig;
                t->sig = q;
                return;
            }
            t = t->sig;
        }
    }
    cout<<"   Esa posicion no existe"<<endl;
}
 
void buscarElemento(lalalista lista, int valor)
{
    lalalista q = lista;
    int i = 1, jajanoma = 0;
 
    while(q!=NULL)
    {
        if(q->numm==valor)
        {
            cout<<endl<<" Se encontro el salon en la posicion "<< i <<endl;
            jajanoma = 1;
        }
        q = q->sig;
        i++;
    }
 
    if(jajanoma==0)
        cout<<"\n\n No puedo encontrarlo porque no esta registrado :("<< endl;
}
 
void imprimir(lalalista lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<<"Salon No. " << lista->numm << endl;
          lista = lista->sig;
          i++;
     }
}
 
 
void eliminarElemento(lalalista &lista, int valor)
{
    lalalista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->numm==valor)
            {
                if(p==lista)
                    lista = lista->sig;
                else
                    ant->sig = p->sig;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sig;
        }
    }
    else
        cout<<" Se vacio la lista :D";
}
 
 
void menu()
{
	cout<<"\t\tLista de Salones\n"<<endl;
    cout<<" 1. Agregar un salon al inicio               "<<endl;
    cout<<" 2. Agregar un salon al final                "<<endl;
    cout<<" 3. Agregar salon antes o despues de una posicion         "<<endl;
    cout<<" 4. Imprimir lista de salones                   "<<endl;
    cout<<" 5. Buscar salon                  "<<endl;
    cout<<" 6. Eliminar salon de la posicion 'x'            "<<endl;
    cout<<" 7. Ordenar la lista              "<<endl;
    cout<<" 8. Salir del programa                            "<<endl;
 
    cout<<"\n Elige que es lo que quieres hacer: ";
}

void ordenarLista(lalalista lista)
{
     lalalista actual , siguiente;
     int t;
     
     actual = lista;
     while(actual->sig != NULL)
     {
          siguiente = actual->sig;
          
          while(siguiente!=NULL)
          {
               if(actual->numm > siguiente->numm)
               {
                    t = siguiente->numm;
                    siguiente->numm = actual->numm;
                    actual->numm = t;          
               }
               siguiente = siguiente->sig;                    
          }    
          actual = actual->sig;
          siguiente = actual->sig;
           
     }
     
     cout<<"\n\n\tLista ordenada :D"<<endl;
}
 
 
int main()
{
	system("color 0d");
    lalalista lista = NULL;
    int op;     
    int _dato;  
    int pos;    
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n Salon que se va a registrar: "; cin>> _dato;
                 insertarInicio(lista, _dato);
            break;
 
 
            case 2:
 
                 cout<< "\n Salon que se va a registrar: "; cin>> _dato;
                 insertarFinal(lista, _dato );
            break;
 
 
            case 3:
 
                 cout<< "\n Salon que se va a registrar: ";cin>> _dato;
                 cout<< " Ingrese la posicion de donde quiere partir para insertar el salon: ";       cin>> pos;
                 insertarElemento(lista, _dato, pos);
            break;
 
 
            case 4:
 
                 cout << "\n\n Salones registrados:\n\n";
                 imprimir(lista);
            break;
 
 
            case 5:
 
                 cout<<"\n Salon que desea buscar: "; cin>> _dato;
                 buscarElemento(lista, _dato);
            break;
 
            case 6:
 
                cout<<"\n Salon que desea eliminar: "; cin>> _dato;
 
                eliminarElemento(lista, _dato);
            break;
 			
 			case 7:
 				ordenarLista(lista);
 				break;
 				
            default:
            	cout<<"Esa opcion no esta disponible"<<endl;
 
                    }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=8);
 
 
   system("pause");
   return 0;
}
