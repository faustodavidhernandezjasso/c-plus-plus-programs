/**
 * @file Main.cpp
 * @version 1.0
 * @brief main.
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "Arreglos.cpp"
#include "Lista.cpp"


using namespace std;


/**
 * Llenamos el arreglo de elementos aleatorios.
 * @param arreglo el arreglo a llenar con elementos aleatorios.
 * @param n la longitud del arreglo.
 */
void llenaArreglo(int arreglo[], int n) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; i++) {
        arreglo[i] = (rand() % n) + 1;
    }
}


/**
 * Imprimimos el arreglo.
 * @param arreglo el arreglo a imprimir.
 * @param n la longitud del arreglo.
 */
void imprimeArreglo(int arreglo[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << arreglo[i] << "]" << endl;   
        } else {
            cout << arreglo[i] << ", ";
        }
    }
}


/**
 * Obtenemos un elemento aleatorio del arreglo ya ordenado.
 * @param arreglo el arreglo del cual vamos a obtener el elemento.
 * @param n el número de elementos del arreglo. 
 */
int elementoAleatorio(int arreglo[], int n) {
    srand((unsigned) time(NULL));
    int i = (rand() % n);
    return arreglo[i];
}


/**
 * Llenamos la lista recibida de elementos aleatorios.
 * @param lista la lista a llenar de elementos aleatorios.
 * @param n el número de elementos.
 */
void llenaLista(Lista<int>* lista, int n) {
    srand((unsigned) time(NULL));
    int c = 0;
    while (c < n) {
        int r = (rand() % n) + 1;
        lista->agregaFinal(r);
        c += 1;
    }
}


/**
 * Obtenemos un elemento aleatorios de la lista ya ordenada.
 * 
 */
int elementoLista(Lista<int>* lista) {
    srand((unsigned) time(NULL));
    int i = (rand() % lista->getLongitud());
    return lista->get(i);
}


/**
 * main.
 */ 
int main(int argc, char* argv[]) {
    int n = 100;
    int* arreglo = new int[n];
    llenaArreglo(arreglo, n);
    imprimeArreglo(arreglo, n);
    Arreglos<int>::quickSort(arreglo, n);
    cout << "Ordenamiento con QuickSort: " << endl;
    imprimeArreglo(arreglo, n);
    int* arr = new int[n];
    llenaArreglo(arr, n);
    cout << "Desordenado: " << endl;
    imprimeArreglo(arr, n);
    cout << "Ordenamiento con SelectionSort: " << endl;
    Arreglos<int>::selectionSort(arr, n);
    imprimeArreglo(arr, n);
    int e = elementoAleatorio(arr, n);
    cout << "Elemento: " << e << endl;
    cout << Arreglos<int>::busquedaBinaria(arr, e, n) << endl;
    Lista<int>* lista = new Lista<int>();
    llenaLista(lista, n);
    cout << *(lista) << endl;
    Lista<int>* ordenada = Lista<int>::mergeSort(lista);
    cout << *(ordenada) << endl;
    e = elementoLista(lista);
    if (Lista<int>::busquedaLineal(ordenada, e)) {
        cout << "El elemento: " << e << " está en la lista." << endl;
    }
    e = 101;
    if (Lista<int>::busquedaLineal(ordenada, e)) {
        cout << "El elemento: " << e << " está en la lista." << endl;
    } else {
        cout << "El elemento: " << e << " no está en la lista." << endl;
    }
    delete arreglo;
    delete arr;
    delete lista;
    return 0;
}