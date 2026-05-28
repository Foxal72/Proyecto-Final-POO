#include "EcoMision.h"

//
// Created by User on 27/05/2026.
//
EcoMision::EcoMision() {
    e = new Explorador();
    r = new ReservaNatural();
}
Explorador* EcoMision::getExplorador() {
    return e;
}
ReservaNatural* EcoMision::getReserva() {
    return r;
}