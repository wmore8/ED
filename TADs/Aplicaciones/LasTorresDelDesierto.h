

// Las torres del desierto

#ifndef TORRES
#define TORRES


#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <map> 
#include <stdexcept>


enum Direccion {Norte, Sur, Este, Oeste};

Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}


class Desierto {

	// ATRIBUTOS

public:

	// MÉTODOS



};


#endif