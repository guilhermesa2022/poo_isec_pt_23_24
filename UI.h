#ifndef CODIGOFONTE_UI_H
#define CODIGOFONTE_UI_H

#include "Terminal.h"
#include "Habitacao.h"

using namespace term;

class UI{
public:
    UI();
    ~UI();
    Window *ini_cmd_UI();
    Window *ini_dadosW_UI();
    int exec(string fileName);
    void START();
    string getCmd();
    int commandLine(string cmd);
    void ini_cor();
    void atulizar_cmdW();
    void criarZonasWindow();
    void atualizar_zonas_UI(const int &linha, const int &coluna);
    void verespaco();

private:
    [[nodiscard]]
    bool isIntegerString(string s)const;
    [[nodiscard]]
    bool isIntegerString(initializer_list<string> list)const;

    Terminal &t;
    Window *cmdW;
    Window *dadosW;
    Window ***zonasW;
    const int dimx;
    const int dimy;
    int linhas;
    int colunas;
    const int dimzonasx;
    const int dimzonasy;
    int numdados;
    Habitacao *habitacao;
};

#endif //CODIGOFONTE_UI_H