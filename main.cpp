#include <iostream>
#include <sstream>
#include <iomanip>
#include "Zona.h"
#include "Terminal.h"
#include "Habitacao.h"
#include "Sensor.h"
#include "Propriedade.h"
#include "Processador.h"
#include "UI.h"
#include "Regra_Igual.h"
#include "Regra_entre.h"
#include "Regra_menor.h"
#include "Regra_maior.h"
#include "Regra_fora.h"
#include <memory>
#include "Aquecedor.h"
using namespace term;

int main() {
    UI S;
    S.START();
    /*
    shared_ptr<Propriedade> propriedade = make_shared<Propriedade>(0 , 100);
    shared_ptr<Propriedade> propriedade2 = make_shared<Propriedade>(0);
    shared_ptr<Propriedade> propriedade3 = make_shared<Propriedade>();
    cout << "pros 1: " <<  propriedade->getValor() << endl;
    cout << "pros 2: " <<  propriedade2->getValor() << endl;
    shared_ptr<Aquecedor> a = make_shared<Aquecedor>(propriedade, propriedade2);
    a->mudaEstado("ligar");
    a->liga();
    cout << "pros 1: " <<  propriedade->getValor() << endl;
    cout << "pros 2: " <<  propriedade2->getValor() << endl;


    shared_ptr<Sensor> sensor = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade));
    shared_ptr<Sensor> sensor2 = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade2));
    shared_ptr<Sensor> sensor3 = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade3));


    Processador p(1, "ligar");
    Processador p2(1, "ligar");



    p2.addRegra("menor", weak_ptr<Sensor>(sensor), {50});
    cout <<  " teste de proc :::  "<<  p2.testar() << endl;
    p2.addAparelho(a);
    p2.alteraEstada();
    cout <<  "Teste altera o estado por um proc para um aparellho" << endl;
    cout << "pros 1: " <<  propriedade->getValor() << endl;
    cout << "pros 2: " <<  propriedade2->getValor() << endl;
    cout <<"dedededededed :       " << propriedade->getValor() << endl;
    p.addRegra("igual", weak_ptr<Sensor>(sensor), {50});
    p.addRegra("maior", weak_ptr<Sensor>(sensor2), {99});
    p.addRegra("entre", weak_ptr<Sensor>(sensor3), {-20, 0});
    cout << p.testar() << endl;
    cout << p.getAsSting();
*/
    shared_ptr<Propriedade> propriedade = make_shared<Propriedade>(0 , 100);
    shared_ptr<Propriedade> propriedade2 = make_shared<Propriedade>(0);
    Propriedade proteste(*propriedade2);
    proteste.aumentaValor(102);
    cout << "pros 1: " <<  propriedade2->getValor() << endl;
    cout << "pros 2 copia: " <<  proteste.getValor() << endl;
    shared_ptr<Propriedade> propriedade3 = make_shared<Propriedade>();
    shared_ptr<Sensor> sensor = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade));
    shared_ptr<Sensor> sensor2 = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade2));
    shared_ptr<Sensor> sensor3 = make_shared<Sensor>(weak_ptr<Propriedade>(propriedade3));
    shared_ptr<Aquecedor> *a = new shared_ptr<Aquecedor>(make_shared<Aquecedor>(propriedade, propriedade2));
    auto a2 = make_shared<Aquecedor>(propriedade, propriedade2);

    Processador *p = new Processador(1, "ligar");
    (*p).addRegra("menor", weak_ptr<Sensor>(sensor), {50});
    (*p).addRegra("igual", weak_ptr<Sensor>(sensor), {50});
    (*p).addAparelho(*a);
    Processador p1(*p);
    p1.addAparelho(a2);
    p1.removerRegra(1);
    delete a;
    cout << (*p).getAsSting() << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << p1.getAsSting() << endl;

    cout << "----------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------" << endl;
    return 0;
}
