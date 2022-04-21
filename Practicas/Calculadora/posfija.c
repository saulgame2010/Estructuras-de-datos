#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADPilaDin.h"
// #include "TADPilaEst.h"
#include <math.h>

/*Aqui se revisa que los cadParentesis
esten bien escritos, si es asi, retorna
un int 1, si esta mal retorna un 0
*/
int cadParentesis(char cadena[], int tam_cadena){
	int i,j;

	pila mi_pila; //Aqui se crea la pila
	elemento e1; //Declaramos un elemento
	Initialize(&mi_pila); //Inicializamos la pila

	for(i=0;i<tam_cadena;i++){	/*Aqui se recorre la expresion, si es un "("se mete a la pila*/
		if(cadena[i]=='('){
			e1.c='(';
			Push(&mi_pila,e1);
		}
		else if(cadena[i]==')'){ /*Si se intenta sacar un elemento pero la pila esta vacia manda error*/
			if(Empty(&mi_pila))
					return 0;
				e1=Pop(&mi_pila);
			}
	}

  //Aqui revisa si falta algun elemento, como un parentesis
	if(!Empty(&mi_pila))
		return 0;

  //Si todo salio como debia, manda alv la pila
	Destroy(&mi_pila);
	return 1;
}


//Aca revisamos que tipo de operador es y le damos su prioridad
int tipoOperador(elemento e){
	char op; //esta es la variable del operador
	op = e.c;
	if(op == '-' || op == '+')
		return 2;
	if(op == '*' || op == '/')
		return 3;
	if( op == '^')
		return 4;
	if(op == ')')
		return 1;
	if(op == '(')
		return 0;
	if(op>64 && op<91)
		return 6;

	return 5;
}
/*Aqui se agregan los elementos a la pila donde estara la expresion postfija
vamos a recibir al elemento op, la referencia a la pila (*X), un arreglo pos[] en donde
vamos  aguardar la expresion ya en postfijo, un apuntador *j que nos ayudara como referencia
al contador de la expresion posfija y tipo, que es el tipo de operador que se metera a la pila*/
void agregarOp(elemento op, pila *X, elemento pos[], int *j, int tipo){
	switch(tipo){ /*Este switch es para ver el valor del tipo de operador, este valor es el que le dimos
		en la funcion tipoOperador*/
		case 0: //Si es 0 significa que es parentesis '(', así que se va a ingresar siempre, o sea, hara un push
			Push(X, op);
		break;
		case 1: //si es 1 significa que es ')' asi que hara un pop XD
			while(tipoOperador(Top(X)) != 0){
				pos[*j] = Pop(X); //Saca de la pila al '('
				(*j)++;
			}
			Pop(X);
		break;
		case 2: case 3: case 4: //Este es para los demas operadores y siempre hara push
			if(Empty(X) == TRUE || tipo > tipoOperador(Top(X))){
				Push(X, op);
			}else{ /*Si no es ningun caso de los anteriores se hace un pop siempre y cuando la pila no este vacia
				o si el operador que se va a ingresar es menor o igual en valor al que ya esta adentro*/
				while(Empty(X) == FALSE && tipo <= tipoOperador(Top(X))){
					pos[*j] = Pop(X);
					(*j)++;
				}
				Push(X, op);
			}
		break;
	}
}
/*aqui consulta el valor que el usuario le dio a cada una de las letras que ingreso
el char que recibe, es la letra/s que el usuario ingreso. el int[] es un arreglo de tablaValores
(los de las letras) y retorna los valores*/
int consultaValor(char c, int valores[]){

	return valores[c-'A'];
}

