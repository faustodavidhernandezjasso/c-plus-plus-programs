/**
 * @file Coleccion.hpp
 * @version 1.0
 * @brief Interface para colecciones
 */
#ifndef COLECCION_H
#define COLECCION_H
template <class T>
class Coleccion;


template <typename T>
class Coleccion {


public:


    /**
     * Agrega un elemento a la colección.
     * @param elemento a agregar.
     * @throws std::invalid_argument si el elemento es nulo.
     */
    virtual void agrega(T elemento) = 0;


    /**
     * Elimina un elemento de la colección.
     * @param elemento a eliminar.
     */
    virtual void elimina(T elemento) = 0;


    /**
     * Nos indica sí un elemento pertene a la colección.
     * @param elemento que queremos verificar que pertenece a la colección.
     * @return <code>true</code> si el elemento pertenece a la colección,
     *         <code>false</code> en otro caso.
     */
    virtual bool contiene(T elemento) = 0;


    /**
     * Nos indica sí la colección está vacía, es decir, no tiene
     * ningún elemento.
     * @return <code>true</code> si la colección está vacía,
     *         <code>false</code> en otro caso.
     */
    virtual bool esVacia() = 0;


    /**
     * Nos regresa el número de elementos de la colección.
     * @return el número de elementos de la colección.
     */
    virtual int getElementos() = 0;


    /**
     * Limpia la colección. Después de la ejecución, la colección
     * está vacía.
     */
    virtual void limpia() = 0;


};


#endif /* COLECCION_H */