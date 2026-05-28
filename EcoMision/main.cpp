//
// Created by User on 27/05/2026.
//
#include "EcoMision.h"
#include <iostream>
#include <vector>
#include <string>
#include "Zona.h"
//
// Created by User on 27/05/2026.
//
#include "EcoMision.h"
#include <iostream>
#include <vector>
#include <string>
#include "Zona.h"
#include "CentroRecuperacionAnimal.h"
#include "VivideroRestauracion.h"

using namespace std;

int main() {
    cout << "BIENVENIDO A ECOMISION" << endl;
    EcoMision* ecoo = new EcoMision;
    Explorador* e = ecoo->getExplorador();
    ReservaNatural* r = ecoo->getReserva();
    vector<vector<Zona*>> z = r->getZonas();

    int totalBasuraMundo = 0;
    int animalesMundo = 0;
    int plantasMundo = 0;

    // Contar objetivos totales iniciales en el mapa
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vector<ObjetoInteractuable*> o = z.at(i).at(j)->getObjetos();
            string nam = z.at(i).at(j)->getNombre();
            if (nam == "Río") {
                totalBasuraMundo += 3;
            }
            for (size_t k = 0; k < o.size(); k++) {
                string clasismo = o.at(k)->getClase();
                if (clasismo == "Animal Herido") {
                    animalesMundo++;
                }
                else if (clasismo == "Semilla Nativa") {
                    plantasMundo++;
                }
                else if (clasismo == "Residuo Contaminante" || clasismo == "Fuente Contaminada") {
                    totalBasuraMundo++;
                }
            }
        }
    }

    // Bucle de juego condicional corregido
    while (true) {
        int aheridos = 0;
        int sVotadas = 0;
        int basuraRestante = 0;

        // 1. Calcular animales curados en tiempo real (Coordenadas del Centro: 2,1)
        CentroRecuperacionAnimal* centro = dynamic_cast<CentroRecuperacionAnimal*>(r->getZonas().at(2).at(1));
        if (centro) {
            for (AnimalHerido* an : centro->getAnimales()) {
                if (an->getCurado()) {
                    aheridos++;
                }
            }
        }

        // 2. Calcular semillas entregadas en tiempo real (Coordenadas del Vividero: 2,3)
        VivideroRestauracion* vividero = dynamic_cast<VivideroRestauracion*>(r->getZonas().at(2).at(3));
        if (vividero) {
            sVotadas = vividero->getPlantas().size();
        }

        // 3. Calcular basura restante en el mapa entero e inventario
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                vector<ObjetoInteractuable*> objetosEnZona = r->getZonas().at(i).at(j)->getObjetos();
                for (ObjetoInteractuable* obj : objetosEnZona) {
                    if (obj->getClase() == "Residuo Contaminante" || obj->getClase() == "Fuente Contaminada") {
                        basuraRestante++;
                    }
                }
            }
        }
        for (ObjetoInteractuable* obj : e->getInventario()) {
            if (obj->getClase() == "Residuo Contaminante") {
                basuraRestante++;
            }
        }

        int desperdiciosSolucionados = totalBasuraMundo - basuraRestante;

        // Condición de victoria real y actualizada
        if (aheridos >= animalesMundo && sVotadas >= plantasMundo && desperdiciosSolucionados >= totalBasuraMundo) {
            break;
        }

        // Ejecutar el turno en la zona actual
        r->zonaActual(e, r);
    }

    cout << "Felicidades! Terminaste el juego con exito y salvaste la reserva." << endl;
    delete ecoo;
    return 0;
}