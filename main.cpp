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
            string tipoStr, unidad;
            float magnitud;

            iss >> tipoStr >> magnitud >> unidad;

            TipoMovimiento tipo;

            if (tipoStr == "avanzar"){
                tipo = AVANZAR;
            } else if (tipoStr == "girar"){
                tipo = GIRAR;
            } else {
                cout << "(Formato erroneo) Tipo de movimiento invalido." << endl;
                continue;
            }

            listaC.agregarMovimiento(tipo, magnitud, unidad);


        } else if (comando == "agregar_analisis"){
            string tipoStr, objeto;
            iss >> tipoStr >> objeto;
            string comentario = "";
            string resto;
            getline(iss, resto);

            if (!resto.empty()){
                int inicio = resto.find('\'');
                int fin = resto.rfind('\'');
                if (inicio != string::npos && fin != inicio){
                    comentario = resto.substr(inicio + 1, fin - inicio - 1);
                }
            }

            TipoAnalisis tipo;

            if (tipoStr == "fotografiar"){
                tipo = FOTOGRAFIAR;
            } else if (tipoStr == "composicion"){
                tipo = COMPOSICION;
            } else if (tipoStr == "perforar"){
                tipo = PERFORAR;
            } else {
                cout << "(Formato erroneo) Tipo de analisis invalido." << endl;
                continue;
            }

            listaC.agregarAnalisis(tipo, objeto, comentario);


        } else if (comando == "agregar_elemento"){
            string tipoStr, unidad;
            float tamano, x, y;

            iss >> tipoStr >> tamano >> unidad >> x >> y;

            TipoElemento tipo;

            if (tipoStr == "roca"){
                tipo = ROCA;
            } else if (tipoStr == "crater"){
                tipo = CRATER;
            } else if (tipoStr == "monticulo"){
                tipo = MONTICULO;
            } else if (tipoStr == "duna"){
                tipo = DUNA;
            } else {
                cout << "(Formato erroneo) Tipo de elemento invalido." << endl;
                continue;
            }

            listaE.agregarElemento(tipo, tamano, unidad, x, y);


        } else if (comando == "guardar"){
            string tipo, archivo;
            iss >> tipo >> archivo;

            if (tipo == "comandos"){
                listaC.guardar(archivo);
            }
            else if (tipo == "elementos"){
                listaE.guardar(archivo);
            }
            else{
                cout << "(Formato erroneo) Tipo de archivo invalido." << endl;
            }
            

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