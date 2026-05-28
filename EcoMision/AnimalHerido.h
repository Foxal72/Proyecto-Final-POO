//
// Created by User on 22/05/2026.
//

#ifndef ECOMISION_ANIMALHERIDO_H
#define ECOMISION_ANIMALHERIDO_H
#include "ObjetoInteractuable.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class AnimalHerido : public ObjetoInteractuable {
private:
    string descripcionAnimal;
    bool estaCurado;
    bool animalConocido;
public:
    AnimalHerido(string n, int p, string d);

    void interactuar(ReservaNatural* r, Explorador* e) override;
    void mostrarInformacion() override;
    void curar();
    void conocerAnimal();
    bool getCurado();
    bool getAnalizado();
};
#endif //ECOMISION_ANIMALHERIDO_H
