/**
 * @file Lista.cpp
 * @version 1.0
 * @brief Clase genérica para listas doblemente ligadas.
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iterator>
#include <stdexcept>
#include "Coleccion.hpp"

#ifndef LISTA
#define LISTA

template <class T>
class Lista;


template <typename T>
class Lista : public Coleccion<T> {


public:

    /**
     * Clase interna privada para nodos.
     */
    template <typename K>
    class Nodo {


    private:


        /* El elemento del nodo. */
        T elemento_;
        /* El nodo anterior. */
        Nodo* anterior_;
        /* El nodo siguiente. */
        Nodo* siguiente_;
        friend class Lista<T>;


    public:


        /* Constructor */
        Nodo(T elemento) : elemento_(elemento), anterior_(nullptr), siguiente_(nullptr) {
        }


        /* Nos regresa el nodo siguiente */
        Nodo* getSiguiente() {
            return this->siguiente_;
        }


        /* Sobreescribimos el operador == */
        friend bool operator==(const Nodo<T>& nodo, const Nodo<T>& n) {
            return (nodo.elemento_ == n.elemento_);
        }


        /* Sobreescribimos el operador != */
        friend bool operator!=(const Nodo<T>& nodo, const Nodo<T>& n) {
            return !(nodo == n);
        }


    };


    /**
     * Clase para iteradores.
     */
    class const_iterator {


    protected:


        /**
         * Nodo actual.
         */
        Nodo<T>* current;   
        /**
         * Clase amiga.
         */
        friend class Lista<T>;


        /**
         * Regresamos una referencia del elemento del iterador.
         */         
        T& retrieve() const {
            return this->current->elemento_;
        }


        /**
         * Constructor.
         */
        const_iterator(Nodo<T>* current) {
            this->current = current;
        }
    

    public:


        /**
         * Constructor.
         */
        const_iterator() {
            this->current = nullptr;
        }


        /**
         * Sobreescribimos el operador *.
         */
        const T& operator*() const {
            retrieve();
        }


        /**
         * Sobreescribimos el operador ++.
         */
        const_iterator& operator++() {
            current = current->siguiente_;
            return *(this);
        }


        /**
         * Sobreescribimos el operador ++.
         */
        const_iterator operator++(int) {
            const_iterator it = *(this);
            ++*(this);
            return it;
        }


        /**
         * Sobreescribimos el operador --.
         */
        const_iterator& operator--() {
            current = current->anterior_;
            return *(this);
        }


        /**
         * Sobreescribimos el operador --.
         */
        const_iterator operator--(int) {
            const_iterator it = *(this);
            --*(this);
            return it;
        }


        /**
         * Sobreescribimos el operador ==.
         */
        bool operator==(const const_iterator& i) const {
            return (this->current == i.current);
        }


        /**
         * Sobreescribimos el operador !=.
         */
        bool operator!=(const const_iterator& i) const {
            return (this->current != i.current);
        }


    };


    /**
     * Clase para iteradores.
     */
    class iterator : public const_iterator {

    
    protected:


        /**
         * Constructor.
         */
        iterator(Nodo<T>* p) : const_iterator(p) {};
        /**
         * Clase amiga.
         */
        friend class Lista<T>;

    
    public:


        /**
         * Constructor.
         */
        iterator() : const_iterator() {}


        /**
         * Sobreescribimos el operador *.
         */
        T& operator*() {
            return this->current->elemento_;
        }


        /**
         * Sobreescribimos el operador *.
         */
        const T& operator*() const {
            return this->current->elemento_;
        }


        /**
         * Sobreescribimos el operador ++.
         */
        iterator& operator++() {
            this->current = this->current->siguiente_;
            return *(this);
        }


        /**
         * Sobreescribimos el operador ++.
         */
        iterator operator++(int) {
            iterator it = *(this);
            ++*(this);
            return it;
        }


        /**
         * Sobreescribimos el operador --.
         */
        iterator& operator--() {
            this->current = this->current->siguiente_;
            return *(this);
        }


        /**
         * Sobreescribimos el operador --.
         */
        iterator operator--(int) {
            iterator it = *(this);
            --*(this);
            return it;
        }


    };


