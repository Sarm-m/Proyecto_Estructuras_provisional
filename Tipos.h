#pragma once
#include <string>
using namespace std;

enum TipoMovimiento {AVANZAR, GIRAR};
enum TipoAnalisis {FOTOGRAFIAR, COMPOSICION, PERFORAR};
enum TipoComando {MOVIMIENTO, ANALISIS};
enum TipoElemento {ROCA, CRATER, MONTICULO, DUNA}; 


inline bool validarUnidad(TipoMovimiento tipo, string unidad){
    if (tipo == AVANZAR)
    return unidad == "cm" || unidad == "dm" || unidad == "m" || unidad == "km";
    if (tipo == GIRAR)
    return unidad == "grd" || unidad =="rad";
    return false;
}