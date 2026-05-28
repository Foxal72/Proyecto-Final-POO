//
// Created by User on 24/05/2026.
//

#ifndef ECOMISION_CENTRORECUPERACIONANIMAL_H
#define ECOMISION_CENTRORECUPERACIONANIMAL_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "Explorador.h"
#include "Zona.h"
#include "AnimalHerido.h"
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;
class CentroRecuperacionAnimal : public Zona {
private:
    vector<AnimalHerido*> animales;
public:
    CentroRecuperacionAnimal();
    vector<AnimalHerido*> getAnimales();
    void dejarAnimal(Explorador* e);
    void mostrarAnimales();
    void curarAnimal(LaboratorioAmbiental* l);
    void descansarConLosAnimales(Explorador* e);
    void opciones(Explorador *e, ReservaNatural *r, Zona *z) override;
};
#endif //ECOMISION_CENTRORECUPERACIONANIMAL_H
