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
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
Nodo *arbol = NULL;


int main()
    {
    menu();

    getch();
    return 0;
    }


//Menu
void menu()
    {
    int dato, opcion, contador =0;

    do
        {
        cout << "\tMenu" << endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Mostrar el arbol" << endl;
        cout << "3. Salir" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion)
            {
            case 1 :
                cout<<"\nDigite un numero: ";
                cin>>dato;
                insertarNodo(arbol,dato);
                cout<<"\n";
                system("pause");
                break;

            case 2:cout<<"\nArbol Completo:\n\n";
                   mostrarArbol(arbol,contador);
                   cout<<"\n";
                   system("pause");
                   break;

            }
        system("cls");

        }
    while (opcion != 3);
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

