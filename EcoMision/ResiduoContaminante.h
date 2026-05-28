//
// Created by User on 22/05/2026.
//

#ifndef ECOMISION_RESIDUOCONTAMINANTE_H
#define ECOMISION_RESIDUOCONTAMINANTE_H
#include "ObjetoInteractuable.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class ResiduoContaminante : public ObjetoInteractuable {

public:
    ResiduoContaminante();
    ~ResiduoContaminante();
    void interactuar(ReservaNatural *r, Explorador* e) override;

};
#endif //ECOMISION_RESIDUOCONTAMINANTE_H
