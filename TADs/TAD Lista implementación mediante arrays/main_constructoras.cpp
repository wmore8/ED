/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez Martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


#include "list_array.h"
#include <iostream>

void f1(ListArray l) {

	// Modificamos la COPIA
	l.push_back("A");
	l.push_back("B");

	std::cout << "   Contenido de l (copia) dentro de f1: ";
	l.display();
	std::cout << std::endl;

} //  aquí se llama a la DESTRUCTORA de l

ListArray f2() {

	ListArray aux;   // constructora por defecto
	aux.push_back("X");
	aux.push_back("Y");
	aux.push_back("Z");

	std::cout << "   Contenido de aux dentro de f2: ";
	aux.display();
	std::cout << std::endl;

	return aux;      // retorno por valor
}

int main() {

	// ------ Constructora por defecto ------
	// ListArray(int initial_capacity = DEFAULT_CAPACITY)

	ListArray l;

	l.push_back("uno");
	l.push_back("dos");

	std::cout << "\nContenido inicial de l: ";
	l.display();
	std::cout << l;

	// ------ Constructora de copia ------

	// Constructora de copia, caso 1

	ListArray l1(l);
	std::cout << "\nContenido inicial de l1 copia de l: ";
	l.display();

	// Constructora de copia, caso 2
	// Inicialización a partir de otro objeto

	ListArray l2 = l;
	std::cout << "\nContenido inicial de l2 copia de l: ";
	l.display();


	// Constructora de copia, caso 3

	// ---- Paso por valor ----
	std::cout << "\nLlamada a f1" << std::endl;
	f1(l);

	std::cout << "Contenido de l tras f1(l): ";
	l.display();

	// Constructora de copia, caso 4

	// ---- Retorno por valor ----
	std::cout << "\nLlamada a f2" << std::endl;
	ListArray l3 = f2();

	std::cout << "Contenido de l3 (devuelta): ";
	l3.display();

	return 0;
} 	// Fin de main aquí se llama a la DESTRUCTORA de l, l1 y l2

