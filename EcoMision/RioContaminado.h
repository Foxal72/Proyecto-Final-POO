#ifndef RIOCONTAMINADO_H

#define RIOCONTAMINADO_H
#include "Zona.h"
#include "Explorador.h"

class RioContaminado: public Zona{
private:
    bool estaLimpio;
public:
    RioContaminado();
    void limpiar(Explorador* e);
    void opciones(Explorador* e, ReservaNatural* r, Zona* z) override;
};
#endif
