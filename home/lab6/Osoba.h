//
// Created by mleko on 5/28/19.
//

#ifndef LAB6_OSOBA_H
#define LAB6_OSOBA_H

#include <iostream>
#include <string.h>
using namespace std;
class Osoba {
private:
    string imie;
    string nazwisko;
    int rok_urodzenia;

public:
    Osoba(string _imie, string _nazwisko, int _rok_urodzenia) : imie(_imie), nazwisko(_nazwisko), rok_urodzenia(_rok_urodzenia) {}
    Osoba() {
        string names[] = {"Rysiek", "Marek", "Patryk"};
        string surnames[] = {"Kot", "Pies", "Koło"};
        imie = names[rand()%3];
        nazwisko = surnames[rand()%3];
        rok_urodzenia = rand() % 60 + 1950;
    }
    bool operator==(const Osoba& cmp) const;
    bool operator<(const Osoba& cmp) const {return imie < cmp.imie && nazwisko < cmp.nazwisko; }
    string getDesc();
};


#endif //LAB6_OSOBA_H
