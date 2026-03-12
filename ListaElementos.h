#pragma once
#include "NodoElemento.h"
using namespace std;



//Lista de comandos
class ListaElementos{
public:
    ListaElementos(); 
    ~ListaElementos();

    void vaciar();
    void insertarAlFinal(NodoElemento* nuevo);
    void cargarDesdeArchivo(string nombre_archivo);
    int obtenerCantidad() const;
    NodoElemento* obtenerCabeza() const;



protected:
    NodoElemento* cabeza;
    int cantidad;
};

#include "ListaElementos.hxx"