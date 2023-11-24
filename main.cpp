#include <iostream>
#include <sstream>
#include <iomanip>
#include "Zona.h"
#include "Terminal.h"
#include "Habitacao.h"
#include "UI.h"

using namespace term;

int main() {
    UI S;
    S.START();
    /*
    Habitacao h(4,4);
    Habitacao* h2 = new Habitacao(2,2);
    delete h2;
    cout << "===================================================== teste1 " << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            try{h.add_Zona(i,j);}catch(const char* strcatch) {cout << strcatch << endl;}
        }
    }
    cout << "===================================================== teste2" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            try{h.add_Zona(i,j); }catch(const char* strcatch) {cout << strcatch << endl;}
        }
    }
    cout << "=====================================================teste 3" << endl;

    for (int i = 0; i < 100; ++i) {
            try{h.removerZona(i); }catch(const char* strcatch) {cout << strcatch << endl;}
    }


    try{h.removerZona(2); }catch(const char* strcatch) {cout << strcatch << endl;}
    cout << "===================================================== teste 4" << endl;
            cout << h.zlista() << endl;
    cout << "===================================================== testezcomp " << endl;

    cout << h.zcomp(1) << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << h.zcomp(2) << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << h.zcomp(100) << endl;

    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;
    cout << "===================================================== testezcomp " << endl;








    cout << "=====================================================" << endl;
    cout << "=====================================================" << endl;
    cout << "=====================================================" << endl;
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
    z1.eleminarProcessador(0);
    //cout << z1.listaPropriedades();

    //z1.setPropriedades("Fumo", -20);

    cout <<" eeeeeeeeeeee " << z1.getAsString() << endl;


    Habitacao He(2, 3);


    */
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
