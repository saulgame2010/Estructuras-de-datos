#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
	
	int num, *p_num = &num;
	cout<<"Ingresa un numero\n"<<endl;
	cin>>num;
	
	if(num < 2) {
		cout<<"El numero no es primo\n";
		cout<<"Su pos es: "<<p_num;		
	} else{
		if(num%num == 0 && num%1 == 0){
			cout<<"El numero es primo\n";
			cout<<"Su pos es: "<<p_num;
		}
		else {
			cout<<"El numero es par\n";
			cout<<"Su pos es: "<<p_num;
		}
	}
	
	return 0;
}
