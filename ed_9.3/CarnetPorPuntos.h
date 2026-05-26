// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Carnet por puntos


#ifndef CARNET
#define CARNET

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>


using namespace std;

const int PUNTOS_INICIALES = 15;

class CarnetPuntos {
private:
	// ATRIBUTOS
	unordered_map<string, int> conductores;
	vector<int> puntosConductores;

public:

	// MÉTODOS
	//CONSTRUCTORA PARA INICIALIZAR EL ARRAY (16 porque contamos el 0 tambien)
	CarnetPuntos() : puntosConductores(16) {};

	//Coste: O(1) o O(N) en funcion del contenido de la tabla hash. El promedio suele ser constante por el insert
	void nuevo(const string& dni) {
		if (conductores.count(dni) == 1) {
			throw std::domain_error("Conductor duplicado");
		}

		conductores.insert({dni,PUNTOS_INICIALES});
		puntosConductores[PUNTOS_INICIALES]++;
	}

	//Coste: O(1) La operacion erase es constante con unordered_map
	void quitar(const string& dni, int puntos) {
		if (conductores.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}

		puntosConductores[conductores[dni]]--;
		int puntosActualizados = conductores[dni] - puntos;

		if (puntosActualizados < 0) {
			puntosActualizados = 0;
		}

		conductores[dni] = puntosActualizados;
		puntosConductores[puntosActualizados]++;
	}


	//Coste: O(1) consultar con count en un unordered_map es constante 
	int consultar(const string& dni) const{
		if (conductores.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}
		return conductores.at(dni);
	}

	//Coste: O(1) consultar con count en un unordered_map es constante. Usamos un unordered_map con un tamaño maximo de 15, en el que guardamos los puntos como clave
	// y almacenamos la cantidad de conductores que tienen esos puntos como valor;

	int cuantos_con_puntos(int puntos) const {
		if (puntos < 0 || puntos > 15) {
			throw std::domain_error("Puntos no validos");
		}

		return puntosConductores[puntos];
	}

};
#endif
