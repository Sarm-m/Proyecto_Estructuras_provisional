#pragma once
#include <string>
#include "Tipos.h"
using namespace std;


//nodo de comando
class NodoComando{
    public:

    NodoComando(TipoComando tipo);

    TipoComando obtenerTipo() const;

    //Movimiento
    TipoMovimiento obtenerTipoMov() const;
    float obtenerMagnitud() const;
    string obtenerUnidad() const;
    void fijarMovimiento(TipoMovimiento tipo, float magnitud, string unidad);



    //analisis
    TipoAnalisis obtenerTipoAnls() const;
    string obtenerObjeto() const;
    string obtenerComentario() const;
    void fijarAnalisis(TipoAnalisis tipo, string objeto, string comentario);


    //lista enlazada
    NodoComando* obtenerSiguiente() const;
    void fijarSiguiente(NodoComando* siguiente);



    protected:

    TipoComando tipoC;
    TipoMovimiento tipoM;
    float magnitud;
    string unidad;
    TipoAnalisis tipoA;
    string objeto;
    string comentario;
    NodoComando* siguiente;
};




#include "NodoComando.hxx"