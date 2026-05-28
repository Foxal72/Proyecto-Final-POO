#include "SenderoMontania.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

SenderoMontania::SenderoMontania() {
    nombreZona = "Sendero de Montana";
    zonaAnalizada = false;
    analizasteTodo = false;
    obstaculo = false;
}

void SenderoMontania::analizarPaisaje(ReservaNatural* r, Explorador* e) {
    if (analizasteTodo) {
        cout << "Ya disfrutaste de la vista de este hermoso paisaje." << endl;
    } else {
        int energia = e->getEnergia();
        if (energia - 2 < 0) {
            cout << "Estas muy cansado para subir y analizar el paisaje." << endl;
        } else {
            analizasteTodo = true;
            e->perderEnergia(2);
            cout << "Subes a la parte mas alta del sendero y observas toda la reserva..." << endl;
            cout << "¡Tienes una vista espectacular de los alrededores!" << endl;
            r->analizarTodo(); // Revela todas las zonas de la reserva
            cout << "Has cartografiado toda la reserva natural." << endl;
        }
    }
}

void SenderoMontania::opciones(Explorador* e, ReservaNatural* r, Zona* z) {
    int opcion = 0;
    cout << "Estas en " << getNombre() << endl;
    cout << "Que haces?" << endl;
    cout << "1. Analizar zona" << endl;
    cout << "2. Objetos del lugar" << endl;
    cout << "3. Analizar Paisaje (Revelar mapa)" << endl;
    cout << "4. Cambiar de zona" << endl;
    cout << "5. Mostrar inventario" << endl;
    cin >> opcion;

    if (opcion == 1) {
        analizarZona(e);
    } else if (opcion == 2) {
        mostrarObjetos();
        int mostron;
        cout << "Con cual objeto vas a interactuar? (0 para volver)" << endl;
        cin >> mostron;
        if (mostron > 0 && mostron <= objetosZona.size()) {
            interactuarObjeto(mostron - 1, r, e);
        }
    } else if (opcion == 3) {
        analizarPaisaje(r, e);
    } else if (opcion == 4) {
        int aja = 0;
        cout << "A donde quieres ir? (0 para volver)" << endl;
        r->alrededores(e);
        cin >> aja;
        if (aja != 0) {
            r->zonasCambio(e, r);
        }
    } else if (opcion == 5) {
        e->mostrarInventario();
    } else {
        cout << "Opcion no valida." << endl;
    }
}