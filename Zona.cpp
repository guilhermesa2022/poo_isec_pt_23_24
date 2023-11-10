//
// Created by 35193 on 09/11/2023.
//

#include "Zona.h"
#include <sstream>
#include <new>
#include <utility>

// inicialiar as var static;;
int Zona::baseId = 0;

// criar
Zona::Zona(string  nomeDaZona): tilulo(std::move(nomeDaZona)), id(baseId++){
    iniciarPropriedadesDefault();
}

// info
string Zona::getAsString() const {
    ////////////////////////////// colocar os nome e id da zona;
    ////////////////////////////// inumerar os propriedades;
    ostringstream dados;
    dados << "Id da zona " << tilulo << " : " << id << endl;
    int num = 0;
    for(const auto& prop : propriedades){
        dados << "propriedades : " << num++ << "=> " << prop.first << " / " << prop.second->getValor()<<endl;
    }

    return dados.str();
}
int Zona::getId() const {
    return id;
}
int Zona::getNumeroPropriedades() const {
    return (int)propriedades.size();
}

//private
void Zona::iniciarPropriedadesDefault(){
    int min[] = {-273, 0};
    int max[] = {100};

    propriedades["Temperatura"] = new Propriedade(min[0]);
    propriedades["Luz"] = new Propriedade(min[1]);
    propriedades["Radiacao"] = new Propriedade(min[1]);
    propriedades["Vibracao"] = new Propriedade(min[1]);
    propriedades["Humidade"] = new Propriedade(min[1], max[0]);
    propriedades["Fumo"] = new Propriedade(min[1], max[0]);
    propriedades["Som"] = new Propriedade(min[1]);
}

//propriedade
bool Zona::addPropriedade(const string& nomeDaPropriedades, optional<double> min){
    if(propriedades.find(nomeDaPropriedades) != propriedades.end()){
        return false;
    }
    propriedades[nomeDaPropriedades] = new Propriedade(min);
    return true;
}
bool Zona::addPropriedade(const string& nomeDaPropriedades, optional<double> min, optional<double> max){
    if(propriedades.find(nomeDaPropriedades) != propriedades.end()){
        return false;
    }
    propriedades[nomeDaPropriedades] = new Propriedade(min, max);
    return true;
}
bool Zona::addPropriedade(const string& nomeDaPropriedades){
    if(propriedades.find(nomeDaPropriedades) != propriedades.end()){
        return false;
    }
    propriedades[nomeDaPropriedades] = new Propriedade();
    return true;
}
bool Zona::setPropriedades(const string& nomeDaPropriedades, int valor) {
    if(propriedades.find(nomeDaPropriedades) == propriedades.end()){
        return false;
    }
    propriedades[nomeDaPropriedades]->definirValor(valor);
    return true;
}

// Sensor
bool Zona::addSensor(const string &propsNome) {
    if(propriedades.find(propsNome) == propriedades.end()){
        return false;
    }
    sensores.push_back(new Sensor(propriedades[propsNome]));
    return true;
}

