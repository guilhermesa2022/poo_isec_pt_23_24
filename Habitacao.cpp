//
// Created by 35193 on 21/11/2023.
//

#include "Habitacao.h"
#include <iostream>
Habitacao::Habitacao(int linhas, int colunas) {
    zonas = new Zona **[linhas];

    for(int i = 0; i < linhas; i++){
        zonas[i] =new Zona *[colunas];
    }

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            zonas[i][j] = nullptr;
        }
    }

}

int Habitacao::getInfo(int linha, int coluna) const {
    return zonas[linha][coluna]->getId();
}

void Habitacao::addZona(int linha, int coluna) {
    zonas[linha][coluna] = new Zona;
}