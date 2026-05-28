#ifndef SENDEROMONTANIA_H

#define SENDEROMONTANIA_H

#include "Zona.h"
#include "ReservaNatural.h"
#include "Explorador.h"

class SenderoMontania: public Zona{
    bool analizasteTodo;
public:
    SenderoMontania();
    void analizarPaisaje(ReservaNatural* r, Explorador* e);
    void opciones(Explorador* e, ReservaNatural* r, Zona* z) override;
};

#endif
