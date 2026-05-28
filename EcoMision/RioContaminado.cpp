#include "RioContaminado.h"


#include <iostream>

#include "ResiduoContaminante.h"

using  std::cin;
RioContaminado:: RioContaminado(){
    
    estaLimpio = false;
    nombreZona = "Rio";
    zonaAnalizada = false;
    obstaculo = false;
}

void RioContaminado:: limpiar(Explorador* e){
    if (estaLimpio == false){
        int energia = e->getEnergia();
        int espacio = e->getEspacio();
        if (energia-10 < 0) {
            cout << "No tienes suficiente energia para limpiar el rio" << endl;
        }
        else if (espacio-12 < 0) {
            cout << "No tienes suficiente espacio para guardar la basura del rio" << endl;
        }
        else {
            estaLimpio = true;
            cout<< "Empiezas a limpiar el rio..."<< endl;
            e->perderEnergia(10);
            cout << "Has limpiado toda la basura del rio!!!" << endl;
            cout << "tienes que llevar a resiclar los residuos contaminantes" << endl;
            e->conseguirObjeto(new ResiduoContaminante());
            e->conseguirObjeto(new ResiduoContaminante());
            e->conseguirObjeto(new ResiduoContaminante());
        }

    }
}

void RioContaminado::opciones(Explorador *e, ReservaNatural *r, Zona *z) {
    string nombre = getNombre();
    int opcion = 0;
    string pregunta = "";
    cout << "Estas en " << nombre << endl;
    cout << "Que haces?" << endl;
    cout << "1. Analizar zona" << endl;
    cout << "2. Objetos del lugar" << endl;
    cout << "3. Limpiar Rio" << endl;
    cout << "4. Cambiar de zona" << endl;
    cout << "5. Mostrar inventario" << endl;
    cin >> opcion;
    if (opcion == 1) {
        analizarZona(e);

    }
    else if (opcion == 2) {
        mostrarObjetos();
        int mostron;
        cout << "Con cual objeto vas a interactuar?" << endl;
        cout << "si escribes 0, volveras a las opciones" << endl;
        cin >> mostron;
        if (mostron == 0) {

        }
        else if (mostron <= objetosZona.size()){
            int num = mostron-1;
            interactuarObjeto(num, r, e);

        }
    }
    else if (opcion == 4) {
        int aja = 0;
        cout << "A donde quieres ir? (0 para volver)" << endl;
        r ->alrededores(e);
        cin >> aja;
        if (aja == 0) {

        }
        else {
            r->zonasCambio(e,r);
        }
    }
    else if (opcion == 3) {
        limpiar(e);
    }
    else if (opcion == 5) {
        e->mostrarInventario();
    }
    else {
        cout << "opcion valida return" << endl;
        return;
    }
}