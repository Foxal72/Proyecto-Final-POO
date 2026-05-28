//
// Created by User on 22/05/2026.
//

#ifndef ECOMISION_PLANTAMEDICINAL_H
#define ECOMISION_PLANTAMEDICINAL_H
#include "ObjetoInteractuable.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class PlantaMedicinal : public ObjetoInteractuable {
private:

public:
    PlantaMedicinal();
    ~PlantaMedicinal();
    void interactuar(ReservaNatural* r, Explorador* e) override;

};
#endif //ECOMISION_PLANTAMEDICINAL_H
