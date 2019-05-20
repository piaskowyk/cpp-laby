
#include "Osoba.h"
using namespace program;
using namespace std;

bool Osoba::zapisz(ostream& out) const {
    out << imie << "," << nazwisko << "," << rok_ur << endl;
    return true;
}

bool Osoba::wczytaj(istream& in){
    string item;
    int rok;
    in >> imie >> item >> nazwisko >> item >> rok;
    return true;
}

std::ostream & operator << (std::ostream &out, const Osoba &osoba) {
    return out << osoba.pobierzImie();
}