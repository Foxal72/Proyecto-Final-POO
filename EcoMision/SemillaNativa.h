#ifndef SEMILLANATIVA_H

#define SEMILLANATIVA_H
#include "ObjetoInteractuable.h"

class SemillaNativa: public ObjetoInteractuable{
    
private:
    string descripcionPlnata;
    bool semillaConocida;
public:
    
    SemillaNativa(string n, string d);
    
    void recolectar();
    
    void conocerSemilla();
    
    void interactuar(ReservaNatural* r, Explorador* e) override;

    void mostrarInformacion() override;

    bool getAnalizadoP();
};

#endif
