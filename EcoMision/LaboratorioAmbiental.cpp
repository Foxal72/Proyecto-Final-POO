//
// Created by User on 25/05/2026.
//
#include "LaboratorioAmbiental.h"
#include "SemillaNativa.h" // Aseguramos inclusión para dynamic_cast

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;

LaboratorioAmbiental::LaboratorioAmbiental() {
    nombreZona = "Laboratorio Ambiental";
    zonaAnalizada = true;
    curas = 0;
}

void LaboratorioAmbiental::crearCuras(Explorador *e) {
    string plantitas = "Planta Medicinal";
    int totalCurasNuevas = 0;

    // CORREGIDO: Iteración segura directamente sobre el inventario real
    size_t i = 0;
    while (i < e->getInventario().size()) {
        if (e->getInventario().at(i)->getClase() == plantitas) {
            e->dejarObjeto(i);
            totalCurasNuevas++;
            // No incrementamos 'i' porque los elementos se desplazan a la izquierda
        } else {
            i++;
        }
    }
    curas += totalCurasNuevas;
    cout << "Has creado " << totalCurasNuevas << " curas, ahora tienes " << curas << endl;
}

void LaboratorioAmbiental::resiclarBasura(Explorador *e) {
    string basura = "Residuo Contaminante";
    int resitado = 0;

    // CORREGIDO: Iteración segura directamente sobre el inventario real
    size_t i = 0;
    while (i < e->getInventario().size()) {
        if (e->getInventario().at(i)->getClase() == basura) {
            e->dejarObjeto(i);
            resitado++;
        } else {
            i++;
        }
    }
    cout << "Has reciclado " << resitado << " residuos contaminantes." << endl;
}

void LaboratorioAmbiental::analizarAnimal(Explorador *e) {
    string achis = "Animal Herido";
    for (size_t i = 0; i < e->getInventario().size(); i++) {
        if (e->getInventario().at(i)->getClase() == achis) {
            AnimalHerido* ana = dynamic_cast<AnimalHerido*>(e->getInventario().at(i));
            if (ana) {
                ana->conocerAnimal();
                e->iventarioInteractuado(i, ana);
            }
        }
    }
}

void LaboratorioAmbiental::analizarSemilla(Explorador *e) {
    string sentomaru = "Semilla Nativa";
    for (size_t i = 0; i < e->getInventario().size(); i++) {
        if (e->getInventario().at(i)->getClase() == sentomaru) {
            SemillaNativa* semiciento = dynamic_cast<SemillaNativa*>(e->getInventario().at(i));
            if (semiciento) {
                semiciento->conocerSemilla();
                e->iventarioInteractuado(i, semiciento);
            }
        }
    }
}

void LaboratorioAmbiental::descansarLaboratorio(Explorador *e) {
    cout << "Pasas la noche en el laboratorio..." << endl;
    e->recargarEnergia();
    cout << "Te sientes como nuevo!!!" << endl;
}

int LaboratorioAmbiental::getCuras() {
    return curas;
}

void LaboratorioAmbiental::restarCura() {
    if (curas > 0) curas--;
}

void LaboratorioAmbiental::opciones(Explorador *e, ReservaNatural *r, Zona *z) {
    string nombre = getNombre();
    int opcion = 0;
    cout << "Estas en " << nombre << endl;
    cout << "Que haces?" << endl;
    cout << "1. Crear curas" << endl;
    cout << "2. Analizar animal" << endl;
    cout << "3. Analizar semilla" << endl;
    cout << "4. Descansar" << endl;
    cout << "5. Cambiar de zona" << endl;
    cout << "6. Mostrar inventario" << endl;
    cout << "7. Reciclar Basura" << endl; // CORREGIDO: Opción expuesta al jugador
    cin >> opcion;

    if (opcion == 1) {
        crearCuras(e);
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
        analizarAnimal(e);
    }
    else if (opcion == 3) {
        analizarSemilla(e);
    }
    else if (opcion == 4) {
        descansarLaboratorio(e);
    }
    else if (opcion == 6) {
        e->mostrarInventario();
    }
    else if (opcion == 7) {
        resiclarBasura(e);
    }
    else {
        cout << "Opcion no valida" << endl;
    }
}