#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo
    {
    int dato;
    Nodo *derecha;
    Nodo *izquierda;
    };

// Prototipos

Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
void preOrden(Nodo * );
void inOrden(Nodo *);
void postOrden(Nodo *);


int main()
    {
    Nodo *arbol = NULL;

    int n;
    int x;

    cout << "\n -------Arbol Binario-------   \n\n";

    cout << " Cantidad de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
        {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertarNodo(arbol, x);
        }

    cout << "\n Mostrando Arboles Binarios de Busqueda \n\n";
    mostrarArbol(arbol, 0);

    cout << "\n Recorridos del Arboles Binarios de Busqueda..";

    cout << "\n\n En orden   :  ";
    inOrden(arbol);
    cout << "\n\n Pre Orden  :  ";
    preOrden(arbol);
    cout << "\n\n Post Orden :  ";
    postOrden(arbol);

    cout << endl << endl;

    system("pause");
    return 0;
    }


//Funcion para crear un nodo nuevo

Nodo *crearNodo(int n)
    {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;

    return nuevo_nodo;
    }

//Funcion para agregar un nodo

void insertarNodo(Nodo *&arbol, int n)
    {
    if (arbol == NULL)
        {
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
        }
    else
        {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz)
            {
            insertarNodo(arbol->izquierda, n);
            }
        else
            {
            insertarNodo(arbol->derecha, n);
            }
        }
    }

//Funcion para ver el arbol

void mostrarArbol(Nodo *arbol, int cont)
    {
    if (arbol == NULL)
        {
        return ;
        }
    else
        {
        mostrarArbol(arbol->derecha,cont+1);
        for(int i=0; i<cont; i++)
            {
            cout<<"   ";

            }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izquierda,cont+1);
        }
    }
//Funcion PreOrden

void preOrden(Nodo *arbol)
    {
    if(arbol == NULL)
        {
        return;
        }
    else
        {
        cout<<arbol->dato<<" _ ";
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
        }
    }

//Funcion InOrden
void inOrden(Nodo *arbol)
    {
    if(arbol == NULL)
        {
        return;
        }
    else
        {
        inOrden(arbol->izquierda);
        cout<<arbol->dato<<" _ ";
        inOrden(arbol->derecha);
        }
    }

//Funcion postOrden
void postOrden(Nodo *arbol)
    {
    if(arbol == NULL)
        {
        return;
        }
    else
        {
        postOrden(arbol->izquierda);
        postOrden(arbol->derecha);
        cout<<arbol->dato<<" _ ";
        }
    }
