/**
 * @file Main.cpp 
 * @version 1.0
 * @brief main.
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include "Pila.cpp"
#include "Cola.cpp"

using namespace std;


/**
 * Sacamos elementos de la pila.
 * @param pila la pila de la que sacaremos los elementos.
 */
void sacaElementosDeLaPila(Pila<int>* pila) {
    while (!(pila->esVacia())) {
        cout << "Elemento que se saca de la pila: " << pila->saca() << endl;
    }
}


/**
 * Llenamos la pila de elementos aleatorios.
 * @param n el número de elementos que tendrá la pila.
 * @param pila la pila que llenaremos.
 */
void llenaPila(int& n, Pila<int>* pila) {
    int c = 0;
    srand((unsigned) time(NULL));
    while (c < n) {
        int r = (rand() % n) + 1;
        cout << "Elemento que ingresa a la pila: " << r << endl;
        pila->mete(r);
        c += 1;
    }
}


/**
 * Sacamos elementos de la cola.
 * @param cola la cola de la que sacaremos los elementos.
 */
void sacaElementosDeLaCola(Cola<int>* cola) {
    while (!(cola->esVacia())) {
        cout << "Elementos que se saca de la cola: " << cola->saca() << endl;
    }
}


/**
 * Llenamos la cola de elementos aleatorios.
 * @param n el número de elementos que trendrá la cola.
 * @param cola la cola que llenaremos.
 */
void llenaCola(int& n, Cola<int>* cola) {
    int c = 0;
    srand((unsigned) time(NULL));
    while (c < n) {
        int r = (rand() % n) + 1;
        cout << "Elemento que ingresa a la cola: " << r << endl;
        cola->mete(r);
        c += 1;
    }
}


/**
 * main.
 */
int main(int argc, char* argv[]) {
    Pila<int>* pila = new Pila<int>();
    Cola<int>* cola = new Cola<int>();
    int n = 10;
    llenaPila(n, pila);
    cout << *(pila) << endl;
    sacaElementosDeLaPila(pila);
    llenaCola(n, cola);
    cout << *(cola) << endl;
    sacaElementosDeLaCola(cola);
    delete pila;
    delete cola;
    return 0;
}
