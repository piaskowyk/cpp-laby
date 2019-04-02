#include "Wielokat.h"
#include <iostream>

Wielokat::Wielokat(int size) {
    elementCount = 0;
    tabSize = size;
    punkty = new Punkt[size];
}

Wielokat::Wielokat(const Wielokat &other) {
    this->elementCount = other.elementCount;
    this->tabSize = other.tabSize;
    this->punkty = new Punkt[other.tabSize];

    for(int i = 0; i < other.elementCount; i++){
        this->punkty[i] = other.punkty[i];
    }
}

Wielokat::Wielokat(Wielokat &&other) noexcept {
    elementCount = other.elementCount;
    tabSize = other.tabSize;
    punkty = other.punkty;

    other.elementCount = 0;
    other.tabSize = 0;
    other.punkty = nullptr;
}

Wielokat& Wielokat::operator = (Wielokat&& other)
{
    if (this != &other)
    {
        delete[] punkty;

        punkty = other.punkty;
        elementCount = other.elementCount;
        tabSize = other.tabSize;

        other.punkty = nullptr;
        other.elementCount = 0;
        other.tabSize = 0;
    }
    return *this;
}

Wielokat& Wielokat::operator = (const Wielokat&& other)
{
    if (this != &other)
    {
        delete[] punkty;

        punkty = other.punkty;
        elementCount = other.elementCount;
        tabSize = other.tabSize;
    }
    return *this;
}

void Wielokat::addPunkt(Punkt &osoba) {
    if(elementCount < tabSize){
        punkty[elementCount] = osoba;
        elementCount++;
    } else {
        throw std::runtime_error("Brak miejsca na kolejny punkt w tablic");
    }
}


Punkt & Wielokat::operator[](size_t index) {
    if(index >= 0 && index < elementCount){
        return punkty[index];
    } else {
        throw std::runtime_error("Indeks z poza tablicy.");
    }
}

const Punkt & Wielokat::operator[](size_t index) const {
    if(index >= 0 && index < elementCount){
        return punkty[index];
    } else {
        throw std::runtime_error("Indeks z poza tablicy.");
    }
}