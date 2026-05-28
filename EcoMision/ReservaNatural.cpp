//
// Created by User on 26/05/2026.
//
#include "ReservaNatural.h"
#include "Portal.h"
#include "FuenteContaminada.h"
#include "BosqueHumedo.h"
#include "CentroRecuperacionAnimal.h"
#include "LaboratorioAmbiental.h"
#include "Obstaculo.h"
#include "ResiduoContaminante.h"
#include "RioContaminado.h"
#include "SenderoMontania.h"
#include "VivideroRestauracion.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

ReservaNatural::ReservaNatural() {
    zonas.resize(5, vector<Zona*>(5, nullptr));

    zonas.at(2).at(2) = new LaboratorioAmbiental();
    zonas.at(2).at(1) = new CentroRecuperacionAnimal();
    zonas.at(2).at(3) = new VivideroRestauracion();
    zonas.at(1).at(2) = new BosqueHumedo();
    zonas.at(3).at(2) = new BosqueHumedo();
    zonas.at(0).at(4) = new SenderoMontania();
    zonas.at(3).at(3) = new BosqueHumedo();
    zonas.at(4).at(0) = new BosqueHumedo();
    zonas.at(4).at(1) = new BosqueHumedo();
    zonas.at(1).at(0) = new BosqueHumedo();
    zonas.at(1).at(1) = new BosqueHumedo();
    zonas.at(2).at(0) = new RioContaminado();
    zonas.at(3).at(1) = new RioContaminado();
    zonas.at(4).at(2) = new RioContaminado();

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (zonas.at(i).at(j) == nullptr) {
                zonas.at(i).at(j) = new Zona();
            }
        }
    }

    // Hora de llenarlas de objetos
    zonas.at(1).at(0)->ponerObjetos(new Obstaculo("Barrera", 20));
    zonas.at(1).at(0)->ponerObjetos(new Portal(0,4));
    zonas.at(0).at(4)->ponerObjetos(new Portal(1,0));
    zonas.at(1).at(2)->ponerObjetos(new AnimalHerido("Perro Rigoverto", 2, "Es sin duda un perro"));
    zonas.at(1).at(2)->ponerObjetos(new PlantaMedicinal());
    zonas.at(1).at(2)->ponerObjetos(new ResiduoContaminante());
    zonas.at(1).at(1)->ponerObjetos(new PlantaMedicinal());
    zonas.at(1).at(1)->ponerObjetos(new FuenteContaminada());
    zonas.at(2).at(0)->ponerObjetos(new Obstaculo("piedra", 2));
    zonas.at(2).at(0)->ponerObjetos(new SemillaNativa("Gira Sol Girador", "Gira y gira..."));
    zonas.at(2).at(0)->ponerObjetos(new ResiduoContaminante());
    zonas.at(4).at(2)->ponerObjetos(new AnimalHerido("Slenderman",6,"Dicen las malas lenguas que esconde niños"));
    zonas.at(4).at(2)->ponerObjetos(new SemillaNativa("Flor Wither","Si la tocas te last.. auch"));
    zonas.at(4).at(2)->ponerObjetos(new ResiduoContaminante());
    zonas.at(4).at(0)->ponerObjetos(new AnimalHerido("Tartigrado", 1, "Sabias que los tartigrados te estan caminando por la cara?"));
    zonas.at(4).at(0)->ponerObjetos(new ResiduoContaminante());
    zonas.at(4).at(1)->ponerObjetos(new PlantaMedicinal());
    zonas.at(3).at(2)->ponerObjetos(new SemillaNativa("Cacareta","No se que hace pero no me genera confianza"));
    zonas.at(3).at(2)->ponerObjetos(new PlantaMedicinal());
    zonas.at(3).at(2)->ponerObjetos(new FuenteContaminada());
    zonas.at(3).at(3)->ponerObjetos(new Obstaculo("Arbol Caido",6));
    zonas.at(3).at(3)->ponerObjetos(new AnimalHerido("Ryon", 5, "Solo se estaba relajando en el bosque"));
}

void ReservaNatural::analizarTodo() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            zonas.at(i).at(j)->analizadoTrue();
        }
    }
}

void ReservaNatural::alrededores(Explorador* e) {
    int x = e->getX();
    int y = e->getY();
    int opciones = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            string nomb = zonas.at(i).at(j)->getNombre();
            if (i == y && j == x) continue;

            if(abs(i - y) <= 1 && abs(j - x) <= 1 && nomb != "") {
                opciones++;
                cout << opciones << ". " << nomb << endl;
            }
        }
    }
}

void ReservaNatural::zonasCambio(Explorador *e, ReservaNatural* r) {
    vector<int> posibleX;
    vector<int> posibleY;
    int x = e->getX();
    int y = e->getY();
    int contador = 0;
    int n = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            string nomb = zonas.at(i).at(j)->getNombre();
            if(abs(i - y) <= 1 && abs(j - x) <= 1 && nomb != "" && !(i == y && j == x)) {
                posibleX.push_back(j);
                posibleY.push_back(i);
                contador++;
            }
        }
    }

    cin >> n;

    // CORREGIDO: Prevención de Crash por lectura de memoria inválida.
    if (n == 0) {
        return;
    }
    if (n < 1 || n > contador) {
        cout << "Ingrese una opcion valida." << endl;
        return;
    }

    int X = posibleX.at(n-1);
    int Y = posibleY.at(n-1);

    string zonaElegida = zonas.at(Y).at(X)->getNombre(); // Corrección matriz [Y][X]
    bool obst = zonas.at(Y).at(X)->getObstaculo();

    if (obst) {
        string pregunta = "";
        cout << "Hay un obstaculo. ¿Quieres intentar quitarlo? (Y/N)" << endl;
        cin >> pregunta;
        if (pregunta == "Y" || pregunta == "y") {
            zonas.at(Y).at(X)->quitarObstaculo(r, e);
            obst = zonas.at(Y).at(X)->getObstaculo();
            if (!obst) { // Si se logró quitar el obstáculo
                cout << "Cambias de zona hacia " << zonaElegida << endl;
                e->cambiarZona(X, Y);
            }
        }
        else {
            cout << "Decides no quitar el obstaculo." << endl;
        }
    }
    else {
        cout << "Cambias de zona hacia " << zonaElegida << endl;
        e->cambiarZona(X, Y);
    }
}

void ReservaNatural::zonaActual(Explorador *e, ReservaNatural* r) {
    int x = e->getX();
    int y = e->getY();
    zonas.at(y).at(x)->opciones(e, r, zonas.at(y).at(x));
}

vector<vector<Zona *> > ReservaNatural::getZonas() {
    return zonas;
}

void ReservaNatural::actualizarLab(LaboratorioAmbiental* l) {
    zonas.at(2).at(2) = l;
}