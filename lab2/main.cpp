#include <iostream>
#include "obiekty.h"

using namespace std;

int main() {
    cout << "Tworzenie macierzy m1, m2, m3" << endl;
    Macierz m1, m2, m3;
    cout << "m1:" << endl << m1 << endl;
    cout << "m2:" << endl << m2 << endl;
    cout << "m3:" << endl << m3 << endl;

    cout << "Ustawianie wartości pól w macierzch" << endl;
    m1.setMxx(1);
    m1.setMxy(2);
    m1.setMyy(4);

    m2.setMxx(1);
    m2.setMxy(1);
    m2.setMyy(1);

    m3.setMxx(3);
    cout << "Wypisanie macierzy m1, m2, m3:" << endl;
    cout << "m1:" << endl << m1 << endl;
    cout << "m2:" << endl << m2 << endl;
    cout << "m3:" << endl << m3 << endl;



    m3 = m1 - m2;
    cout<<m3<<endl;
    --m3;
    cout<<m3<<endl;
    m3--;
    cout<<m3<<endl;
    cout<<(double)m3<<endl;
    return 0;
}