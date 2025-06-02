#pragma once
#include <string>

/**
 * struct Letra
 * ------------
 * La estructura Letra representa una sola línea o verso de una canción. 
 * Cada objeto de tipo Letra guarda dos cosas principales:
 *
 * Campos:
 *   - texto
 *   - sig  
 */
struct Letra {
    std::string texto; // es una cadena de texto que contiene lo que se canta en esa línea.
    Letra*      sig;   //es un puntero que apunta a otra estructura Letra, es decir, 
                       //a la siguiente línea de la canción. Esta conexión permite que las líneas se encadenen una tras otra
   
                       explicit Letra(const std::string& t) : texto(t), sig(nullptr) {}
};