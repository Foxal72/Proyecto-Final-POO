#ifndef OBSTACULO_H

#define OBSTACULO_H
#include "ObjetoInteractuable.h"
#include "Explorador.h"

class Obstaculo: public ObjetoInteractuable{
    
private:

public:
    
    Obstaculo(string n, int d);

    void interactuar(ReservaNatural* r, Explorador* e) override;
};

#endif
