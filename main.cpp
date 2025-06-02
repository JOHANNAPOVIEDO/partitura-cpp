#include <sstream> 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Partitura.h"  
#include "Letra.h"

//La función splitPorComas toma una línea de texto que contiene varias palabras separadas por comas.
static std::vector<std::string> splitPorComas(const std::string& linea) {
    std::vector<std::string> resultado;
    std::stringstream ss(linea);
    std::string campo;
    while (std::getline(ss, campo, ',')) {
        resultado.push_back(campo);
    }
    return resultado;
}

int main() {
    Partitura* miPartitura = new Partitura();
    Cancion*   ultimoCancion = nullptr;

    std::ifstream archivo("canciones.txt");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir 'canciones.txt'\n";
        delete miPartitura;
        return 1;
    }

    std::string lineaTexto;
    while (std::getline(archivo, lineaTexto)) {
        auto campos = splitPorComas(lineaTexto);
        if (campos.empty() || campos[0].empty()) continue;

        Cancion* nuevaCancion = new Cancion(campos[0]);
        if (miPartitura->primeraCancion == nullptr) {
            miPartitura->primeraCancion = nuevaCancion;
            ultimoCancion = nuevaCancion;
        } else {
            ultimoCancion->sigCancion = nuevaCancion;
            ultimoCancion = nuevaCancion;
        }

        Letra* ultimaLetra = nullptr;
        for (size_t i = 1; i < campos.size(); ++i) {
            if (campos[i].empty()) break;
            Letra* nuevaLetra = new Letra(campos[i]);
            if (nuevaCancion->primeraLetra == nullptr) {
                nuevaCancion->primeraLetra = nuevaLetra;
                ultimaLetra = nuevaLetra;
            } else {
                ultimaLetra->sig = nuevaLetra;
                ultimaLetra = nuevaLetra;
            }
        }
    }
    archivo.close();
     
    // Imprimir
    std::cout << "=== IMPRIMIENDO PARTITURA ===\n\n";
    for (Cancion* c = miPartitura->primeraCancion; c; c = c->sigCancion) {
        std::cout << "Cancion: " << c->nombre << "\n";
        int n = 1;
        for (Letra* l = c->primeraLetra; l; l = l->sig) {
            std::cout << "  Linea" << n++ << ": " << l->texto << "\n";
        }
        std::cout << "\n";
    }

    // Liberar memoria
    for (Cancion* c = miPartitura->primeraCancion; c;) {
        for (Letra* l = c->primeraLetra; l;) {
            Letra* sigL = l->sig;
            delete l;
            l = sigL;
        }
        Cancion* sigC = c->sigCancion;
        delete c;
        c = sigC;
    }
    delete miPartitura;
    return 0;
}
