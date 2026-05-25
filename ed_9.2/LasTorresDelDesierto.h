

// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Las torres del desierto

#ifndef TORRES
#define TORRES


#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <map> 
#include <stdexcept>

using namespace std;

using Coordenadas = pair<int, int>;

enum Direccion {Norte, Sur, Este, Oeste};

Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}

class Desierto {

    // ATRIBUTOS
    unordered_map<string, Coordenadas> mapa_torres;
    unordered_map<int, map<int, string>> torres_x;
    unordered_map<int, map<int, string>> torres_y;

public:

    // MeTODOS

    //coste: O(1) el acceso a los unordered_map a traves de count es constante.
    void anyadir_torre(const string& nombre, int x, int y) {
        if (mapa_torres.count(nombre) == 1) {
            throw std::domain_error("Torre ya existente");
        }
        if (torre_en_posicion(x,y).first) {
            throw std::domain_error("Posicion ocupada");
        }

        Coordenadas c = { x,y };
        mapa_torres.insert({ nombre,c });
        torres_x[x].insert({ y,nombre });
        torres_y[y].insert({ x,nombre });
    }

    //coste: O(log T) siendo T el numero de Torres. Borrar la torre en el unordered_map es constante O(1), pero al borrarlo en el map ordenado, el coste es logaritmico
    void eliminar_torre(const string& nombre) {
        if (mapa_torres.count(nombre) == 0) {
            throw std::domain_error("Torre no existente");

        }

        Coordenadas c = mapa_torres[nombre];
        mapa_torres.erase(nombre);
        torres_x[c.first].erase(c.second);
        torres_y[c.second].erase(c.first);
    }

    //coste: O(1) el acceso a los unordered_map a traves de count es constante.
    Coordenadas posicion(const string& nombre) const {
        if (mapa_torres.count(nombre) == 0) {
            throw std::domain_error("Torre no existente");
        }

        return mapa_torres.at(nombre);
    }

    //coste: O(log T) siendo T el numero de Torres. Buscar la torre en el unordered_map es constante O(1), pero al buscarlo en el map ordenado, el coste es logaritmico
    pair<bool, string> torre_en_posicion(int x, int y) const{
        pair<bool, string> torre = { false, "" };

        if (torres_x.count(x) == 1 && torres_x.at(x).count(y) == 1) {
            torre.first = true;
            torre.second = torres_x.at(x).at(y);
        }

        return torre;
    }
    // Coste: O(log T) siendo T el numero de torres en esa misma fila/columna. Usamos upper_bound y lower_bound nativos del map para encontrar al vecino mas cercano.
    string torre_mas_cercana(const string& nombre, const Direccion& dir) const {
        // 1. Si no existe la torre, lanzamos error
        if (mapa_torres.count(nombre) == 0) {
            throw std::domain_error("Torre no existente");
        }

        Coordenadas c = mapa_torres.at(nombre);
        int x = c.first;
        int y = c.second;

        switch (dir){
        case Norte: {
            // Buscamos la siguiente Y mayor en la misma X
            auto it = torres_x.at(x).upper_bound(y);
            if (it != torres_x.at(x).end()) {
                return it->second;
            }
        } break;
        case Sur: {
            // Buscamos hacia atras en la misma X
            auto it = torres_x.at(x).lower_bound(y);
            if (it != torres_x.at(x).begin()) {
                --it; // Retrocedemos uno para coger el estrictamente menor
                return it->second;
            }
        }break;
        case Este: {
            // Buscamos la siguiente X mayor en la misma Y
            auto it = torres_y.at(y).upper_bound(x);
            if (it != torres_y.at(y).end()) {
                return it->second;
            }
        }break;
        case Oeste: {
            // Buscamos hacia atras en la misma Y
            auto it = torres_y.at(y).lower_bound(x);
            if (it != torres_y.at(y).begin()) {
                --it; // Retrocedemos uno para coger el estrictamente menor
                return it->second;
            }
        }break;
        default:
            break;
        }

        // Si hemos llegado aqui, es que no habia nada en esa direccion
        throw std::domain_error("No hay torres en esa direccion");
    }
}; 


#endif