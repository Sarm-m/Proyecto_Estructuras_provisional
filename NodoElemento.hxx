#include "NodoElemento.h"

//Constructor
NodoElemento::NodoElemento(TipoElemento tipo){

    this->tipoE = tipo;
    this->siguiente = nullptr;

}


// definicion de tipo de elemento
TipoElemento NodoElemento::obtenerTipo() const{
    return tipoE;

}


float NodoElemento::obtenerTamano() const{
    return tamano;
}

string NodoElemento::obtenerUnidad() const{
    return unidad;
}

float NodoElemento::obtenerCoordenadaX() const{
    return coordX;
}

float NodoElemento::obtenerCoordenadaY() const{
    return coordY;
}

void NodoElemento::fijarElemento(TipoElemento tipo, float tamano, string unidad, float x, float y){
    this->tipoE = tipo;
    this->tamano = tamano;
    this->unidad = unidad;
    this->coordX = x;
    this->coordY = y;
}


//definicion de lista 
NodoElemento* NodoElemento::obtenerSiguiente() const{
    return siguiente;
} 

void NodoElemento::fijarSiguiente(NodoElemento* siguiente){
    this->siguiente = siguiente;
}
