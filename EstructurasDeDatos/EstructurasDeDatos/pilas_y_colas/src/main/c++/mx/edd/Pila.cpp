/**
 * @file Pila.cpp
 * @version 1.0
 * @brief Clase genérica para pilas.
 */
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#ifndef PILA
#define PILA


template <class T>
class Pila;


template <typename T>
class Pila {


private:

    
    /* Clase interna para nodos. */
    template <typename K>
    class Nodo {

    
        /* El elemento del nodo. */
        T elemento_;
        /* El nodo siguiente. */
        Nodo<T>* siguiente_;
        /* Clase amiga */
        friend class Pila<T>;


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


    /* La cabeza de la pila */
    Nodo<T>* cabeza;
    /* El rabo de la pila */
    Nodo<T>* rabo;


public:


    /**
     * Destructor.
     */
    virtual ~Pila() {
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
     * Metemos un elemento a la pila.
     * @param elemento el elemento a meter a la pila.
     */
    void mete(T elemento) {
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        if (this->cabeza == nullptr) {
            this->cabeza = this->rabo = nuevo;
        } else {
            nuevo->siguiente_ = this->cabeza;
            this->cabeza = nuevo;
        }
    }


    /**
     * Sacamos un elemento de la pila
     * @return el elemento de un extremo de la pila.
     * @throws std::invalid_argument sí la pila está vacía.
     */
    T saca() {
        if (this->cabeza == nullptr) {
            throw std::invalid_argument("La pila está vacía");
        }
        T elemento = this->cabeza->elemento_;
        this->cabeza = this->cabeza->siguiente_;
        if (this->cabeza == nullptr) {
            this->rabo = nullptr;
        }
        return elemento;
        
    }

    
    /**
     * Miramos en un extremo de la pila.
     * @return el elemento de un extremo de la pila.
     * @throws std::invalid_argument sí la pila está vacía.
     */
    T mira() {
        if (this->cabeza == nullptr) {
            throw std::invalid_argument("La pila está vacía");
        }
        return this->cabeza->elemento_;
    }


    /**
     * Nos indica sí la pila está vacía.
     * @return <tt>true</tt> sí la pila no tiene elementos.
     *         <tt>false</tt> en otro caso.
     */
    bool esVacia() {
        return this->cabeza == nullptr;
    }


    /**
     * Sobreescribimos el operador ==.
     */
    friend bool operator ==(const Pila<T>& pila, const Pila<T>& p) {
        Nodo<T>* nodo = pila.cabeza;
        Nodo<T>* n = p.cabeza;
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
     * Representación en cadenas de pilas.
     */
    std::string toString() const {
        std::stringstream s;
        Nodo<T>* auxiliar = this->cabeza;
        s << auxiliar->elemento_;
        s << "\n";
        auxiliar = auxiliar->siguiente_;
        while (auxiliar != nullptr) {
            s << auxiliar->elemento_;
            auxiliar = auxiliar->siguiente_;
            if (auxiliar == nullptr) {
                break;
            } else {
                s << "\n";
            }
        }
        return s.str();
    }


    /**
     * Sobreescribimos el operador ==.
     */
    friend std::ostream& operator <<(std::ostream& strm, const Pila<T>& pila) {
        return strm << pila.toString();
    }


};


#endif /* PILA */