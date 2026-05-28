#include "Portal.h"
#include "Zona.h"
#include "Explorador.h"
#include <iostream>
using namespace std;

// CORREGIDO: Se quitó 'destino' del constructor base ya que no existe
Portal::Portal(int x, int y) : ObjetoInteractuable() {
    nombre = "Portal hacia otra zona";
    clase = "Portal hacia otra zona";
    peso = 0;
    desgaste = 0;
    recogible = false;
    destinoX = x;
    destinoY = y;
}

void Portal::atravesar(ReservaNatural* r, Explorador* e) {
    // CORREGIDO: Las variables correctas son destinoX y destinoY
    e->cambiarZona(destinoX, destinoY);
    vector<vector<Zona*>> zonasesss = r->getZonas();
    // CORREGIDO: Se añadió ->getNombre() porque la matriz guarda Zona*, no string
    string destino = zonasesss.at(destinoX).at(destinoY)->getNombre();
    cout << "El explorador se ha teletransportado a " << destino << endl;
    r->zonaActual(e, r);
}

void Portal::interactuar(ReservaNatural* r, Explorador* e) {
    string decision;
    cout << "quieres atravezar el portal? (Y/N)" << endl;
    cin >> decision;
    // CORREGIDO: Las letras 'y' y 'n' no tenían comillas, causando error de variable no declarada
    if (decision == "Y" || decision == "y") {
        atravesar(r, e);
    }
    else if (decision == "N" || decision == "n") {
        cout << "Prefieres no atravezar el portal" << endl;
    }
    else {
        cout << "da una opcion valida" << endl;
    }
}