/*Esta madre evalua la expresion posfija, recibe el arreglo expPos[]  que es una cadena(la expresion postfija)
tambien recibe el arreglo valores[] que son los valores de las letras que ingresa el usuario*/
float resExpresion(char expPos[], int valores[]){
	int c,i;
	elemento aux, val, operando1, operando2;
	pila numeros; //esta es la pila que nos ayudara a evaluar los numeritos
	Initialize(&numeros); //inicializamos la pila

	for(c=0; c<strlen(expPos); c++){//Se asigna a la variable auxiliar el valor de la exp Posfija en la posicion de c
		aux.c = expPos[c];

		if(tipoOperador(aux) == 6){ /*si el elemento que esta en aux es de tipo operador 6
			(o sea, el valor que le dimos en la funcion tipoOperador)significa que es una letra, por lo tanto entra a la condicion*/
			val.f = (float)consultaValor(expPos[c], valores); /*val es un flotante,
			 se le asigna el valor que se consulta de la letra que esta en ese momento en expPos[c]*/
			Push(&numeros, val); //metemos el valor de val a la pila
		}
		if(tipoOperador(aux) < 5){ //si esto es menor a 5, significa que es un operador
			/*Vamos a sacar los dos operadores que estan en la cima y los pondremos en
			operando1 y operando2 respectivamente*/

			operando1 = Pop(&numeros);
			operando2 = Pop(&numeros);

			switch(expPos[c]){ /*aqui se hacen las operaciones, val tendra el resultado de la operacion*/
				case '+':
					val.f = operando1.f + operando2.f;
				break;

				case '-':
					val.f = operando2.f - operando1.f;
				break;

				case '*':
					val.f = operando1.f * operando2.f;
				break;

				case '/':
					val.f = operando2.f / operando1.f;
				break;

				case '^':
					val.f = pow(operando2.f, operando1.f);
				break;
			}

			Push(&numeros, val);//pa' dentro
		}
	}
	/*aqui se verifican errores, al final soo debe quedar un elemento, si quedan mas, esta mal*/
	if(Size(&numeros) > 1){
		system("cls");
		for(i=0; i<10; i++)
			system("@path && echo ---System protection permision denied---");
		printf("Hubo un error en la redaccion de tu expresion\n");
		return -1;
	}
	val = Pop(&numeros);
	return  val.f;
}
/*Aqui se reciben los valores que el usuario le dara a cada letra, tambien se recibe la exp posfija*/
void tablaValores(char expPos[], int valores[]){
	int c, valorTemp, pos;
	elemento aux;
	for(c=0; c<strlen(expPos); c++){
		aux.c = expPos[c];
		if(tipoOperador(aux) == 6){
			pos = expPos[c] - 'A';;
			if(valores[pos] == -1){ /*Si es -1 significa que no se le ha asignado un valor.*/
				printf("Introduce el valor de la variable %c: ", expPos[c]);
				fflush(stdin);
				scanf("%d", &valorTemp);
				valores[expPos[c] - 'A'] = valorTemp;
			}
		}
	}
}

int main(){

	int k, m, tam, i, jpos=0, x=10, valores[26];
	char cad[100], cadPos[100]; //la primera es la que da el usuario, la segunda es donde se guarda la posfija
	elemento arrElemento[100], pos[100]; /*En la primera se copia la cadena dada por el usuario
	en la segunda se guarda la posfija*/
	float res; //este sera el resultado calculado
	printf("Ingresa la expresion infija: ");
	scanf("%s", &cad);
	system("cls");
	printf("Expresion infija: %s\n", cad);
	tam = strlen(cad);

	for (i = 0; i < tam; ++i){
		arrElemento[i].c = cad[i];
	}


	if(cadParentesis(cad, tam) == 0){//si esto se cumple, significa que esta mal escrita la expresion
		printf("ERROR: expresion mal escrita\n");
		exit(0);
	}

	pila p;
	Initialize(&p);


	for(i=0; i<tam; i++){
		if(tipoOperador(arrElemento[i]) < 5){
			agregarOp(arrElemento[i], &p, pos, &jpos, tipoOperador(arrElemento[i]));
		}
		else{
			pos[jpos] = arrElemento[i];
			jpos++;
		}
	}

	while(Empty(&p) == FALSE){
		pos[jpos] = Pop(&p);
		jpos++;
	}
	pos[jpos].c = '\0';

	//Imprime la cadena posfija
	for(i=0; pos[i].c != '\0'; i++){
		cadPos[i] = pos[i].c;
	}
	cadPos[i] = '\0';

	strupr(cadPos);

	for(i=0; i<26; i++) //esta cosa le asigna un -1 en los espacios del arreglo donde no se haya guardado un valor
		valores[i] = -1;

	printf("Expresion postfijas: %s\n", cadPos);


	tablaValores(cadPos, valores);

	printf("\n\n-------------------------------------\nResultado: %.2f\n", resExpresion(cadPos, valores));
	Destroy(&p);
}
