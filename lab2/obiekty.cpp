#include <iostream>
#include "obiekty.h"

Wektor1x2::Wektor1x2(): x(0), y(0) {}

Wektor1x2::Wektor1x2(int x, int y): x{x}, y{y} {}

int Wektor1x2::getX() const {
    return this->x;
}

int Wektor1x2::getY() const{
    return this->y;
}

void Wektor1x2::setX(int x){
    this->x = x;
}

void Wektor1x2::setY(int y){
    this->y = y;
}

std::ostream & operator << (std::ostream &out, const Wektor1x2 &pkt) {
    return out << "(" << pkt.getX() << "," << pkt.getY() << ")";
}

Wektor1x2 operator * (const Wektor1x2& w, const int& k){
    Wektor1x2 result;

    result.setX(w.getX() * k);
    result.setY(w.getY() * k);

    return result;
}

Wektor1x2 operator * (const int& k, const Wektor1x2& w){
    Wektor1x2 result;

    result.setX(k * w.getX());
    result.setY(k * w.getY());

    return result;
}

int Wektor1x2::operator [] (const int index) const {
    if(index != 0 && index != 1){
        throw "Index out of array.";
    }

    int out = 0;
    if(index == 0){
        out = this->x;
    }
    if(index == 1){
        out = this->y;
    }

    return out;
}

Wektor1x2& Wektor1x2::operator - (){
    this->y *= -1;
    this->x *= -1;

    return *this;
}

bool Wektor1x2::operator != (const Wektor1x2 &w) const {
    return this->y != w.getY() && this->x != w.getX();
}

Wektor1x2::operator int() const {
    return this->x * this->x + this->y * this->y;
}


//###############################################################################

Macierz2x2::Macierz2x2(): Macierz2x2(0, 0, 0, 0) {}

Macierz2x2::Macierz2x2(int a, int b, int c, int d): A{a}, B{b}, C{c}, D{d} {}

int Macierz2x2::getA() const {
    return A;
}

void Macierz2x2::setA(int a) {
    Macierz2x2::A = a;
}

int Macierz2x2::getB() const {
    return B;
}

void Macierz2x2::setB(int b) {
    Macierz2x2::B = b;
}

int Macierz2x2::getC() const {
    return C;
}

void Macierz2x2::setC(int c) {
    Macierz2x2::C = c;
}

int Macierz2x2::getD() const {
    return D;
}

void Macierz2x2::setD(int d) {
    Macierz2x2::D = d;
}

std::ostream & operator << (std::ostream &out, const Macierz2x2 &matrix) {
    return out <<
        "(0,0): " << matrix.getA() << std::endl <<
        "(1,0): " << matrix.getB() << std::endl <<
        "(0,1): " << matrix.getC() << std::endl <<
        "(1,1): " << matrix.getD() << std::endl;
}

Macierz2x2::Macierz2x2(const Macierz2x2 &other) {
    this->C = other.C;
    this->A = other.A;
    this->B = other.B;
    this->D = other.D;
}

Wektor1x2 Macierz2x2::operator * (const Wektor1x2 & w) const {
    Wektor1x2 result;

    result.setX(this->A * w.getX() + this->C * w.getY());
    result.setX(this->B * w.getX()  + this->D * w.getY());

    return result;
}

Macierz2x2 Macierz2x2::operator + (const Macierz2x2 &second) const {
    Macierz2x2 result;

    result.A = this->A + second.A;
    result.C = this->C + second.C;
    result.B = this->B + second.B;
    result.D = this->D + second.D;

    return result;
}

Macierz2x2& Macierz2x2::operator += (const Macierz2x2 &second) {

    this->A += second.A;
    this->B += second.B;
    this->C += second.C;
    this->D += second.D;

    return *this;
}

Macierz2x2& Macierz2x2::operator -- (){
    --this->A;
    --this->B;
    --this->C;
    --this->D;

    return *this;
}

const Macierz2x2 Macierz2x2::operator -- (int){
    Macierz2x2 mCp(*this);

    this->A--;
    this->B--;
    this->C--;
    this->D--;

    return mCp;
}