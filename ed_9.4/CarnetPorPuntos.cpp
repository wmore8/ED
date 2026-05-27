
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Carnet por puntos 2

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "CarnetPorPuntos.h"


bool resuelveCaso() {
	std::string op, dni;
	int punt;
	std::cin >> op;
	if (!std::cin)
		return false;

	CarnetPuntos C;

	while (op != "FIN") {
		try {
			if (op == "nuevo") {
				cin >> dni;
				C.nuevo(dni);
			}
			else if (op == "quitar") {
				cin >> dni >> punt;
				C.quitar(dni, punt);
			}
			else if (op == "recuperar") {
				cin >> dni >> punt;
				C.recuperar(dni, punt);
			}
			else if (op == "consultar") {
				cin >> dni;
				int puntos = C.consultar(dni);

				cout << "Puntos de " << dni << ": " << puntos << "\n";

			}
			else if (op == "cuantos_con_puntos") {
				cin >> punt;
				int cuantos = C.cuantos_con_puntos(punt);

				cout << "Con " << punt << " puntos hay " << cuantos << "\n";
			}
			else if (op == "lista_por_puntos") {
				cin >> punt;
				list<string> lista = C.lista_por_puntos(punt);

				cout << "Tienen " << punt << " puntos: ";

				for (string alumno : lista) {
					cout << alumno << " ";
				}
				cout << "\n";
			}
			
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << "\n";
		}
		std::cin >> op;
	}
	std::cout << "---\n";
	return true;
}

	
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("9_4.in");
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