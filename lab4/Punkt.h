//
// Created by mleko on 4/9/19.
//

#ifndef LAB4_PUNKT_H
#define LAB4_PUNKT_H


#include <ostream>

namespace geometry {

    class Punkt {
    private:
        float x;
        float y;
    public:
        Punkt(float _x, float _y): x{_x}, y{_y}{};
        float getX() const { return x; };
        float getY() const { return y; };
        void setX(const float _x) { x = _x; };
        void setY(const float _y) { y = _y; };
        bool zapisz(std::ostream & os) const;
        bool wczytaj(std::istream & is);
    };

}



#endif //LAB4_PUNKT_H
