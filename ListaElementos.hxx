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

string elementoATexto(TipoElemento t){
    if(t == ROCA) return "roca";
    if(t == CRATER) return "crater";
    if(t == MONTICULO) return "monticulo";
    if(t == DUNA) return "duna";
    return "";
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
        cout << "(Archivo erróneo) " << nombre_archivo << " no se encuentra o no puede leerse." << endl;
        return;
    }

    if (archivo.peek() == EOF){
        cout << "(Archivo vacío) " << nombre_archivo << " no contiene comandos." << endl;
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

    
    cout << cantidad << " comandos cargados correctamente desde " << nombre_archivo << "." << endl;

}




int ListaElementos::obtenerCantidad() const{
    return cantidad;
}



NodoElemento* ListaElementos::obtenerCabeza() const{
    return cabeza;
}



void ListaElementos::agregarElemento(TipoElemento tipo, float tamano, string unidad, float x, float y){

    if (tamano <= 0){
        cout << "(Formato erróneo) La información del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)." << endl;
        return;
    }

    NodoElemento* nuevo = new NodoElemento(tipo);
    nuevo -> fijarElemento(tipo, tamano, unidad, x, y);
    insertarAlFinal(nuevo);

    cout << "El elemento ha sido agregado exitosamente." << endl;
}




void ListaElementos::guardar (string nombre_archivo){
    
    if(cabeza == nullptr){
        cout << "(No hay información) La información requerida no está almacenada en memoria." << endl;
        return;
    }

    ofstream archivo(nombre_archivo);

    if(!archivo.is_open()){
        cout << "(Problemas en archivo) Error guardando en " << nombre_archivo << "." << endl;
        return;
    }

    NodoElemento* actual = cabeza;

    while (actual != nullptr){
        archivo << elementoATexto(actual -> obtenerTipo()) << " " << actual -> obtenerTamano() << " " << actual -> obtenerUnidad() << " " << actual -> obtenerCoordenadaX() << " " << actual -> obtenerCoordenadaY() << endl;
        actual = actual -> obtenerSiguiente();
    }
    archivo.close();

    cout << "(Escritura exitosa) La información ha sido guardada en " << nombre_archivo << "." << endl;
}