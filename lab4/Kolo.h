//
// Created by mleko on 4/9/19.
//

#ifndef LAB4_KOLO_H
#define LAB4_KOLO_H


#include "Figura.h"

namespace geometry {

    class Kolo : public Figura{
    protected:
        float promien;
    public:
        Kolo(float _r, const string & _etykieta, Punkt pkt): Figura(pkt, _etykieta), promien{_r} {};
        virtual float pole();
        virtual bool zapisz(std::ostream & os) const;
        virtual bool wczytaj(std::istream & is);
    };

}


#endif //LAB4_KOLO_H
