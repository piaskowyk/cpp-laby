#pragma once

#include <iostream>

using namespace std;

class Osoba {

private:
    string imie;
    int rok;

public:
    Osoba(): Osoba("", 0) {};
    Osoba(string name): Osoba(name, 0) {};
    Osoba(int year): Osoba("", year) {};
    Osoba(string name, int year);
    const string &getImie() const { return imie; }
    void setImie(const string &name){ this->imie = name; };
    int getRok() const { return rok; };
    void setRok(int year) { (year < 1) ? this->rok = 0 : this->rok = year; };

};