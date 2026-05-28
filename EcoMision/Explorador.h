#ifndef ECOMISION_EXPLORADOR_H
#define ECOMISION_EXPLORADOR_H

#include <iostream>
#include <vector>
#include <string>
#include "ObjetoInteractuable.h"

using std::vector;
using std::string;

// Declaraciones adelantadas
class Zona;
class ReservaNatural;
class LaboratorioAmbiental;

class Explorador {
private:
    vector<ObjetoInteractuable*> inventario;
    int espacio;
    int energia;
    int X;
    int Y;
public:
    Explorador();
    void perderEnergia(int n);
    void recargarEnergia();
    void recogerObjeto(Zona* z, int n);
    void dejarObjeto(int n);
    void mostrarInventario();
    int getEnergia();
    int getEspacio();
    vector<ObjetoInteractuable*> getInventario();
    void cambiarZona(int x, int y);
    void iventarioInteractuado(int n, ObjetoInteractuable* o);
    void conseguirObjeto(ObjetoInteractuable* o);
    int getX() { return X; }
    int getY() { return Y; }
};

#endif