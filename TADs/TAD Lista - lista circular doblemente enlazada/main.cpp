/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez Martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


#include "list_linked_double.h"
#include <iostream>
#include <string>
using namespace std;
 
int main() {

	ListLinkedDouble<string> l1;

	l1.push_back("uno");
	l1.push_back("dos");

	cout << "\nContenido de l1: ";
	cout << l1 << endl;

	ListLinkedDouble<string> l2(l1);
	cout << "\nContenido de l2: ";
	cout << l2 << endl;

	return 0;
} 

