//
// Created by mleko on 4/9/19.
//

#ifndef LAB4_PIERSCIEN_H
#define LAB4_PIERSCIEN_H


#include "Kolo.h"

namespace geometry {
    class Pierscien : public Kolo{
    protected:
        float promien_wewn;
    public:
        Pierscien(float _r_w, float r, const string & _etykieta, Punkt pkt): Kolo(r, _etykieta, pkt), promien_wewn{_r_w} {};
        virtual float pole();
        virtual bool zapisz(std::ostream & os) const;
        virtual bool wczytaj(std::istream & is);
    };

}


#endif //LAB4_PIERSCIEN_H
