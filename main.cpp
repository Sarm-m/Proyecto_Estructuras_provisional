#include "ListaComandos.h"
#include "ListaElementos.h"
#include <iostream>
#include <sstream>
using namespace std;


int main (){

    ListaComandos listaC;
    ListaElementos listaE;
    

    string entrada;
    while(true){
        cout << "$ ";
        getline(cin, entrada);

        istringstream iss(entrada);

        string comando;
        iss >> comando;
        
        if (comando == "cargar_comandos"){
            string archivo;
            iss >> archivo;
            listaC.cargarDesdeArchivo(archivo); //este es el metodo del objeto al cual se llamará cuando le pasemos el comando y llama carga los comandos


        } else if (comando == "cargar_elementos"){
            string archivo;
            iss >> archivo;
            listaE.cargarDesdeArchivo(archivo); //este es el metodo del objeto que lee una lista de elementos


        } else if (comando == "agregar_movimiento"){
            //TODO


        } else if (comando == "agregar_analisis"){
            //TODO


        } else if (comando == "agregar_elemento"){
            //TODO


        } else if (comando == "guardar"){
            //TODO


        } else if (comando == "simular_comandos"){
            //TODO


        } else if (comando == "ayuda"){
            cout << "los comandos disponibles para esta aplicacion son: " << endl;
            cout << "cargar_comandos, cargar_elementos, agregar_movimiento, agregar_analisis, "<< endl <<"agregar_elemento, guardar, simular_comandos, salir" << endl;


        } else if (comando == "salir"){
            break;
        }
    }

    return 0;
}