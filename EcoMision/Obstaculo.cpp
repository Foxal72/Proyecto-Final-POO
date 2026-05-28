#include "Obstaculo.h"

#include <iostream>
#include "CentroRecuperacionAnimal.h"
#include "Zona.h"
#include "AnimalHerido.h"
#include "Explorador.h"
#include "LaboratorioAmbiental.h"

Obstaculo:: Obstaculo(string n, int d): ObjetoInteractuable(){
    nombre = n;
    desgaste = d;
    clase = "obstaculo";
    recogible = false;
    
    peso = 0;
}


void Obstaculo:: interactuar(ReservaNatural* r, Explorador* e){
    cout << "empiezas a quitar el obstaculo..." << endl;
    cout << "Lograste quitar el obstaculo!!!" << endl;
    e->perderEnergia(desgaste);

}
