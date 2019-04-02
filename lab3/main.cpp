#include <iostream>
#include "Punkt.h"
#include "Wielokat.h"

using namespace std;

int main() {
    cout << "Test lab3" << endl;
    Punkt punkt1;
    Punkt punkt2(2, 5);
    Punkt punkt3(10, 11);
    Punkt punkt4(5, 8);

    cout << "Punkt2: " << punkt2.getX() << ", " << punkt2.getY() << endl;
    punkt2.setX(5);
    punkt2.setY(12);
    cout << "Punkt2 po zmianie" << punkt2.getX() << ", " << punkt2.getY() << endl;

    cout << "Test Wielokątów" << endl;

    Wielokat wielokat(20);
    Wielokat wielokat1;

    cout << "Ilość pkt: " << wielokat.getElementCount() << " " << wielokat.getTabSize() << endl;
    wielokat.addPunkt(punkt1);
    wielokat.addPunkt(punkt2);
    cout << "Ilość pkt: " << wielokat.getElementCount() << endl;

    try {
        wielokat1.addPunkt(punkt1);
        wielokat1.addPunkt(punkt2);
        wielokat1.addPunkt(punkt3);
        wielokat1.addPunkt(punkt4);
    }
    catch(exception& e) {
        cout<<"Exception: " << e.what() << endl;
    }

    Wielokat wielokatCopy(wielokat);
    cout << "Ilość pkt: " << wielokatCopy.getElementCount() << endl;

    Wielokat tmp = wielokatCopy;
    cout << "Ilość pkt: " << tmp.getElementCount() << endl;
    cout << "pkt[1]: (" << tmp[1].getX() << ", " << tmp[1].getY() << ")" << endl;

    Wielokat w1;
    Punkt pkt(3,4);
    w1.addPunkt(pkt);
    Wielokat w2;
    w2 = std::move(w1);
    cout << "pkt[0]: (" << w2[0].getX() << ", " << w2[0].getY() << ")" << endl;

    return 0;
}