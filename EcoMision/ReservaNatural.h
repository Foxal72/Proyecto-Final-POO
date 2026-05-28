#ifndef ECOMISION_RESERVANATURAL_H
#define ECOMISION_RESERVANATURAL_H

#include <vector>
using std::vector;

class Zona;
class Explorador;
class LaboratorioAmbiental;

class ReservaNatural {
private:
    vector<vector<Zona*>> zonas;
public:
    ReservaNatural();
    void alrededores(Explorador* e);
    void zonasCambio(Explorador* e, ReservaNatural* r);
    void analizarTodo();
    void zonaActual(Explorador* e, ReservaNatural* r);
    vector<vector<Zona*>> getZonas();
    void actualizarLab(LaboratorioAmbiental* l);
};

#endif