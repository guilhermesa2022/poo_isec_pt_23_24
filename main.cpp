#include <iostream>
#include <sstream>
#include <iomanip>
#include "Zona.h"
#include "Terminal.h"

using namespace term;

void print_size(Terminal& t, int* dim) {
    dim[0] = t.getNumCols();
    dim[1] = t.getNumRows();
    std::ostringstream o;
    o << "tamanho do terminal: " << std::setw(7) << t.getNumCols() << "x" << t.getNumRows();
    std::string str = o.str();
    t.clear();
    t << set_color(0) << move_to(t.getNumCols()-str.length(), t.getNumRows()-1) << str;
}


int main() {
    int ee;
    int dim[2];

    cout << "teste = 1 " << "simular = 2 ";
    cin >> ee ;

    if(ee == 2){
        Terminal &t = Terminal::instance();
        print_size(t, dim);

        for(int i=1; i<20; i++) {
            t.init_color(i, i, 0);
        }


        string lixo;
        vector<Window*> wzona;
        Window Wcmd =  Window(0, dim[1] - 3, dim[0], 3);
        Wcmd << set_color(3) << "comando: ";
        string numeroDeZOnas = "quantas zonas 2x2 ate 4x4";
        t << move_to(dim[0] / 2 - (numeroDeZOnas.size()/2), dim[1] / 2 - 4) << numeroDeZOnas;
        Wcmd >> numeroDeZOnas;
        int p = (int)numeroDeZOnas[0] - 48;
        int f = (int)numeroDeZOnas[2] - 48;

        Wcmd << set_color(3) << "comando: ";
        for(int i = 0; i < p; i++)
            for(int j = 0; j < f; j++){
                wzona.push_back(new Window(15 * j, i * 7 , 15, 7));

            }
        Window wdados =  Window(f*15, 0, dim[0] - f*15, dim[1] - 2);
        Wcmd.clear();
        Wcmd >> numeroDeZOnas;






    }else{
        Zona z2, z1("quarto");
        z1.setPropriedades("Temperatura", -1900);
        z1.setPropriedades("Radiacao", 11100);
        z1.setPropriedades("Humidade", 11100);
        z1.setPropriedades("Fumo", 10);
        z1.addSensor("Temperatura");
        z1.addSensor("Fumo");
        z1.addSensor("Radiacao");
        z1.addProcessador();
        z1.addProcessador();
        z1.addRegrasPorc(0, 0, "maior", -300);
        z1.addRegrasPorc(0, 1, "menor", 2);

        cout << z1.getAsString() << endl;

        cout << z1.listaPropriedades();

        z1.setPropriedades("Fumo", -20);

        cout << z1.getAsString() << endl;
        std::cout << "Hello, World!" << std::endl;
    }

    return 0;
}