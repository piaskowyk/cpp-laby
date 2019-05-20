//
// Created by mleko on 4/9/19.
//

#include "Figura.h"
using namespace geometry;

const string Figura::opis() const {
    return "etykieta:" + etykieta + " - (" + to_string(srodek.getX()) + "," + to_string(srodek.getY()) + ")";
}

float Figura::pole() {
    return 0;
}

bool Figura::zapisz(ostream& out) const {
    out << "etykieta: " << etykieta;
    srodek.zapisz(out);
    return true;
}

bool Figura::wczytaj(istream& in){
    in >> etykieta;
    srodek.wczytaj(in);
    return true;
}