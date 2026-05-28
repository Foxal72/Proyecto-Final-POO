//
// Created by User on 22/05/2026.
//
#include "AnimalHerido.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

AnimalHerido::AnimalHerido(string n, int p, string d) {
    nombre = n;
    peso = p;
    desgaste = 0;
    descripcionAnimal = d;
    clase = "Animal Herido";
    recogible = true;
    estaCurado = false;
    animalConocido = false;
}

void AnimalHerido::interactuar(ReservaNatural* r, Explorador* e) {
    cout << "Has rescadado el animal herido" << endl;
}

void AnimalHerido::conocerAnimal() {
    if (animalConocido  == true) {
        cout << "ya conoces este animal"<< endl;
    }
    else {
        animalConocido = true;
        cout << "El animal se llama " << nombre << " y el " << descripcionAnimal << endl;
    }
}

void AnimalHerido::curar() {
    estaCurado = true;
    cout << "has curado a " << nombre << " :D."<< endl;

}
void AnimalHerido::mostrarInformacion() {
    string sino = "";
    if (estaCurado == true) {
        sino = "Si";
    }
    else {
        sino = "No";
    }
    if (animalConocido == true) {
        cout << "Nombre: " << nombre << endl;
        cout << "Descripcion: " << descripcionAnimal << endl;
        cout << "Clase: " << clase   << endl;
        cout << "Peso: " << peso << endl;
        cout << "Fue Curado? " << sino << endl;
    }
    else {
        string misterioMisterioso = "???";
        cout << "Nombre: " << misterioMisterioso << endl;
        cout << "Descripcion: " << misterioMisterioso << endl;
        cout << "Clase: " << clase   << endl;
        cout << "Peso: " << peso << endl;
        cout << "Fue Curado? " << sino << endl;
    }
}

bool AnimalHerido::getCurado() {
    return estaCurado;
}

bool AnimalHerido::getAnalizado() {
    return animalConocido;
}
