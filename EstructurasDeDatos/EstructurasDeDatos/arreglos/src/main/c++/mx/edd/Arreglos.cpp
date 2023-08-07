/**
 * @file Arreglos.cpp
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
     * Constructor.
     */
    Arreglos() {};


public:


    /**
     * Función genérica para comparar elementos.
     * @param a el primer elemento.
     * @param b el segundo elemento.
     */
    static int compara(const void* a, const void* b) {
        int aa = *((int*) a);
        int bb = *((int*) b);
        return aa-bb;
    }



    /**
     * Ordena el arreglo recibido usando el algoritmo QuickSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     */
    static void quickSort(T* arreglo, int n) {
        quickSort(arreglo, 0, n - 1, compara);
    }


    /**
     * Ordena el arreglo recibido usando el algoritmo QuickSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     * @param compara función genérica para comparar elementos.
     */
    static void quickSort(T* arreglo, int n,
                          int (*compara)(const void*, const void*)) {
        quickSort(arreglo, 0, n - 1, compara);
    }



    /**
     * Ordena el arreglo recibido usando el algoritmo SelectionSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     */
    static void selectionSort(T* arreglo, int n) {
        selectionSort(arreglo, n, compara);
    }


    /**
     * Ordena el arreglo recibido usando el algoritmo SelectionSort.
     * @param arreglo el arreglo a ordenar.
     * @param n el número de elementos del arreglo.
     * @param compara función genérica para comparar elementos.
     */
    static void selectionSort(T* arreglo, int n,
                              int (*compara)(const void*, const void*)) {
        for (int i = 0; i < n; i++) {
            int m = i;
            for (int j = i + 1; j < n; j++) {
                if (compara(arreglo + j, arreglo + m) < 0) {
                    m = j;
                }
            }
            intercambia(arreglo, i, m);
        }
    }


    /**
     * Busca el elemento recibido en el arreglo ordenado recibido.
     * @param arreglo el arreglo ordenado a buscar.
     * @param elemento el elemento a buscar.
     * @param n el número de elementos del arreglo.
     * @return el índice del elemento en el arreglo.
     */
    static int busquedaBinaria(T* arreglo, T elemento, int n) {
        return busquedaBinaria(arreglo, elemento, 0, n - 1, compara);
    }


    /**
     * Busca el elemento recibido en el arreglo ordenado recibido.
     * @param arreglo el arreglo ordenado a buscar.
     * @param elemento el elemento a buscar.
     * @param n el número de elementos del arreglo.
     * @param compara función genérica para comparar elementos.
     * @return el índice del elemento en el arreglo.
     */
    static int busquedaBinaria(T* arreglo, T elemento, int n,
                               int (*compara)(const void*, const void*)) {
        return busquedaBinaria(arreglo, elemento, 0, n - 1, compara);
    }


    
private:


    /**
     * Algoritmo QuickSort
     * @param arreglo el arreglo a ordenar.
     * @param a índice desde donde se inicia la primera recursión.
     * @param b índice desde donde se termina la segunda recursión.
     * @param compara función genérica para comparar elementos.
     */
    static void quickSort(T* arreglo, int a, int b,
                          int (*compara)(const void*, const void*)) {
        if (b <= a) {
            return;
        }
        int i = a + 1;
        int j = b;
        while (i < j) {
            if (compara(arreglo + i, arreglo + a) > 0 && compara(arreglo + j, arreglo + a) <= 0) {
                intercambia(arreglo, i, j);
                i += 1;
                j -= 1;
            } else if (compara(arreglo + i, arreglo + a) <= 0) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        if (compara(arreglo + i, arreglo + a) > 0) {
            i -= 1;
        }
        intercambia(arreglo, a, i);
        quickSort(arreglo, a, i - 1, compara);
        quickSort(arreglo, i + 1, b, compara);
    }


    /**
     * Intercambiamos dos elementos en un arreglo.
     * @param arreglo el arreglo en el cual intercambiarémos los elementos.
     * @param i índice <em>i</em>-ésimo.
     * @param j índice <em>j</em>-ésimo.
     */
    static void intercambia(T* arreglo, int i, int j) {
        if (i == j) {
            return;
        }
        T elemento = *(arreglo + i);
        *(arreglo + i) = *(arreglo + j);
        *(arreglo + j) = elemento;
    }


    /**
     * Algoritmo Búsqueda Binaria.
     * @param arreglo el arreglo en el cual buscaremos.
     * @param a inicio de la recursión sí el elemento buscado es menor.
     * @param b fin de la recursión sí el elemento buscado es mayor.
     * @param compara función genérica para comparar elementos.
     * @return el índice del elemento buscado.
     */
    static int busquedaBinaria(T arreglo[], T elemento, int a, int b,
                               int (*compara)(const void*, const void*)) {
        if (b < a) {
            return -1;
        }
        int m = a + ((b - a) / 2);
        if (compara(&elemento, arreglo + m) == 0) {
            return m;
        } else if (compara(&elemento, arreglo + m) < 0) {
            return busquedaBinaria(arreglo, elemento, a, m - 1, compara);
        } else {
            return busquedaBinaria(arreglo, elemento, m + 1, b, compara);
        }
    }


};


#endif /* ARREGLOS_H */