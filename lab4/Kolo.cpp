//
// Created by mleko on 4/9/19.
//

#include "Kolo.h"
#include <ostream>
using namespace std;
using namespace geometry;

float Kolo::pole() {
    return 3.14 * promien * promien;
}


bool Kolo::zapisz(ostream& out) const {
    out << opis() << " - r = " << promien;
    srodek.zapisz(out);
    return true;
}

bool Kolo::wczytaj(istream& in){
    in >> promien >> etykieta;
    srodek.wczytaj(in);
    return true;
}