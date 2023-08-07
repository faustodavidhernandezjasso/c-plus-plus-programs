/**
 * @file Arreglos.hpp
 * @version 1.0
 * @brief Clase para ordenar y buscar en arreglos genéricos.
 */
#ifndef ARREGLOS_H
#define ARREGLOS_H


template <class T>
class Arreglos;


template <typename T>
class Arreglos {


private:


    /**
     * Constructor privado.
     */
    Arreglos() {};


public:


    /**
     * Función genérica para comparar elementos.
     * @param a el primer elemento.
     * @param b el segundo elemento.
     * @return la diferencia de un elemento con otro.
     */
    int compara(const void* a, const void* b);



    /**
     * Ordena el arreglo recibido usando el algoritmo QuickSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     */
    static void quickSort(T* arreglo, int n);


    /**
     * Ordena el arreglo recibido usando el algoritmo QuickSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     * @param compara función genérica para comparar elementos.
     */
    static void quickSort(T* arreglo, int n,
                          int (*compara)(const void*, const void*));



    /**
     * Ordena el arreglo recibido usando el algoritmo SelectionSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     */
    static void selectionSort(T* arreglo, int n);


    /**
     * Ordena el arreglo recibido usando el algoritmo SelectionSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     * @param compara función genérica para comparar elementos.
     */
    static void selectionSort(T* arreglo, int n,
                              int (*compara)(const void*, const void*));


    /**
     * Busca el elemento recibido en el arreglo ordenado recibido.
     * @param arreglo el arreglo ordenado a buscar.
     * @param elemento el elemento a buscar.
     * @param n el número de elementos del arreglo.
     * @return el índice del elemento en el arreglo.
     */
    static int busquedaBinaria(T* arreglo, T elemento, int n);


    /**
     * Busca el elemento recibido en el arreglo ordenado recibido.
     * @param arreglo el arreglo ordenado a buscar.
     * @param elemento el elemento a buscar.
     * @param n el número de elementos del arreglo.
     * @param compara función genérica para comparar elementos.
     * @return el índice del elemento en el arreglo.
     */
    static int busquedaBinaria(T* arreglo, T elemento, int n,
                               int (*compara)(const void*, const void*));


};


#endif /* ARREGLOS_H */