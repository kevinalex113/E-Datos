#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Libro {
  char *titulo;
  int anioDePublicacion;
  struct Libro *next;
  struct Libro *Previous;
};

struct Libro *anterior=NULL;
struct Libro *raiz=NULL;

void imprimir_lista(){

}

void aniadir(Libro *&nodo){
  Libro *nuevo = new Libro();
  if (nuevo==NULL)
    printf("Te acabaste la memoria");
  if(raiz== NULL){
    raiz=nuevo;
  }
  else{

  }
  nuevo->next=NULL;
  nuevo->previous=&
}

void borrar(){

}

void obtener(){

}

void modificar(){

}

int main (int args, char *argv[]){
  struct Libro *lista, *cola;

  return 0;
}
