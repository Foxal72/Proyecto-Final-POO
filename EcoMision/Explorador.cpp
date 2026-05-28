//
// Created by User on 24/05/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include "Explorador.h"
#include "CentroRecuperacionAnimal.h"
#include "Zona.h"
#include "AnimalHerido.h"
#include "Explorador.h"
#include "LaboratorioAmbiental.h"
#include "CentroRecuperacionAnimal.h"
#include "Zona.h"
#include "AnimalHerido.h"
#include "Explorador.h"
#include "LaboratorioAmbiental.h"
using std::vector;
using std::cout;
using std::endl;
using std::string;

Explorador::Explorador() {
    espacio = 20;
    energia = 20;
    X = 2;
    Y = 2;
}
//void Explorador::interactuar(int n, Zona* z, Explorador* e) {
//    z->interactuarObjeto(n, z, e);
//}

vector<ObjetoInteractuable*> Explorador::getInventario() {
    return inventario;
}

void Explorador::perderEnergia(int n) {
    cout << "Perdiste " << n << " de energia" << endl;
    energia -= n;
}

void Explorador::recogerObjeto(Zona* z, int n) {
    vector<ObjetoInteractuable*> o = z->getObjetos();
    inventario.push_back(o.at(n));
    int ufquepeso = o.at(n)->getPeso();
    espacio -= ufquepeso;
}

void Explorador::dejarObjeto(int n) {
    ObjetoInteractuable* objetazo = inventario.at(n);
    int suPesao = objetazo->getPeso();
    espacio += suPesao;
    inventario.erase(inventario.begin()+n);
}

int Explorador::getEspacio() {
    return espacio;
}

int Explorador::getEnergia() {
    return energia;
}

void Explorador::recargarEnergia() {
    energia = 20;
}

void Explorador::iventarioInteractuado(int n, ObjetoInteractuable* o) {
    inventario.at(n) = o;
}

void Explorador::conseguirObjeto(ObjetoInteractuable *o) {
    inventario.push_back(o);
}




void Explorador::cambiarZona(int x, int y) {
    X = x;
    Y = y;
}
void Explorador::mostrarInventario(){
    cout << "Inventario" << endl;
    for (int i = 0; i < inventario.size(); i++) {
        string oyo = inventario.at(i) -> getClase();
        cout << i+1 << ". " << oyo << endl;
    }
}