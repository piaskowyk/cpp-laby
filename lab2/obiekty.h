#pragma once

#include <ostream>

class Macierz2x2;

class Wektor1x2 {

private:
    int x;
    int y;

public:
    Wektor1x2();
    Wektor1x2(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    Wektor1x2& operator - ();
    int operator [] (int index) const;
    bool operator != (const Wektor1x2 & w) const;
    explicit operator int() const;

};

class Macierz2x2 {

private:
    int A;
    int B;
    int C;
    int D;

public:
    Macierz2x2();
    Macierz2x2(const Macierz2x2& other);
    Macierz2x2(int a, int b, int c, int d);
    int getA() const;
    void setA(int mxx);
    int getB() const;
    void setB(int myy);
    int getC() const;
    void setC(int mxy);
    int getD() const;
    void setD(int mxy);
    Wektor1x2 operator * (const Wektor1x2 & w) const;
    Macierz2x2 operator + (const Macierz2x2& second) const;
    Macierz2x2& operator += (const Macierz2x2& second);
    Macierz2x2& operator--();
    const Macierz2x2 operator--(int);

};

std::ostream & operator<< (std::ostream &out, const Macierz2x2 &matrix);
std::ostream & operator<< (std::ostream &out, const Wektor1x2 &pkt);

Wektor1x2 operator * (const Wektor1x2& w, const int& k);
Wektor1x2 operator * (const int& k, const Wektor1x2& w);