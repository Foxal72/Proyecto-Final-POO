//
// Created by User on 25/05/2026.
//

#ifndef ECOMISION_LABORATORIOAMBIENTAL_H
#define ECOMISION_LABORATORIOAMBIENTAL_H
#include <iostream>
#include <vector>
#include <string>
#include "AnimalHerido.h"
#include "SemillaNativa.h"
#include "PlantaMedicinal.h"
#include "Zona.h"
#include "ReservaNatural.h"
#include "Explorador.h"
using std::vector;
using std::cout;
using std::endl;
using std::string;
class LaboratorioAmbiental : public Zona {
private:
    int curas;
public:
    LaboratorioAmbiental();
    void crearCuras(Explorador* e);
    void analizarAnimal(Explorador* e);
    void analizarSemilla(Explorador* e);
    void resiclarBasura(Explorador* e);
    void descansarLaboratorio(Explorador* e);
    int getCuras();
    void restarCura();
    void opciones(Explorador* e, ReservaNatural* r, Zona* z) override;
};
#endif //ECOMISION_LABORATORIOAMBIENTAL_H
