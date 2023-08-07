/**
 * @file Main.cpp
 * @version 1.0
 * @brief main.
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iterator>
#include "Lista.cpp"

using namespace std;


/**
 * Llenamos una lista con elementos aleatorios.
 * @param lista la lista a llenar con elementos aleatorios.
 * @param n el número de elementos que agregaremos a lista.
 */
void llenaLista(Lista<int>* lista, int& n) {
    int c = 0;
    srand((unsigned) time(NULL));   
    while (c < n) {
        int r = (rand() % n) + 1;
        lista->agregaFinal(r);
        c += 1;
    }
}


/**
 * Eliminamos los elementos de la lista.
 * @param lista la lista de la cual eliminaremos 
 * elementos.
 */
void eliminaElementos(Lista<int>* lista) {
    int l = lista->getLongitud();
    int c = 0;
    while (c < l) {
        if (c < (l / 2)) {
            lista->eliminaUltimo();
        } else {
            lista->eliminaPrimero();
        }
        c += 1;
    }
}


/**
 * Insertamos elementos en índices aleatorios en la lista.
 * @param lista la lista en la cuál insertaremos los elementos.
 * @param n el rango de los índices en los cuales insertaremos los elementos.
 */
void insertaEnPosicionAleatoria(Lista<int>* lista, int& n) {
    int l = lista->getLongitud();
    srand((unsigned) time(NULL));
    int c = 0;
    while (c < 5) {
        int r = (rand() % n);
        cout << "Elemento siguiente: " << lista->get(r) << endl;
        cout << "Posición: " << r << endl;
        cout << "Elemento: " << c + 1 << endl;
        lista->inserta(r, c + 1);
        cout << *(lista) << endl;
        c += 1;
    }
}


/**
 * main.
 */
int main(int argc, char* argv[]) {
    int n = 50;
    Lista<int>* lista = new Lista<int>();
    llenaLista(lista, n);
    cout << *(lista) << endl;
    insertaEnPosicionAleatoria(lista, n);       
    Lista<int>* copia = lista->copia();
    cout << *(copia) << endl;
    Lista<int>* reversa = lista->reversa();
    cout << *(reversa) << endl;
    cout << lista->getLongitud() << endl;
    cout << copia->getLongitud() << endl;
    cout << reversa->getLongitud() << endl;
    if (*(lista) == *(copia)) {
        cout << "Las listas son iguales." << endl;
    }
    cout << lista->eliminaPrimero() << endl;
    cout << lista->getLongitud() << endl;
    cout << *(lista) << endl;
    cout << lista->eliminaUltimo() << endl;
    cout << *(lista) << endl;
    cout << lista->getLongitud() << endl;
    eliminaElementos(lista);
    eliminaElementos(copia);
    eliminaElementos(reversa);
    lista->limpia();
    copia->limpia();
    reversa->limpia();
    cout << *(lista) << endl;
    cout << *(copia) << endl;
    cout << *(reversa) << endl;
    if (lista->esVacia()) {
        cout << "La lista está vacía." << endl;
    }
    delete lista;
    delete copia;
    delete reversa;
    return 0;
}