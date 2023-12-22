#include <iostream>
#include <sstream>
#include <iomanip>
#include "Zona.h"
#include "Terminal.h"
#include "Habitacao.h"
#include "Sensor.h"
#include "Regra.h"
#include "Propriedade.h"
#include "Processador.h"
#include "UI.h"
#include "Regra_Igual.h"
#include "Regra_entre.h"
#include "Regra_menor.h"
#include "Regra_maior.h"
#include "Regra_fora.h"
#include <memory>
using namespace term;

int main() {
    UI S;
    S.START();
    shared_ptr<Propriedade> propriedade = make_shared<Propriedade>(0 , 100);
    shared_ptr<Propriedade> propriedade2 = make_shared<Propriedade>(0);
    shared_ptr<Propriedade> propriedade3 = make_shared<Propriedade>();
    shared_ptr<Sensor> sensor = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade));
    shared_ptr<Sensor> sensor2 = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade2));
    shared_ptr<Sensor> sensor3 = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade3));
    propriedade->definirValor(50);
    propriedade2->definirValor(100);
    propriedade3->definirValor(-10);
    Processador p(1, "ligar");
    p.addRegra("igual", weak_ptr<Sensor>(sensor), {50});
    p.addRegra("maior", weak_ptr<Sensor>(sensor2), {100});
    p.addRegra("menor", weak_ptr<Sensor>(sensor3), {0});
    cout << p.testar() << endl;
    cout << p.getAsSting();

    return 0;
}
