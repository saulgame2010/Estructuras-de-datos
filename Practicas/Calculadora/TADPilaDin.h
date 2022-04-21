//DEFINICIONES DE CONSTANTES
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	char c;
	int q;
	float f;
	//***
	//***
	//***
}elemento;

//Definir un nodo que sera utilizado para almacenar una posicion de la pila (Nodo), lo que incluira a un elemento y a un apuntador al siguiente nodo
typedef struct nodo
{
	//Elemento a almacenar en cada nodo de la pila
	elemento e;
	//Apuntador al elemento de debajo
	struct nodo *abajo;
}nodo;

//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila
{
	nodo *tope;
}pila;

//DECLARACION DE FUNCIONES
void Initialize(pila *s);			//Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e);		//Empilar (Introducir un elemento a la pila)
elemento Pop (pila *s);				//Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s);				//Vacia (Preguntar si la pila esta vacia)
elemento Top(pila *s);				//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
int Size(pila *s);					//Tamaño de la pila (Obtener el número de elementos en la pila)
void Destroy(pila *s);				//Elimina pila (Borra a todos los elementos y a la pila de memoria)
