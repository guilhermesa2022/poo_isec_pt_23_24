//
// Created by 35193 on 09/11/2023.
//

#include "Sensor.h"
int Sensor::baseId = 0;

Sensor::Sensor(Propriedade* propriedade): propriedade(propriedade), id(baseId++){}

int Sensor::getid() const {
    return id;
}

double Sensor::getvalor(){
    medir();
    return ultimaMedicao;
}

bool Sensor::medir() {
    ultimaMedicao = propriedade->getValor();
    return true;
}