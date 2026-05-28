//
// Created by User on 26/05/2026.
//

#ifndef ECOMISION_VIVIDERORESTAURACION_H
#define ECOMISION_VIVIDERORESTAURACION_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "Zona.h"
#include "SemillaNativa.h"
#include "Explorador.h"
#include "LaboratorioAmbiental.h"
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;

class VivideroRestauracion : public Zona {
private:
    vector<SemillaNativa*> plantas;
public:
    VivideroRestauracion();
    vector<SemillaNativa*> getPlantas();
    void mostrarPlantas();
    void dejarSemilla(Explorador* e);
    void opciones(Explorador *e, ReservaNatural *r, Zona *z) override;
};
#endif //ECOMISION_VIVIDERORESTAURACION_H
