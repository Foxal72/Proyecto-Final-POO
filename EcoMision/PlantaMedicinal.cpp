//
// Created by User on 22/05/2026.
//
#include "PlantaMedicinal.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

PlantaMedicinal::PlantaMedicinal() {
    nombre = "Planta Medicinal";
    clase = "Planta Medicinal";
    recogible = true;
    peso = 2;
    desgaste = 0;
}
PlantaMedicinal::~PlantaMedicinal() {
}
void PlantaMedicinal::interactuar(ReservaNatural* r, Explorador* e) {
    cout << "has recogido la planta" << endl;
}
