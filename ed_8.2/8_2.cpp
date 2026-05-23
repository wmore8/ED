 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Me pillo el toro

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
// Introduce más librerías si son necesarias
/*
Para resolver el problema utilizamos un diccionario ordenado (map) donde la clave es el nombre del alumno (string) y el valor es su puntuación (int). 
Como los nombres pueden tener espacios, utilizamos getline() para leer la línea completa, usando cin.ignore() tras leer el número inicial.

Coste total: O(N log A) donde N es el numero de ejercicios y A el numero de alumnos distintos. Leer y procesar cada ejercicio cuesta O(log A) por la busqueda/insercion 
en el mapa. Recorrer el mapa al final cuesta O(A). El espacio utilizado es O(A) para almacenar a los alumnos.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


bool resuelveCaso() {
    int N; cin >> N;

    if (N == 0) return false;
    cin.ignore();
    // leer los datos de la entrada
    map<string, int> alumnos;

    for (int i = 0; i < N; i++) {
        string nombre, resultado;
        getline(cin, nombre);
        getline(cin, resultado);

        if (!alumnos[nombre]) {
            alumnos[nombre] = 0;
        }
        
        if (resultado == "CORRECTO") {
            alumnos[nombre]++;
        }
        else {
            alumnos[nombre]--;
        }
        
        
    }
    // Escribir solución

    for (auto alumno : alumnos) {
        if (alumno.second != 0) {
            cout << alumno.first << ", " << alumno.second << "\n";
        }
    }

    cout << "---\n";
  
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("8_2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("8_2.out");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
#endif
    return 0;
}