#include <iostream>
#include "obiekty.h"

using namespace std;

int main() {
    cout << "Tworzenie macierzy m1, m2, m3, i wektora w" << endl;
    Macierz2x2 m1, m2, m3;
    Wektor1x2 w(1, 2);

    cout << "m1:" << endl << m1 << endl;
    cout << "m2:" << endl << m2 << endl;
    cout << "m3:" << endl << m3 << endl;
    cout << "w:" << endl << w << endl;

    cout << "Ustawianie wartości pól w macierzch" << endl;
    m1.setA(1);
    m1.setC(2);
    m1.setB(4);
    m1.setD(4);

    m2.setA(1);
    m2.setC(1);
    m2.setB(1);
    m2.setD(1);

    m3.setA(3);

    cout << "Wypisanie macierzy m1, m2, m3:" << endl;
    cout << "m1:" << endl << m1 << endl;
    cout << "m2:" << endl << m2 << endl;
    cout << "m3:" << endl << m3 << endl;

    cout << "Dekrementacja macierzy --m, m--:" << endl;
    cout << "m1:" << endl << m1 << endl;
    cout << "m1:" << endl << --m1 << endl;
    cout << "m1:" << endl << m1-- << endl;
    cout << "m1:" << endl << m1 << endl;

    cout << "Dodawanie dwóch macierzy:" << endl;
    m1 += m2;
    cout << "m1:" << endl << m1 << endl;
    m3 = m1 + m2;
    cout << "m3:" << endl << m3 << endl;

    cout << "Mnożenie wektora przez liczbę:" << endl;
    cout << "w:" << endl << w << endl;
    w = w * 2;
    cout << "w * 2:" << endl << w << endl;
    w = 3 * w;
    cout << "3 * w:" << endl << w << endl;

    cout << "Zmiana znaku wektora:" << endl;
    w = -w;
    cout << "w:" << endl << w << endl;

    cout << "Porównanie dwóch wektorów:" << endl;
    Wektor1x2 w2;
    bool result = w != w2;
    cout << "w:" << endl << result << endl;

    cout << "Dostęp do pól wektora:" << endl;
    cout << "w:" << endl << w[0] << endl;

    cout << "Operator konwersji:" << endl;
    cout << "w:" << endl << (int)w << endl;

    return 0;
}