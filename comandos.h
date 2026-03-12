#ifndef COMANDOS_H
#define COMANDOS_H

#include <string>
using namespace std;


enum TipoMovimiento {AVANZAR, GIRAR};
enum TipoAnalisis {FOTOGRAFIAR, COMPOSICION, PERFORAR};
enum TipoComando {MOVIMIENTO, ANALISIS};
enum TipoElemento {ROCA, CRATER, MONTICULO, DUNA}; 



//comandos de movimiento
struct comandos_movimiento{

    TipoMovimiento tipoM; // puede ser avanzar o girar

    float magnitud; // valor o cantidad de movimiento, puede ser 40, 35, 0.75
    
    string unidad; //es la unidad de medicion de movimiento; ya sea "cm" en avanzar, o "grd" en girar

};




//comandos de analisis
struct comandos_analisis{

    TipoAnalisis tipoA; //puede ser fotografiar, composicion, perforar

    string objeto; //es el nombre del objeto que se va a analisar

    string comentario; //brinda informacion adicional del objeto que se está analisando

};

struct nodo_de_comandos{

    TipoComando tipoC; //recordemos que los comandos pueden ser analisis y movimiento, esto nos ayudará a definir si se guardará un movimiento o un analisis

    comandos_movimiento mov; //llamamos la estructura de los comandos de movimiento y la definimos como "mov"; se usará si "tipo == MOVIMIENTO"
    
    comandos_analisis anls; //Llamamos la estructura de los comandos de analisis y la definimos como "anls"; se usará si "Tipo == ANALISIS"
    
    nodo_de_comandos* siguiente; //Apuntará al siguiente nodo, esto le empezará a dar forma a la cadena o lista enlazada de acciones para el robot

};

struct Lista_de_comandos{

    nodo_de_comandos* cabeza; //lo que hace es apuntar al primer nodo de comandos (a la cabeza) y si está vacía (nullptr) entonces la lista está vacía
    
    int cantidadC; // nos ayudará a saber cuantos comandos se cargarán y sirve para poder imprimir cuantos comandos se cargaron 

};

//se define lo que tendrá un elemento, con sus atributos
struct elemento{

    TipoElemento tipoE;  

    float tamano;

    string unidad;

    float coordX;

    float coordY;

    elemento* siguiente;

};

struct Lista_de_elementos{

    elemento* cabeza; //apunta al primer nodo de elemento (a la cabeza) valida que no sea (nullptr)

    int cantidadE; //nos ayudará a validar cuantos elementos fueron cargados y de paso imprimirlos despues
};


//inicializar las listas
void inicializarC(Lista_de_comandos &Lista);
void inicializarE(Lista_de_elementos &Lista);


//vaciar las listas
void vaciarC(Lista_de_comandos &Lista);
void vaciarE(Lista_de_elementos &Lista);


//insertar al final, lo que hace es que buscará donde insertar el nodo nuevo que llegue
void insertar_al_finalC(Lista_de_comandos &Lista, nodo_de_comandos* nuevo);
void insertar_al_finalE(Lista_de_elementos &Lista, elemento* nuevo);



//validacion de unidad
bool validacion_unidad(TipoMovimiento tipoM, string unidad);

//carga de comandos
void cargar_comandos(Lista_de_comandos &Lista, string nombre_archivo); 


//cargar elementos
void cargar_elementos(Lista_de_elementos &Lista, string nombre_archivo);
#endif