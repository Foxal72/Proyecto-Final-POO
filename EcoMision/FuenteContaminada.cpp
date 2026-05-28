#include "FuenteContaminada.h"

#include <iostream>

#include "ResiduoContaminante.h"

FuenteContaminada:: FuenteContaminada() {
    nombre = "Fuente Contaminada";
    clase = "Fuente Contaminada";
    peso = 0;
    desgaste = 0;
    recogible = false;
    this-> estaLimpia = false;
    
}

void FuenteContaminada::limpiar(Explorador* e){
    if (estaLimpia == false){
        estaLimpia = true;
        e->conseguirObjeto(new ResiduoContaminante());
        e->perderEnergia(3);
        std::cout<<"La fuente ha sido limpìada existosamente"<<std::endl;
    }else {
        std::cout<<"La fuente ya esta limpia "<<std::endl;
    }
}

void FuenteContaminada::interactuar(ReservaNatural* r, Explorador* e){
    string decision;
    cout << "quieres limpiar la fuente? (Y/N)" << endl;
    cin >> decision;
    if (decision == "Y" or decision == "y") {
        int fatiga = e->getEnergia();
        int peso = e->getEspacio();
        if (fatiga-3 < 0) {
            cout << "Estas muy cansado para limpiar la fuente" << endl;
        }
        else if (peso-4 < 0)
        {
            cout << "Te falta espacio para recoger la basura de la fuente" << endl;
        }
        else {
            limpiar(e);
        }
    }
    else if (decision == "N" or decision == "n") {
        cout << "decides no limpiar la fuente" << endl;
    }
    else {
        cout << "da una opcion valida" << endl;
    }

}
