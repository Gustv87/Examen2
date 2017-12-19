#include<iostream>
#include<conio.h>
#include<stdlib.h>

struct Nodo{
    int dato;
    Nodo *derecha;
    Nodo *izquierda;
};

Nodo *crearNodo(int);
void agregarNodo(Nodo *&, int);


Nodo *arbol = NULL;



int main (){

    getch();
    return 0;
}

//Funcion para crear un nodo nuevo

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda= NULL;

    return nuevo_nodo;
}

//Funcion para agregar un nodo

void agregarNodo(Nodo *&arbol, int n){
    if(arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(n);
    }
}


