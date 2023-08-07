/**
 * @file Cola.cpp
 * @version 1.0
 * @brief Clase para colas genéricas.
 */
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdexcept>


#ifndef COLA_CPP
#define COLA_CPP


template <class T>
class Cola;


template <typename T>
class Cola {


private:

    
    /* Clase interna para nodos. */
    template <typename K>
    class Nodo {

    
        /* El elemento del nodo. */
        T elemento_;
        /* El nodo siguiente. */
        Nodo<T>* siguiente_;
        /* Clase amiga */
        friend class Cola<T>;


    public:


        /**
         * Constructor.
         */
        Nodo(T elemento) : elemento_(elemento), siguiente_(nullptr) {}


        /**
         * Obtenemos el nodo siguiente.
         * @return el nodo siguiente.
         */
        Nodo<T>* getSiguiente() {
            return this->siguiente_;
        }


        /**
         * Obtenemos el elemento del nodo.
         * @return el elemento del nodo.
         */
        T getElemento() {
            return this->elemento_;
        }


    };


    /* La cabeza de la cola */
    Nodo<T>* cabeza;
    /* El rabo de la cola */
    Nodo<T>* rabo;


public:


    /**
     * Destructor.
     */
    virtual ~Cola() {
        Nodo<T>* auxiliar = this->cabeza;
        while (auxiliar != nullptr) {
            Nodo<T>* n = auxiliar->siguiente_;
            delete auxiliar;
            auxiliar = nullptr;
            auxiliar = n;
        }
        this->cabeza = nullptr;
    }


    /**
     * Metemos un elemento a la cola.
     * @param elemento el elemento a meter a la cola.
     */
    void mete(T elemento) {
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        if (this->rabo == nullptr) {
            this->cabeza = this->rabo = nuevo;
        } else {
            this->rabo->siguiente_ = nuevo;
            this->rabo = nuevo;
        }
    }


    /**
     * Sacamos un elemento de la cola.
     * @return el elemento de un extremo de la cola.
     * @throws std::invalid_argument sí la cola está vacía.
     */
    T saca() {
        if (this->cabeza == nullptr) {
            throw std::invalid_argument("La cola está vacía");
        }
        T elemento = this->cabeza->elemento_;
        this->cabeza = this->cabeza->siguiente_;
        if (this->cabeza == nullptr) {
            this->rabo = nullptr;
        }
        return elemento;
        
    }

    
    /**
     * Miramos en un extremo de la cola.
     * @return el elemento de un extremo de la cola.
     * @throws std::invalid_argument sí la cola está vacía.
     */
    T mira() {
        if (this->cabeza == nullptr) {
            throw std::invalid_argument("La cola está vacía");
        }
        return this->cabeza->elemento_;
    }


    /**
     * Nos indica sí la cola está vacía.
     * @return <tt>true</tt> sí la cola no tiene elementos.
     *         <tt>false</tt> en otro caso.
     */
    bool esVacia() {
        return this->cabeza == nullptr;
    }


    /**
     * Sobreescribimos el operador ==.
     */
    friend bool operator ==(const Cola<T>& cola, const Cola<T>& c) {
        Nodo<T>* nodo = cola.cabeza;
        Nodo<T>* n = c.cabeza;
        while (nodo != nullptr && n != nullptr) {
            if (nodo->getElemento() != n->getElemento()) {
                return false;
            }
            nodo = nodo->getSiguiente();
            n = n->getSiguiente();
        }
        if (nodo == nullptr && n == nullptr) {
            return true;
        } else {
            return false;
        }
    }


    /**
     * Representación en cadenas de colas.
     */
    std::string toString() const {
        std::stringstream s;
        Nodo<T>* auxiliar = this->cabeza;
        s << auxiliar->elemento_;
        s << " ";
        auxiliar = auxiliar->siguiente_;
        while (auxiliar != nullptr) {
            s << auxiliar->elemento_;
            auxiliar = auxiliar->siguiente_;
            if (auxiliar == nullptr) {
                break;
            } else {
                s << " ";
            }
        }
        return s.str();
    }


    /**
     * Sobreescribimos el operador ==.
     */
    friend std::ostream& operator <<(std::ostream& strm, const Cola<T>& cola) {
        return strm << cola.toString();
    }

};


#endif  /* COLA_CPP */