#pragma once
#include "NodoComando.h"
using namespace std;



//Lista de comandos
class ListaComandos{
public:
    ListaComandos(); 
    ~ListaComandos();

    void vaciar();
    void insertarAlFinal(NodoComando* nuevo);
    void cargarDesdeArchivo(string nombre_archivo);
    int obtenerCantidad() const;
    NodoComando* obtenerCabeza() const;



protected:
    NodoComando* cabeza;
    int cantidad;
};


#include "ListaComandos.hxx"