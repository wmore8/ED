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
#include "queue_array.h"
#include "queue_linkedlist.h"
#include <queue>
using namespace std;

int main() {

	cout << "\n --- Cola implementada con array --- \n" << endl;
	
	QueueArray<string> c1;
	c1.push("Carmen");
	c1.push("Jose");
	c1.push("Conchi");

	cout << " Antes de cambiar el primer elemento es: " << c1.front() << endl;
	c1.front() = "Sonia";
	cout << " Ahora el primer elemento es: " << c1.front() << endl;

	cout << " Desencolando elementos: " ;
	while (!c1.empty()) {
		cout << c1.front() << "  ";
		c1.pop();
	}
	

	cout << "\n\n --- Cola implementada con lista enlazada --- \n" << endl;

	QueueLinkedList<string> c2;
	c2.push("Carmen");
	c2.push("Jose");
	c2.push("Conchi");

	cout << " Antes de cambiar el primer elemento es: " << c2.front() << endl;
	c2.front() = "Sonia";
	cout << " Ahora el primer elemento es: " << c2.front() << endl;

	cout << " Desencolando elementos: ";
	while (!c2.empty()) {
		cout << c2.front() << "  ";
		c2.pop();
	}

	cout << "\n\n --- Cola con la STL queue --- \n" << endl;

	queue<string> c3;
	c3.push("Carmen");
	c3.push("Jose");
	c3.push("Conchi");

	cout << " Antes de cambiar el primer elemento es: " << c3.front() << endl;
	c3.front() = "Sonia";
	cout << " Ahora el primer elemento es: " << c3.front() << endl;

	cout << " Desencolando elementos: ";
	while (!c3.empty()) {
		cout << c3.front() << "  ";
		c3.pop();
	}

	return 0;
}
