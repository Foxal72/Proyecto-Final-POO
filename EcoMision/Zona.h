#ifndef ECOMISION_ZONA_H
#define ECOMISION_ZONA_H

#include <iostream>
#include <vector>
#include <string>
#include "ObjetoInteractuable.h"
#include "ReservaNatural.h"
using std::vector;
using std::string;

// Declaraciones adelantadas para evitar inclusión circular
class Explorador;
class ReservaNatural;

class Zona {
protected:
    string nombreZona;
    bool zonaAnalizada;
    vector<ObjetoInteractuable*> objetosZona;
    bool obstaculo;
public:
    Zona();
    virtual ~Zona() {}
    
    void interactuarObjeto(int num, ReservaNatural* r, Explorador* e);
    string getNombre();
    void mostrarObjetos();
    void analizarZona(Explorador* e);
    void objetoRecogido(int n);
    vector<ObjetoInteractuable*> getObjetos();
    void tienedObstaculo();
    bool getObstaculo();
    void quitarObstaculo(ReservaNatural* r, Explorador* e);
    void analizadoTrue();
    virtual void opciones(Explorador* e, ReservaNatural* r, Zona* z);
    void ponerObjetos(ObjetoInteractuable* obj);
};

#endif