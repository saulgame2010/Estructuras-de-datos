#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

struct guns {
	int no;	
	guns *sig;
};

void insertar(guns *gnr, int no);

int main() {
	system("COLOR 0d");
	guns *gnr = NULL;
	int no;
	cout<<"Orale, pon el numero ";
	cin>>no;
	insertar(gnr, no);
	
	return 0;
}
 	
void insertar(guns *gnr, int no) {
	guns *nuevo = new guns();
	nuevo->no = no;
	guns *aux1 = gnr;
	guns *aux2;
	
	while((aux1 != NULL) && (aux1->no < no)) {
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	
	if(gnr == aux1){
		gnr = nuevo;
	} else {
		aux2->sig = nuevo;
	}
	
	nuevo->sig = aux1;
	cout<<"jsjs "<<no<<" agregado";
}