private:


    /**
     * La cabeza de la lista.
     */
    Nodo<T>* cabeza_;
    /**
     * El rabo de la lista.
     */
    Nodo<T>* rabo_;
    /**
     * La longitud de la lista.
     */
    int longitud_;


    /**
     * Buscamos el nodo que contiene al elemento recibido.
     * @param elemento el elemento a buscar en los nodos de la lista.
     * @return puntero al nodo que contiene el elemento.
     */
    Nodo<T>* buscaNodo(T elemento) {
        Nodo<T>* auxiliar = cabeza_;
        while (auxiliar != nullptr) {
            if (auxiliar->elemento_ == elemento) {
                return auxiliar;
            }
            auxiliar = auxiliar->siguiente_;
        }
        return nullptr;
    }


    /**
     * Buscamos el <em>i</em>-ésimo nodo.
     * @param i el índice a buscar.
     * @return puntero al <em>i</em>-ésimo nodo.
     */
    Nodo<T>* iesimoNodo(int i) {
        Nodo<T>* nodo = this->cabeza_;
        int contador = 0;
        while (contador != i) {
            contador += 1;
            nodo = nodo->siguiente_;
        }
        return nodo;
    }


public:


    /**
     * Destructor.
     */
    virtual ~Lista() {
        limpia();
    }


    /**
     * Agrega un elemento a la colección.
     * El método es idéntico a {@link #agregaFinal}.
     * @param elemento a agregar.
     * @throws std::invalid_argument si el elemento es nulo.
     */
    void agrega(T elemento) {
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        this->longitud_ += 1;
        if (rabo_ == nullptr) {
            cabeza_ = rabo_ = nuevo;
        } else {
            rabo_->siguiente_ = nuevo;
            nuevo->anterior_ = rabo_;
            rabo_ = nuevo;
        }
    }


    /**
     * Elimina un elemento de la colección.
     * @param elemento a eliminar.
     */
    void elimina(T elemento) {
        Nodo<T>* elimina = buscaNodo(elemento);
        if (elimina == nullptr) {
            return;
        } else {
            this->longitud_ -= 1;
            if ((cabeza_->elemento_ == elimina->elemento_) && (rabo_->elemento_ == elimina->elemento_)) {
                cabeza_ = rabo_ = nullptr;
            } else if (cabeza_->elemento_ == elimina->elemento_) {
                Nodo<T>* siguiente = cabeza_->siguiente_;
                siguiente->anterior_ = nullptr;
                cabeza_ = siguiente;
            } else if (rabo_->elemento_ == elimina->elemento_) {
                Nodo<T>* anterior = rabo_->anterior_;
                anterior->siguiente_ = nullptr;
                rabo_ = anterior;
            } else {
                Nodo<T>* anterior = elimina->anterior_;
                Nodo<T>* siguiente = elimina->siguiente_;
                anterior->siguiente_ = siguiente;
                siguiente->anterior_ = anterior;
            }
        }

    }


    /**
     * Nos indica sí un elemento pertene a la colección.
     * @param elemento que queremos verificar que pertenece a la colección.
     * @return <code>true</code> si el elemento pertenece a la colección,
     *         <code>false</code> en otro caso.
     */
    bool contiene(T elemento) {
        Nodo<T>* nodo = buscaNodo(elemento);
        if (nodo == nullptr) {
            return false;
        } else {
            return true;
        }
    }


    /**
     * Nos indica sí la colección está vacía, es decir, no tiene
     * ningún elemento.
     * @return <code>true</code> si la colección está vacía,
     *         <code>false</code> en otro caso.
     */
    bool esVacia() {
        return (cabeza_ == nullptr) && (rabo_ == nullptr) && (longitud_ == 0);
    }


    /**
     * Nos regresa el número de elementos de la colección.
     * El método es idéntico a {@link #getLongitud}.
     * @return el número de elementos de la colección.
     */
    int getElementos() {
        return this->longitud_;
    }


    /**
     * Limpia la colección. Después de la ejecución, la colección
     * está vacía.
     */
    void limpia() {
        Nodo<T>* auxiliar = this->cabeza_;
        while (auxiliar != nullptr) {
            Nodo<T>* siguiente = auxiliar->siguiente_;
            delete auxiliar;
            auxiliar = nullptr;
            auxiliar = siguiente;
        }
        auxiliar = nullptr;
        this->cabeza_ = nullptr;
        this->rabo_ = nullptr;
        this->longitud_ = 0;
    }


    /**
     * Representación en cadena de las listas.
     */
    std::string toString() const {
        std::stringstream s;
        if (this->longitud_ == 0) {
            s << "[]";
            return s.str();
        } else {
            s << "[";
            Nodo<T>* nodo = this->cabeza_;
            while (nodo != nullptr) {
                s << nodo->elemento_;
                if (nodo->siguiente_ == nullptr) {
                    break;
                }
                s << ", ";
                nodo = nodo->siguiente_;
            }
            s << "]";
            return s.str();
        }
    }


    /**
     * Sobreescribimos el operador <<.
     */
    friend std::ostream& operator <<(std::ostream& strm, const Lista<T>& lista) {
        return strm << lista.toString();
    }


    /**
     * Sobreescribimos el operador ==.
     */
    friend bool operator ==(const Lista<T>& lista, const Lista<T>& l) {
        if (lista.longitud_ != l.longitud_) {
            return false;
        }
        Nodo<T>* nodo = lista.cabeza_;
        Nodo<T>* n = l.cabeza_;
        while (nodo != nullptr && n != nullptr) {
            if (*(nodo) != *(n)) {
                return false;
            }
            nodo = nodo->getSiguiente();
            n = n->getSiguiente();
        }
        return true;
        
    }


    /**
     * Sobreescribimos el operador ==.
     */
    friend bool operator !=(const Lista<T>& lista, const Lista<T>& l) {
        return !(lista == l);
    }
    

    /**
     * Regresa el número de elementos de la lista.
     * El método es idéntico a {@link #getElementos}.
     * @return la longitud de la lista. El número de elementos de la lista.
     */
    int getLongitud() {
        return this->longitud_;
    }


    /**
     * Agrega un elemento al final de la lista.
     * El método es idéntico a {@link #agrega}.
     * @param elemento el elemento a agregar.
     * @throws std::invalid_argument si <code>elemento</code> es nulo.
     */
    void agregaFinal(T elemento) {
        if (!elemento) {
            throw std::invalid_argument("No se puede agregar el elemento a lista");
        }
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        this->longitud_ += 1;
        if (this->rabo_ == nullptr) {
            this->cabeza_ = this->rabo_ = nuevo;
        } else {
            this->rabo_->siguiente_ = nuevo;
            nuevo->anterior_ = this->rabo_;
            this->rabo_ = nuevo;
        }
    }


    /**
     * Agrega un elemento al final de la lista.
     * @param elemento el elemento a agregar.
     * @throws std::invalid_argument si <code>elemento</code> es nulo.
     */
    void agregaInicio(T elemento) {
        if (!elemento) {
            throw std::invalid_argument("No se puede agregar el elemento a lista");
        }
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        this->longitud_ += 1;
        if (this->cabeza_ == nullptr) {
            this->cabeza_ = this->rabo_ = nuevo;
        } else {
            this->cabeza_->anterior_ = nuevo;
            nuevo->siguiente_ = this->cabeza_;
            this->cabeza_ = nuevo;
        }
    }


    /**
     * Inserta un elemento en un índice explícito.
     * @param i el índice en dónde se va a insertar el elemento.
     * @param elemento el elemento a insertar.
     * @throws std::invalid_argument si <code>elemento</code> es nulo.
     */
    void inserta(int i, T elemento) {
        if (!elemento) {
            throw std::invalid_argument("El elemento es nulo");
        }
        if (i < 1) {
            agregaInicio(elemento);
        } else if (i > this->longitud_ - 1) {
            agregaFinal(elemento);
        } else {
            this->longitud_ += 1;
            Nodo<T>* nodo = new Nodo<T>(elemento);
            Nodo<T>* s = iesimoNodo(i);
            Nodo<T>* a = s->anterior_;
            nodo->anterior_ = a;
            a->siguiente_ = nodo;
            nodo->siguiente_ = s;
            s->anterior_ = nodo;
        }
    }


    /**
     * Elimina el primer elemento de la lista.
     * @return el primer elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T eliminaPrimero() {
        if (this->cabeza_ == nullptr) {
            throw std::invalid_argument("Lista vacía");
        }
        this->longitud_ -= 1;
        T elemento = this->cabeza_->elemento_;
        if (this->longitud_ == 0) {
            this->cabeza_ = this->rabo_ = nullptr;
        } else {
            Nodo<T>* siguiente = this->cabeza_->siguiente_;
            siguiente->anterior_ = nullptr;
            this->cabeza_ = siguiente;
        }
        return elemento;
    }


    /**
     * Elimina el último elemento de la lista.
     * @return el último elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T eliminaUltimo() {
        if (this->rabo_ == nullptr) {
            throw std::invalid_argument("Lista vacía");
        }
        this->longitud_ -= 1;
        T elemento = this->rabo_->elemento_;
        if (this->longitud_ == 0) {
            this->cabeza_ = this->rabo_ = nullptr;
        } else {
            Nodo<T>* anterior = this->rabo_->anterior_;
            anterior->siguiente_ = nullptr;
            this->rabo_ = anterior;
        }
        return elemento;
    }


    /**
     * Regresa el primer elemento de la lista.
     * @return el primer elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T getPrimero() {
        if (this->longitud_ == 0) {
            throw std::invalid_argument("Lista vacía");
        }
        return this->cabeza_->elemento_;
    }


    /**
     * Regresa el último elemento de la lista.
     * @return el último elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T getUltimo() {
        if (this->longitud_ == 0) {
            throw std::invalid_argument("Lista vacía");
        }
        return this->cabeza_->elemento_;
    }


    /**
     * Regresa el <em>i</em>-ésimo elemento de la lista.
     * @param i el índice del elemento que queremos.
     * @return el <em>i</em>-ésimo elemento de la lista.
     * @throws std::invalid_argument si la lista vacía.
     */
    T get(int i) {
        if (i < 0 || i >= this->longitud_) {
            throw std::out_of_range("Índice inválido");
        }
        int contador = 0;
        Nodo<T>* auxiliar = this->cabeza_;
        while (auxiliar != nullptr) {
            if (contador == i) {
                return auxiliar->elemento_;
            }
            contador += 1;
            auxiliar = auxiliar->siguiente_;
        }
    }


    /**
     * Regresamos un puntero a la copia de la lista.
     * @return un puntero a una copia de la lista.
     */
    Lista<T>* copia() {
        Nodo<T>* nodo = this->cabeza_;
        Lista<T>* copia = new Lista<T>();
        while (nodo != nullptr) {
            copia->agregaFinal(nodo->elemento_);
            nodo = nodo->siguiente_;
        }
        return copia;
    }


    /**
     * Regresamos un puntero a una reversa de la lista.
     * @return un puntero a la reversa de la lista.
     */
    Lista<T>* reversa() {
        Nodo<T>* nodo = this->rabo_;
        Lista<T>* reversa = new Lista<T>();
        while (nodo != nullptr) {
            reversa->agregaFinal(nodo->elemento_);
            nodo = nodo->anterior_;
        }
        return reversa;
    }


    /**
     * Regresamos el índice del elemento recibido en la lista.
     * @param elemento el elemento del que se busca el índice.
     * @return el índice del elemento de la lista.
     * Sí el elemento no está en lista regresamos -1.
     */
    int indiceDe(T elemento) {
        int contador = 0;
        Nodo<T>* nodo = this->cabeza_;
        while (nodo != nullptr) {
            if (nodo->elemento_ == elemento) {
                return contador;
            }
            contador += 1;
            nodo = nodo->siguiente_;
        }
        return -1;
    }


    /**
     * Mueve el iterador al inicio.
     * @return un iterador que apunta al inicio de la lista.
     */
    iterator begin() {
        iterator it = this->cabeza_;
        return it;
    }  


    /**
     * Mueve el iterador al inicio.
     * @return un iterador que apunta al inicio de la lista.
     */
    const_iterator begin() const {
        const_iterator it = this->cabeza_;
        return it;
    }


    /**
     * Mueve el iterador al final.
     * @return un iterador que apunta al final de la lista.
     */
    iterator end() {
        iterator it = this->rabo_;
        return it;
    }


    /**
     * Mueve el iterador al final.
     * @return un iterador que apunta al final de la lista.
     */
    const_iterator end() const {
        const_iterator it = this->rabo_;
        return it;
    }


};


#endif /* LISTA_CPP */