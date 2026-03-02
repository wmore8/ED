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
#include <string>
#include "stack_array.h"
#include "stack_linkedlist.h"
#include "pila.h"
using namespace std;

int main() {

	cout << "\n --- Pila implementada con array --- \n" << endl;

	StackArray<string> s1;
	s1.push("Carmen");
	s1.push("Jose");
	s1.push("Conchi");

	cout << " Antes de cambiar la cima: " << s1.top() << endl;
	s1.top() = "Sonia";
	cout << " Ahora la cima es: " << s1.top() << endl;

	cout << " Desapilando elementos: " ;
	while (!s1.empty()) {
		cout << s1.top() << "  ";
		s1.pop();
	}

	cout << "\n\n --- Pila implementada con lista enlazada --- \n" << endl;

	StackLinkedList<string> s2;
	s2.push("Carmen");
	s2.push("Jose");
	s2.push("Conchi");
	
	cout << " Antes de cambiar la cima: " << s2.top() << endl;
	s2.top() = "Sonia";
	cout << " Ahora la cima es: " << s2.top() << endl;

	cout << " Desapilando elementos: ";
	while (!s2.empty()) {
		cout << s2.top() << "  ";
		s2.pop();
	}

	return 0;
}
