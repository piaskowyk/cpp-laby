#include "Osoba.h"

bool Osoba::operator==(const Osoba &cmp) const {
    return imie == cmp.imie && nazwisko == cmp.nazwisko;
}

string Osoba::getDesc() {
    return imie + " " + nazwisko + " " + to_string(rok_urodzenia);
}
