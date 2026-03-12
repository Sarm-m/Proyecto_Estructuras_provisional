#pragma once
#include "Tipos.h"
#include <string>
using namespace std;

 

//constructor
class NodoElemento{
    public:
    
    NodoElemento(TipoElemento tipo);

    TipoElemento obtenerTipo() const;

    float obtenerTamano() const;
    string obtenerUnidad() const;
    float obtenerCoordenadaX() const;
    float obtenerCoordenadaY() const;

    void fijarElemento(TipoElemento tipo, float tamano, string unidad, float x, float y);
    


    //lista
    NodoElemento* obtenerSiguiente() const;
    void fijarSiguiente(NodoElemento* siguiente);





    protected:

    TipoElemento tipoE;
    float tamano;
    string unidad;
    float coordX;
    float coordY;

    NodoElemento* siguiente;

    


};

#include "NodoElemento.hxx"