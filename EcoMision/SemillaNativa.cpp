#include "SemillaNativa.h"

#include <iostream>

using std::string;

SemillaNativa:: SemillaNativa(string n, string d){
    this->descripcionPlnata = d;
    this->peso = 1;
    this->nombre = n;
    this->clase = "Semilla Nativa";
    this->recogible = true;
    this->semillaConocida = false;
    

}
void SemillaNativa::interactuar(ReservaNatural* r, Explorador* e) {
    
    std::cout<< "semilla recolectada"<<std::endl;
    
}
void SemillaNativa:: conocerSemilla(){
    
    if (semillaConocida == false){
        semillaConocida = true;
        std::cout<<"Semilla registrada"<< std::endl;


    }

    }

void SemillaNativa::mostrarInformacion() {
    if (semillaConocida == true) {
        cout << "Nombre: " << nombre << endl;
        cout << "Descripcion: " << descripcionPlnata << endl;
        cout << "Clase: " << clase   << endl;
        cout << "Peso: " << peso << endl;
    }
    else {
        string misterioMisterioso = "???";
        cout << "Nombre: " << misterioMisterioso << endl;
        cout << "Descripcion: " << misterioMisterioso << endl;
        cout << "Clase: " << clase   << endl;
        cout << "Peso: " << peso << endl;
    }
}

bool SemillaNativa::getAnalizadoP() {
    return semillaConocida;
}
