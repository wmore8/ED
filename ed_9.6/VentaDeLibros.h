// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Venta de libros por internet

#ifndef LIBROS
#define LIBROS

#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct VentasLibro {
	string nombre;
	int total;
	int antiguedad;
};

//modificamos el operador menor para que en el set de ventas aparezcan ordenadas por numero de ventas en orden descendente y en caso de empate por anitguedad (descendente)
const bool operator< (const VentasLibro& a, const VentasLibro& b) {
	return (a.total > b.total) || (b.total == a.total && a.antiguedad > b.antiguedad);
}

class Libros{

	unordered_map<string, int> estanteria;
	unordered_map<string, VentasLibro> ventas_info;
	set<VentasLibro> ventas;
	int id = 0;

public:
	
	//Coste: O(1) los accesos a las funciones de unordered_map son constantes. 
	void nuevoLibro(int n, const string& x) {
		if (estanteria.count(x) == 1) {
			estanteria[x] += n;
		}
		else {
			estanteria.insert({ x,n });
		}
	}

	//Coste: O(log N) siendo N el numero de ventas. Hacemos erase e insert en el set ordenado del top 10 de ventas. El resto de operaciones son constantes O(1)
	void comprar(const string& x) {
		if (estanteria.count(x) == 0) {
			throw std::invalid_argument("Libro no existente");
		}
		if (estanteria.count(x) == 1 && estanteria.at(x) == 0) {
			throw std::out_of_range("No hay ejemplares");
		}

		estanteria[x]--;

		id++; //aumentamos en 1 el id de antiguedad
		
		if (ventas_info.count(x) == 1) {
			VentasLibro vieja = ventas_info[x];
			ventas.erase(vieja); //borramos la venta antigua para mantener el TOP 10 actualizado
			ventas_info[x].antiguedad = id;
			ventas_info[x].total += 1;
			
			VentasLibro nueva = ventas_info[x];
			ventas.insert(nueva);
		}else{
			VentasLibro venta = { x,1,id };

			ventas_info.insert({ x,venta });
			ventas.insert(venta);
		}

	}
	//Coste: O(1) constante, ya que acceder a metodo count es constante en unordered_map
	const bool estaLibro(const string& x) {
		return estanteria.count(x) == 1;
	}
	
	//Coste : O(log N) eliminamos el libro del unordered map de libros,y del set de ventas
	void elimLibro(const string& x) {
		if (estanteria.count(x) == 1){
			estanteria.erase(x);
		}

		if (ventas_info.count(x) == 1) {
			VentasLibro aux = ventas_info[x];
			ventas_info.erase(x);
			ventas.erase(aux);
		}
	}

	//Coste : O(1) comprobamos que el libro exista con count y luego devolvemos el numero de libros almacenados en la clace. Como es un unordered_map, el coste es constante
	int numEjemplares(const string& x) const{
		if (estanteria.count(x) == 0) {
			throw std::invalid_argument("Libro no existente");
		}

		return estanteria.at(x);
	}
	
	//Coste: O(1) constante, ya que sabemos cuantas vueltas vamos a aiterar como mucho. Al usar un vector, los push_bak son cosntantes O(1)
	vector<string> top10() {
		vector<string> topLibros;

		auto it = ventas.begin();

		for (int i = 0; i < 10 && it != ventas.end(); i++) {
			topLibros.push_back(it->nombre);
			it++;
		}

		return topLibros;
	}
	

};




#endif
