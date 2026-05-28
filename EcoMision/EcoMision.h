//
// Created by User on 27/05/2026.
//

#ifndef ECOMISION_ECOMISION_H
#define ECOMISION_ECOMISION_H
#include "ReservaNatural.h"
#include "Explorador.h"

class EcoMision {
private:
   Explorador* e;
   ReservaNatural* r;
public:
   EcoMision();
   ReservaNatural* getReserva();
   Explorador* getExplorador();

};
#endif //ECOMISION_ECOMISION_H
