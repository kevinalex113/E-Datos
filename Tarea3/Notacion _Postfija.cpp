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
	char expresion[21]={ }, car, aux[21]={ };
	int i=0, j=0;
	cout << "Ingrese la expresion" << '\n';fflush(stdout);
	scanf("%s", expresion);
	while(expresion[i]!='\0'){
		if(expresion[i]>47&&expresion[i]<58){
			cout << expresion[i];
			aux[j]=expresion[i];
			j++;
		}
		else if(expresion[i]==41){
			while(top->simbolo!=40){
				cout << top->simbolo;
				aux[j]=top->simbolo;
				j++;
				Pop();
			}
			Pop();
		}
		else if(expresion[i]==42 || expresion[i]==43 || expresion[i]==45 || expresion[i]==47||expresion[i]==40){
			if(top==NULL){
				Pila *nuevo = new(Pila);
				nuevo->simbolo=expresion[i];
				Push(nuevo);
			}
			else if((expresion[i]==43||expresion[i]==45)&&(car==42||car==47)){
				cout << top->simbolo;
				aux[j]=top->simbolo;
				j++;
				Pop();
				Pila *nuevo = new(Pila);
				nuevo->simbolo=expresion[i];
				Push(nuevo);
			}
			else{
				Pila *nuevo = new(Pila);
				nuevo->simbolo=expresion[i];
				Push(nuevo);
			}
		}
		i++;
		if(top!=NULL){
			car=top->simbolo;
		}
	}
	while(top!=NULL){
		cout << top->simbolo;
		aux[j]=top->simbolo;
		j++;
		Pop();
	}
	printf("\n\n%s", aux);
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
