#include <iostream>
#include <stdexcept>
#include "Osoba.h"
#include "Grupa.h"

using namespace std;

int main() {
    cout << "Test lab3" << endl;
    Osoba osoba1;
    Osoba osoba2("Maciek", 5);
    Osoba osoba3("Maciek");
    Osoba osoba4(5);

    try {
        Osoba osoba5("", -5);
    }
    catch(exception& e) {
        cout<<e.what();
    }

    cout << "Osoba2" << osoba2.getImie() << ", " << osoba2.getRok() << endl;
    osoba2.setImie("Marek");
    osoba2.setRok(2000);
    cout << "Osoba2 po zmianie" << osoba2.getImie() << ", " << osoba2.getRok() << endl;

    cout << "Test Grupy" << endl;

    Grupa grupa;
    Grupa grupa1(2);

    cout << "Ilość osób w grupe: " << grupa.getElementCount() << " " << grupa.getTabSize() << endl;
    grupa.addOsoba(osoba1);
    grupa.addOsoba(osoba2);
    cout << "Ilość osób w grupe: " << grupa.getElementCount() << endl;

    try {
        grupa1.addOsoba(osoba1);
        grupa1.addOsoba(osoba2);
        grupa1.addOsoba(osoba3);
        grupa1.addOsoba(osoba4);
    }
    catch(exception& e) {
        cout<<"Exception: " << e.what() << endl;
    }

    Grupa grupaCopy(grupa);
    cout << "Ilość osób w grupe: " << grupaCopy.getElementCount() << endl;

    Grupa tmp = grupaCopy;
    cout << "Ilość osób w grupe: " << tmp.getElementCount() << endl;

    return 0;
}