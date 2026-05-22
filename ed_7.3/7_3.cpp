 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: El juego de la mona

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
// Introduce más librerías si son necesarias
/*
Para resolver el ejercicio necesitamos utilizar una lista ordenada para ver las cartas de los jugadores tras el reparto. Mientras leemos la entrada simulamos el reparto
de cartas entre los distintos jugadores. En cada ronda verficamos que la carta a repartir no este duplicada, y en caso de que lo este, la eliminamos de la mano del jugador.
En el otro la añadimos y seguimos repartiendo.

El coste de la funcion es de O(M log(M/N)), siendo M el numero total de cartas repartidas y N el numero de jugadores.  El coste de recorrer todas las cartas es lineal 
O(M), y el coste de buscar, insertar o borrar una carta en el conjunto de un jugador es logarítmico O(log K), donde K es la cantidad de cartas en su mano (como mucho M/N). 
Como las operaciones en los conjuntos se hacen durante el recorrido de todas las cartas, el coste total asciende a: O(M log(M/N)).
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


void mostrarJugadores(vector<set<int>> jugadores) {

    for (int i = 0; i < jugadores.size(); i++) {
        cout << "J" << i + 1 << ": {";

        for (int valor : jugadores[i]) {
            if (valor == *jugadores[i].begin()) {
                cout << valor;
            }
            else {
                cout << ", " << valor;
            }
        }
        cout << "}\n";
    }
    cout << "---\n";
}

bool resuelveCaso() {
    int N, M; cin >> N >> M;

    if (!cin) return false;
    // leer los datos de la entrada
    vector<set<int>> jugadores(N);

    // Leemos las M cartas y las vamos repartiendo
    for (int i = 0; i < M; i++) {
        int carta;
        cin >> carta;

        int turno = i % N;

        // Si el jugador ya tiene la carta, hace pareja y la borra
        if (jugadores[turno].count(carta) == 1) {
            jugadores[turno].erase(carta);
        }
        // Si no la tiene, se la queda
        else {
            jugadores[turno].insert(carta);
        }
    }
    // Escribir solución
    mostrarJugadores(jugadores);
  
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("7_3.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("7_3.out");
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