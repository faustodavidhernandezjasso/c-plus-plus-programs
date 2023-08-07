/**
 * @file Lista.hpp
 * @version 1.0
 * @brief Clase genérica para listas doblemente ligadas.
 */
#include "Coleccion.hpp"


#ifndef LISTA_H
#define LISTA_H


template <class T>
class Lista;


template <typename T>
class Lista : public Coleccion {


private:


    /**
     * La longitud de la lista.
     */
    int longitud_;


public:


    /**
     * Regresa el número de elementos de la lista.
     * @return la longitud de la lista. El número de elementos de la lista.
     */
    int getLongitud();
    

    /**
     * Agrega un elemento al final de la lista.
     * @param elemento el elemento a agregar.
     * @throws std::invalid_argument si <code>elemento</code> es nulo.
     */
    void agregaFinal(T elemento);


    /**
     * Agrega un elemento al final de la lista.
     * @param elemento el elemento a agregar.
     * @throws std::invalid_argument si <code>elemento</code> es nulo.
     */
    void agregaInicio(T elemento);


    /**
     * Inserta un elemento en un índice explícito.
     * @param i el índice en dónde se va a insertar el elemento.
     * @param elemento el elemento a insertar.
     * @throws std::invalid_argument si <code>elemento</code> es nulo.
     */
    void inserta(int i, T elemento);


    /**
     * Elimina el primer elemento de la lista.
     * @return el primer elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T eliminaPrimero();


    /**
     * Elimina el último elemento de la lista.
     * @return el último elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T eliminaUltimo();


    /**
     * Regresa el primer elemento de la lista.
     * @return el primer elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T getPrimero();


    /**
     * Regresa el último elemento de la lista.
     * @return el último elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T getUltimo();


    /**
     * Regresa el <em>i</em>-ésimo elemento de la lista.
     * @param i el índice del elemento que queremos.
     * @return el <em>i</em>-ésimo elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T get(int i);


    /**
     * Regresamos un puntero a la copia de la lista.
     * @return un puntero a una copia de la lista.
     */
    Lista<T>* copia();


    /**
     * Regresamos un puntero a una reversa de la lista.
     * @return un puntero a la reversa de la lista.
     */
    Lista<T>* reversa();


    /**
     * Regresamos el índice del elemento recibido en la lista.
     * @param elemento el elemento del que se busca el índice.
     * @return el índice del elemento de la lista.
     * Sí el elemento no está en lista regresamos -1.
     */
    int indiceDe(T elemento); 


    /**
     * Función genérica para comparar elementos.
     * @param a el primer elemento.
     * @param b el segundo elemento.
     * @return la diferencia de un elemento con otro.
     */
    static int compara(const void* a, const void* b);


    /**
     * Algoritmo mergeSort.
     * @param compara función genérica para comparar elementos de la lista.
     * @return una copia de la lista ordenada.
     */
    Lista<T>* mergeSort(int (*compara)(const void*, const void*));


    /**
     * Algoritmo mergeSort.
     * @param lista la lista a ordenar.
     * @return una copia de la lista ordenada.
     */
    static Lista<T>* mergeSort(Lista<T>* lista);


    /**
     * Busca un elemento en una lista ordenada.
     * @param elemento el elemento a buscar.
     * @param compara función genérica para comparar elementos.
     * @return <tt>true</tt> sí el elemento pertenece a lista.
     *         <tt>false</tt> en otro caso.
     */
    bool busquedaLineal(T elemento, int (*compara)(const void*, const void*));


    /**
     * Busca un elemento en una lista ordenada.
     * @param lista la lista ordenada en la cual buscaremos el elemento.
     * @param elemento el elemento a buscar.
     * @return <tt>true</tt> sí el elemento pertenece a lista.
     *         <tt>false</tt> en otro caso.
     */
    static bool busquedaLineal(Lista<T>* lista, T elemento);


};


#endif /* LISTA_H */