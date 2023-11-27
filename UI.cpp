#include "UI.h"
#include "Terminal.h"
#include "Comando.h"

#include <sstream>
#include <fstream>

using namespace term;

/***************************************** Public *****************************************/

UI::UI(): t(Terminal::instance()), dimx(t.getNumCols()), dimy(t.getNumRows()), linhas(0), colunas(0), dadosW(nullptr), dimzonasy((dimy - 3) / 4), dimzonasx((dimy - 3) / 4 * 3){
    habitacao = nullptr;
    numdados = 0;
    ini_cor();
    cmdW = ini_cmd_UI();
    *cmdW << set_color(3) <<move_to(0,0) << "Comando -> ";
    dadosW = ini_dadosW_UI();
}

UI::~UI() {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            delete zonasW[i][j];
        }
    }

    for (int i = 0; i < linhas; ++i) {
        delete[] zonasW[i];
    }

    delete[] zonasW;
    delete dadosW;
    delete cmdW;
    delete habitacao;
}

void UI::START() {
    string cmd;
    int res = 0;

    while (res != 1) {
        cmd = getCmd();
        res = commandLine(cmd);
        verespaco();
    }
}

string UI::getCmd() {
    string cmd;
    (*cmdW) >> cmd;
    atulizar_cmdW();
    return cmd;
}

int UI::commandLine(string cmd) {
    istringstream iss(cmd);
    string s1, s2;
    iss >> s1 >> s2;
    int res;

    if (s1 == "exec") {
        res = exec(s2);
        if (res == 1) {return res;}
    }

    Comando c(cmd);

    switch (c.validaCmd()) {
        case 0:
            bool flag;
            if (c.validaStx()) {
                *dadosW << set_color(5) << move_to(0, numdados) << c.descricao();
                numdados += 6;
                if (c.SAIR()) {return 1;}

                vector <string> inputAux = c.getVectorInput();

                switch (c.getIndex()) {
                    case 2:

                        if (habitacao == nullptr) {
                            if (stoi(inputAux[1]) > 1 && stoi(inputAux[1]) < 5
                                && stoi(inputAux[2]) > 1 && stoi(inputAux[2]) < 5) {
                                linhas = stoi(inputAux[1]);
                                colunas = stoi(inputAux[2]);
                                habitacao = new Habitacao(linhas, colunas);
                                criarZonasWindow();
                                dadosW =ini_dadosW_UI();
                            } else {
                                *dadosW << set_color(5) << move_to(0, numdados++) << "Dimensoes invalidas";
                                break;
                            }
                        } else {
                            *dadosW << set_color(5) << move_to(0, numdados++) << "ja existe uma habitacao";
                        }
                        break;
                    case 4:
                        if(habitacao != nullptr) {
                            int linhasTemp, colunasTemp;
                            if (stoi(inputAux[1]) >= 0 && stoi(inputAux[1]) < linhas
                                && stoi(inputAux[2]) >= 0 && stoi(inputAux[2]) < colunas) {
                                linhasTemp = stoi(inputAux[1]);
                                colunasTemp = stoi(inputAux[2]);
                                try{
                                habitacao->add_Zona(linhasTemp, colunasTemp);
                                atualizar_zonas_UI(linhas, colunas);
                                }catch(const char* strcatch){
                                    *dadosW << set_color(5) << move_to(0, numdados++) << strcatch;
                                }
                            } else {
                                *dadosW << set_color(5) << move_to(0, numdados++) << "Dimensoes invalidas";
                                break;
                            }
                        } else {
                            *dadosW << set_color(3) << move_to(0, numdados++) << "nao existe zona";
                        }
                        break;
                    default:
                        break;
                }
            } else {
                *dadosW << set_color(19) << move_to(0, numdados++) << "Sintaxe invalida";
            }
            break;
        case 1:
            *dadosW << set_color(19) << move_to(0, numdados++) << "Comando nao encontrado";
            break;
        case 2:
            *dadosW << set_color(19) << move_to(0, numdados++) << "Argumentos a menos";
            break;
        case 3:
            *dadosW << set_color(19) << move_to(0, numdados++) << "Argumentos a mais";
            break;
        default:
            break;
    }
    // Comando c é destruido aqui
    return 0;
}

int UI::exec(string fileName)  {
    ifstream ifs(fileName);
    string line;
    int n = 0, res = 0;

    if(!ifs.is_open()) {return -1;}

    while (!ifs.eof()) {
        getline(ifs, line);
        res = commandLine(line);
        n++;
    }

    ifs.close();

    return res;
}

Window *UI::ini_cmd_UI() {
    return new Window(0, dimy - 3, dimx, 3);
}

Window *UI::ini_dadosW_UI() {
    delete dadosW;
    numdados = 0;
    return new Window(dimzonasx*colunas, 0, dimx - (dimzonasx*colunas), dimy-3);
}

void UI::ini_cor(){
    for(int i=1; i<20; i++) {
        t.init_color(i, i, 0);
    }
}

void UI::atulizar_cmdW() {
    cmdW->clear();
    *cmdW << set_color(3) << move_to(0,0) << "Comando -> ";
}

void UI::criarZonasWindow() {
    zonasW = new Window **[linhas];

    for (int i = 0; i < linhas; ++i) {
        zonasW[i] = new Window *[colunas];
    }

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            zonasW[i][j] = nullptr;
        }
    }
}

void UI::atualizar_zonas_UI(const int &linha, const int &coluna) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if(habitacao->get_idZona(i, j) != nullptr){

                if(zonasW[i][j] == nullptr)
                    zonasW[i][j] = new Window(j*dimzonasx, i*dimzonasy, dimzonasx, dimzonasy);

                (zonasW[i][j])->clear();
                *(zonasW[i][j]) << set_color(3) << move_to(0, 0) << habitacao->get_idZona(i, j)->getId();
                *(zonasW[i][j]) << set_color(3) << move_to(0, 1) << "num de Sensores: "<< habitacao->get_idZona(i, j)->numeroDeSensores();
                *(zonasW[i][j]) << set_color(3) << move_to(0, 2) << "num de Aparelhos: "<<habitacao->get_idZona(i, j)->numeroDeAparelhos();
                *(zonasW[i][j]) << set_color(3) << move_to(0, 3) << "num de Processadores: "<<habitacao->get_idZona(i, j)->numeroDeProcessadores();
            }
        }
    }
}

/***************************************** Private *****************************************/


bool UI::isIntegerString(string s) const {
    istringstream iss(s);
    int n;

    iss >> n;
    if (iss.fail()) {return false;}

    return true;
}

bool UI::isIntegerString(initializer_list<string> list) const {
    int n;

    for (const string & s : list) {
        istringstream iss(s);
        iss >> n;
        if (iss.fail()) {return false;}
    }

    return true;
}

void UI::verespaco(){
    if (numdados + 5 > dimy){
        dadosW->clear();
        numdados = 0;
    }
}