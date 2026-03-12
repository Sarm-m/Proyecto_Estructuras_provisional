#include "NodoComando.h"

//Constructor
NodoComando::NodoComando(TipoComando tipo){

    this->tipoC = tipo;
    this->siguiente = nullptr;

}


// definicion de tipo de comando (movimiento y analisis)
TipoComando NodoComando::obtenerTipo() const{
    return tipoC;

}


// definicion de movimientos
TipoMovimiento NodoComando::obtenerTipoMov() const{
    return tipoM;
}

float NodoComando::obtenerMagnitud() const{
    return magnitud;
}

string NodoComando::obtenerUnidad() const{
    return unidad;
}

void NodoComando::fijarMovimiento(TipoMovimiento tipo, float magnitud, string unidad){
    this->tipoM = tipo;
    this->magnitud = magnitud;
    this->unidad = unidad;
}



//definicion de analisis
TipoAnalisis NodoComando::obtenerTipoAnls() const{
    return tipoA;
}

string NodoComando::obtenerObjeto() const{
    return objeto;
}

string NodoComando::obtenerComentario() const{
    return comentario;
}

void NodoComando::fijarAnalisis(TipoAnalisis tipo, string objeto, string comentario){
    this->tipoA = tipo;
    this->objeto = objeto;
    this->comentario = comentario;
}


//definicion de lista enlazada
NodoComando* NodoComando::obtenerSiguiente() const{
    return siguiente;
} 

void NodoComando::fijarSiguiente(NodoComando* siguiente){
    this->siguiente = siguiente;
}
