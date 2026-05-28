//
// Created by User on 22/05/2026.
//
#include "ResiduoContaminante.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

ResiduoContaminante::ResiduoContaminante() {
    nombre = "Residuo Contaminante";
    clase = "Residuo Contaminante";
    peso = 4;
    desgaste = 0;
    recogible = true;
}

ResiduoContaminante::~ResiduoContaminante() {
}

void ResiduoContaminante::interactuar(ReservaNatural *r, Explorador* e) {
    cout << "Recojes la basura" << endl;
}
