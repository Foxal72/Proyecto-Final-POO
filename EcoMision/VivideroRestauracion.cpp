//
// Created by User on 26/05/2026.
//
#include "VivideroRestauracion.h"

VivideroRestauracion::VivideroRestauracion() {
    nombreZona = "Vividero de Restauracion";
    zonaAnalizada = true;
}

vector<SemillaNativa *> VivideroRestauracion::getPlantas() {
    return plantas;
}

void VivideroRestauracion::mostrarPlantas() {
    for (size_t i = 0; i < plantas.size(); i++) {
        cout << i + 1 << "." << endl;
        plantas.at(i)->mostrarInformacion();
    }
}

void VivideroRestauracion::dejarSemilla(Explorador *e) {
    size_t i = 0;
    while (i < e->getInventario().size()) {
        ObjetoInteractuable* o = e->getInventario().at(i);
        if (o->getClase() == "Semilla Nativa") {
            SemillaNativa* similla = dynamic_cast<SemillaNativa*>(o);
            if (similla) {
                if (similla->getAnalizadoP()) {
                    plantas.push_back(similla);
                    string sumilla = similla->getNombre();
                    e->dejarObjeto(i);
                    cout << "Plantaste a " << sumilla << " en el Vividero de Restauracion." << endl;
                    continue; // No avanzamos el índice porque el vector se acortó
                } else {
                    cout << "Esta semilla no la conoces, analizala primero antes de plantarla." << endl;
                }
            }
        }
        i++;
    }
}

void VivideroRestauracion::opciones(Explorador *e, ReservaNatural *r, Zona *z) {
    string nombre = getNombre();
    int opcion = 0;
    cout << "Estas en " << nombre << endl;
    cout << "Que haces?" << endl;
    cout << "1. Dejar semilla" << endl;
    cout << "2. Ver plantas" << endl;
    cout << "3. Cambiar de zona" << endl;
    cout << "4. Mostrar Inventario" << endl;
    cin >> opcion;

    if (opcion == 1) {
        dejarSemilla(e);
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
    else if (opcion == 2) {
        mostrarPlantas();
    }
    else if (opcion == 4) {
        e->mostrarInventario();
    }
    else {
        cout << "Elija una opcion valida." << endl;
    }
}