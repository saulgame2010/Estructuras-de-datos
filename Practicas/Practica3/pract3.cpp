#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#define max 100
 
using namespace std;
 
struct nodo {  
       char palabra;
       struct nodo *sgte;
       };
 
typedef struct nodo *TPila; 
typedef struct nodo *Tlista; 
 
 
void push(TPila &,char);
char pop(TPila &);
void agrega(Tlista &,char);
void deletee(TPila &);
int  pin(char );
int  ppila(char );
void mostrar( Tlista &);
void simbs( TPila &, char []);
 
  int main(void)
    {   TPila p=NULL;
        TPila M=NULL;
        Tlista lista=NULL;
        char cad[max], c,x;
        int tam;
 
        system("color 0d");
        
        do{
           cout<<"Ingresa una expresion:";
           gets(cad);
              if(M!=NULL)
                 deletee(M);
           simbs(M,cad); 
           }while(M!=NULL);         
 
        tam=strlen(cad);
        for(int i=0;i<tam;i++)
        {
            if((cad[i]>=49&&cad[i]<=57)||(cad[i]>=97&&cad[i]<=122))
                agrega(lista,cad[i]);
            if(cad[i]=='+'||cad[i]=='-'||cad[i]=='*'||cad[i]=='/'||cad[i]=='('||cad[i]=='^')
            {   if(p==NULL)
                    push(p,cad[i]);
                else
                {
                    if(pin(cad[i])>ppila(p->palabra))
                        push(p,cad[i]);
                    else
                    {   if(pin(cad[i])==ppila(p->palabra))
                          {
                            c=pop(p);
                            agrega(lista,c);
                            push(p,cad[i]);
                          }
                        else
                          {
                            c=pop(p);
                            agrega(lista,c);
                          }
                    }
                }
            }
            if(cad[i]==')')
               {
                while(p->palabra!='('&&p!=NULL)
                   {
                       c=pop(p);
                       agrega(lista,c);
                    }
                if(p->palabra=='(')
                        c=pop(p);
                }
        }
        while(p!=NULL)
            {
                c=pop(p);
                agrega(lista,c);
            }
 
        mostrar(lista);
        system("pause");
        return 0;
    }
 

void push(TPila &p,char a)
{
    TPila q=new struct nodo;
    q->palabra=a;
    q->sgte=p;
    p=q;
 }
 

char pop(TPila &p)
{
    int n;
    TPila aux;
 
    n=p->palabra;
    aux=p;
    p=p->sgte;
    delete(aux);
    return n;
 
}

void simbs( TPila &p, char cad[])
{
     TPila aux;
     int i = 0;
 
     while( cad[i] != '\0')
     {
            if( cad[i]=='(' || cad[i]=='[' || cad[i]=='{' )
            {
                 push( p, cad[i] );
            }
            else if( cad[i]==')' || cad[i]==']' || cad[i]=='}' )
            {
                 aux = p;
 
                 if(aux!=NULL)
                 {
                      if( cad[i]==')' )
                      {
                           if( aux->palabra == '(')
                              pop( p );
                      }
                      else if( cad[i]==']' )
                      {
                           if( aux->palabra == '[')
                              pop( p );
                      }
                      else if( cad[i]=='}' )
                      {
                           if( aux->palabra == '{')
                              pop( p );
                      }
                 }
                 else
                     push( p, cad[i] );
            }
            i++;
     }
 
     if(p==NULL)
         cout<<"\nListo"<<endl<<endl;
     else
         cout<<"\n\tfalta algun parentesis"<<endl;
 
 
}

void deletee(TPila &M)
{    TPila aux;
 
     if(M !=NULL)
     {
         while(M!=NULL)
         {
             aux=M;
             M=M->sgte;
             delete(aux);
         }
 
      }
}
 

int pin(char a)
{
    if(a=='^')
        return 4;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 5;
}

void agrega(Tlista &lista,char a)
{
    Tlista t, q = new(struct nodo);
 
    q->palabra  = a;
    q->sgte = NULL;
 
    if(lista==NULL)
      {
        lista = q;
      }
    else
      {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
      }
 
}
 

int ppila(char a)
{
    if(a=='^')
        return 3;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 0;
}

void mostrar( Tlista &lista)
{
    TPila aux;
    aux=lista;
 
    if(lista!=NULL)
     {    cout<<"\nLa notacion postfija es: ";
          while(aux!=NULL)
          {    cout<<aux->palabra;
               aux = aux->sgte;
          }
      }
      cout<<endl<<endl;
}


