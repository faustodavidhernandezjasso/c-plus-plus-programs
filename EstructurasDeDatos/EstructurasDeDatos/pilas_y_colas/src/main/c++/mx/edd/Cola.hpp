/**
 * @file Cola.hpp
 * @version 1.0
 * @brief Clase genérica para colas.
 */
#ifndef COLA_HPP
#define COLA_HPP


template <class T>
class Cola;


template <typename T>
class Cola {


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


#endif /* COLA_HPP */