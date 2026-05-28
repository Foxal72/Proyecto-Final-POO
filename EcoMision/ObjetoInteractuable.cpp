#include "ObjetoInteractuable.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
ObjetoInteractuable::ObjetoInteractuable() {
    nombre = "";
    clase = "";
    peso = 0;
    desgaste = 0;
    recogible = false;
}
//ObjetoInteractuable::~ObjetoInteractuable() {}
void ObjetoInteractuable::interactuar(ReservaNatural* r, Explorador* e) {
    cout << "este objeto esiste" << endl;
}
string ObjetoInteractuable::getNombre() {
    return nombre;
}

bool ObjetoInteractuable::getRecogible() {
    return recogible;
}
string ObjetoInteractuable::getClase() {
    return clase;
}
int ObjetoInteractuable::getPeso() {
    return peso;
}
int ObjetoInteractuable::getDesgaste() {
    return desgaste;
}

void ObjetoInteractuable::mostrarInformacion() {
    cout << "Nombre: " << nombre << endl;
    //cout << "Clase: " << clase << endl;
    cout << "Peso: " << peso << endl;
}
