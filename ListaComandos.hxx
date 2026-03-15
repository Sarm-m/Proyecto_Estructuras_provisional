#include "ListaComandos.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//constructor
ListaComandos::ListaComandos(){
    cabeza = nullptr;
    cantidad = 0;
}


ListaComandos::~ListaComandos(){
    vaciar();
}

string movimientoATexto(TipoMovimiento t){
    if(t == AVANZAR) return "avanzar";
    if(t == GIRAR) return "girar";
    return "";
}

string analisisATexto(TipoAnalisis t){
    if(t == FOTOGRAFIAR) return "fotografiar";
    if(t == COMPOSICION) return "composicion";
    if(t == PERFORAR) return "perforar";
    return "";
}

void ListaComandos::vaciar(){

    NodoComando* actual = cabeza; //empieza creando un puntero que recorre la lista

    while (actual != nullptr){      //mientras haya nodos que recorrer, el sigue hasta que "actual" sea "nullptr"
        NodoComando* siguiente = actual->obtenerSiguiente();
        delete actual;                  //elimina el nodo actual que se está leyendo para liberar memoria
        actual = siguiente;             //se libera la memoria del nodo que se recorre "actual" para evitar memory leak
    }

}


void ListaComandos::insertarAlFinal(NodoComando* nuevo){

     if (cabeza == nullptr){
        cabeza = nuevo;
    } else{

        NodoComando* actual = cabeza;

     while (actual->obtenerSiguiente() != nullptr){
        actual = actual->obtenerSiguiente();
    }
        actual->fijarSiguiente(nuevo); //nuevo es el siguiente
}
    cantidad++;

}




void ListaComandos::cargarDesdeArchivo(string nombre_archivo){
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
        float magnitud;
        string unidad;

        iss >> tipo; 
        

        //validacion de tipo para crear un nuevo nodo
        if (tipo == "avanzar" || tipo == "girar"){

            iss >> magnitud;
            iss >> unidad;

            //crea nuevo nodo de movimiento
            NodoComando* nuevo = new NodoComando(MOVIMIENTO);

            //inserta nuevos datos en el nodo
            nuevo->fijarMovimiento((tipo == "avanzar") ? AVANZAR : GIRAR, magnitud, unidad);
            nuevo->fijarSiguiente(nullptr);
            insertarAlFinal(nuevo);



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
            NodoComando* nuevo = new NodoComando(ANALISIS);

            //agregar datos 
            nuevo->fijarAnalisis((tipo == "fotografiar") ? FOTOGRAFIAR : (tipo == "composicion") ? COMPOSICION : PERFORAR, objeto, comentario);
            nuevo->fijarSiguiente(nullptr);
            insertarAlFinal(nuevo);

        }


    }

    
    cout << cantidad << " comandos se han cargado correctamente desde: " << nombre_archivo << "." << endl;


}




int ListaComandos::obtenerCantidad() const{
    return cantidad;
}



NodoComando* ListaComandos::obtenerCabeza() const{
    return cabeza;
}

    void ListaComandos::agregarMovimiento(TipoMovimiento tipo, float magnitud, string unidad){

        if(magnitud <= 0){
            cout << "(Formato erroneo) La informacion del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)." << endl;
            return;
        }

        NodoComando* nuevo = new NodoComando(MOVIMIENTO);
        nuevo -> fijarMovimiento(tipo, magnitud, unidad);
        insertarAlFinal(nuevo);

        cout << "El comando de movimiento ha sido agregado exitosamente." << endl;
    } 



    void ListaComandos::agregarAnalisis(TipoAnalisis tipo, string objeto, string comentario){

        if (objeto == ""){
            cout << "(Formato erróneo) La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario)." << endl;
            return;
        }

        NodoComando* nuevo = new NodoComando(ANALISIS);
        nuevo -> fijarAnalisis(tipo, objeto, comentario);
        insertarAlFinal(nuevo);

        cout << "El comando de análisis ha sido agregado exitosamente." << endl;
    }  



    void ListaComandos::guardar(string nombre_archivo){

        if (cabeza == nullptr){
            cout << "(No hay información) La información requerida no está almacenada en memoria." << endl;
            return;
        }

        ofstream archivo(nombre_archivo);

        if(!archivo.is_open()){
            cout << "(Problemas en archivo) Error guardando en " << nombre_archivo << "." << endl;
            return;
        }

        NodoComando* actual = cabeza;

        while(actual != nullptr){
            if (actual -> obtenerTipo() == MOVIMIENTO){
                archivo << movimientoATexto(actual -> obtenerTipoMov()) << " " << actual -> obtenerMagnitud() << " " << actual -> obtenerUnidad() << endl;
            }
            else if (actual -> obtenerTipo() == ANALISIS){
                archivo << analisisATexto(actual -> obtenerTipoAnls())<< " " << actual -> obtenerObjeto();

                if (actual -> obtenerComentario() != ""){
                    archivo << " '" << actual -> obtenerComentario() << "'";
                }
                archivo << endl;
            }
            actual = actual -> obtenerSiguiente();
        }
        archivo.close();
        cout << "(Escritura exitosa) La información ha sido guardada en " << nombre_archivo << "." << endl;
    }



    void simularComandos(float coordX, float coordY){

        //TODO que implementa sebastian


    }