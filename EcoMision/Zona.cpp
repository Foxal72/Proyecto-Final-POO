//
// Created by User on 19/05/2026.
//
#include <iostream>
#include <vector>
#include "Zona.h"
#include "AnimalHerido.h"
#include "Obstaculo.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;

Zona::Zona() {
    nombreZona = "";
    zonaAnalizada = false;
    obstaculo = false;
}

string Zona::getNombre() {
    return nombreZona;
}

void Zona::mostrarObjetos() {
    if (zonaAnalizada) {
        if (objetosZona.empty()) {
            cout << "No hay objetos en la zona." << endl;
        } else {
            for (size_t i = 0; i < objetosZona.size(); i++) {
                ObjetoInteractuable* o = objetosZona.at(i);
                cout << i + 1 << ". " << o->getClase() << " (" << o->getNombre() << ")" << endl;
            }
        }
    } else {
        cout << "No se conoce la zona, analizala primero." << endl;
    }
}

void Zona::analizarZona(Explorador* e) {
    if (zonaAnalizada) {
        cout << "Ya conoces esta zona como la palma de tu mano." << endl;
    } else {
        int cheko = e->getEnergia();
        if (cheko - 1 < 0) {
            cout << "No tienes suficiente energia para analizar la zona." << endl;
        } else {
            zonaAnalizada = true;
            e->perderEnergia(1);
            cout << "Compruebas tus entornos...." << endl;
            cout << "Ahora puedes ver todos los objetos de la zona." << endl;
        }
    }
}

void Zona::interactuarObjeto(int num, ReservaNatural* r, Explorador* e) {
    ObjetoInteractuable* ob = objetosZona.at(num);
    int mcanso = ob->getDesgaste();
    int keCansado = e->getEnergia();

    if (keCansado - mcanso < 0) {
        cout << "Estas demasiado cansado para hacer eso." << endl;
    } else {
        ob->interactuar(r, e);
        bool res = ob->getRecogible();
        if (res) {
            int mushoPeso = e->getEspacio();
            int taPesao = ob->getPeso();
            if (mushoPeso - taPesao < 0) {
                cout << "No tienes espacio en tu inventario." << endl;
            } else {
                e->recogerObjeto(this, num);
                objetoRecogido(num);
                cout << "Objeto guardado en el inventario." << endl;
            }
        }
    }
}

void Zona::objetoRecogido(int n) {
    objetosZona.erase(objetosZona.begin() + n);
}

vector<ObjetoInteractuable*> Zona::getObjetos() {
    return objetosZona;
}

void Zona::tienedObstaculo() {
    for (size_t i = 0; i < objetosZona.size(); i++) {
        if (objetosZona.at(i)->getClase() == "obstaculo") {
            obstaculo = true;
            cout << "Hay un obstaculo que impide el paso." << endl;
        }
    }
}

bool Zona::getObstaculo() {
    return obstaculo;
}

void Zona::quitarObstaculo(ReservaNatural* r, Explorador* e) {
    if (obstaculo) {
        for (size_t i = 0; i < objetosZona.size(); i++) {
            if (objetosZona.at(i)->getClase() == "obstaculo") {
                Obstaculo* o = dynamic_cast<Obstaculo*>(objetosZona.at(i));
                if (o) {
                    int energy = o->getDesgaste();
                    if (e->getEnergia() - energy < 0) {
                        cout << "No tienes suficiente energia para quitar el obstaculo." << endl;
                        break;
                    } else {
                        o->interactuar(r, e);
                        obstaculo = false;
                        objetosZona.erase(objetosZona.begin() + i); // Borrar obstaculo del mapa
                        break;
                    }
                }
            }
        }
    }
}

void Zona::analizadoTrue() {
    zonaAnalizada = true;
}

void Zona::opciones(Explorador* e, ReservaNatural* r, Zona* z) {
    int opcion = 0;
    cout << "Estas en " << getNombre() << endl;
    cout << "Que haces?" << endl;
    cout << "1. Analizar zona" << endl;
    cout << "2. Objetos del lugar" << endl;
    cout << "3. Cambiar de zona" << endl;
    cout << "4. Mostrar inventario" << endl;
    cin >> opcion;

    if (opcion == 1) {
        analizarZona(e);
    }
    else if (opcion == 2) {
        mostrarObjetos();
        if (zonaAnalizada && !objetosZona.empty()) {
            int mostron;
            cout << "Con cual objeto vas a interactuar? (escribe 0 para volver): ";
            cin >> mostron;
            // CORREGIDO: Validación correcta del índice ingresado por el usuario
            if (mostron > 0 && mostron <= objetosZona.size()) {
                interactuarObjeto(mostron - 1, r, e);
            }
        }
    }
    else if (opcion == 3) {
        int aja = 0;
        cout << "A donde quieres ir? (0 para volver)" << endl;
        r->alrededores(e);
        cin >> aja;
        if (aja != 0) {
            r->zonasCambio(e, r);
        }
    }
    else if (opcion == 4) {
        e->mostrarInventario();
    }
    else {
        cout << "Opcion no valida." << endl;
    }
}

void Zona::ponerObjetos(ObjetoInteractuable *obj) {
    objetosZona.push_back(obj);
    // CORREGIDO: Activa automáticamente la bandera si el objeto es un obstáculo
    if (obj->getClase() == "obstaculo") {
        obstaculo = true;
    }
}