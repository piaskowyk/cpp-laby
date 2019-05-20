//
// Created by mleko on 4/9/19.
//

#ifndef LAB4_FIGURA_H
#define LAB4_FIGURA_H


#include "Punkt.h"
#include <iostream>
using namespace std;

namespace geometry {
    class Figura {
    protected:
        Punkt srodek;
        string etykieta;
    public:
        Figura(Punkt & pkt, const string & _etykieta): srodek{pkt}, etykieta{_etykieta} {};
        void setEtykieta(const string & _etykieta) { etykieta = _etykieta; };
        const string opis() const;
        virtual float pole();
        virtual bool zapisz(std::ostream & os) const = 0;
        virtual bool wczytaj(std::istream & is) = 0;
    };
}


#endif //LAB4_FIGURA_H
