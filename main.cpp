#include <iostream>
#include "Zona.h"

int main() {
    Zona z2, z1("quarto");
    z1.setPropriedades("Temperatura", -1900);
    z1.setPropriedades("Radiacao", 11100);
    z1.setPropriedades("Humidade", 11100);
    z1.setPropriedades("Fumo", -11100);
    cout << z1.getAsString() << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
