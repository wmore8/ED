
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Autoescuela

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "autoescuela.h"


bool resuelveCaso() {
	std::string op, alum, prof;
	int punt;
	std::cin >> op;
	if (!std::cin)
		return false;

	autoescuela AE;

	while (op != "FIN") {
		try {
			if (op == "alta") {
				cin >> alum >> prof;
				AE.alta(alum, prof);
			}
			else if (op == "es_alumno") {
				cin >> alum >> prof;

				if (AE.es_alumno(alum, prof)) {
					cout << alum << " es alumno de " << prof << "\n";
				}
				else {
					cout << alum << " no es alumno de " << prof << "\n";
				}
			}
			else if (op == "puntuacion") {
				cin >> alum;
				int puntos = AE.puntuacion(alum);
				cout << "Puntuacion de " << alum << ": " << puntos << "\n";
			}
			else if (op == "actualizar") {
				cin >> alum >> punt;
				AE.actualizar(alum, punt);
			}
			else if (op == "examen") {
				cin >> prof >> punt;
				set<string> aptos = AE.examen(prof, punt);

				cout << "Alumnos de " << prof << " a examen:\n";
				for (auto alumno : aptos) {
					cout << alumno << "\n";
				}
			}
			else if (op == "aprobar") {
				cin >> alum;
				AE.aprobar(alum);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		std::cin >> op;
	}
	std::cout << "---\n";
	return true;
}

	
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("9_1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	/*std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());*/
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//std::cout.rdbuf(coutbuf);
#endif
	return 0;
}