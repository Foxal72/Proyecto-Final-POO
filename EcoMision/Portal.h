#ifndef PORTAL_H

#define PORTAL_H

#include <string>

using std::string;
#include "ObjetoInteractuable.h"
#include "ReservaNatural.h"

class Portal: public ObjetoInteractuable{
private:
    int destinoX;
    int destinoY;
    
public:
    Portal(int x, int y);
    void atravesar(ReservaNatural *r, Explorador* e);
    void interactuar(ReservaNatural *r, Explorador* e) override;
};


#endif
