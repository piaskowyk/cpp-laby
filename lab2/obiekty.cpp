#include <iostream>
#include "obiekty.h"

Punkt::Punkt(): x(0), y(0) {}

Punkt::Punkt(double x, double y): x{x}, y{y} {}

double Punkt::getX() const {
    return this->x;
}

double Punkt::getY() const{
    return this->y;
}

void Punkt::setX(double x){
    this->x = x;
}

void Punkt::setY(double y){
    this->y = y;
}

//###############################################################################

Macierz::Macierz(): Macierz(0,0,0) {} //mxx(0), myy(0), mxy(0) {}

Macierz::Macierz(double mxx, double myy, double mxy): mxx{mxx}, myy{myy}, mxy{mxy} {}

double Macierz::getMxx() const {
    return mxx;
}

void Macierz::setMxx(double mxx) {
    Macierz::mxx = mxx;
}

double Macierz::getMyy() const {
    return myy;
}

void Macierz::setMyy(double myy) {
    Macierz::myy = myy;
}

double Macierz::getMxy() const {
    return mxy;
}

void Macierz::setMxy(double mxy) {
    Macierz::mxy = mxy;
}

std::ostream & operator << (std::ostream &out, const Macierz &matrix) {
    return out <<
        "(0,0): " << matrix.getMxx() << std::endl <<
        "(1,0): " << matrix.getMxy() << std::endl <<
        "(0,1): " << matrix.getMyy() << std::endl <<
        "(1,1): " << matrix.getMxy() << std::endl;
}

std::ostream & operator << (std::ostream &out, const Punkt &pkt) {
    return out << "(" << pkt.getX() << "," << pkt.getY() << ")";
}


void Macierz::operator -= (const Macierz & matrix){
    this->mxy -= matrix.mxy;
    this->mxx -= matrix.mxx;
    this->myy -= matrix.myy;
}

Macierz Macierz::operator - (const Macierz & matrix){
    Macierz m;
    m.mxy = this->mxy - matrix.mxy;
    m.mxx = this->mxx - matrix.mxx;
    m.myy = this->myy - matrix.myy;

    return m;
}

Macierz::Macierz(const Macierz &other) {
    this->mxy = other.mxy;
    this->mxx = other.mxx;
    this->myy = other.myy;
}

Punkt Macierz::operator * (const Punkt & pkt){
    Punkt result;

    result.setX(this->mxx * pkt.getX() + this->mxy * pkt.getY());
    result.setX(this->myy * pkt.getX()  + this->mxy * pkt.getY());

    return result;
}

Punkt Punkt::operator * (const Macierz & matrix){
    Punkt result;

    result.setX(matrix.getMxx() * this->x + matrix.getMxy() * this->y);
    result.setX(matrix.getMyy() * this->x  + matrix.getMxy() * this->y);

    return result;
}

Macierz operator+(const Macierz &first, const Macierz &second) {
    Macierz result(first);

    result.setMxx(first.getMxx() + second.getMxx());
    result.setMxy(first.getMxy() + second.getMxy());
    result.setMyy(first.getMyy() + second.getMyy());

    return result;
}

Macierz operator * (const Macierz &matrix, const double &factor) {
    Macierz result(matrix);

    result.setMxx(matrix.getMxx() * factor);
    result.setMxy(matrix.getMxy() * factor);
    result.setMyy(matrix.getMyy() * factor);

    return result;
}

Macierz operator * (const double &factor, const Macierz &matrix) {
    Macierz result(matrix);

    result.setMxx(matrix.getMxx() * factor);
    result.setMxy(matrix.getMxy() * factor);
    result.setMyy(matrix.getMyy() * factor);

    return result;
}

Macierz& Macierz::operator--(){
    --this->myy;
    --this->mxx;
    --this->mxy;

    return *this;
}

Macierz * Macierz::operator--(int){
    this->myy--;
    this->mxx--;
    this->mxy--;

    return this;
}

Punkt& Punkt::operator-(){
    this->y *= -1;
    this->x *= -1;

    return *this;
}

bool Macierz::operator < (const Macierz & matrix){
    return this->mxx * this->myy - this->mxy * this->mxy < matrix.getMxx() * matrix.getMyy() - matrix.getMxy() * matrix.getMxy();
}

Macierz::operator double() {
    return this->getMxx() * this->getMyy() - this->getMxy() * this->getMxy();
}

double Punkt::operator [] (const int index){
    if(index != 0 && index != 1){
        throw "Index out of array.";
    }

    double out = 0;
    if(index == 0){
        out = this->x;
    }
    if(index == 1){
        out = this->y;
    }

    return out;
}

