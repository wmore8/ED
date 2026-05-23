 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Capitulos repetidos

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
Para resolver este problema utilizamos la tecnica de la Ventana Deslizante. Mantenemos un rango de dias [inicio, i] donde no hay capitulos repetidos. Usamos un 
unordered_map para guardar la ultima posicion (dia) en la que vimos cada capitulo. Si al leer un capitulo vemos que ya lo habiamos visto, y ademas esa emision pasada
esta dentro de nuestro periodo actual (>= inicio), significa que se ha roto la racha. Actualizamos el 'inicio' del periodo para que empiece justo el dia despues de
esa emision repetida.

Coste asintotico: O(N) en el caso promedio por el uso de unordered_map, siendo N el numero de capitulos. Recorremos el array una sola vez. 
Coste espacial: O(C), siendo C el numero de capitulos distintos que guardamos en el map.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta


bool resuelveCaso() {
    // leer los datos de la entrada
    int N = 0; cin >> N;

    int valor = 0, max_dias = 0, inicio = 0;
    unordered_map<int, int> ultima_emision;

    for (int i = 0; i < N; i++) {
        int cap = 0; 

        cin >> cap;

        if (ultima_emision.count(cap) == 1 && ultima_emision[cap] >= inicio) {
            // La nueva racha empieza justo al dia siguiente de la repeticion anterior.
            inicio = ultima_emision[cap] + 1;
        }

        // Actualizamos o registramos en el diccionario el dia de hoy para este capitulo
        ultima_emision[cap] = i;

        // Calculamos cuantos dias tiene nuestra racha actual (desde inicio hasta i) y nos quedamos con el maximo
        max_dias = max(max_dias, i - inicio + 1);
    }  
    // Escribir solucion
    cout << max_dias << "\n";
  
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("8_5.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("8_5.out");
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