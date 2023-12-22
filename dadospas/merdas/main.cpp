#include <iostream>
#include <sstream>
#include <iomanip>
#include "Zona.h"
#include "Terminal.h"
#include "Habitacao.h"
#include "Sensor.h"
#include "Regra.h"
#include "Regra_Igual.h"
#include "Propriedade.h"
#include "UI.h"
#include <memory>
using namespace term;

int main() {
    UI S;
    S.START();
    shared_ptr<Propriedade> propriedade = make_shared<Propriedade>(0 , 100);
    shared_ptr<Sensor> sensor = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade));
    propriedade->definirValor(50);
    propriedade->definirValor(-10);
    sensor->medir();
    cout << sensor->getAsString() << " teste1\n";
    unique_ptr<RegraBase> regra = make_unique<Regra_Igual>(sensor, 40);
    cout << regra->getEstado() << " teste2\n";
    return 0;
}
