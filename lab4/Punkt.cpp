//
// Created by mleko on 4/9/19.
//

#include "Punkt.h"
#include <iostream>

using namespace std;
using namespace geometry;

bool Punkt::zapisz(ostream& out) const {
    out << "(" << x << "," << y << ")" << endl;
    return true;
}

bool Punkt::wczytaj(istream& in){
    in >> this->x >> this->y;
    return true;
}