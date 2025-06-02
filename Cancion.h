#pragma once
#include <string>
#include "Letra.h"

/**
 * struct Cancion
 * ------------
 * Representa una canción dentro de una especie de lista enlazada.
 * Cada canción tiene tres componentes principales:
 *
 * Campos:
 *   - nombre
 *   - primeraLetra
 *   - sigCancion 
 */

struct Cancion {
    std::string nombre; //es una cadena de texto (std::string) que guarda el nombre de la canción
    Letra*      primeraLetra; //es un puntero a un objeto de tipo Letra, que representa la letra de la canción
    Cancion*    sigCancion; //es un puntero a otra estructura Cancion, que permite conectar esta canción con la siguiente
    

// Este contructor denominado Cancion(const std::string& n) se usa para crear una nueva canción asignándole un nombre, y
// dejando vacíos (nullptr) tanto el puntero a la letra como el puntero a la siguiente canción.

    explicit Cancion(const std::string& n)
        : nombre(n), primeraLetra(nullptr), sigCancion(nullptr) {}
};