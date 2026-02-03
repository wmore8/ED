/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez Martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


#include "list_linked_single.h"
#include <iostream>



int main() {

	// ------ Constructora por defecto ------
	// ListArray(int initial_capacity = DEFAULT_CAPACITY)

	ListLinkedSingle l;

	l.push_back("uno");
	l.push_back("dos");

	std::cout << "\nContenido inicial de l: ";
	l.display();
	std::cout << l;



	return 0;
} 	// Fin de main aquí se llama a la DESTRUCTORA de l, l1 y l2

