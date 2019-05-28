
#include "Zwierze.h"

bool Zwierze::operator==(const Zwierze &cmp) const {
    return imie == cmp.imie && gatunek == cmp.gatunek;
}

string Zwierze::getDesc() const{
    return imie + " " + gatunek + " " + to_string(wiek);
}

string Zwierze::getKey() const{
    return imie + gatunek;
}

int Zwierze::getAge() const {
    return wiek;
}

string Zwierze::getType() const {
    return gatunek;
}

void Zwierze::setAge(int _wiek) {
    wiek = _wiek;
}
