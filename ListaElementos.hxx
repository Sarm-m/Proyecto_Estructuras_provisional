#include "ListaElementos.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


//constructor
ListaElementos::ListaElementos(){
    cabeza = nullptr;
    cantidad = 0;
}


ListaElementos::~ListaElementos(){
    vaciar();
}



void ListaElementos::vaciar(){

    NodoElemento* actual = cabeza; //empieza creando un puntero que recorre la lista

    while (actual != nullptr){      //mientras haya nodos que recorrer, el sigue hasta que "actual" sea "nullptr"
        NodoElemento* siguiente = actual->obtenerSiguiente();
        delete actual;                  //elimina el nodo actual que se está leyendo para liberar memoria
        actual = siguiente;             //se libera la memoria del nodo que se recorre "actual" para evitar memory leak
    }

    cabeza = nullptr;
    cantidad = 0;

}


void ListaElementos::insertarAlFinal(NodoElemento* nuevo){

     if (cabeza == nullptr){
        cabeza = nuevo;
    } else{

        NodoElemento* actual = cabeza;

     while (actual->obtenerSiguiente() != nullptr){
        actual = actual->obtenerSiguiente();
    }
        actual->fijarSiguiente(nuevo); //nuevo es el siguiente
}
    cantidad++;

}




void ListaElementos::cargarDesdeArchivo(string nombre_archivo){
    ifstream archivo (nombre_archivo);

    if (!archivo.is_open()){
        cout << "Error: El archivo no se puede abrir" << endl;
        return;
    }

    if (archivo.peek() == EOF){
        cout << "El archivo que quieres cargar, está vacío" << endl;
        return;
    }

    vaciar();

    string linea;
    while (getline (archivo, linea)){

        istringstream iss (linea);
        
        string tipo;
        float tamano;
        string unidad;
        float coordx;
        float coordy;

        iss >> tipo; 
        

        //validacion de tipo para crear un nuevo nodo
        if (tipo == "roca" || tipo == "crater" || tipo == "monticulo" || tipo == "duna"){

            iss >> tamano;
            iss >> unidad;
            iss >> coordx;
            iss >> coordy;

            

            //inserta nuevos datos en el nodo
            TipoElemento tipoE = (tipo == "roca") ? ROCA : 
                               (tipo == "crater") ? CRATER:
                               (tipo == "monticulo") ? MONTICULO : DUNA;


            //crea nuevo nodo de movimiento
            NodoElemento* nuevo = new NodoElemento(tipoE);
            nuevo->fijarElemento(tipoE, tamano, unidad, coordx, coordy);
            nuevo->fijarSiguiente(nullptr);
            insertarAlFinal(nuevo);

        }


    }

    
    cout << cantidad << " elementos se han cargado correctamente desde: " << nombre_archivo << "." << endl;

}




int ListaElementos::obtenerCantidad() const{
    return cantidad;
}



NodoElemento* ListaElementos::obtenerCabeza() const{
    return cabeza;
}



void agregarElemento(TipoElemento tipo, float tamano, string unidad, float x, float y){


    //TODO que implementa Santiago



}




void guardar (string nombre_archivo){
    

    //TODO que implementa Santiago



}