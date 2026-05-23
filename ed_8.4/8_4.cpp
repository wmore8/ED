 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Actualización de un diccionario

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <sstream>
#include <cctype>
// Introduce mas librerias si son necesarias
/*
Para resolver este problema utilizamos dos diccionarios (map) para almacenar el estado antiguo y el nuevo. Leemos las lineas completas usando getline y las procesamos
con stringstream.
Luego comparamos ambos diccionarios:
- Si una clave del antiguo no esta en el nuevo -> Borrada (-)
- Si una clave del antiguo esta en el nuevo pero con distinto valor -> Modificada (*)
- Si una clave del nuevo no esta en el antiguo -> Añadida (+)
Guardamos los resultados en 3 sets (conjuntos ordenados) para que se impriman automaticamente en orden alfabetico.

Coste asintotico: O(K log K) donde K es el total de claves en la linea, por las inserciones en los mapas y sets.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta


bool resuelveCaso() {
    // leer los datos de la entrada
    map<string, int> diccionario_antiguo;
    map<string, int> diccionario_nuevo;

    string linea_antigua, linea_nueva;

    getline(cin, linea_antigua);
    getline(cin, linea_nueva);

    stringstream ss_anitguo(linea_antigua);
    string clave;
    int valor;

    //leemos el diccionario antiguo
    while (ss_anitguo >> clave >> valor) {
        diccionario_antiguo[clave] = valor;
    }

    //leemos el diccionario nuevo
    stringstream ss_nuevo(linea_nueva);

    while (ss_nuevo >> clave >> valor) {
        diccionario_nuevo[clave] = valor;
    }

    //los 3 sets de estados
    set<string> agregados, borrados, modificados;

    for (const auto& palabra : diccionario_antiguo) {
        // si alguna palabra del viejo diccionario no se encuentra en el nuevo
        if (diccionario_nuevo.count(palabra.first) == 0) {
            borrados.insert(palabra.first);
        }
        else if (diccionario_nuevo[palabra.first] != palabra.second) { // si esta, pero el valor no es el mismo, entonces ha sido modificado
            modificados.insert(palabra.first);
        }
    }

    //buscamos las nuevas palabras añadidas
    for (const auto& palabra : diccionario_nuevo) {
        if (diccionario_antiguo.count(palabra.first) == 0) {
            agregados.insert(palabra.first);
        }
    }
   
    // Escribir solucion
    if (agregados.empty() && modificados.empty() && borrados.empty()) {
        cout << "Sin cambios\n";
    }
    else {
        if (!agregados.empty()) {
            cout << "+";
            for (const string& s : agregados) cout << " " << s;
            cout << "\n";
        }
        if (!borrados.empty()) {
            cout << "-";
            for (const string& s : borrados) cout << " " << s;
            cout << "\n";
        }
        if (!modificados.empty()) {
            cout << "*";
            for (const string& s : modificados) cout << " " << s;
            cout << "\n";
        }
    }
   

    cout << "---\n";
  
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("8_4.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("8_4.out");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore();

    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
#endif
    return 0;
}