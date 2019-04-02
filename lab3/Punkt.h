#pragma once

class Punkt {

private:
    float x;
    float y;

public:
    Punkt(): Punkt(.0, .0) {};
    Punkt(float x, float y): x(x), y(y) {};
    float getX() const { return x; };
    float getY() const { return y; };

    void setX(float x){ this->x = x; };
    void setY(float y) { this->y = y; };

};