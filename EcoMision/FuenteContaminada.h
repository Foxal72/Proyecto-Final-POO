#ifndef FUENTECONTAMINADA_H
#define FUENTECONTAMINADA_H

#include "Explorador.h"
#include "ObjetoInteractuable.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class FuenteContaminada : public ObjetoInteractuable {
private:
    bool estaLimpia;
public:
    FuenteContaminada();
    void limpiar(Explorador* e);
    void interactuar(ReservaNatural* r, Explorador* e) override; // CORREGIDO: Se quitó el doble punto y coma
};

#endif
