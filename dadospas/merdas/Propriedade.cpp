#include "Propriedade.h"

#include <optional>
#include <map>

/***************************************** Public *****************************************/


int Propriedade::baseId = 0;

Propriedade::Propriedade(optional<double> min, optional<double> max) : minimo(min), maximo(max), valor(0), id(baseId++) {
    if (minimo.has_value() && maximo.has_value())
        if (minimo > maximo){
            tie(minimo, maximo) = make_tuple(maximo, minimo);
        }
}

//Propriedade::Propriedade(optional<double> max, bool escolha): minimo({}), maximo(max), valor(0){}

void Propriedade::definirValor(double valorA) {
    if (minimo.has_value() && maximo.has_value()) {
        if (valor + valorA < minimo.value()) {
            valor = minimo.value();
        } else if (valor + valorA > maximo.value()) {
            valor = maximo.value();
        } else {
            valor += valorA;
        }
    } else if (minimo.has_value()) {
        if (valor + valorA < minimo.value()) {
            valor = minimo.value();
        } else {
            valor += valorA;
        }
    } else if (maximo.has_value()) {
        if (valor + valorA > maximo.value()) {
            valor = maximo.value();
        } else {
            valor += valorA;
        }
    } else {
        valor += valorA;
    }
}

[[nodiscard]]
double Propriedade::getValor() const {
    return valor;
}

[[nodiscard]]
bool Propriedade::has_max() const {
    return minimo.has_value();
}

[[nodiscard]]
bool Propriedade::has_min() const {
    return maximo.has_value();
}

[[nodiscard]]
double Propriedade::getmax() const {
    if (maximo.has_value())
        return maximo.value();
    else
        throw "erro nao ha maximo";
}

[[nodiscard]]
double Propriedade::getmin() const {
    if (minimo.has_value())
        return minimo.value();
    else
        throw "erro nao ha minimo";
}

[[nodiscard]]
int Propriedade::getid() const {
    return id;
}


/***************************************** Private *****************************************/
