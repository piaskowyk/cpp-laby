//
// Created by mleko on 4/9/19.
//

#include "Pierscien.h"
using namespace geometry;

float Pierscien::pole() {
    return 3.14 * promien * promien - 3.14 * promien_wewn * promien_wewn;
}


bool Pierscien::zapisz(ostream& out) const {
    out << opis() << " - r = " << promien << " r_w = " << promien_wewn;
    srodek.zapisz(out);
    return true;
}

bool Pierscien::wczytaj(istream& in){
    in >> promien >> etykieta >> promien_wewn;
    srodek.wczytaj(in);
    return true;
}