#pragma once
#include "Cancion.h"

struct Partitura {
    Cancion* primeraCancion; //Es un puntero a una Cancion,representa el inicio de la lista de canciones
    Partitura() : primeraCancion(nullptr) {} //Este es el constructor de la estructura,porque automáticamente su campo primeraCancion se inicializa como nullptr.
                                            //Es decir, al principio la partitura no tiene ninguna canción
};