#ifndef ECOMISION_OBJETOINTERACTUABLE_H
#define ECOMISION_OBJETOINTERACTUABLE_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
// Declaraciones adelantadas
class ReservaNatural;
class Explorador;

class ObjetoInteractuable {
protected:
    string nombre;
    string clase;
    int desgaste;
    int peso;
    bool recogible;
public:
    ObjetoInteractuable();
    //virtual ~ObjetoInteractuable() {}

    // Firma unificada para evitar errores de override
    virtual void interactuar(ReservaNatural* r, Explorador* e);
    virtual void mostrarInformacion();

    string getNombre();
    bool getRecogible();
    string getClase();
    int getPeso();
    int getDesgaste();
};

#endif
