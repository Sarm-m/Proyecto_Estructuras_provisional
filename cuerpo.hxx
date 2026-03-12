//comandos hxx
#include "Lista_comandos.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


void cargar_comandos(Lista_de_comandos &Lista, string nombre_archivo){

    ifstream archivo (nombre_archivo);

    if (!archivo.is_open()){
        cout << "Error: El archivo no se puede abrir" << endl;
        return;
    }

    if (archivo.peek() == EOF){
        cout << "El archivo que quieres cargar, está vacío" << endl;
        return;
    }

    vaciarC(Lista);

    string linea;
    while (getline (archivo, linea)){

        istringstream iss (linea);
        
        string tipo;
        float magnitud;
        string unidad;

        iss >> tipo; 
        

        //validacion de tipo para crear un nuevo nodo
        if (tipo == "avanzar" || tipo == "girar"){

            iss >> magnitud;
            iss >> unidad;

            //crea nuevo nodo de movimiento
            nodo_de_comandos* nuevo = new nodo_de_comandos();

            //inserta nuevos datos en el nodo
            nuevo->tipoC = MOVIMIENTO;
            nuevo->mov.tipoM = (tipo == "avanzar") ? AVANZAR : GIRAR;
            nuevo->mov.magnitud = magnitud;
            nuevo->mov.unidad = unidad;
            nuevo->siguiente = nullptr;
            insertar_al_finalC(Lista, nuevo);



        }else if (tipo == "fotografiar" || tipo == "composicion" || tipo == "perforar"){
        
            string objeto;
            iss >> objeto;

            //se debe leer un comentario opcionanl - ayuda de ChatGPT inicio
            string comentario = "";
            string opcional;
            getline(iss, opcional);

            if (!opcional.empty()){
                int inicio = opcional.find('\'');
                int fin = opcional.rfind('\'');
                if (inicio != string::npos && inicio != fin){
                    comentario = opcional.substr(inicio + 1, fin - inicio - 1);
                }
            }
            //Fin ayuda de ChatGPT


            //creacion de nodo de analisis
            nodo_de_comandos* nuevo = new nodo_de_comandos();

            //agregar datos 
            nuevo->tipoC = ANALISIS;
            nuevo->anls.tipoA = (tipo == "fotografiar") ? FOTOGRAFIAR : 
                                (tipo == "composicion") ? COMPOSICION : PERFORAR;
            nuevo->anls.objeto = objeto;
            nuevo->anls.comentario = comentario;
            nuevo->siguiente = nullptr;
            insertar_al_finalC(Lista, nuevo);

        }


    }

    
    cout << Lista.cantidadC << "Los comandos se han cargado correctamente de: " << nombre_archivo << "." << endl;

}





//cargar elementos
void cargar_elementos(Lista_de_elementos &Lista, string nombre_archivo){

    ifstream archivo (nombre_archivo);

    if (!archivo.is_open()){
        cout << "Error: El archivo no se puede abrir" << endl;
        return;
    }

    if (archivo.peek() == EOF){
        cout << "El archivo que quieres cargar, está vacío" << endl;
        return;
    }

    vaciarE(Lista);

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

            //crea nuevo nodo de movimiento
            elemento* nuevo = new elemento();

            //inserta nuevos datos en el nodo
            nuevo->tipoE = (tipo == "roca") ? ROCA : 
                               (tipo == "crater") ? CRATER:
                               (tipo == "monticulo") ? MONTICULO : DUNA;
            nuevo->tamano = tamano;
            nuevo->unidad = unidad;
            nuevo->coordX = coordx;
            nuevo->coordY = coordy;
            nuevo->siguiente = nullptr;
            insertar_al_finalE(Lista, nuevo);

        }


    }

    
    cout << Lista.cantidadE << "Los elementos se han cargado correctamente de: " << nombre_archivo << "." << endl;

}







bool validacion_unidad(TipoMovimiento tipoM, string unidad){
    if (tipoM == AVANZAR){
        return unidad == "cm" || unidad == "dm" || unidad == "m" || unidad == "km";
    }

    if (tipoM == GIRAR){
        return unidad == "grd" || unidad == "rad";
        
    }
    return false;
}


//inicializar
void inicializarC(Lista_de_comandos &Lista){
    Lista.cabeza = nullptr;
    Lista.cantidadC = 0;
}

void inicializarE(Lista_de_elementos &Lista){
    Lista.cabeza = nullptr;
    Lista.cantidadE = 0;
}



//vaciar las listas
void vaciarC(Lista_de_comandos &Lista){

    nodo_de_comandos* actual = Lista.cabeza; //empieza creando un puntero que recorre la lista

    while (actual != nullptr){      //mientras haya nodos que recorrer, el sigue hasta que "actual" sea "nullptr"
        nodo_de_comandos* siguiente = actual->siguiente;
        delete actual;                  //elimina el nodo actual que se está leyendo para liberar memoria
        actual = siguiente;             //se libera la memoria del nodo que se recorre "actual" para evitar memory leak
    }

    inicializarC(Lista);            //el puntero se mueve al siguiente nodo que se guardó antes
    
}



void vaciarE(Lista_de_elementos &Lista){

    elemento* actual = Lista.cabeza;

    while (actual != nullptr){
        elemento* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    inicializarE(Lista);
}


//si la lista está vacía, el nuevo nodo es la cabeza, y si la lista tiene nodos, el nuevo nodo se pone al final de la cadena
void insertar_al_finalC(Lista_de_comandos &Lista, nodo_de_comandos* nuevo){


    if (Lista.cabeza == nullptr){
        Lista.cabeza = nuevo;
    } else{

        nodo_de_comandos* actual = Lista.cabeza;

     while (actual->siguiente != nullptr){
        actual = actual->siguiente;
    }
        actual->siguiente = nuevo; //nuevo es el siguiente
}
    Lista.cantidadC++;
}


void insertar_al_finalE(Lista_de_elementos &Lista, elemento* nuevo){

 if (Lista.cabeza == nullptr){
        Lista.cabeza = nuevo;
    } else{

        elemento* actual = Lista.cabeza;

     while (actual->siguiente != nullptr){
        actual = actual->siguiente;
    }
        actual->siguiente = nuevo; //nuevo es el siguiente
}
    Lista.cantidadE++;

}