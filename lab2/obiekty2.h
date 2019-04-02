#pragma once

#include <ostream>

class Macierz;

class Punkt {
private:
    double x;
    double y;

public:
    Punkt();
    Punkt(double x, double y);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    Punkt operator * (const Macierz & matrix);
    Punkt& operator - ();
    double operator [] (const int index);
};

class Macierz {
private:
    double mxx;
    double myy;
    double mxy;

public:
    Macierz();
    Macierz(const Macierz& other);
    Macierz(double mxx, double myy, double mxy);
    double getMxx() const;
    void setMxx(double mxx);
    double getMyy() const;
    void setMyy(double myy);
    double getMxy() const;
    void setMxy(double mxy);
    void operator -= (const Macierz & matrix);
    Macierz operator - (const Macierz & matrix);
    Punkt operator * (const Punkt & pkt);
    Macierz& operator--();
    Macierz * operator--(int);
    bool operator < (const Macierz & matrix);
    explicit operator double();
};

std::ostream & operator<< (std::ostream &out, const Macierz &matrix);
std::ostream & operator<< (std::ostream &out, const Punkt &pkt);
Macierz operator+(const Macierz& first,const Macierz& second);
Macierz operator * (const Macierz &matrix, const double &factor);
Macierz operator * (const double &factor, const Macierz &matrix);
