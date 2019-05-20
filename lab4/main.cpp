#include <iostream>
#include "Punkt.h"
#include "Figura.h"
#include "Kolo.h"
#include "Trojkat.h"

using namespace geometry;

int main() {
    Punkt p1(1,2);
    Punkt p2(3,2);
    Punkt p3(5,6);

    Kolo k1(5, "koło", p1);
    cout << k1.opis() << " pole " << k1.pole() << endl;

    Kolo** koloArray = new Kolo*[3];
    koloArray[0] = new Kolo(5, "koło", p1);
    koloArray[1] = new Kolo(5, "koło", p1);
    koloArray[2] = new Kolo(5, "koło", p1);

    Trojkat** trojkatArray = new Trojkat*[3];
    trojkatArray[0] = new Trojkat(p1, p2, p3, "");
    trojkatArray[1] = new Trojkat(p1, p2, p3, "");
    trojkatArray[2] = new Trojkat(p1, p2, p3, "");
    cout << trojkatArray[0]->opis() << " pole " << k1.pole();


    return 0;
}