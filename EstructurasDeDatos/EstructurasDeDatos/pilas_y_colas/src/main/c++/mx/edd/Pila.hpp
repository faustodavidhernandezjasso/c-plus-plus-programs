/**
 * @file Pila.hpp
 * @version 1.0
 * @brief Clase genérica para pilas.
 */
#ifndef PILA_HPP
#define PILA_HPP


template <class T>
class Pila;


template <typename T>
class Pila {


public:


    /**
     * Metemos un elemento a la pila.
     * @param elemento el elemento a meter a la pila.
     */
    void mete(T elemento);


    /**
     * Sacamos un elemento de la pila
     * @return el elemento de un extremo de la pila.
     * @throws std::invalid_argument sí la pila está vacía.
     */
    T saca();

    
    /**
     * Miramos en un extremo de la pila.
     * @return el elemento de un extremo de la pila.
     * @throws std::invalid_argument sí la pila está vacía.
     */
    T mira();


    /**
     * Nos indica sí la pila está vacía.
     * @return <tt>true</tt> sí la pila no tiene elementos.
     *         <tt>false</tt> en otro caso.
     */
    bool esVacia();


};


#endif /* PILA_HPP */