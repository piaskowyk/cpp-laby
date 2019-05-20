//
// Created by mleko on 4/9/19.
//

#ifndef LAB4_TROJKAT_H
#define LAB4_TROJKAT_H


#include "Punkt.h"
#include "Figura.h"

namespace geometry {
    class Trojkat : public Figura {
    protected:
        Punkt p1, p2, p3;
    public:
        Trojkat(Punkt _p1, Punkt _p2, Punkt _p3, const string & _etykieta): Figura(_p1, _etykieta), p1{_p1}, p2{_p2}, p3{_p3} {};
        virtual float pole();
        virtual bool zapisz(std::ostream & os) const;
        virtual bool wczytaj(std::istream & is);
    };

}


#endif //LAB4_TROJKAT_H
