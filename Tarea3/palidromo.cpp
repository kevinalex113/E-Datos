#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Pila{
	char simbolo;
	Pila *siguiente;
};

struct Pila *top = NULL;

void Push(Pila *nuevo);
void Pop();

int main(){
	char palabra[20];
	int i =0, verdad=1;
	cout << "Ingrese la palabra para ver si es palidroma o no:";
	scanf("%s", palabra);
	
	while(palabra[i] != '\0'){
		Pila *nuevo = new(Pila);
		nuevo->simbolo=palabra[i];
		Push(nuevo);
		i++;
	}
	i=0;
	while(palabra[i]!='\0'){
		if(palabra[i]!=top->simbolo){
			verdad=0;
			break;
		}
		else{
			Pop();
		}
		i++;
	}
	if(verdad==1){
		cout<<'\n'<<"La palabra es Palidroma: "<<palabra<<'\n';
	}
	else{
		cout<<'\n'<<"La palabra no es Palidroma: "<<palabra<<'\n';
	}
	return 0;
}


void Push(Pila *nuevo){
	nuevo->siguiente=top;
	top=nuevo;
}

void Pop(){
	Pila *aux;
	if(top){
		aux=top;
		top=aux->siguiente;
		delete(aux);
	}
	else{
		cout << "La lista esta Vacia" << '\n';
	}
}
