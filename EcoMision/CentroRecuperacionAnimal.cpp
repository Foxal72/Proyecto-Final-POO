//
// Created by User on 26/05/2026.
//
// Created by User on 26/05/2026.
//
#include "CentroRecuperacionAnimal.h"
#include "Zona.h"
#include "AnimalHerido.h"
#include "Explorador.h"
#include "LaboratorioAmbiental.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;

CentroRecuperacionAnimal::CentroRecuperacionAnimal() {
    nombreZona = "Centro de Recuperacion Animal";
    zonaAnalizada = true;
}

void CentroRecuperacionAnimal::descansarConLosAnimales(Explorador *e) {
    if (animales.empty()) {
        cout << "Duermes en el solitario Centro de Recuperacion Animal..." << endl;
        e->recargarEnergia();
        cout << "Te sientes como nuevo!!!" << endl;
    }
    else {
        int rangoMax = animales.size();
        int aleator = rand() % rangoMax;
        string bosheor = animales.at(aleator)->getNombre();
        cout << "Duermes junto a los animales rescatados..." << endl;
        e->recargarEnergia();
        cout << "Te sientes como nuevo!!!" << endl;
        cout << "..." << bosheor << " te miro mientras dormias\n";
    }
}

vector<AnimalHerido *> CentroRecuperacionAnimal::getAnimales() {
    return animales;
}

void CentroRecuperacionAnimal::mostrarAnimales() {
    for (size_t i = 0; i < animales.size(); i++) {
        cout << i + 1 << "." << endl;
        animales.at(i)->mostrarInformacion();
    }
}

void CentroRecuperacionAnimal::dejarAnimal(Explorador *e) {
    // CORREGIDO: Iteración segura sobre el inventario dinámico del explorador
    int i = 0;
    while (i < e->getInventario().size()) {
        ObjetoInteractuable* o = e->getInventario().at(i);
        if (o->getClase() == "Animal Herido") {
            AnimalHerido* ana = dynamic_cast<AnimalHerido*>(o);
            if (ana) {
                if (ana->getAnalizado()) {
                    animales.push_back(ana);
                    string seshama = ana->getNombre();
                    e->dejarObjeto(i); // Borra el objeto del inventario real
                    cout << "Dejaste a " << seshama << " en el Centro de Recuperacion Animal" << endl;
                    continue; // No incrementamos 'i' porque el siguiente elemento bajó a la posición actual
                } else {
                    cout << "Este animal no lo conoces, analizalo primero antes de dejarlo" << endl;
                }
            }
        }
        i++;
    }
}

void CentroRecuperacionAnimal::curarAnimal(LaboratorioAmbiental *l) {
    for (size_t i = 0; i < animales.size(); i++) {
        bool toyMalito = animales.at(i)->getCurado();
        if (!toyMalito) {
            if (l->getCuras() <= 0) {
                cout << "No te quedan curas en el laboratorio" << endl;
                break;
            }
            else {
                animales.at(i)->curar();
                l->restarCura(); // CORREGIDO: Ahora sí consume la cura del laboratorio
            }
        }
    }
}

void CentroRecuperacionAnimal::opciones(Explorador *e, ReservaNatural *r, Zona *z) {
    string nombre = getNombre();
    vector<vector<Zona*>> zos = r->getZonas();
    LaboratorioAmbiental* l = dynamic_cast<LaboratorioAmbiental *>(zos.at(2).at(2));
    int opcion = 0;

    cout << "Estas en " << nombre << endl;
    cout << "Que haces?" << endl;
    cout << "1. Dejar animales" << endl;
    cout << "2. Curar animales" << endl;
    cout << "3. Ver animales" << endl;
    cout << "4. Descansar" << endl;
    cout << "5. Cambiar de zona" << endl;
    cout << "6. Mostrar Inventario" << endl;
    cin >> opcion;

    if (opcion == 1) {
        dejarAnimal(e);
    }
    else if (opcion == 5) {
        int aja = 0;
        cout << "A donde quieres ir? (0 para volver)" << endl;
        r->alrededores(e);
        cin >> aja;
        if (aja != 0) {
            r->zonasCambio(e, r);
        }
    }
    else if (opcion == 2) {
        curarAnimal(l);
        r->actualizarLab(l);
    }
    else if (opcion == 3) {
        mostrarAnimales();
    }
    else if (opcion == 4) {
        descansarConLosAnimales(e);
    }
    else if (opcion == 6) {
        e->mostrarInventario();
    }
    else {
        cout << "Opcion no valida" << endl;
    }
}