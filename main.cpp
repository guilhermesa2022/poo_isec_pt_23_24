#include <iostream>
#include <sstream>
#include <iomanip>
#include "Zona.h"
#include "Terminal.h"
#include "Habitacao.h"
#include "Interface.h"

using namespace term;

int main() {
    Zona z2, z1("quarto");
    z1.setPropriedades("Temperatura", -1900);
    z1.setPropriedades("Radiacao", 11100);
    z1.setPropriedades("Humidade", 11100);
    z1.setPropriedades("Fumo", 10);
    z1.addSensor("Temperatura");
    z1.addSensor("Fumo");
    z1.addSensor("Radiacao");
    z1.addSensor("Radiacao");
    z1.addSensor("Radiacao");
    z1.addProcessador();
    z1.addProcessador();
    z1.addRegrasPorc(0, 0, "maior", -300);
    z1.addRegrasPorc(0, 1, "menor", 2);
    z1.addRegrasPorc(0, 1, "igual", 2);

    cout <<" eeeeeeeeeeee " << z1.getAsString() << endl;

    z1.eleminarSensor(0);
    //cout << z1.listaPropriedades();

    //z1.setPropriedades("Fumo", -20);

    cout <<" eeeeeeeeeeee " << z1.getAsString() << endl;

    cout << "=====================================================" << endl;

    Habitacao He(2, 3);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
