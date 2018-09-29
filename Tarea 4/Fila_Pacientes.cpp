#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct Paciente{
    string nombre;
    int edad;
    string enfermedad;
    Paciente *siguiente;
};

Paciente *front;
Paciente *back;

Paciente *crear();
void Enqueue(Paciente *nuevo);
void Dequeue();
void Front();
void Back();
bool Empty();
int Sizeof();
void menu();

int main(){
    int opcion;
    bool invalido, repetir=true;
    cout << "******************************************************************" << '\n' ;
	cout << "****************************BIENVENIDO****************************" << '\n' ;
	cout << "******************************************************************" << '\n' ;
    do{
        do{
	        menu();
	        fflush(stdin);
	        cin >> opcion;
	        invalido = false;
	        if(opcion<0||opcion>7){
	            cout << "Opcion Invalida" << '\n' ;
	            invalido = true;
	        }
        }while(invalido);
        switch(opcion){
            case 1:{
				Paciente *nuevo = crear();
				if(front==NULL&&back==NULL){
                	front=nuevo;
                	back=nuevo;
				}
				else{
                	Enqueue(nuevo);
            	}
                break;
            }
            case 2:{
                Dequeue();
                break;
            }
            case 3:{
                Front();
                break;
            }
            case 4:{
                Back();
                break;
            }
            case 5:{
                if(Empty()){
                    cout << "La lista esta vacia" << '\n' ;
                }
                else{
                    cout << "La lista esta LLena" << '\n' ;
                }
                break;
            }
            case 6:{
                cout << "El numero de pacientes en la fila es de: " << Sizeof() << '\n' ;
                break;
            }
            case 7:{
                cout << "******************************************************************" << '\n' ;
				cout << "**********************Adios, Hasta la Proxima**********************" << '\n' ;
				cout << "******************************************************************" << '\n' ;
                repetir = false;
                break;
            }
        }
    }while(repetir);
    while(front=NULL){
        Dequeue();
    }
    return 0;
}

void menu(){
	cout << '\n' << "*******************************MENU*******************************" << '\n' ;
	cout << "1.- Enqueue: Inserta un elemento en la cola" << '\n' ;
    cout << "2.- Dequeue: Saca un elemento de la cola y lo regresa" << '\n' ;
    cout << "3.- Front: Regresa el elemento que esta al principio de la cola sin sacarlo." << '\n' ;
    cout << "4.- Back: Regresa el ultimo elemento de la cola sin sacarlo." << '\n' ;
    cout << "5.- Empty: Regresa Verdadero (o cero) si la cola esta vacia, o falso en caso contrario" << '\n' ;
    cout << "6.- Size: Regresa el numero de elemento de la cola" << '\n' ;
	cout << "7.- Salir" << '\n' ;
	cout << "******************************************************************" << '\n' ;
	cout << "¿Que es lo que quiere realizar?" << '\n';
}

Paciente *crear(){
    Paciente *nuevo = new(Paciente);
    cout << "Nombre del Paciente" << '\n' ;fflush(stdin);
    cin >> nuevo->nombre;
    cout << "Edad del Paciente" << '\n' ;
    cin >> nuevo->edad;
    cout << "Enfermedad del Paciente" << '\n' ;fflush(stdin); 
    cin >> nuevo->enfermedad;
    nuevo->siguiente = NULL;
    return nuevo;
}

void Enqueue(Paciente *nuevo){
    back->siguiente = nuevo;
	back = nuevo;
}

void Dequeue(){
    Paciente *aux;
	if(front!=NULL&&back!=NULL){
		aux = front;
		front=aux->siguiente;
        cout << "Paciente que sale:" << '\n' ;
        cout << "Nombre: " << aux->nombre << '\n' ;
        cout << "Edad: " << aux->edad << '\n' ;
        cout << "Enfermedad: " << aux->enfermedad << '\n' ;
		delete(aux);
	}
	else{
		cout << "Lista Vacia" << '\n' ;
	}
}

void Front(){
    cout << "Primer Paciente:" << '\n' ;
    cout << "Nombre: " << front->nombre << '\n' ;
    cout << "Edad: " << front->edad << '\n' ;
    cout << "Enfermedad: " << front->enfermedad << '\n' ;
}

void Back(){
    cout << "Ultimo Paciente:" << '\n' ;
    cout << "Nombre: " << back->nombre << '\n' ;
    cout << "Edad: " << back->edad << '\n' ;
    cout << "Enfermedad: " << back->enfermedad << '\n' ;
}

bool Empty(){
    bool vacio;
    if(front==NULL && back==NULL){
        vacio = true;
        return vacio;
    }
    else{
        vacio = false;
        return vacio;
    }
}

int Sizeof(){
   int tamanio = 0;
    Paciente *aux=front;
	while(aux!=NULL){
		tamanio++;
		aux = aux->siguiente;
	}
	return tamanio;
}
