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


int main() {
  ListArray l;
  l.push_back("Carmen");
  l.push_back("Jose");
  l.push_back("Conchi");

  l.display();

  // 1. Llamada a front() sin const  

  std::cout << std::endl <<
      "Para poder modificar el primer elemento se llama al front() que no tiene const" 
      << std::endl;

  l.front() = "UNO";   // se puede modificar
  
  l.display();
  
  // 2. Llamada a front() con const
  
  // Creamos una lista const
  const ListArray& lista_const = l;

  // Error al asignar
  // lista_const.front() = "DOS";   

  std::cout << std::endl <<
      "Al ser una lista no modificable, llama al front que tiene const: "
      << lista_const.front();

  return 0;
}

