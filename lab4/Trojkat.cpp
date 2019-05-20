//
// Created by mleko on 4/9/19.
//

#include <cmath>
#include "Trojkat.h"

using namespace geometry;

float Trojkat::pole() {
    float a = sqrt(
            p1.getX() - p2.getX() * p1.getX() - p2.getX()
            +
            p1.getY() - p2.getY() * p1.getY() - p2.getY()
    );

    float b = sqrt(
            p1.getX() - p3.getX() * p1.getX() - p3.getX()
            +
            p1.getY() - p3.getY() * p1.getY() - p3.getY()
    );

    float c = sqrt(
            p2.getX() - p3.getX() * p2.getX() - p3.getX()
            +
            p2.getY() - p3.getY() * p2.getY() - p3.getY()
    );

    float p = (a+b+c)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}


bool Trojkat::zapisz(ostream& out) const {
    out << opis() << " - ";
    p1.zapisz(out);
    p1.zapisz(out);
    p1.zapisz(out);
    return true;
}

bool Trojkat::wczytaj(istream& in){
    in >> etykieta;
    p1.wczytaj(in);
    p2.wczytaj(in);
    p3.wczytaj(in);
    return true;
}