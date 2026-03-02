/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez Martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


#include <iostream>
#include <list>
#include <deque>
using namespace std;



void ej_list() {

	list<int> l = { 10, 20, 30, 40 };

	cout << endl;

	// Intentar saltar posiciones
	auto it = l.begin();
	// cout << *(it + 3);    ERROR (no es random access)

	advance(it, 3);   // O(3)
	cout << *it << endl;  // Muestra 40
}


void ej_deque() {

	deque<int> d = { 10, 20, 30, 40 };

	cout << endl;

	// Acceso directo con iterador
	auto it = d.begin();
	cout << *(it + 3) << endl;   //  O(1)
}


int main() {	
	cout << "Ejemplo con list: \n";
	ej_list();
	cout << "\nEjemplo con deque: \n";
	ej_deque();
	return 0;
}

