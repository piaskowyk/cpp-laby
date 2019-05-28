

#ifndef LAB6_ZWIERZE_H
#define LAB6_ZWIERZE_H

#include <iostream>
#include <string.h>
using namespace std;

class Zwierze {
private:
    string imie;
    string gatunek;
    int wiek;

public:
    Zwierze(string _imie, string _gatunek, int _wiek) : imie(_imie), gatunek(_gatunek), wiek(_wiek) {}
    Zwierze() {
        string names[] = {"Rysiek", "Marek", "Patryk"};
        string type[] = {"Kot", "Pies", "Ryba"};
        imie = names[rand()%3];
        gatunek = type[rand()%3];
        wiek = rand() % 20 + 1;
    }
    bool operator==(const Zwierze& cmp) const;
    bool operator<(const Zwierze& cmp) const {return imie < cmp.imie && gatunek < cmp.gatunek; }
    string getDesc() const;
    string getKey() const;
    int getAge() const;
    string getType() const;
    void setAge(int _wiek);
};


#endif //LAB6_ZWIERZE_H
