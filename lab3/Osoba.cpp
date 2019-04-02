#include "Osoba.h"

Osoba::Osoba(string name, int year){
    imie = name;
    if(year < 1){
        year = 0;
    } else {
        rok = year;
    }
}